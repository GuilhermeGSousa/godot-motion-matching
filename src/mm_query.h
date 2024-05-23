#pragma once

#include <godot_cpp/variant/string.hpp>

using namespace godot;

struct MMQueryInput {
    // Add data required for the query here
};

struct MMQueryResult {
    String animation_match;
    float time_match;
    float cost;
};
