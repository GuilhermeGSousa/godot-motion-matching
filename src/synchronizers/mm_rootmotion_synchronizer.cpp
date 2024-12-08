#include "mm_rootmotion_synchronizer.h"

#include "mm_character.h"

void MMRootMotionSynchronizer::sync(MMCharacter* p_controller, Node3D* p_character, float p_delta_time) {
    const Vector3 position_delta = p_character->get_global_position() - p_controller->get_global_position();
    Vector3 controller_position = p_controller->get_global_position();
    Vector3 character_position = p_character->get_global_position();

    controller_position.x = p_character->get_global_position().x;
    controller_position.z = p_character->get_global_position().z;

    character_position.y = p_controller->get_global_position().y;

    p_controller->set_global_position(controller_position);
    p_controller->set_global_basis(p_character->get_global_basis());

    p_character->set_global_position(character_position);
}
void MMRootMotionSynchronizer::_bind_methods() {
}
