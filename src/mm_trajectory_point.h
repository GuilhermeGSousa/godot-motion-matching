#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include "common.h"

using namespace godot;

struct MMCollisionState {
    bool on_floor = false;
    Vector3 floor_normal;
    Vector3 floor_position;
    bool against_wall = false;
    Vector3 wall_normal;

    void reset() {
        on_floor = false;
        against_wall = false;
    }
};

struct MMTrajectoryPoint {
    Vector3 position;
    Vector3 velocity;
    float facing_angle;

    MMCollisionState collision_state;

    Transform3D get_transform(const Vector3& up_axis = Vector3(0, 1, 0)) const {
        Transform3D result;
        result.origin = position;
        result.set_basis(Basis(up_axis, facing_angle));
        return result;
    }
};