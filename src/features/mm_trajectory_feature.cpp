#include "mm_trajectory_feature.h"

#include "mm_root_velocity_feature.h"

MMTrajectoryFeature::MMTrajectoryFeature() {
}

MMTrajectoryFeature::~MMTrajectoryFeature() {
}

size_t MMTrajectoryFeature::get_dimension_count() const {
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
        const float future_time =
            UtilityFunctions::clampf(time + future_delta_time * i, 0.0f, p_animation->get_length());

        add_frame(future_time);
    }

    for (size_t i = 1; i < past_frames + 1; i++) {
        const float past_time =
            UtilityFunctions::clampf(time - past_delta_time * i + 1, 0.0f, p_animation->get_length());

        add_frame(past_time);
    }

    return result;
}

PackedFloat32Array MMTrajectoryFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    const Transform3D& character_transform = p_query_input.character_transform;

    // Get the trajectory points in local space
    PackedFloat32Array result;
    auto add_point = [this, &character_transform, &result](int index, const MMTrajectoryPoint& trajectory_point) {
        const Vector3 local_position =
            character_transform.basis.xform_inv(trajectory_point.position - character_transform.origin);

        result.append(local_position.x);
        if (include_height) {
            result.append(local_position.y);
        }
        result.append(local_position.z);
        if (include_facing) {
            const float facing = trajectory_point.facing_angle;
            result.append(facing);
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

TypedArray<Vector3> MMTrajectoryFeature::get_trajectory_points(const PackedFloat32Array& p_trajectory_data) const {
    PackedFloat32Array denormalized_data = PackedFloat32Array(p_trajectory_data);
    denormalize(denormalized_data);

    TypedArray<Vector3> result;
    const int offset = _get_point_dimension_count();
    for (int i = 0; i < future_frames * offset; i += offset) {

        const Vector3 point(denormalized_data[i], include_height ? denormalized_data[i + 1] : 0,
                            include_height ? denormalized_data[i + 2] : denormalized_data[i + 1]);
        result.push_back(point);
    }
    return result;
}

void MMTrajectoryFeature::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_trajectory_points", "p_trajectory_data"),
                         &MMTrajectoryFeature::get_trajectory_points);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, past_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, past_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, future_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, future_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::BOOL, include_height);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::BOOL, include_facing);
}

size_t MMTrajectoryFeature::_get_point_dimension_count() const {
    size_t dimensions = 2; // x, z
    if (include_height) {
        dimensions++; // y
    }
    if (include_facing) {
        dimensions++; // facing
    }
    return dimensions;
}
