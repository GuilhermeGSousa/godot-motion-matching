#ifndef MM_FEATURE_H
#define MM_FEATURE_H

#include "common.h"
#include "mm_query.h"

#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/editor_node3d_gizmo.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>

using namespace godot;

class MMFeature : public Resource {
    GDCLASS(MMFeature, Resource)

public:
    enum NormalizationMode { Raw,
                             Standard,
                             MinMax };

public:
    MMFeature(/* args */);
    virtual ~MMFeature();
    virtual void setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) {};

    virtual void setup_for_animation(Ref<Animation> animation) {};

    virtual int64_t get_dimension_count() const = 0;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, double time) const = 0;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const = 0;

    virtual void display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const {};

    void normalize(float* p_data) const;
    void denormalize(float* p_data) const;
    float compute_cost(const float* p_motion_data, const float* p_query_data) const;

    GETSET(float, weight, 1.0f);
    GETSET(NormalizationMode, normalization_mode, Standard);
    GETSET(PackedFloat32Array, means);
    GETSET(PackedFloat32Array, std_devs);
    GETSET(PackedFloat32Array, maxes);
    GETSET(PackedFloat32Array, mins);

protected:
    static void _bind_methods();
    void _normalize_minmax(float* p_data) const;
    void _denormalize_minmax(float* p_data) const;
    void _normalize_standard(float* p_data) const;
    void _denormalize_standard(float* p_data) const;
};

#endif // MM_FEATURE_H
