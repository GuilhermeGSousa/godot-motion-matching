#include "mm_trajectory_feature.h"

#include "mm_root_velocity_feature.h"

MMTrajectoryFeature::MMTrajectoryFeature() {
}

MMTrajectoryFeature::~MMTrajectoryFeature() {
}

size_t MMTrajectoryFeature::get_dimension_count() const {
    // Two velocity dimensions plus facing
    return (include_height ? 4 : 3) * (past_frames + future_frames);
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

    auto add_frame = [this, &result, &p_animation](float time) {
        if (_root_position_track != -1) {
            const Vector3 future_pos = p_animation->position_track_interpolate(_root_position_track, time);
            result.append(future_pos.x);
            if (include_height) {
                result.append(future_pos.y);
            }
            result.append(future_pos.z);
        } else {
            result.append(0.0f);
            if (include_height) {
                result.append(0.0f);
            }
            result.append(0.0f);
        }

        if (_root_rotation_track != -1) {
            const Quaternion future_rotation = p_animation->rotation_track_interpolate(_root_rotation_track, time);
            // result.append(future_rotation.get_euler().y);
            result.append(0.0f);
        } else {
            result.append(0.0f);
        }
    };

    for (size_t i = 0; i < future_frames; i++) {
        const float future_time =
            UtilityFunctions::clampf(time + future_delta_time * i, 0.0f, p_animation->get_length());

        add_frame(future_time);
    }

    for (size_t i = 0; i < past_frames; i++) {
        const float past_time =
            UtilityFunctions::clampf(time - past_delta_time * (i + 1), 0.0f, p_animation->get_length());

        add_frame(past_time);
    }

    return result;
}

PackedFloat32Array MMTrajectoryFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    const std::vector<MMTrajectoryPoint>& trajectory = p_query_input.trajectory;
    const Transform3D& character_transform = p_query_input.character_transform;

    // Get the trajectory points in local space
    PackedFloat32Array result;
    auto add_point = [this, &trajectory, &character_transform, &result](int index) {
        const Vector3 local_position = character_transform.xform_inv(trajectory[index].position);
        result.append(local_position.x);
        if (include_height) {
            result.append(local_position.y);
        }
        result.append(local_position.z);
        result.append(0.0f); // TODO: Add rotation
    };

    for (int i = 0; i < future_frames; i++) {
        add_point(i);
    }
    return result;
}

void MMTrajectoryFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, past_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, past_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, future_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, future_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::BOOL, include_height);
}
