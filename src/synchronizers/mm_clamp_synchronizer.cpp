#include "synchronizers/mm_clamp_synchronizer.h"

#include "mm_controller.h"

MMSyncResult MMClampSynchronizer::sync(const MMController* controller, const Node3D* character, float delta_time) {
    MMSyncResult result;

    result.controller_position = controller->get_global_position();
    result.controller_rotation = controller->get_quaternion();

    const Vector3 position_delta = character->get_global_position() - controller->get_global_position();

    if (position_delta.length() > clamp_distance) {
        result.character_position =
            result.controller_position +
            position_delta.normalized() * clamp_distance;
    } else {
        result.character_position = character->get_global_position();
    }

    result.character_rotation = character->get_quaternion();

    return result;
}

void MMClampSynchronizer::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMClampSynchronizer, Variant::FLOAT, clamp_distance);
}