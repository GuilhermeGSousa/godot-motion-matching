#pragma once

#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include <map>
#include <vector>

using namespace godot;

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

    std::vector<BoneState> bone_states;
    Dictionary bone_name_to_index; // Give me a real unordered_map please :(
};
