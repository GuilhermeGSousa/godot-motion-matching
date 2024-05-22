#pragma once

#include <godot_cpp/classes/animation_library.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/classes/skeleton_profile.hpp>
#include <godot_cpp/variant/typed_array.hpp>

#include "common.h"

using namespace godot;

class MMFeature;

class MMAnimationLibrary : public AnimationLibrary {
    GDCLASS(MMAnimationLibrary, AnimationLibrary)

public:
    MMAnimationLibrary(/* args */);
    virtual ~MMAnimationLibrary();
    void bake_data(const Node3D *p_animation_root, const Skeleton3D *p_skeleton,
                   const String &p_skeleton_root_bone);

    GETSET(float, sampling_rate, 1.f)
    GETSET(PackedFloat32Array, motion_data)
    GETSET(TypedArray<MMFeature>, features)

protected:
    static void _bind_methods();

private:
    size_t _total_dimension_count{0};
};
