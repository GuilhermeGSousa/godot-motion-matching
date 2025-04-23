#include "features/mm_bone_data_feature.h"

#include "mm_bone_data_feature.h"
#include "mm_bone_state.h"

#include <godot_cpp/classes/editor_node3d_gizmo_plugin.hpp>
#include <godot_cpp/classes/point_mesh.hpp>
#include <godot_cpp/classes/sphere_mesh.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <numeric>

void MMBoneDataFeature::setup_skeleton(const MMCharacter* p_character, const AnimationMixer* p_player, const Skeleton3D* p_skeleton) {
    _skeleton = p_skeleton;
    _skeleton_path = p_player->get_root_motion_track().get_concatenated_names();
    const StringName root_bone_name = p_player->get_root_motion_track().get_concatenated_subnames();
    _root_bone_index = p_skeleton->find_bone(root_bone_name);
}

void MMBoneDataFeature::setup_for_animation(Ref<Animation> animation) {
}

int64_t MMBoneDataFeature::get_dimension_count() const {
    return bone_names.size() * 3;
}

PackedFloat32Array MMBoneDataFeature::bake_animation_pose(Ref<Animation> p_animation, double time) const {
    PackedFloat32Array result;

    for (int64_t i = 0; i < bone_names.size(); ++i) {
        BoneState bone_state = _sample_bone_state(p_animation, time, bone_names[i]);

        result.append(bone_state.pos.x);
        result.append(bone_state.pos.y);
        result.append(bone_state.pos.z);
    }
    return result;
}

PackedFloat32Array MMBoneDataFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    PackedFloat32Array result;
    for (int64_t i = 0; i < bone_names.size(); ++i) {
        const BoneState& bone_state = p_query_input.skeleton_state.find_bone_state(bone_names[i]);
        const Vector3& pos = bone_state.pos;
        const Quaternion& rot = bone_state.rot;

        result.append(pos.x);
        result.append(pos.y);
        result.append(pos.z);
    }
    return result;
}

void MMBoneDataFeature::display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const {
    Ref<StandardMaterial3D> material = p_gizmo->get_plugin()->get_material("bone_material", p_gizmo);
    if (material.is_null()) {
        p_gizmo->get_plugin()->create_material("bone_material", Color(0, 0, 1, 1));
        material = p_gizmo->get_plugin()->get_material("bone_material", p_gizmo);
    }

    float* dernomalized_data = new float[get_dimension_count()];
    memcpy(dernomalized_data, p_data, sizeof(float) * get_dimension_count());
    denormalize(dernomalized_data);

    for (int64_t i = 0; i < get_dimension_count(); i += 7) {
        Ref<SphereMesh> sphere_mesh;
        sphere_mesh.instantiate();
        sphere_mesh->set_radius(0.05);
        sphere_mesh->set_height(0.05);
        sphere_mesh->set_material(material);

        const Vector3 pos = Vector3(dernomalized_data[i], dernomalized_data[i + 1], dernomalized_data[i + 2]);

        Transform3D point_transform = Transform3D();
        point_transform.origin = pos;
        p_gizmo->add_mesh(sphere_mesh, material, point_transform, nullptr);
    }

    delete[] dernomalized_data;
}

void MMBoneDataFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMBoneDataFeature, Variant::PACKED_STRING_ARRAY, bone_names);
}

BoneState MMBoneDataFeature::_sample_bone_state(Ref<Animation> p_animation, double p_time, const String& p_bone_path) const {

    std::vector<Transform3D> bone_transforms;
    int32_t current_bone_index = _skeleton->find_bone(p_bone_path);
    String current_bone;
    const int32_t root_bone_index = _root_bone_index;
    while (current_bone_index != root_bone_index && current_bone_index != -1) {
        current_bone = _skeleton->get_bone_name(current_bone_index);
        const String bone_path = String(_skeleton_path) + String(":") + current_bone;

        Transform3D bone_transform = _skeleton->get_bone_rest(current_bone_index);
        int32_t pos_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
        int32_t rot_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);
        int32_t scl_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_SCALE_3D);

        if (pos_track != -1) {
            bone_transform.origin = p_animation->position_track_interpolate(pos_track, p_time);
        }

        if (rot_track != -1) {
            bone_transform.basis.set_quaternion(p_animation->rotation_track_interpolate(rot_track, p_time));
        }

        if (scl_track != -1) {
            bone_transform.basis.scale(p_animation->scale_track_interpolate(scl_track, p_time));
        }

        bone_transforms.emplace_back(bone_transform);
        current_bone_index = _skeleton->get_bone_parent(current_bone_index);
    }

    Transform3D global_transform = _skeleton->get_bone_global_rest(root_bone_index);
    global_transform = std::reduce(
        bone_transforms.rbegin(),
        bone_transforms.rend(),
        global_transform,
        [](const Transform3D& acc, const Transform3D& bone_transform) {
            return acc * bone_transform;
        });

    BoneState bone_state;
    bone_state.pos = global_transform.origin;
    bone_state.rot = global_transform.basis.get_quaternion();
    bone_state.scl = global_transform.basis.get_scale();
    return bone_state;
}
