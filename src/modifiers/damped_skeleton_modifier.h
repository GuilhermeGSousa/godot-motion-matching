#ifndef DAMPED_SKELETON_MODIFIER_H
#define DAMPED_SKELETON_MODIFIER_H

#include "common.h"
#include "mm_bone_state.h"

#include <godot_cpp/classes/skeleton_modifier3d.hpp>

using namespace godot;

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
#endif // DAMPED_SKELETON_MODIFIER_H
