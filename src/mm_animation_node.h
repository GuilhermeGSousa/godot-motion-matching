/**************************************************************************/
/*  mm_animation_node.h                                                   */
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

#ifndef MM_ANIMATION_NODE_H
#define MM_ANIMATION_NODE_H

#include "scene/animation/animation_blend_tree.h"
#include "scene/animation/animation_tree.h"

#include "common.h"
#include "mm_animation_library.h"

class MMAnimationNode : public AnimationRootNode {
    GDCLASS(MMAnimationNode, AnimationRootNode);

public:
    MMAnimationNode();
    virtual ~MMAnimationNode() = default;

    GETSET(StringName, library);
    GETSET(float, query_frequency, 2.0f)

    virtual AnimationNode::NodeTimeInfo _process(const AnimationMixer::PlaybackInfo p_playback_info, bool p_test_only = false) override;
    virtual void get_parameter_list(List<PropertyInfo>* r_list) const override;
    virtual Variant get_parameter_default_value(const StringName& p_parameter) const override;
    virtual bool is_parameter_read_only(const StringName& p_parameter) const override;
    virtual String get_caption() const override;
    virtual bool has_filter() const override;

    static StringName MOTION_MATCHING_INPUT_PARAM;

protected:
    void _validate_property(PropertyInfo& p_property) const;

    static void _bind_methods();

private:
    struct AnimationInfo {
        StringName name;
        double length;
        AnimationMixer::PlaybackInfo playback_info;
    };

    AnimationInfo _current_animation_info;

    void _start_transition(const StringName p_animation, float p_time);
    AnimationNode::NodeTimeInfo _update_current_animation(bool p_test_only);

    MMQueryOutput _last_query_output;
    float _time_since_last_query{0.f};
};

#endif // MM_ANIMATION_NODE_H
