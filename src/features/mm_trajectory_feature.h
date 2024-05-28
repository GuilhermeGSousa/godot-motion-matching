#pragma once

#include "common.h"
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

    GETSET(float, past_delta_time, 0.1f);
    GETSET(int, past_frames, 1);
    GETSET(float, future_delta_time, 0.1f);
    GETSET(int, future_frames, 5);
    GETSET(bool, include_height, false);

protected:
    static void _bind_methods();

private:
    int _root_bone{-1};
    NodePath _root_bone_path;
    int _root_position_track{-1};
    int _root_rotation_track{-1};
};