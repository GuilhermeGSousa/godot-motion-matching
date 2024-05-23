#include "mm_root_velocity_feature.h"

#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

MMRootVelocityFeature::MMRootVelocityFeature() {
}

MMRootVelocityFeature::~MMRootVelocityFeature() {
}

size_t MMRootVelocityFeature::get_dimension_count() const {
    return 3;
}

void MMRootVelocityFeature::setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {

    const StringName skel_path = p_player->get_root_motion_track().get_concatenated_names();
    const StringName root_bone_name = p_player->get_root_motion_track().get_concatenated_subnames();
    _root_bone = p_skeleton->find_bone(root_bone_name);
    _rest_pose = p_skeleton->get_bone_rest(_root_bone);

    _root_bone_path = UtilityFunctions::str(skel_path) + ":" + UtilityFunctions::str(root_bone_name);
}

void MMRootVelocityFeature::setup_for_animation(Ref<Animation> animation) {
    _root_postion_track = animation->find_track(_root_bone_path, Animation::TrackType::TYPE_POSITION_3D);
    _root_rotation_track = animation->find_track(_root_bone_path, Animation::TrackType::TYPE_ROTATION_3D);
}

PackedFloat32Array MMRootVelocityFeature::bake_animation_pose(Ref<Animation> p_animation, float p_time) const {
    PackedFloat32Array pose;

    Vector3 pos, prev_pos;
    if (_root_postion_track != -1) {
        prev_pos = p_animation->position_track_interpolate(_root_postion_track, p_time);
        pos = p_animation->position_track_interpolate(_root_postion_track, p_time + delta_time);
    } else {
        pos = _rest_pose.get_origin();
        prev_pos = _rest_pose.get_origin();
    }

    Quaternion rotation;
    if (_root_postion_track != -1) {
        rotation = p_animation->rotation_track_interpolate(_root_rotation_track, p_time);
    } else {
        rotation = _rest_pose.get_basis().get_rotation_quaternion();
    }

    const Vector3 velocity = rotation.xform_inv(pos - prev_pos) / delta_time;
    pose.append(velocity.x);
    pose.append(velocity.y);
    pose.append(velocity.z);
    return pose;
}

PackedFloat32Array MMRootVelocityFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    PackedFloat32Array pose;
    pose.resize(get_dimension_count());
    pose.set(0, 0.0);
    pose.set(1, 0.0);
    pose.set(2, 0.0);
    return pose;
}

void MMRootVelocityFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMRootVelocityFeature, Variant::FLOAT, delta_time);
}
