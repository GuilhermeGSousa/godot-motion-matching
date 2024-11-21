#ifndef MM_CLAMP_SYNCHRONIZER_H
#define MM_CLAMP_SYNCHRONIZER_H

#include "common.h"
#include "synchronizers/mm_synchronizer.h"

class MMClampSynchronizer : public MMSynchronizer {
    GDCLASS(MMClampSynchronizer, MMSynchronizer)

public:
    virtual MMSyncResult sync(const MMCharacter* controller, const Node3D* character, float delta_time) override;

    GETSET(float, clamp_distance, 10.f);

protected:
    static void _bind_methods();
};

#endif // MM_CLAMP_SYNCHRONIZER_H
