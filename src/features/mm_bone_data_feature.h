#pragma once

#include "common.h"
#include "features/mm_feature.h"

using namespace godot;

class MMBoneDataFeature : public MMFeature {
    GDCLASS(MMBoneDataFeature, MMFeature)

public:
    virtual void setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual uint32_t get_dimension_count() const override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, float time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const override;

    GETSET(PackedStringArray, bone_names, PackedStringArray());

protected:
    static void _bind_methods();

private:
    StringName _skeleton_path;
};
