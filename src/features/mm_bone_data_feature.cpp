#include "features/mm_bone_data_feature.h"

#include "mm_animation_player.h"
#include "mm_bone_data_feature.h"
#include "mm_bone_state.h"

void MMBoneDataFeature::setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {
    _skeleton_path = p_player->get_root_motion_track().get_concatenated_names();
}

void MMBoneDataFeature::setup_for_animation(Ref<Animation> animation) {
}

uint32_t MMBoneDataFeature::get_dimension_count() const {
    return bone_names.size() * 7;
}

PackedFloat32Array MMBoneDataFeature::bake_animation_pose(Ref<Animation> p_animation, float time) const {
    PackedFloat32Array result;
    for (size_t i = 0; i < bone_names.size(); ++i) {
        const String bone_path = UtilityFunctions::str(_skeleton_path) + UtilityFunctions::str(":") + bone_names[i];

        const int32_t pos_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
        const int32_t rot_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);

        if (pos_track != -1) {
            const Vector3 pos = p_animation->position_track_interpolate(pos_track, time);
            result.append(pos.x);
            result.append(pos.y);
            result.append(pos.z);
        } else {
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
        }

        if (rot_track != -1) {
            const Quaternion rot = p_animation->rotation_track_interpolate(rot_track, time);
            result.append(rot.x);
            result.append(rot.y);
            result.append(rot.z);
            result.append(rot.w);
        } else {
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
        }
    }
    return result;
}

PackedFloat32Array MMBoneDataFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    PackedFloat32Array result;
    for (size_t i = 0; i < bone_names.size(); ++i) {

        const Vector3& pos = p_query_input.skeleton_state.find_bone_state(bone_names[i]).pos;
        const Quaternion& rot = p_query_input.skeleton_state.find_bone_state(bone_names[i]).rot;

        result.append(pos.x);
        result.append(pos.y);
        result.append(pos.z);
        result.append(rot.x);
        result.append(rot.y);
        result.append(rot.z);
        result.append(rot.w);
    }
    return result;
}

void MMBoneDataFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMBoneDataFeature, Variant::PACKED_STRING_ARRAY, bone_names);
}
