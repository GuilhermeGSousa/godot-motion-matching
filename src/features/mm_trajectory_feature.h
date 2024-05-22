#pragma once

#include "features/mm_feature.h"

using namespace godot;

class MMTrajectoryFeature : public MMFeature {
    GDCLASS(MMTrajectoryFeature, MMFeature)

public:
    MMTrajectoryFeature(/* args */);
    virtual ~MMTrajectoryFeature();
    virtual size_t get_dimension_count() const override;

    virtual void setup_skeleton(const Node3D *p_animation_root,
                                const Skeleton3D *p_skeleton,
                                const String &p_root_bone) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation,
                                                   float time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(
        /* some runtime data*/) const override;

protected:
    static void _bind_methods();
};