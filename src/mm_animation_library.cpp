#include "mm_animation_library.h"

#include <godot_cpp/variant/utility_functions.hpp>

#include "common.h"
#include "features/mm_feature.h"
#include "math/stats.hpp"

using namespace godot;

MMAnimationLibrary::MMAnimationLibrary() : AnimationLibrary() {
}

MMAnimationLibrary::~MMAnimationLibrary() {
}

void MMAnimationLibrary::bake_data(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {
    motion_data.clear();

    size_t dim_count = 0;
    for (auto i = 0; i < features.size(); ++i) {
        MMFeature* f = Object::cast_to<MMFeature>(features[i]);
        dim_count += f->get_dimension_count();
        f->setup_skeleton(p_player, p_skeleton);
    }

    TypedArray<StringName> animation_list = get_animation_list();

    // Normalization data
    std::vector<StatsAccumulator> stats(dim_count);

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
        for (float time = 0; time < animation_length; time += time_step) {
            PackedFloat32Array pose_data;
            // For every feature
            int dim_index = 0;
            for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {
                const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
                const PackedFloat32Array feature_data = feature->bake_animation_pose(animation, time);

                // Update stats
                for (int i = 0; i < feature_data.size(); i++) {
                    stats[dim_index].add_sample(feature_data[i]);
                    dim_index++;
                }

                pose_data.append_array(feature_data);
            }
            data.append_array(pose_data);
        }
    }

    // Compute mean and standard deviation
    int dim_index = 0;
    for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {
        MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);

        PackedFloat32Array feature_means;
        feature_means.resize(feature->get_dimension_count());
        PackedFloat32Array feature_std_devs;
        feature_std_devs.resize(feature->get_dimension_count());

        for (size_t feature_element_index = 0; feature_element_index < feature->get_dimension_count();
             feature_element_index++) {
            feature_means.set(feature_element_index, stats[dim_index].get_mean());
            feature_std_devs.set(feature_element_index, stats[dim_index].get_standard_deviation());
            dim_index++;
        }

        feature->set_means(feature_means);
        feature->set_std_devs(feature_std_devs);
    }

    _normalize_data(data, dim_count);

    motion_data = data.duplicate();
}

MMQueryOutput MMAnimationLibrary::query(const MMQueryInput& p_query_input) {
    // TODO: Use fancier search algorithms
    // TODO: Do this using an offset array instead

    float cost = FLT_MAX;
    MMQueryOutput result;
    int current_index = 0;

    const TypedArray<StringName> animation_list = get_animation_list();

    int32_t dim_count = 0;
    PackedFloat32Array feature_vector = PackedFloat32Array();
    for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {
        const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
        PackedFloat32Array feature_data = feature->evaluate_runtime_data(p_query_input);
        feature->normalize(feature_data);
        feature_vector.append_array(feature_data);
        dim_count += feature->get_dimension_count();
    }

    for (size_t anim_index = 0; anim_index < animation_list.size(); anim_index++) {
        const StringName& anim_name = animation_list[anim_index];
        Ref<Animation> animation = get_animation(anim_name);
        const float animation_length = animation->get_length();
        const float time_step = 1.0f / get_sampling_rate();

        for (float time = 0; time < animation_length; time += time_step) {
            const int64_t start_index = current_index;
            const int64_t end_index = start_index + dim_count;
            PackedFloat32Array frame_data = motion_data.slice(start_index, end_index);

            const float pose_cost = compute_cost(feature_vector, frame_data);
            current_index += dim_count;

            if (pose_cost < cost) {
                cost = pose_cost;
                result.cost = cost;
                result.animation_match = anim_name;
                result.time_match = time;
                result.matched_frame_data = frame_data;
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

void MMAnimationLibrary::_normalize_data(PackedFloat32Array& p_data, size_t p_dim_count) const {
    for (size_t frame_index = 0; frame_index < p_data.size(); frame_index += p_dim_count) {
        for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {

            const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);

            for (size_t feature_element_index = 0; feature_element_index < feature->get_dimension_count();
                 feature_element_index++) {
                if (feature->get_std_devs()[feature_element_index] < SMALL_NUMBER) {
                    continue;
                }

                float value = p_data[feature_element_index + frame_index];

                value = (value - feature->get_means()[feature_element_index]) /
                    feature->get_std_devs()[feature_element_index];

                p_data.set(feature_element_index + frame_index, value);
            }
        }
    }
}

void MMAnimationLibrary::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::ARRAY, features, PROPERTY_HINT_TYPE_STRING,
                           UtilityFunctions::str(Variant::OBJECT) + '/' + UtilityFunctions::str(Variant::BASIS) +
                               ":MMFeature",
                           PROPERTY_USAGE_DEFAULT);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::PACKED_FLOAT32_ARRAY, motion_data);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::FLOAT, sampling_rate);
}