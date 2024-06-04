#pragma once

#include "common.h"
#include "mm_query.h"

#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/editor_node3d_gizmo.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>

using namespace godot;
class MMAnimationPlayer;

class MMFeature : public Resource {
    GDCLASS(MMFeature, Resource)

public:
    MMFeature(/* args */);
    virtual ~MMFeature();
    virtual void setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton){};

    virtual void setup_for_animation(Ref<Animation> animation){};

    virtual size_t get_dimension_count() const = 0;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, float time) const = 0;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const = 0;

    void normalize(PackedFloat32Array& p_data) const;
    void denormalize(PackedFloat32Array& p_data) const;

    GETSET(PackedFloat32Array, means);
    GETSET(PackedFloat32Array, std_devs);
    GETSET(PackedFloat32Array, maxes);
    GETSET(PackedFloat32Array, mins);

protected:
    static void _bind_methods();
};