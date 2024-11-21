#ifndef MM_SYNCHRONIZER_H
#define MM_SYNCHRONIZER_H

#include "common.h"

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource.hpp>

using namespace godot;

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
#endif // MM_SYNCHRONIZER_H
