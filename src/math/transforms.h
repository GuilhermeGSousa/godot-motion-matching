#pragma once

#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

float global_to_local_facing_angle(float local_facing_angle, const Transform3D& transform) {

    const Vector3 global_dir(UtilityFunctions::cos(local_facing_angle), 0.f, UtilityFunctions::sin(local_facing_angle));

    const Vector3 local_dir = transform.get_basis().get_quaternion().xform(global_dir);

    return UtilityFunctions::atan2(local_dir.z, local_dir.x);
}