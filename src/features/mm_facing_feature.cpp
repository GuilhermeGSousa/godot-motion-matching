#include "features/mm_facing_feature.h"
#include "mm_facing_feature.h"

#include <godot_cpp/variant/transform3d.hpp>

size_t MMFacingFeature::get_dimension_count() const {
    return 1;
}

void MMFacingFeature::setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {
    const StringName skel_path = p_player->get_root_motion_track().get_concatenated_names();
    const StringName root_bone_name = p_player->get_root_motion_track().get_concatenated_subnames();
    _root_bone = p_skeleton->find_bone(root_bone_name);

    _root_bone_path = UtilityFunctions::str(skel_path) + ":" + UtilityFunctions::str(root_bone_name);
}

void MMFacingFeature::setup_for_animation(Ref<Animation> animation) {
    _root_rotation_track = animation->find_track(_root_bone_path, Animation::TrackType::TYPE_ROTATION_3D);
}

PackedFloat32Array MMFacingFeature::bake_animation_pose(Ref<Animation> p_animation, float p_time) const {
    PackedFloat32Array result;

    const Quaternion rotation = p_animation->rotation_track_interpolate(_root_rotation_track, p_time);
    const float angle = rotation.get_euler().y;
    result.append(angle);
    return result;
}

PackedFloat32Array MMFacingFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    PackedFloat32Array result;

    const Transform3D& controller_transform = p_query_input.controller_transform;
    Vector3 motion_direction = p_query_input.controller_velocity;

    if (motion_direction.length() < 0.01f) {
        result.append(0.f);
        return result;
    }

    motion_direction.y = 0;
    motion_direction.normalize();

    Vector3 forward_vector = controller_transform.basis.xform(Vector3(0, 0, 1));
    forward_vector.y = 0;

    float angle = motion_direction.signed_angle_to(forward_vector, Vector3(0, 1, 0));

    result.append(angle);
    return result;
    return PackedFloat32Array();
}

void MMFacingFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMFacingFeature, Variant::FLOAT, weight);
}
