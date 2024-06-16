#include "mm_trajectory_point.h"

MMTrajectoryPointRC::MMTrajectoryPointRC() {
}

MMTrajectoryPointRC::~MMTrajectoryPointRC() {
}

void MMTrajectoryPointRC::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_position"), &MMTrajectoryPointRC::get_position);
    ClassDB::bind_method(D_METHOD("get_facing_angle"), &MMTrajectoryPointRC::get_facing_angle);
}
