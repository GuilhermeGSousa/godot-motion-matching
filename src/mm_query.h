/**************************************************************************/
/*  mm_query.h                                                            */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef MM_QUERY_H
#define MM_QUERY_H

#include "core/object/ref_counted.h"
#include "scene/3d/skeleton_3d.h"

#include "mm_bone_state.h"
#include "mm_trajectory_point.h"

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

    bool is_valid() const {
        // Add validation logic here
        return !trajectory.empty();
    }

protected:
    static void _bind_methods() {
    }
};

struct MMQueryOutput {
    String animation_match;
    float time_match;
    float cost;
    PackedFloat32Array matched_frame_data;
    Dictionary feature_costs;
};

#endif // MM_QUERY_H
