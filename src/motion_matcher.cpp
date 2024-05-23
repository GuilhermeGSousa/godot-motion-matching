#include "motion_matcher.h"

#include <godot_cpp/classes/engine.hpp>

void MotionMatcher::_ready() {
    _controller = get_node<MMController>(controller_path);
    _animation_player = get_node<MMAnimationPlayer>(animation_player_path);
}

void MotionMatcher::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    MMQueryInput query_input;
    // Fill query_input with data from the controller

    const MMQueryResult result = _animation_player->query(query_input);
    _animation_player->request_animation(result.animation_match, result.time_match);
}

void MotionMatcher::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::NODE_PATH, controller_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES,
                           "MMController");
    BINDER_PROPERTY_PARAMS(MotionMatcher, Variant::NODE_PATH, animation_player_path,
                           PROPERTY_HINT_NODE_PATH_VALID_TYPES, "MMAnimationPlayer");
}