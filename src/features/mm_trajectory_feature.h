#pragma once

#include "features/mm_feature.h"

using namespace godot;

class MMTrajectoryFeature : public MMFeature {
    GDCLASS(MMTrajectoryFeature, MMFeature)

public:
    MMTrajectoryFeature(/* args */);
    virtual ~MMTrajectoryFeature();
    virtual size_t get_dimension_count() const override;

    virtual void setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, float time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const override;

protected:
    static void _bind_methods();
};