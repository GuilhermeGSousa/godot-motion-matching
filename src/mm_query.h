#ifndef MM_QUERY_H
#define MM_QUERY_H

#include "mm_bone_state.h"
#include "mm_query.h"
#include "mm_trajectory_point.h"

#include <functional>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

struct MMQueryOutput {
    String animation_match;
    float time_match;
    float cost;
    PackedFloat32Array matched_frame_data;
    Dictionary feature_costs;
};

class MMQueryInput : public RefCounted {
    GDCLASS(MMQueryInput, RefCounted);

public:
    // Add data required for the query here
    Vector3 controller_velocity;
    Transform3D controller_transform;
    Transform3D character_transform;
    std::vector<MMTrajectoryPoint> trajectory;
    std::vector<MMTrajectoryPoint> trajectory_history;
    SkeletonState skeleton_state;
    std::function<void(const MMQueryOutput&)> on_query_result;

    bool is_valid() const {
        // Add validation logic here
        return !trajectory.empty();
    }

protected:
    static void _bind_methods() {
    }
};

#endif // MM_QUERY_H
