#pragma once

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/vector3.hpp>


using namespace godot;

struct MMQueryInput {
    // Add data required for the query here
    Vector3 controller_velocity;
    Transform3D controller_transform;
};

struct MMQueryResult {
    String animation_match;
    float time_match;
    float cost;
};
