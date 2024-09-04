#pragma once

#include "synchronizers/mm_synchronizer.h"

#include "common.h"

using namespace godot;

class MMClampSynchronizer : public MMSynchronizer {
    GDCLASS(MMClampSynchronizer, MMSynchronizer)

public:
    virtual MMSyncResult sync(const MMController* controller, const Node3D* character, float delta_time);

    GETSET(float, clamp_distance, 10.f);

protected:
    static void _bind_methods();
};