#include "mm_rootmotion_synchronizer.h"

#include "mm_character.h"

MMSyncResult MMRootMotionSynchronizer::sync(const MMCharacter* controller, const Node3D* character, float delta_time) {
    MMSyncResult result;

    result.character_position = character->get_global_position();
    result.character_rotation = character->get_global_basis().get_rotation_quaternion();
    result.controller_position = character->get_global_position();
    result.controller_rotation = character->get_global_basis().get_rotation_quaternion();

    return result;
}
void MMRootMotionSynchronizer::_bind_methods() {
}
