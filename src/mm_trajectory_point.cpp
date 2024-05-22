#include "mm_trajectory_point.h"

#include <godot_cpp/core/class_db.hpp>

MMTrajectoryPoint::MMTrajectoryPoint() : RefCounted() {
}

MMTrajectoryPoint::~MMTrajectoryPoint() {
}

void MMTrajectoryPoint::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMTrajectoryPoint, Variant::VECTOR3, position);
    BINDER_PROPERTY_PARAMS(MMTrajectoryPoint, Variant::VECTOR3, velocity);
}
