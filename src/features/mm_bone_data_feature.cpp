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

#include "core/error/error_macros.h"
#include "mm_bone_data_feature.h"
#include "mm_bone_state.h"

#include "core/math/vector3.h"
#include "core/math/basis.h"
#include "scene/resources/animation.h"

void MMBoneDataFeature::setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) {
    _skeleton_path = p_player->get_root_motion_track().get_concatenated_names();
}

void MMBoneDataFeature::setup_for_animation(Ref<Animation> p_animation) {
    for (Animation::Track * track :p_animation->get_tracks()) {
        if (!String(track->path).begins_with(_skeleton_path)) {
            continue;
        }
        String bone_name = String(track->path).split(":")[1];
        if (!bone_names.has(bone_name)) {
            bone_names.append(bone_name);
        }
    }
}

int64_t MMBoneDataFeature::get_dimension_count() const {
    return bone_names.size() * 18;
}

// All positions/velocities must be relative to the root bone's frame of reference (this part is very important).
PackedFloat32Array MMBoneDataFeature::bake_animation_pose(Ref<Animation> p_animation, double time) const {
    PackedFloat32Array result;
    ERR_FAIL_COND_V(p_animation.is_null(), result);

    for (int64_t i = 0; i < bone_names.size(); ++i) {
        const String bone_path = String(_skeleton_path) + String(":") + bone_names[i];

        const int32_t pos_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
        const int32_t rot_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);
        const int32_t scale_track = p_animation->find_track(bone_path, Animation::TrackType::TYPE_SCALE_3D);

        if (pos_track != -1) {
            const Vector3 position = p_animation->position_track_interpolate(pos_track, time);
            result.append(position.x);
            result.append(position.y);
            result.append(position.z);
        } else {
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
        }

        if (scale_track != -1) {
            const Vector3 scale = p_animation->scale_track_interpolate(scale_track, time);
            result.append(scale.x);
            result.append(scale.y);
            result.append(scale.z);
        } else {
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
        }

        // Make a 6 float feature by truncating Basis matrix.
        // See scientific literature for why this is a benefit.
        if (rot_track != -1) {
            const Basis rotation = Basis(p_animation->rotation_track_interpolate(rot_track, time)).orthonormalized();
            const Vector3 axis_x = rotation.get_column(Vector3::AXIS_X);
            result.append(axis_x.x);
            result.append(axis_x.y);
            result.append(axis_x.z);
            const Vector3 axis_y = rotation.get_column(Vector3::AXIS_Y);
            result.append(axis_y.x);
            result.append(axis_y.y);
            result.append(axis_y.z);
        } else {
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
        }

        double delta_time = 1.0 / 60.0;
        if (pos_track != -1) {
            const Vector3 position = p_animation->position_track_interpolate(pos_track, time);
            Vector3 prev_position = p_animation->position_track_interpolate(pos_track, time - delta_time);
            Vector3 velocity = (position - prev_position) / delta_time;
            result.append(velocity.x);
            result.append(velocity.y);
            result.append(velocity.z);
        } else {
            result.append(0.0f);
            result.append(0.0f);
            result.append(0.0f);
        }
        if (rot_track != -1) {
            const Basis rotation = Basis(p_animation->rotation_track_interpolate(rot_track, time)).orthonormalized();
            Basis prev_rotation = Basis(p_animation->rotation_track_interpolate(rot_track, time - delta_time)).orthonormalized();
            Quaternion delta_rot = prev_rotation.inverse() * rotation;
            Vector3 angular_velocity_axis;
            real_t angular_velocity_magnitude;

            delta_rot.get_axis_angle(angular_velocity_axis, angular_velocity_magnitude);
            angular_velocity_magnitude /= delta_time;

            Vector3 angular_velocity = angular_velocity_axis * angular_velocity_magnitude;
            result.append(angular_velocity.x);
            result.append(angular_velocity.y);
            result.append(angular_velocity.z);
        } else {
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
        const Vector3& position = p_query_input.skeleton_state.find_bone_state(bone_names[i]).pos;
        result.append(position.x);
        result.append(position.y);
        result.append(position.z);

        const Vector3& scale = p_query_input.skeleton_state.find_bone_state(bone_names[i]).scl;
        result.append(scale.x);
        result.append(scale.y);
        result.append(scale.z);

        // Only 6 dimensions is needed to recover a rotation for a 3x3 basis matrix.
        const Basis& rotation = p_query_input.skeleton_state.find_bone_state(bone_names[i]).rot;
        const Vector3 axis_x = rotation.get_column(Vector3::AXIS_X);
        result.append(axis_x.x);
        result.append(axis_x.y);
        result.append(axis_x.z);

        const Vector3 axis_y = rotation.get_column(Vector3::AXIS_Y);
        result.append(axis_y.x);
        result.append(axis_y.y);
        result.append(axis_y.z);

        Vector3 velocity  = p_query_input.skeleton_state.find_bone_state(bone_names[i]).vel;
        result.append(velocity.x);
        result.append(velocity.y);
        result.append(velocity.z);

        Vector3 scale_velocity = p_query_input.skeleton_state.find_bone_state(bone_names[i]).scl_vel;
        result.append(scale_velocity.x);
        result.append(scale_velocity.y);
        result.append(scale_velocity.z);

        Vector3 angular_velocity = p_query_input.skeleton_state.find_bone_state(bone_names[i]).ang_vel;
        result.append(angular_velocity.x);
        result.append(angular_velocity.y);
        result.append(angular_velocity.z);
    }
    return result;
}

void MMBoneDataFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMBoneDataFeature, Variant::PACKED_STRING_ARRAY, bone_names);
}
