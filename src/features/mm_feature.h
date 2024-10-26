/**************************************************************************/
/*  mm_feature.h                                                          */
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

#ifndef MM_FEATURE_H
#define MM_FEATURE_H

#include "core/io/resource.h"
#include "scene/3d/skeleton_3d.h"
#include "scene/animation/animation_player.h"
#include "scene/resources/animation.h"

#ifdef TOOLS_ENABLED
#include "editor/plugins/node_3d_editor_gizmos.h"
#endif

#include "common.h"
#include "mm_query.h"

class MMFeature : public Resource {
    GDCLASS(MMFeature, Resource)

public:
    enum NormalizationMode { Raw,
                             Standard,
                             MinMax };

public:
    MMFeature(/* args */);
    virtual ~MMFeature();
    virtual void setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) {};

    virtual void setup_for_animation(Ref<Animation> animation) {};

    virtual int64_t get_dimension_count() const = 0;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, double time) const = 0;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const = 0;

#ifdef TOOLS_ENABLED
    virtual void display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const {};
#endif

    void normalize(float* p_data) const;
    void denormalize(float* p_data) const;
    float compute_cost(const float* p_motion_data, const float* p_query_data) const;

    GETSET(NormalizationMode, normalization_mode, Standard);
    GETSET(PackedFloat32Array, means);
    GETSET(PackedFloat32Array, std_devs);
    GETSET(PackedFloat32Array, maxes);
    GETSET(PackedFloat32Array, mins);

protected:
    static void _bind_methods();
    void _normalize_minmax(float* p_data) const;
    void _denormalize_minmax(float* p_data) const;
    void _normalize_standard(float* p_data) const;
    void _denormalize_standard(float* p_data) const;
};

#endif // MM_FEATURE_H
