#pragma once

#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <vector>

using namespace godot;

struct BoneState {

    void reset() {
        pos = Vector3();
        rot = Quaternion();
        scl = Vector3(1.0, 1.0, 1.0);
        vel = Vector3();
        ang_vel = Vector3();
        sck_vel = Vector3();
    }

    Vector3 pos;
    Quaternion rot;
    Vector3 scl;
    Vector3 vel;
    Vector3 ang_vel;
    Vector3 sck_vel;
};

struct SkeletonState {

    SkeletonState() = default;
    ~SkeletonState() = default;
    SkeletonState(size_t size) : bone_states(size) {
    }

    const BoneState& operator[](int32_t idx) const {
        return bone_states[idx];
    }

    BoneState& operator[](int32_t idx) {
        return bone_states[idx];
    }

    std::vector<BoneState> bone_states;
};
