#pragma once

#include <godot_cpp/core/type_info.hpp>

using namespace godot;

int64_t hash_combine(int64_t a, int64_t b) {
    return a ^ (b + 0x9e3779b9 + (a << 6) + (a >> 2));
}