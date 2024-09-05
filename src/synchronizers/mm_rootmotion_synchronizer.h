#pragma once

#include "synchronizers/mm_synchronizer.h"

#include "common.h"

using namespace godot;

class MMRootMotionSynchronizer : public MMSynchronizer {
    GDCLASS(MMRootMotionSynchronizer, MMSynchronizer)

public:
    virtual MMSyncResult sync(const MMController* controller, const Node3D* character, float delta_time) override;

protected:
    static void _bind_methods();
};
