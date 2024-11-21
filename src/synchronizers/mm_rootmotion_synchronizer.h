#ifndef MM_ROOTMOTION_SYNCHRONIZER_H
#define MM_ROOTMOTION_SYNCHRONIZER_H

#include "common.h"
#include "synchronizers/mm_synchronizer.h"

class MMRootMotionSynchronizer : public MMSynchronizer {
    GDCLASS(MMRootMotionSynchronizer, MMSynchronizer)

public:
    virtual MMSyncResult sync(const MMCharacter* controller, const Node3D* character, float delta_time) override;

protected:
    static void _bind_methods();
};

#endif // MM_ROOTMOTION_SYNCHRONIZER_H
