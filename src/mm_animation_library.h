#pragma once

#include <godot_cpp/classes/animation_library.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/typed_array.hpp>

#include "common.h"
#include "mm_query.h"

using namespace godot;

class MMFeature;
class MMAnimationPlayer;

class MMAnimationLibrary : public AnimationLibrary {
    GDCLASS(MMAnimationLibrary, AnimationLibrary)

public:
    MMAnimationLibrary(/* args */);
    virtual ~MMAnimationLibrary();
    void bake_data(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton);
    MMQueryOutput query(const MMQueryInput& p_query_input);

    float compute_cost(const PackedFloat32Array& p_query_data, const PackedFloat32Array& p_library_data) const;

    GETSET(float, sampling_rate, 1.f)
    GETSET(PackedFloat32Array, motion_data)
    GETSET(TypedArray<MMFeature>, features)

protected:
    static void _bind_methods();

private:
    void _normalize_data(PackedFloat32Array& p_data, size_t p_dim_count) const;
};
