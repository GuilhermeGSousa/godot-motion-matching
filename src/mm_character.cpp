#include "mm_character.h"

#include "common.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/global_constants.hpp>

using namespace godot;

void MMCharacter::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    _animation_player = get_node<MMAnimationPlayer>(animation_player_path);
}

void MMCharacter::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    // Set Rotation
    set_rotation(get_rotation() + _animation_player->get_root_motion_angular_velocity() * delta);
    //  Hard mode: set position
    //  Also, why is this even hard mode?
    set_velocity(_animation_player->get_root_motion_linear_velocity());
    move_and_slide();
}

void MMCharacter::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::NODE_PATH, animation_player_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES,
                           "MMAnimationPlayer");
}