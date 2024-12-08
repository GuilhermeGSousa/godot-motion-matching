#include "synchronizers/mm_clamp_synchronizer.h"

#include "mm_character.h"

void MMClampSynchronizer::sync(MMCharacter* p_controller, Node3D* p_character, float p_delta_time) {
    const Vector3 position_delta = p_character->get_global_position() - p_controller->get_global_position();
    const real_t delta_length = position_delta.length();

    Vector3 character_position = p_character->get_global_position();
    if (position_delta.length() > clamp_distance) {
        character_position = p_controller->get_global_position() + position_delta.normalized() * clamp_distance;
    }
    character_position.y = p_character->get_global_position().y;

    p_character->set_global_position(character_position);
}

void MMClampSynchronizer::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMClampSynchronizer, Variant::FLOAT, clamp_distance);
}
