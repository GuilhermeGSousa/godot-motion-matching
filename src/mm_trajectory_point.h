#pragma once

#include <godot_cpp/classes/ref_counted.hpp>

#include "common.h"

using namespace godot;

struct MMTrajectoryPoint {
    Vector3 position;
    Vector3 velocity;
    float facing_angle;
};