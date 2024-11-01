/**************************************************************************/
/*  mm_animation_node.cpp                                                 */
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

#include "mm_animation_node.h"

#include "mm_query.h"

StringName MMAnimationNode::MOTION_MATCHING_INPUT_PARAM = "motion_matching_input";

AnimationNode::NodeTimeInfo MMAnimationNode::_process(const AnimationMixer::PlaybackInfo p_playback_info, bool p_test_only) {
    NodeTimeInfo result;

    if (Engine::get_singleton()->is_editor_hint()) {
        return result;
    }

    if (animation_library.is_null()) {
        return result;
    }

    MMQueryInput* query_input = Object::cast_to<MMQueryInput>(get_parameter(MOTION_MATCHING_INPUT_PARAM));

    if (!query_input || !query_input->is_valid()) {
        return result;
    }

    // Run query
    animation_library->query(*query_input);

    // const bool has_current_animation = get_animation_tree()->get_animation_player()->get_current_animation().is_empty();
    // const bool is_same_animation = has_current_animation && result.animation_match == _last_query_output.animation_match;
    // Play selected animation

    return result;
}

void MMAnimationNode::get_parameter_list(List<PropertyInfo>* r_list) const {
    AnimationNode::get_parameter_list(r_list);
    r_list->push_back(PropertyInfo(Variant::Type::OBJECT, MOTION_MATCHING_INPUT_PARAM));
}

Variant MMAnimationNode::get_parameter_default_value(const StringName& p_parameter) const {
    Variant ret = AnimationNode::get_parameter_default_value(p_parameter);
    if (ret != Variant()) {
        return ret;
    }

    if (p_parameter == MOTION_MATCHING_INPUT_PARAM) {
        Ref<MMQueryInput> p;
        p.instantiate();
        return p;
    }

    return Variant();
}

bool MMAnimationNode::is_parameter_read_only(const StringName& p_parameter) const {
    if (AnimationRootNode::is_parameter_read_only(p_parameter)) {
        return true;
    }

    if (p_parameter == MOTION_MATCHING_INPUT_PARAM) {
        return false;
    }

    return false;
}

String MMAnimationNode::get_caption() const {
    return "Motion Matching";
}

void MMAnimationNode::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::OBJECT, animation_library, PROPERTY_HINT_RESOURCE_TYPE, "MMAnimationLibrary");
}
