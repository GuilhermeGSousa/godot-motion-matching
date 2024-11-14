#include "mm_animation_node.h"

#include "editor/animation_tree_handler_plugin.h"
#include "math/spring.hpp"
#include "mm_query.h"

// #ifdef TOOLS_ENABLED
// // #include "editor/plugins/animation_tree_editor_plugin.h"
// #endif

#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/animation_library.hpp>
#include <godot_cpp/classes/animation_tree.hpp>
#include <godot_cpp/classes/engine.hpp>

// Only play the matched animation if the matched time position
// is QUERY_TIME_ERROR away from the current time
constexpr float QUERY_TIME_ERROR = 0.05;

PackedFloat32Array MMAnimationNode::_process(const PackedFloat64Array& p_playback_info, bool p_test_only) {
    PackedFloat32Array default_result;
    default_result.resize(6);
    default_result.fill(0.0);
    if (Engine::get_singleton()->is_editor_hint()) {
        return default_result;
    }

    if (library.is_empty()) {
        return default_result;
    }
    const double time = p_playback_info[0];
    const double delta_time = p_playback_info[1];
    _current_animation_info.time = time;
    _current_animation_info.delta = delta_time;
    _current_animation_info.seeked = p_playback_info[4] > 0.5;
    _current_animation_info.is_external_seeking = p_playback_info[5] > 0.5;

    const bool is_about_to_end = false; // TODO: Implement this

    // We run queries periodically, or when the animation is about to end
    const bool has_current_animation = !_last_query_output.animation_match.is_empty();
    const bool should_query = (_time_since_last_query > (1.0 / query_frequency)) || is_about_to_end || !has_current_animation;

    if (!should_query) {
        _time_since_last_query += delta_time;
        return _update_current_animation(p_test_only);
    }

    MMQueryInput* query_input = Object::cast_to<MMQueryInput>(get_parameter("motion_matching_input"));

    if (!query_input || !query_input->is_valid()) {
        _time_since_last_query += delta_time;
        return _update_current_animation(p_test_only);
    }

    _time_since_last_query = 0.f;

    // Run query
    Ref<MMAnimationLibrary> animation_library = get_process_tree()->get_animation_library(library);
    ERR_FAIL_COND_V_MSG(animation_library.is_null(), PackedFloat32Array(), "Library not found: " + library);
    const MMQueryOutput query_output = animation_library->query(*query_input);

    const bool is_same_animation = query_output.animation_match == _last_query_output.animation_match;
    const bool is_same_time = abs(query_output.time_match - time) < QUERY_TIME_ERROR;

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
    Ref<Animation> anim = get_process_tree()->get_animation(p_animation);
    ERR_FAIL_COND_MSG(anim.is_null(), vformat("Animation not found: %s", p_animation));

    if (!_current_animation_info.name.is_empty() && blending_enabled) {
        _prev_animation_queue.push_front(_current_animation_info);
    }

    _current_animation_info.name = p_animation;
    _current_animation_info.length = anim->get_length();
    _current_animation_info.time = p_time;
    _current_animation_info.weight = blending_enabled ? 0.f : 1.f;
}

PackedFloat32Array MMAnimationNode::_update_current_animation(bool p_test_only) {
    // const bool will_end = Animation::is_greater_or_equal_approx(
    //     _current_animation_info.time + _current_animation_info.delta,
    //     _current_animation_info.length);

    Spring::_simple_spring_damper_exact(
        _current_animation_info.weight,
        _current_animation_info.blend_spring_speed,
        1.f,
        transition_halflife,
        _current_animation_info.delta);

    int pop_count = 0;
    for (AnimationInfo& prev_info : _prev_animation_queue) {
        Spring::_simple_spring_damper_exact(
            prev_info.weight,
            prev_info.blend_spring_speed,
            0.f,
            transition_halflife,
            _current_animation_info.delta);
        if (prev_info.weight <= SMALL_NUMBER) {
            pop_count++;
        }
    }

    for (int i = 0; i < pop_count; i++) {
        _prev_animation_queue.pop_back();
    }

    // Normalized blend weights in the queue
    const float inv_blend = 1.f - _current_animation_info.weight;
    float prev_blend_total = 0.f;
    for (AnimationInfo& prev_info : _prev_animation_queue) {
        prev_blend_total += prev_info.weight;
    }

    for (AnimationInfo& prev_info : _prev_animation_queue) {
        prev_info.weight *= inv_blend / prev_blend_total;
    }

    if (!p_test_only) {
        for (AnimationInfo& prev_info : _prev_animation_queue) {
            blend_animation(
                prev_info.name,
                prev_info.time,
                prev_info.delta,
                prev_info.seeked,
                prev_info.is_external_seeking,
                prev_info.weight);
        }
        blend_animation(
            _current_animation_info.name,
            _current_animation_info.time,
            _current_animation_info.delta,
            _current_animation_info.seeked,
            _current_animation_info.is_external_seeking,
            _current_animation_info.weight);
    }

    PackedFloat32Array result;
    result.append(0.0);
    result.append(_current_animation_info.time);
    result.append(_current_animation_info.delta);
    result.append(static_cast<float>(Animation::LoopMode::LOOP_NONE));
    result.append(false); // TODO: Will End
    result.append(false); // Is Infinity
    return result;
}

