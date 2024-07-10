#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include "common.h"

using namespace godot;

struct MMTrajectoryPoint {
    Vector3 position;
    Vector3 velocity;
    float facing_angle;
};