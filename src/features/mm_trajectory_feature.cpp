#include "mm_trajectory_feature.h"

#include "math/transforms.h"
#include "mm_root_velocity_feature.h"

#include <godot_cpp/classes/editor_node3d_gizmo_plugin.hpp>
#include <godot_cpp/classes/point_mesh.hpp>
#include <godot_cpp/classes/sphere_mesh.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>

MMTrajectoryFeature::MMTrajectoryFeature() {
}

MMTrajectoryFeature::~MMTrajectoryFeature() {
}

uint32_t MMTrajectoryFeature::get_dimension_count() const {
    return _get_point_dimension_count() * (past_frames + future_frames);
}

void MMTrajectoryFeature::setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {
    const StringName skel_path = p_player->get_root_motion_track().get_concatenated_names();
    const StringName root_bone_name = p_player->get_root_motion_track().get_concatenated_subnames();
    _root_bone = p_skeleton->find_bone(root_bone_name);

    _root_bone_path = UtilityFunctions::str(skel_path) + ":" + UtilityFunctions::str(root_bone_name);
}

void MMTrajectoryFeature::setup_for_animation(Ref<Animation> animation) {
    _root_position_track = animation->find_track(_root_bone_path, Animation::TrackType::TYPE_POSITION_3D);
    _root_rotation_track = animation->find_track(_root_bone_path, Animation::TrackType::TYPE_ROTATION_3D);
}

PackedFloat32Array MMTrajectoryFeature::bake_animation_pose(Ref<Animation> p_animation, float time) const {
    PackedFloat32Array result;

    const Vector3 current_pos = p_animation->position_track_interpolate(_root_position_track, time);
    const Quaternion current_rotation = p_animation->rotation_track_interpolate(_root_rotation_track, time);

    auto add_frame = [this, &result, &p_animation, &current_pos, &current_rotation](float time) {
        Vector3 position;
        Quaternion rotation;
        if (_root_position_track != -1) {
            position = p_animation->position_track_interpolate(_root_position_track, time) - current_pos;
            position = current_rotation.xform_inv(position);
        }

        if (_root_rotation_track != -1) {
            rotation = p_animation->rotation_track_interpolate(_root_rotation_track, time) * current_rotation.inverse();
        }

        result.append(position.x);

        if (include_height) {
            result.append(position.y);
        }

        result.append(position.z);

        if (include_facing) {
            const Vector3 facing = rotation.get_euler();
            result.append(facing.y);
        }
    };

    // We do not include the first frame
    for (size_t i = 1; i < future_frames + 1; i++) {
        const float future_time = UtilityFunctions::clampf(time + future_delta_time * i, 0.0f, p_animation->get_length());

        add_frame(future_time);
    }

    for (size_t i = 1; i < past_frames + 1; i++) {
        const float past_time = UtilityFunctions::clampf(time - past_delta_time * i + 1, 0.0f, p_animation->get_length());

        add_frame(past_time);
    }

    return result;
}

PackedFloat32Array MMTrajectoryFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    const Transform3D& character_transform = p_query_input.character_transform;

    // Get the trajectory points in local space
    PackedFloat32Array result;
    auto add_point = [this, &character_transform, &result](int index, const MMTrajectoryPoint& trajectory_point) {
        const Vector3 local_position = character_transform.basis.xform_inv(trajectory_point.position - character_transform.origin);

        result.append(local_position.x);
        if (include_height) {
            result.append(local_position.y);
        }
        result.append(local_position.z);
        if (include_facing) {
            const float facing = trajectory_point.facing_angle;
            result.append(global_to_local_facing_angle(trajectory_point.facing_angle, character_transform));
        }
    };

    // We do not match the first point of the trajectory (character position)
    for (int i = 1; i < future_frames + 1; i++) {
        add_point(i, p_query_input.trajectory[i]);
    }

    for (size_t i = 1; i < past_frames + 1; i++) {
        add_point(i, p_query_input.trajectory_history[i]);
    }

    return result;
}

void MMTrajectoryFeature::display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const {

    Ref<StandardMaterial3D> material = p_gizmo->get_plugin()->get_material("main", p_gizmo);
    if (material.is_null()) {
        p_gizmo->get_plugin()->create_material("main", Color(1, 0, 0, 1));
        material = p_gizmo->get_plugin()->get_material("main", p_gizmo);
    }

    float* dernomalized_data = new float[get_dimension_count()];
    memcpy(dernomalized_data, p_data, sizeof(float) * get_dimension_count());
    denormalize(dernomalized_data);

    for (size_t i = 0; i < future_frames * _get_point_dimension_count(); i += _get_point_dimension_count()) {
        Ref<SphereMesh> sphere_mesh;
        sphere_mesh.instantiate();
        sphere_mesh->set_radius(0.10);
        sphere_mesh->set_height(0.10);
        sphere_mesh->set_material(material);

        MMTrajectoryPoint point;
        point.position = Vector3(dernomalized_data[i], include_height ? dernomalized_data[i + 1] : 0, include_height ? dernomalized_data[i + 2] : dernomalized_data[i + 1]);
        point.position = p_transform.xform(point.position);

        Transform3D point_transform = Transform3D();
        point_transform.origin = point.position;
        p_gizmo->add_mesh(sphere_mesh, material, point_transform, nullptr);
    }

    delete[] dernomalized_data;
}

TypedArray<Dictionary> MMTrajectoryFeature::get_trajectory_points(const Transform3D& p_character_transform, const PackedFloat32Array& p_trajectory_data) const {
    PackedFloat32Array denormalized_data = PackedFloat32Array(p_trajectory_data);
    denormalize(denormalized_data.ptrw());

    TypedArray<Dictionary> result;
    const int offset = _get_point_dimension_count();
    for (int i = 0; i < future_frames * offset; i += offset) {
        MMTrajectoryPoint point;
        point.position = Vector3(denormalized_data[i], include_height ? denormalized_data[i + 1] : 0, include_height ? denormalized_data[i + 2] : denormalized_data[i + 1]);
        point.position = p_character_transform.xform(point.position);

        if (include_facing) {
            const float local_facing_angle = denormalized_data[i + include_height ? 3 : 2];
            point.facing_angle = 0.0; // TODO
        }

        Dictionary data;
        data.get_or_add("position", point.position);
        data.get_or_add("facing", point.facing_angle);

        result.push_back(data);
    }
    return result;
}

void MMTrajectoryFeature::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_trajectory_points", "character_transform", "trajectory_data"), &MMTrajectoryFeature::get_trajectory_points);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, past_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, past_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, future_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, future_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::BOOL, include_height);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::BOOL, include_facing);
}

uint32_t MMTrajectoryFeature::_get_point_dimension_count() const {
    size_t dimensions = 2; // x, z
    if (include_height) {
        dimensions++; // y
    }
    if (include_facing) {
        dimensions++; // facing
    }
    return dimensions;
}
