#pragma once

#include "common.h"
#include "mm_bone_state.h"

#include <godot_cpp/classes/skeleton_modifier3d.hpp>

using namespace godot;

class DampedSkeletonModifier : public SkeletonModifier3D {
    GDCLASS(DampedSkeletonModifier, SkeletonModifier3D)

public:
    virtual void _ready() override;
    virtual void _process_modification() override;

    GETSET(float, halflife, 0.1);

protected:
    static void _bind_methods();

private:
    SkeletonState _skeleton_state;
};