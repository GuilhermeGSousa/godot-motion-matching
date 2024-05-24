#include "motion_matcher.h"

#include <godot_cpp/classes/engine.hpp>

void MotionMatcher::_ready() {
    _controller = get_node<MMController>(controller_path);
    _animation_player = get_node<MMAnimationPlayer>(animation_player_path);
    _animation_player->connect("animation_finished", Callable(this, "_on_animation_finished"));
}

void MotionMatcher::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    _time_since_last_query += delta;

    if (_time_since_last_query < query_time) {
        return;
    }

    _time_since_last_query = 0.f;
    // Fill query_input with data from the controller
    MMQueryInput query_input;
    query_input.controller_velocity =
        _controller->get_global_transform().basis.get_quaternion().xform_inv(_controller->get_velocity());

    // Run query
    const MMQueryResult result = _animation_player->query(query_input);

    // Play selected animation
    UtilityFunctions::print("Current animation: " + _animation_player->get_current_animation() +
                            " Matched animation: " + result.animation_match);
    if (result.animation_match != _animation_player->get_current_animation() ||
        (result.animation_match == _animation_player->get_current_animation() &&
         abs(result.time_match - _animation_player->get_current_animation_position()) < search_time_threshold)) {
        _animation_player->request_animation(result.animation_match, result.time_match);
    }
}

void MotionMatcher::_on_animation_finished(StringName p_animation_name) {
}

void MotionMatcher::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_animation_finished", "anim"), &MotionMatcher::_on_animation_finished);

    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::NODE_PATH, controller_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES,
                           "MMController");
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::NODE_PATH, animation_player_path,
                           PROPERTY_HINT_NODE_PATH_VALID_TYPES, "MMAnimationPlayer");
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::FLOAT, query_time);
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::FLOAT, search_time_threshold);
}