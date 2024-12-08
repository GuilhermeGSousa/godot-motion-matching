#include "mm_mix_synchronizer.h"

#include "mm_character.h"

void MMMixSynchronizer::sync(MMCharacter* p_controller, Node3D* p_character, float p_delta_time) {

    Vector3 position_delta = p_character->get_global_position() - p_controller->get_global_position();
    Vector3 rotation_delta = p_character->get_global_rotation() - p_controller->get_global_rotation();

    Vector3 controller_position = p_controller->get_global_position() + position_delta * root_motion_amount;

    Vector3 character_position = p_character->get_global_position() - position_delta * (1.0 - root_motion_amount);
    Vector3 character_rotation = p_character->get_global_rotation() - rotation_delta * (1.0 - root_motion_amount);

    controller_position.y = p_controller->get_global_position().y;
    character_position.y = p_controller->get_global_position().y;

    p_controller->set_global_position(controller_position);
    p_character->set_global_position(character_position);

    // p_character->set_global_rotation(character_rotation);
}

void MMMixSynchronizer::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMMixSynchronizer, Variant::FLOAT, root_motion_amount, PROPERTY_HINT_RANGE, "0.0,1.0,0.01");
}
