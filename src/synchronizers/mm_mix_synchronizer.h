#pragma once

#include "common.h"
#include "synchronizers/mm_synchronizer.h"

class MMMixSynchronizer : public MMSynchronizer {
    GDCLASS(MMMixSynchronizer, MMSynchronizer)

public:
    virtual void sync(MMCharacter* p_controller, Node3D* p_character, float p_delta_time) override;

    GETSET(float, root_motion_amount, 1.0f)
protected:
    static void _bind_methods();
};