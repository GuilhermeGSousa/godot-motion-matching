/**************************************************************************/
/*  mm_bone_data_feature.cpp                                              */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "features/mm_bone_data_feature.h"

#include "mm_bone_data_feature.h"
#include "mm_bone_state.h"

void MMBoneDataFeature::setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) {
    _skeleton_path = p_player->get_root_motion_track().get_concatenated_names();
}

void MMBoneDataFeature::setup_for_animation(Ref<Animation> animation) {
}

int64_t MMBoneDataFeature::get_dimension_count() const {
    return bone_names.size() * 7;
}

PackedFloat32Array MMBoneDataFeature::bake_animation_pose(Ref<Animation> p_animation, double time) const {
    PackedFloat32Array result;
    for (int64_t i = 0; i < bone_names.size(); ++i) {
        const String bone_path = String(_skeleton_path) + String(":") + bone_names[i];

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
    for (int64_t i = 0; i < bone_names.size(); ++i) {

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
