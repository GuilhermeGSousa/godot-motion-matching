/**************************************************************************/
/*  mm_bone_state.h                                                       */
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

#ifndef MM_BONE_STATE_H
#define MM_BONE_STATE_H

#include "scene/3d/skeleton_3d.h"

#include <vector>

struct BoneState {

    void reset() {
        pos = Vector3();
        rot = Quaternion();
        scl = Vector3(1.0, 1.0, 1.0);
        vel = Vector3();
        ang_vel = Vector3();
        scl_vel = Vector3();
    }

    Vector3 pos;
    Quaternion rot;
    Vector3 scl;
    Vector3 vel;
    Vector3 ang_vel;
    Vector3 scl_vel;
};

struct SkeletonState {

    SkeletonState() = default;
    ~SkeletonState() = default;
    SkeletonState(size_t size)
        : bone_states(size) {
    }
    SkeletonState(const Skeleton3D* skeleton) {
        const int32_t bone_count = skeleton->get_bone_count();
        bone_states = std::vector<BoneState>(bone_count);
        for (int b = 0; b < bone_count; ++b) {
            bone_name_to_index[skeleton->get_bone_name(b)] = b;
        }
    }

    const BoneState& operator[](int32_t idx) const {
        return bone_states[idx];
    }

    BoneState& operator[](int32_t idx) {
        return bone_states[idx];
    }

    const BoneState& find_bone_state(const String& name) const {
        return bone_states[(uint32_t)bone_name_to_index.find_key(name)];
    }

    BoneState& find_bone_state(const String& name) {
        return bone_states[(uint32_t)bone_name_to_index.find_key(name)];
    }

    void reset_velocities() {
        for (BoneState& state : bone_states) {
            state.vel = Vector3();
            state.ang_vel = Vector3();
            state.scl_vel = Vector3();
        }
    }

    std::vector<BoneState> bone_states;
    Dictionary bone_name_to_index; // Give me a real unordered_map please :(
};

#endif // MM_BONE_STATE_H