Array MMAnimationNode::_get_parameter_list() const {
    Array parameter_list;
    parameter_list.push_back(Dictionary(PropertyInfo(Variant::Type::OBJECT, "motion_matching_input", PROPERTY_HINT_RESOURCE_TYPE, "MMQueryInput", PROPERTY_USAGE_STORAGE)));

    return parameter_list;
}

Variant MMAnimationNode::_get_parameter_default_value(const StringName& p_parameter) const {
    Variant ret = AnimationNodeExtension::_get_parameter_default_value(p_parameter);
    if (ret != Variant()) {
        return ret;
    }

    if (p_parameter == StringName("motion_matching_input")) {
        Ref<MMQueryInput> p;
        p.instantiate();
        return p;
    }

    return Variant();
}

bool MMAnimationNode::_is_parameter_read_only(const StringName& p_parameter) const {
    if (AnimationNodeExtension::_is_parameter_read_only(p_parameter)) {
        return true;
    }

    if (p_parameter == StringName("motion_matching_input")) {
        return false;
    }

    return false;
}

String MMAnimationNode::_get_caption() const {
    return "Motion Matching";
}

bool MMAnimationNode::_has_filter() const {
    return true;
}

void MMAnimationNode::_validate_property(PropertyInfo& p_property) const {
    if (p_property.name == StringName("transition_halflife")) {
        if (!blending_enabled) {
            p_property.usage = PROPERTY_USAGE_NO_EDITOR;
        }
    }

    if (p_property.name == StringName("library")) {
        AnimationTreeHandlerPlugin* plugin = AnimationTreeHandlerPlugin::get_singleton();
        if (!plugin) {
            return;
        }
        AnimationTree* tree = plugin->get_animation_tree();
        if (!tree) {
            return;
        }
        String animations;
        TypedArray<StringName> library_names = tree->get_animation_library_list();

        for (int i = 0; i < library_names.size(); i++) {
            Ref<MMAnimationLibrary> lib = tree->get_animation_library(library_names[i]);
            if (lib.is_null()) {
                continue;
            }
            if (!animations.is_empty()) {
                animations += ",";
            }
            animations += library_names[i];
        }
        if (animations.is_empty()) {
            return;
        }
        p_property.hint = PROPERTY_HINT_ENUM;
        p_property.hint_string = animations;
    }

    AnimationNodeExtension::_validate_property(p_property);
}

void MMAnimationNode::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::STRING_NAME, library);
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::FLOAT, query_frequency);
    ClassDB::bind_method(D_METHOD("get_blending_enabled"), &MMAnimationNode::get_blending_enabled);
    ClassDB::bind_method(D_METHOD("set_blending_enabled", "value"), &MMAnimationNode::set_blending_enabled);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "blending_enabled"), "set_blending_enabled", "get_blending_enabled");
    BINDER_PROPERTY_PARAMS(MMAnimationNode, Variant::FLOAT, transition_halflife);
}

bool MMAnimationNode::get_blending_enabled() const {
    return blending_enabled;
}

void MMAnimationNode::set_blending_enabled(bool value) {
    blending_enabled = value;
    notify_property_list_changed();
}
