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

// Only play the matched animation if the matched time position
// is QUERY_TIME_ERROR away from the current time
constexpr float QUERY_TIME_ERROR = 0.05;

StringName MMAnimationNode::MOTION_MATCHING_INPUT_PARAM;

MMAnimationNode::MMAnimationNode() {
    MOTION_MATCHING_INPUT_PARAM = "motion_matching_input";
    _anim_node.instantiate();

    _anim_node->connect("tree_changed", callable_mp(this, &MMAnimationNode::_tree_changed), CONNECT_REFERENCE_COUNTED);
    _anim_node->connect("animation_node_renamed", callable_mp(this, &MMAnimationNode::_animation_node_renamed), CONNECT_REFERENCE_COUNTED);
    _anim_node->connect("animation_node_removed", callable_mp(this, &MMAnimationNode::_animation_node_removed), CONNECT_REFERENCE_COUNTED);
}

AnimationNode::NodeTimeInfo MMAnimationNode::_process(const AnimationMixer::PlaybackInfo p_playback_info, bool p_test_only) {
    NodeTimeInfo cur_nti = get_node_time_info();

    if (Engine::get_singleton()->is_editor_hint()) {
        return cur_nti;
    }

    if (animation_library.is_null()) {
        return cur_nti;
    }

    const bool is_about_to_end = false; // TODO: Implement this

    // We run queries periodically, or when the animation is about to end
    const bool has_current_animation = !_last_query_output.animation_match.is_empty();
    const bool should_query = (_time_since_last_query > (1.0 / query_frequency)) || is_about_to_end || !has_current_animation;

    if (!should_query) {
        _time_since_last_query += p_playback_info.delta;
        return play_current_animation(p_playback_info, cur_nti, p_test_only);
    }

    MMQueryInput* query_input = Object::cast_to<MMQueryInput>(get_parameter(MOTION_MATCHING_INPUT_PARAM));

    if (!query_input || !query_input->is_valid()) {
        _time_since_last_query += p_playback_info.delta;
        return play_current_animation(p_playback_info, cur_nti, p_test_only);
    }

    _time_since_last_query = 0.f;

    // Run query
    const MMQueryOutput query_output = animation_library->query(*query_input);

    // const bool has_current_animation = get_animation_tree()->get_animation_player()->get_current_animation().is_empty();
    const bool is_same_animation = query_output.animation_match == _last_query_output.animation_match;
    const bool is_same_time = abs(query_output.time_match - p_playback_info.time) < QUERY_TIME_ERROR;

    // Play selected animation
    if (!is_same_animation || !is_same_time) {
        const String animation_match = get_animation_library_name() + "/" + query_output.animation_match;
        const float time_match = query_output.time_match;

        Ref<Animation> anim = process_state->tree->get_animation(animation_match);
        double anim_size = (double)anim->get_length();

        NodeTimeInfo next_nti = cur_nti;
        next_nti.length = anim_size;
        next_nti.position = time_match;

        AnimationMixer::PlaybackInfo pi = p_playback_info;
        pi.weight = 1.0;
        pi.time = next_nti.position;
        pi.looped_flag = Animation::LOOPED_FLAG_NONE;
        blend_animation(animation_match, p_playback_info);

        _last_query_output = query_output;
        return next_nti;
    }

    return play_current_animation(p_playback_info, cur_nti, p_test_only);
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
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::FLOAT, query_frequency);
}

String MMAnimationNode::get_animation_library_name() const {
    // TODO: Let store the library name in the node
    return animation_library->get_path().get_file().rstrip(".tres");
}

AnimationNode::NodeTimeInfo MMAnimationNode::play_current_animation(const AnimationMixer::PlaybackInfo& p_playback_info, const AnimationNode::NodeTimeInfo& p_current_nti, bool p_test_only) {
    const StringName animation = get_animation_library_name() + "/" + _last_query_output.animation_match;

    Ref<Animation> anim = process_state->tree->get_animation(animation);
    double anim_size = (double)anim->get_length();

    bool will_end = Animation::is_greater_or_equal_approx(p_current_nti.position + p_current_nti.delta, p_current_nti.length);

    NodeTimeInfo next_nti = p_current_nti;
    next_nti.will_end = will_end;
    next_nti.length = anim_size;
    next_nti.position = p_playback_info.time;

    if (!p_test_only) {
        AnimationMixer::PlaybackInfo pi = p_playback_info;
        pi.weight = 1.0;
        pi.time = next_nti.position;
        pi.looped_flag = Animation::LOOPED_FLAG_NONE;
        blend_animation(animation, pi);
    }

    return next_nti;
}

void MMAnimationNode::get_child_nodes(List<ChildNode>* r_child_nodes) {
    r_child_nodes->push_back(ChildNode{"Animation", _anim_node});
}

Ref<AnimationNode> MMAnimationNode::get_child_by_name(const StringName& p_name) const {
    if (p_name == "animation") {
        return _anim_node;
    }
    return Ref<AnimationNode>();
}

void MMAnimationNode::_tree_changed() {
    AnimationRootNode::_tree_changed();
}

void MMAnimationNode::_animation_node_renamed(const ObjectID& p_oid, const String& p_old_name, const String& p_new_name) {
    AnimationRootNode::_animation_node_renamed(p_oid, p_old_name, p_new_name);
}

void MMAnimationNode::_animation_node_removed(const ObjectID& p_oid, const StringName& p_node) {
    AnimationRootNode::_animation_node_removed(p_oid, p_node);
}
