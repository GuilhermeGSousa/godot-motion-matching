#pragma once

#include "common.h"

#include "features/mm_feature.h"

#include "mm_animation_player.h"

using namespace godot;

class MMFacingFeature : public MMFeature {
    GDCLASS(MMFacingFeature, MMFeature)

    virtual size_t get_dimension_count() const override;

    virtual void setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, float p_time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const override;

    GETSET(float, weight, 1.f)
protected:
    static void _bind_methods();

private:
    int _root_bone{-1};
    NodePath _root_bone_path;
    int _root_rotation_track{-1};
};