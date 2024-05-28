#pragma once

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include "mm_trajectory_point.h"

using namespace godot;

struct MMQueryInput {
    // Add data required for the query here
    Vector3 controller_velocity;
    Transform3D controller_transform;
    Transform3D character_transform;
    std::vector<MMTrajectoryPoint> trajectory;
};

struct MMQueryOutput {
    String animation_match;
    float time_match;
    float cost;
    PackedFloat32Array matched_frame_data;
};
