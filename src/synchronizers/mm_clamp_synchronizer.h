#ifndef MM_CLAMP_SYNCHRONIZER_H
#define MM_CLAMP_SYNCHRONIZER_H

#include "common.h"
#include "synchronizers/mm_synchronizer.h"

class MMClampSynchronizer : public MMSynchronizer {
    GDCLASS(MMClampSynchronizer, MMSynchronizer)

public:
    virtual void sync(MMCharacter* p_controller, Node3D* p_character, float p_delta_time) override;

    GETSET(float, clamp_distance, 10.f);

protected:
    static void _bind_methods();
};

#endif // MM_CLAMP_SYNCHRONIZER_H
