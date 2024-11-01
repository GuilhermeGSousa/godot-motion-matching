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

#include "editor/plugins/animation_tree_editor_plugin.h"

// Only play the matched animation if the matched time position
// is QUERY_TIME_ERROR away from the current time
constexpr float QUERY_TIME_ERROR = 0.05;

StringName MMAnimationNode::MOTION_MATCHING_INPUT_PARAM;

MMAnimationNode::MMAnimationNode() {
    MOTION_MATCHING_INPUT_PARAM = "motion_matching_input";
}

AnimationNode::NodeTimeInfo MMAnimationNode::_process(const AnimationMixer::PlaybackInfo p_playback_info, bool p_test_only) {
    NodeTimeInfo cur_nti = get_node_time_info();

    if (Engine::get_singleton()->is_editor_hint()) {
        return cur_nti;
    }

    if (library.is_empty()) {
        return cur_nti;
    }

    _current_animation_info.playback_info = p_playback_info;
    _current_animation_info.playback_info.weight = 1.0;

    const bool is_about_to_end = false; // TODO: Implement this

    // We run queries periodically, or when the animation is about to end
    const bool has_current_animation = !_last_query_output.animation_match.is_empty();
    const bool should_query = (_time_since_last_query > (1.0 / query_frequency)) || is_about_to_end || !has_current_animation;

    if (!should_query) {
        _time_since_last_query += p_playback_info.delta;
        return _update_current_animation(p_test_only);
    }

    MMQueryInput* query_input = Object::cast_to<MMQueryInput>(get_parameter(MOTION_MATCHING_INPUT_PARAM));

    if (!query_input || !query_input->is_valid()) {
        _time_since_last_query += p_playback_info.delta;
        return _update_current_animation(p_test_only);
    }

    _time_since_last_query = 0.f;

    // Run query
    Ref<MMAnimationLibrary> animation_library = get_animation_tree()->get_animation_library(library);
    const MMQueryOutput query_output = animation_library->query(*query_input);

    const bool is_same_animation = query_output.animation_match == _last_query_output.animation_match;
    const bool is_same_time = abs(query_output.time_match - p_playback_info.time) < QUERY_TIME_ERROR;

    // Play selected animation
    if (!is_same_animation || !is_same_time) {
        const String animation_match = query_output.animation_match;
        const float time_match = query_output.time_match;
        if (!p_test_only) {
            _start_transition(animation_match, time_match);
        }
        _last_query_output = query_output;
    }

    return _update_current_animation(p_test_only);
}

void MMAnimationNode::_start_transition(const StringName p_animation, float p_time) {
    _current_animation_info.name = p_animation;

    _current_animation_info.playback_info.time = p_time;

    Ref<Animation> anim = process_state->tree->get_animation(p_animation);
    _current_animation_info.length = anim->get_length();
}

AnimationNode::NodeTimeInfo MMAnimationNode::_update_current_animation(bool p_test_only) {
    const bool will_end = Animation::is_greater_or_equal_approx(
        _current_animation_info.playback_info.time + _current_animation_info.playback_info.delta,
        _current_animation_info.length);

    if (!p_test_only) {
        blend_animation(_current_animation_info.name, _current_animation_info.playback_info);
    }

    NodeTimeInfo next_nti;
    next_nti.will_end = will_end;
    next_nti.length = _current_animation_info.length;
    next_nti.position = _current_animation_info.playback_info.time;
    next_nti.delta = _current_animation_info.playback_info.delta;
    return next_nti;
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

void MMAnimationNode::_validate_property(PropertyInfo& p_property) const {
    if (p_property.name == "library") {
        AnimationTree* tree = AnimationTreeEditor::get_singleton()->get_animation_tree();
        String anims;
        if (tree) {
            List<StringName> lib_names;
            tree->get_animation_library_list(&lib_names);
            for (const StringName& lib_name : lib_names) {
                Ref<MMAnimationLibrary> lib = tree->get_animation_library(lib_name);
                if (lib.is_valid()) {
                    if (!anims.is_empty()) {
                        anims += ",";
                    }
                    anims += lib_name;
                }
            }
        }
        if (!anims.is_empty()) {
            p_property.hint = PROPERTY_HINT_ENUM;
            p_property.hint_string = anims;
        }
    }
}

void MMAnimationNode::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::STRING_NAME, library);
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::FLOAT, query_frequency);
}
