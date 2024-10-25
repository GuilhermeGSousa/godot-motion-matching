#pragma once

#include "common.h"
#include "mm_bone_state.h"

#include "scene/3d/skeleton_modifier_3d.h"

class DampedSkeletonModifier : public SkeletonModifier3D {
    GDCLASS(DampedSkeletonModifier, SkeletonModifier3D)

public:
    void _notification(int32_t p_what);
    virtual void _process_modification() override;

    GETSET(float, halflife, 0.1);

protected:
    static void _bind_methods();

private:
    SkeletonState _skeleton_state;
};