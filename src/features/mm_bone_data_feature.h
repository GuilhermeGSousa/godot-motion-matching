#pragma once

#include "common.h"
#include "features/mm_feature.h"

using namespace godot;

class MMBoneDataFeature : public MMFeature {
    GDCLASS(MMBoneDataFeature, MMFeature)

public:
    virtual void setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual size_t get_dimension_count() const override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, float time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const override;

    virtual void debug_gizmo(Ref<EditorNode3DGizmo> gizmo, const PackedFloat32Array data,
                             godot::Transform3D tr = godot::Transform3D{}) override;

    GETSET(PackedStringArray, bone_names, PackedStringArray());

protected:
    static void _bind_methods();
};
