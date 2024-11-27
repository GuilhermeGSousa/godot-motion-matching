#ifndef MM_ROOTMOTION_SYNCHRONIZER_H
#define MM_ROOTMOTION_SYNCHRONIZER_H

#include "common.h"
#include "synchronizers/mm_synchronizer.h"

class MMRootMotionSynchronizer : public MMSynchronizer {
    GDCLASS(MMRootMotionSynchronizer, MMSynchronizer)

public:
    virtual void sync(MMCharacter* p_controller, Node3D* p_character, float p_delta_time) override;

protected:
    static void _bind_methods();
};

#endif // MM_ROOTMOTION_SYNCHRONIZER_H
