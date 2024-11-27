#ifndef MM_SYNCHRONIZER_H
#define MM_SYNCHRONIZER_H

#include "common.h"

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class MMCharacter;

class MMSynchronizer : public Resource {
    GDCLASS(MMSynchronizer, Resource)

public:
    // TODO: This API isn't great and will change, and should be improved to better support GD Script
    virtual void sync(MMCharacter* p_controller, Node3D* p_character, float delta_time) = 0;

protected:
    static void _bind_methods();
};
#endif // MM_SYNCHRONIZER_H
