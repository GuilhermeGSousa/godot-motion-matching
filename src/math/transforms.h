#pragma once

#include "core/math/transform_3d.h"

float global_to_local_facing_angle(float local_facing_angle, const Transform3D& transform) {

    const Vector3 global_dir(cos(local_facing_angle), 0.f, sin(local_facing_angle));

    const Vector3 local_dir = transform.get_basis().get_quaternion().xform(global_dir);

    return atan2(local_dir.z, local_dir.x);
}