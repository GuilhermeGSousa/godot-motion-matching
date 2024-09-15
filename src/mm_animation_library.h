#pragma once

#include <godot_cpp/classes/animation_library.hpp>
#include <godot_cpp/classes/editor_node3d_gizmo.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/typed_array.hpp>

#include "common.h"
#include "features/mm_feature.h"
#include "mm_query.h"

using namespace godot;

class MMFeature;
class MMAnimationPlayer;

class MMAnimationLibrary : public AnimationLibrary {
    GDCLASS(MMAnimationLibrary, AnimationLibrary)

public:
    MMAnimationLibrary(/* args */);
    virtual ~MMAnimationLibrary();
    void bake_data(const AnimationMixer* p_player, const Skeleton3D* p_skeleton);
    MMQueryOutput query(const MMQueryInput& p_query_input);
    size_t get_dim_count() const;
    int32_t get_animation_pose_count(String p_animation_name) const;

    void display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D& p_transform, String p_animation_name, int32_t p_pose_index) const;

    GETSET(TypedArray<MMFeature>, features)
    GETSET(float, sampling_rate, 1.f)

    // Database data
    GETSET(PackedFloat32Array, motion_data)
    GETSET(PackedInt32Array, db_anim_index)
    GETSET(PackedFloat32Array, db_time_index)
protected:
    static void _bind_methods();

private:
    void _normalize_data(PackedFloat32Array& p_data, size_t p_dim_count) const;
};
