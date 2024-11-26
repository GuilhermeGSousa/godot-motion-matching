#ifndef MM_BONE_DATA_FEATURE_H
#define MM_BONE_DATA_FEATURE_H

#include "common.h"
#include "features/mm_feature.h"

#include <godot_cpp/classes/skeleton3d.hpp>

using namespace godot;

class MMBoneDataFeature : public MMFeature {
    GDCLASS(MMBoneDataFeature, MMFeature)

public:
    virtual void setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual int64_t get_dimension_count() const override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, double time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const override;

    virtual void display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const override;

    GETSET(PackedStringArray, bone_names, PackedStringArray());

protected:
    static void _bind_methods();

private:
    BoneState _sample_bone_state(Ref<Animation> p_animation, double p_time, const String& p_bone_path) const;
    StringName _skeleton_path;
    const Skeleton3D* _skeleton;
    int32_t _root_bone_index;
};

#endif // MM_BONE_DATA_FEATURE_H
