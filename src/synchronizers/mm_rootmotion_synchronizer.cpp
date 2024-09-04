#include "synchronizers/mm_rootmotion_synchronizer.h"
#include "mm_rootmotion_synchronizer.h"

MMSyncResult MMRootMotionSynchronizer::sync(const MMController* controller, const Node3D* character, float delta_time) {
    MMSyncResult result;

    result.character_position = character->get_global_position();
    result.character_rotation = character->get_global_rotation();
    result.controller_position = character->get_global_position();
    result.controller_rotation = character->get_global_rotation();

    return result;
}
void MMRootMotionSynchronizer::_bind_methods() {
}