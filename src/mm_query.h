#pragma once

#include "scene/3d/skeleton_3d.h"

#include "mm_bone_state.h"
#include "mm_trajectory_point.h"

struct MMQueryInput {
    // Add data required for the query here
    Vector3 controller_velocity;
    Transform3D controller_transform;
    Transform3D character_transform;
    std::vector<MMTrajectoryPoint> trajectory;
    std::vector<MMTrajectoryPoint> trajectory_history;
    SkeletonState skeleton_state;
};

struct MMQueryOutput {
    String animation_match;
    float time_match;
    float cost;
    PackedFloat32Array matched_frame_data;
    Dictionary feature_costs;
};
