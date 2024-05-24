#include "mm_character.h"

#include "common.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/global_constants.hpp>

using namespace godot;

void MMCharacter::_ready() {
    _animation_player = get_node<MMAnimationPlayer>(animation_player_path);
}

void MMCharacter::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    // Set Rotation
    const Quaternion rotation_delta = _animation_player->get_root_motion_rotation_delta(delta);
    set_quaternion(rotation_delta * get_quaternion());

    // Set Velocity
    set_velocity(_animation_player->get_root_motion_velocity());
    move_and_slide();
    // UtilityFunctions::print("RM Velocity: " + String::num(_animation_player->get_root_motion_velocity().length()));

    // set_position(get_position() + _animation_player->get_root_motion_velocity() * delta);
}

void MMCharacter::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::NODE_PATH, animation_player_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES,
                           "MMAnimationPlayer");
}