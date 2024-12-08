#include "modifiers/damped_skeleton_modifier.h"

#include "damped_skeleton_modifier.h"
#include "math/spring.hpp"

void DampedSkeletonModifier::_process_modification() {
    if (!is_active()) {
        return;
    }

    Skeleton3D* skeleton = get_skeleton();
    if (!skeleton) {
        return;
    }
    const double delta = skeleton->get_modifier_callback_mode_process() == Skeleton3D::ModifierCallbackModeProcess::MODIFIER_CALLBACK_MODE_PROCESS_IDLE ? get_process_delta_time() : get_physics_process_delta_time();
    if (!skeleton->get_bone_count()) {
        return;
    }
    for (int32_t bone_id = 0; bone_id < skeleton->get_bone_count(); ++bone_id) {
        if (skeleton->get_bone_parent(bone_id) == -1) {
            // Skip root bone
            continue;
        }

        const Vector3 desired_pos = skeleton->get_bone_pose_position(bone_id);
        const Quaternion desired_rot = skeleton->get_bone_pose_rotation(bone_id);

        Spring::_simple_spring_damper_exact(
            _skeleton_state[bone_id].pos,
            _skeleton_state[bone_id].vel,
            desired_pos,
            halflife,
            delta);

        Spring::_simple_spring_damper_exact(
            _skeleton_state[bone_id].rot,
            _skeleton_state[bone_id].ang_vel,
            desired_rot,
            halflife,
            delta);

        skeleton->set_bone_pose_position(bone_id, _skeleton_state[bone_id].pos);
        skeleton->set_bone_pose_rotation(bone_id, _skeleton_state[bone_id].rot);
    }
}

void DampedSkeletonModifier::_bind_methods() {
    BINDER_PROPERTY_PARAMS(DampedSkeletonModifier, Variant::FLOAT, halflife);
}
void DampedSkeletonModifier::_notification(int32_t p_what) {
    switch (p_what) {
    case NOTIFICATION_READY:
        Skeleton3D* skeleton = get_skeleton();

        if (skeleton) {
            _skeleton_state = SkeletonState(skeleton);
            for (int b = 0; b < skeleton->get_bone_count(); ++b) {
                BoneState& bone = _skeleton_state[b];
                bone.pos = skeleton->get_bone_pose_position(b);
                bone.rot = skeleton->get_bone_pose_rotation(b);
                bone.scl = skeleton->get_bone_pose_scale(b);
            }
        }
    }
}
