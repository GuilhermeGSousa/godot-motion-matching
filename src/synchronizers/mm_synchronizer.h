#pragma once

#include "scene/3d/node_3d.h"

#include "common.h"

class MMCharacter;

struct MMSyncResult {
    Vector3 character_position;
    Quaternion character_rotation;
    Vector3 controller_position;
    Quaternion controller_rotation;
};

class MMSynchronizer : public Resource {
    GDCLASS(MMSynchronizer, Resource)

public:
    // TODO: This API isn't great and will change, and should be improved to better support GD Script
    virtual MMSyncResult sync(const MMCharacter* controller, const Node3D* character, float delta_time) = 0;

protected:
    static void _bind_methods();
};