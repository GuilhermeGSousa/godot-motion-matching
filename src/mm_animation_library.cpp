#include "mm_animation_library.h"

#include <godot_cpp/variant/utility_functions.hpp>

#include "common.h"
#include "features/mm_feature.h"

using namespace godot;

MMAnimationLibrary::MMAnimationLibrary() : AnimationLibrary() {
}

MMAnimationLibrary::~MMAnimationLibrary() {
}

void MMAnimationLibrary::bake_data(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {
    UtilityFunctions::print("Baking data");
    motion_data.clear();

    size_t dim_count = 0;
    for (auto i = 0; i < features.size(); ++i) {
        MMFeature* f = Object::cast_to<MMFeature>(features[i]);
        dim_count += f->get_dimension_count();
        f->setup_skeleton(p_player, p_skeleton);
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

MMQueryResult MMAnimationLibrary::query(const MMQueryInput& p_query_input) {
    // TODO: Use fancier search algorithms
    // TODO: Do this using an offset array instead

    float cost = FLT_MAX;
    MMQueryResult result;
    int current_index = 0;

    const TypedArray<StringName> animation_list = get_animation_list();
    for (size_t anim_index = 0; anim_index < animation_list.size(); anim_index++) {
        const StringName& anim_name = animation_list[anim_index];
        Ref<Animation> animation = get_animation(anim_name);
        const float animation_length = animation->get_length();
        const float time_step = 1.0f / get_sampling_rate();

        for (int time = 0; time < animation_length; time += time_step) {
            float pose_cost = 0.0f;
            for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {
                const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);

                int64_t start_index = current_index;
                int64_t end_index = start_index + feature->get_dimension_count();

                PackedFloat32Array feature_data = motion_data.slice(start_index, end_index);
                PackedFloat32Array runtime_data = feature->evaluate_runtime_data(p_query_input);

                pose_cost += compute_cost(runtime_data, feature_data);
                current_index += feature->get_dimension_count();
            }

            if (pose_cost < cost) {
                cost = pose_cost;
                result.cost = cost;

                String resource_name = "michelle_anim_lib";
                result.animation_match = resource_name + "/" + anim_name;
                result.time_match = time;
            }
        }
    }
    return result;
}

float MMAnimationLibrary::compute_cost(const PackedFloat32Array& p_query_data,
                                       const PackedFloat32Array& p_library_data) const {
    float cost = 0.0f;
    for (int64_t i = 0; i < p_query_data.size(); i++) {
        float diff = p_query_data[i] - p_library_data[i];
        cost += diff * diff;
    }
    return cost;
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