#include "mm_animation_library.h"

#include <godot_cpp/variant/utility_functions.hpp>

#include "common.h"
#include "features/mm_feature.h"

using namespace godot;

MMAnimationLibrary::MMAnimationLibrary() : AnimationLibrary() {
}

MMAnimationLibrary::~MMAnimationLibrary() {
}

void MMAnimationLibrary::bake_data(const Node3D* p_animation_root, const Skeleton3D* p_skeleton,
                                   const String& p_skeleton_root_bone) {
    UtilityFunctions::print("Baking data");
    motion_data.clear();

    size_t dim_count = 0;
    for (auto i = 0; i < features.size(); ++i) {
        MMFeature* f = Object::cast_to<MMFeature>(features[i]);
        dim_count += f->get_dimension_count();
        f->setup_skeleton(p_animation_root, p_skeleton, p_skeleton_root_bone);
    }
    _total_dimension_count = dim_count;

    TypedArray<StringName> animation_list = get_animation_list();

    PackedFloat32Array data;
    // For every animation
    for (size_t anim_index = 0; anim_index < animation_list.size(); anim_index++) {
        const StringName& anim_name = animation_list[anim_index];
        Ref<Animation> animation = get_animation(anim_name);

        // Initialize features
        for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {
            MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
            feature->setup_for_animation(animation);
        }

        const float animation_length = animation->get_length();
        const float time_step = 1.0f / get_sampling_rate();
        // Every time step
        for (int time = 0; time < animation_length; time += time_step) {
            PackedFloat32Array pose_data;

            // For every feature
            for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {
                const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
                pose_data.append_array(feature->bake_animation_pose(animation, time));
            }

            data.append_array(pose_data);
        }
    }

    motion_data = data.duplicate();
}

void MMAnimationLibrary::_bind_methods() {
    // ClassDB::bind_method(D_METHOD("bake_data", "animation_root"),
    //                      &MMAnimationLibrary::bake_data);

    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::ARRAY, features, PROPERTY_HINT_TYPE_STRING,
                           UtilityFunctions::str(Variant::OBJECT) + '/' + UtilityFunctions::str(Variant::BASIS) +
                               ":MMFeature",
                           PROPERTY_USAGE_DEFAULT);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::PACKED_FLOAT32_ARRAY, motion_data);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::FLOAT, sampling_rate);
}