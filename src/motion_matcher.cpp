#include "motion_matcher.h"

#include <godot_cpp/classes/engine.hpp>

void MotionMatcher::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    _controller = get_node<MMController>(controller_path);
    _character = get_node<MMCharacter>(character_path);
    _animation_player = get_node<MMAnimationPlayer>(animation_player_path);
    _animation_player->connect("animation_finished", Callable(this, "_on_animation_finished"));
    _animation_player->set_callback_mode_process(
        godot::AnimationMixer::AnimationCallbackModeProcess::ANIMATION_CALLBACK_MODE_PROCESS_MANUAL);
    query_time = 0.1f;
}

void MotionMatcher::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    const bool should_query = _time_since_last_query > query_time || _force_transition;
    if (should_query) {
        _time_since_last_query = 0.f;
        _force_transition = false;

        // Fill query_input with data from the controller
        MMQueryInput query_input;
        query_input.controller_velocity = _controller->get_velocity();
        query_input.trajectory = _controller->get_trajectory();
        query_input.controller_transform = _controller->get_global_transform();
        query_input.character_transform = _character->get_global_transform();

        // Run query
        const MMQueryOutput result = _animation_player->query(query_input);

        // Play selected animation
        if (result.animation_match != _animation_player->get_current_animation() ||
            (result.time_match - _animation_player->get_current_animation_position() > search_time_threshold)) {
            _animation_player->inertialize_transition(result.animation_match, result.time_match);
        }
    }
    _animation_player->advance(delta);
    _animation_player->inertialize_update(delta);
    _time_since_last_query += delta;
}

void MotionMatcher::_on_animation_finished(StringName p_animation_name) {
    _force_transition = true;
}

void MotionMatcher::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_animation_finished", "anim"), &MotionMatcher::_on_animation_finished);

    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::NODE_PATH, controller_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES,
                           "MMController");
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::NODE_PATH, character_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES,
                           "MMCharacter");
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::NODE_PATH, animation_player_path,
                           PROPERTY_HINT_NODE_PATH_VALID_TYPES, "MMAnimationPlayer");
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::FLOAT, query_time);
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::FLOAT, search_time_threshold);
}