/**************************************************************************/
/*  mm_trajectory_feature.h                                               */
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

#ifndef MM_TRAJECTORY_FEATURE_H
#define MM_TRAJECTORY_FEATURE_H

#include "common.h"
#include "features/mm_feature.h"
#include <cstdint>

class MMTrajectoryFeature : public MMFeature {
    GDCLASS(MMTrajectoryFeature, MMFeature)

public:
    MMTrajectoryFeature(/* args */);
    virtual ~MMTrajectoryFeature();

    virtual int64_t get_dimension_count() const override;

    virtual void setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, double time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const override;

#ifdef TOOLS_ENABLED
    virtual void display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const override;
#endif

    TypedArray<Dictionary> get_trajectory_points(const Transform3D& p_character_transform, const PackedFloat32Array& p_trajectory_data) const;

    GETSET(double, past_delta_time, 0.1);
    GETSET(int64_t, past_frames, 1);
    GETSET(double, future_delta_time, 0.1);
    GETSET(int64_t, future_frames, 5);
    GETSET(bool, include_height, false);
    GETSET(bool, include_facing, true);

protected:
    static void _bind_methods();

private:
    uint32_t _get_point_dimension_count() const;

    int _root_bone{-1};
    NodePath _root_bone_path;
    int _root_position_track{-1};
    int _root_rotation_track{-1};
};

#endif // MM_TRAJECTORY_FEATURE_H
