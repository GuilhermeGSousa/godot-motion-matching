#include "mm_rootmotion_synchronizer.h"

#include "modules/motion_matching/src/mm_character.h"

#include "scene/3d/node_3d.h"

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