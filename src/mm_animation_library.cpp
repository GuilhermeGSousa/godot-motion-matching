#include "mm_animation_library.h"

#include "common.h"
#include "features/mm_feature.h"
#include "math/hash.h"
#include "math/stats.hpp"

MMAnimationLibrary::MMAnimationLibrary()
    : AnimationLibrary() {
}

MMAnimationLibrary::~MMAnimationLibrary() {
}

void MMAnimationLibrary::bake_data(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) {
    motion_data.clear();
    db_anim_index.clear();
    db_time_index.clear();

    int64_t dim_count = 0;
    for (auto i = 0; i < features.size(); ++i) {
        MMFeature* f = Object::cast_to<MMFeature>(features[i]);
        dim_count += f->get_dimension_count();
        f->setup_skeleton(p_player, p_skeleton);
    }

    TypedArray<StringName> animation_list = get_animation_list();

    // Normalization data
    std::vector<std::vector<StatsAccumulator>> stats(features.size());

    PackedFloat32Array data;
    // For every animation
    for (int64_t animation_index = 0; animation_index < animation_list.size(); animation_index++) {
        const StringName& anim_name = animation_list[animation_index];
        Ref<Animation> animation = get_animation(anim_name);

        // Initialize features
        for (int64_t feature_index = 0; feature_index < features.size(); feature_index++) {
            MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
            stats[feature_index].resize(feature->get_dimension_count());
            feature->setup_for_animation(animation);
        }

        const double animation_length = animation->get_length();
        const double time_step = 1.0f / get_sampling_rate();
        // Every time step
        for (double time = 0; time < animation_length; time += time_step) {
            PackedFloat32Array pose_data;
            // For every feature
            for (int64_t feature_index = 0; feature_index < features.size(); feature_index++) {
                const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
                const PackedFloat32Array feature_data = feature->bake_animation_pose(animation, time);

                ERR_FAIL_COND(feature_data.size() != feature->get_dimension_count());

                // Update stats
                for (int64_t feature_element_index = 0; feature_element_index < feature_data.size(); feature_element_index++) {
                    stats[feature_index][feature_element_index].add_sample(feature_data[feature_element_index]);
                }

                pose_data.append_array(feature_data);
            }

            ERR_FAIL_COND(pose_data.size() != dim_count);

            // Update dataset
            data.append_array(pose_data);
            db_anim_index.push_back(animation_index);
            db_time_index.push_back(time);
        }
    }

    // Compute mean and standard deviation
    for (int64_t feature_index = 0; feature_index < features.size(); feature_index++) {
        MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);

        PackedFloat32Array feature_means;
        feature_means.resize(feature->get_dimension_count());
        PackedFloat32Array feature_std_devs;
        feature_std_devs.resize(feature->get_dimension_count());
        PackedFloat32Array feature_mins;
        feature_mins.resize(feature->get_dimension_count());
        PackedFloat32Array feature_maxes;
        feature_maxes.resize(feature->get_dimension_count());

        for (int64_t feature_element_index = 0; feature_element_index < feature->get_dimension_count(); feature_element_index++) {
            feature_means.set(feature_element_index, stats[feature_index][feature_element_index].get_mean());
            feature_std_devs.set(feature_element_index, stats[feature_index][feature_element_index].get_standard_deviation());
            feature_mins.set(feature_element_index, stats[feature_index][feature_element_index].get_min());
            feature_maxes.set(feature_element_index, stats[feature_index][feature_element_index].get_max());
        }

        feature->set_means(feature_means);
        feature->set_std_devs(feature_std_devs);
        feature->set_mins(feature_mins);
        feature->set_maxes(feature_maxes);
    }

    _normalize_data(data, dim_count);

    motion_data = data.duplicate();

    schema_hash = compute_features_hash();
}

MMQueryOutput MMAnimationLibrary::query(const MMQueryInput& p_query_input) {
    // TODO: Use fancier search algorithms
    // TODO: Do this using an offset array instead
    TypedArray<StringName> animation_list = get_animation_list();
    int32_t dim_count = 0;
    PackedFloat32Array query_vector = PackedFloat32Array();
    for (int64_t feature_index = 0; feature_index < features.size(); feature_index++) {
        const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
        if (!feature) {
            continue;
        }
        PackedFloat32Array feature_data = feature->evaluate_runtime_data(p_query_input);
        feature->normalize(feature_data.ptrw());
        query_vector.append_array(feature_data);
        dim_count += feature->get_dimension_count();
    }

    float cost = FLT_MAX;
    MMQueryOutput result;

    for (int64_t start_frame_index = 0; start_frame_index < motion_data.size(); start_frame_index += dim_count) {
        int start_feature_index = start_frame_index;
        float frame_cost = 0.f;
        Dictionary feature_costs;
        for (int64_t feature_index = 0; feature_index < features.size(); feature_index++) {
            const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
            if (!feature) {
                continue;
            }

            const float feature_cost = feature->compute_cost(
                (query_vector.ptr() + start_feature_index - start_frame_index),
                (motion_data.ptr() + start_feature_index));

            feature_costs.get_or_add(feature->get_class(), feature_cost);
            frame_cost += feature_cost * feature->get_weight();
            start_feature_index += feature->get_dimension_count();
        }

        if (frame_cost < cost) {
            cost = frame_cost;
            result.cost = cost;
            result.matched_frame_data = motion_data.slice(start_frame_index, start_frame_index + dim_count);
            String library_name = get_path().get_file().get_basename() + "/";
            if (library_name.is_empty()) {
                library_name = get_name() + "/";
            }

            result.animation_match = library_name + UtilityFunctions::str(animation_list[db_anim_index[start_frame_index / dim_count]]);
            result.time_match = db_time_index[start_frame_index / dim_count];
            result.feature_costs = feature_costs;
        }
    }

    return result;
}

int64_t MMAnimationLibrary::get_dim_count() const {
    int64_t dim_count = 0;
    for (auto i = 0; i < features.size(); ++i) {
        MMFeature* f = Object::cast_to<MMFeature>(features[i]);
        dim_count += f->get_dimension_count();
    }

    return dim_count;
}

int64_t MMAnimationLibrary::get_animation_pose_count(String p_animation_name) const {
    TypedArray<StringName> animation_list = get_animation_list();
    Ref<Animation> animation = get_animation(p_animation_name);
    if (animation.is_null()) {
        return 0;
    }
    return static_cast<int32_t>(animation->get_length() * get_sampling_rate());
}

void MMAnimationLibrary::display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D& p_transform, String p_animation_name, int32_t p_pose_index) const {
    const int32_t anim_index = get_animation_list().find(p_animation_name);
    const int32_t dim_count = get_dim_count();
    int32_t start_frame_index = 0;
    TypedArray<StringName> animation_list = get_animation_list();
    for (size_t anim_index = 0; anim_index < animation_list.size(); anim_index++) {
        const StringName& anim_name = animation_list[anim_index];
        Ref<Animation> animation = get_animation(anim_name);
        if (anim_name == p_animation_name) {
            break;
        }

        const float animation_length = animation->get_length();
        const float time_step = 1.0f / get_sampling_rate();
        for (float time = 0; time < animation_length; time += time_step) {
            start_frame_index += dim_count;
        }
    }

    int32_t frame_index = start_frame_index + p_pose_index * dim_count;
    for (size_t feature_index = 0; feature_index < features.size(); feature_index++) {
        const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
        const float* frame_motion_data = motion_data.ptr() + frame_index;
        feature->display_data(p_gizmo, p_transform, frame_motion_data);
        frame_index += feature->get_dimension_count();
    }
}

int64_t MMAnimationLibrary::compute_features_hash() const {
    int64_t hash = 0;
    for (int64_t feature_index = 0; feature_index < features.size(); feature_index++) {
        MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
        TypedArray<Dictionary> feature_properties = feature->get_property_list();
        for (int64_t property_index = 0; property_index < feature_properties.size(); property_index++) {
            // TODO: This needs work, but works for now
            const Dictionary feature_property = Dictionary(feature_properties[property_index]);
            const String property_name = feature_property["name"];
            const uint32_t property_type = feature_property["type"];
            const bool property_is_stats =
                property_name == "means" ||
                property_name == "std_devs" ||
                property_name == "mins" ||
                property_name == "maxes";
            if (property_type != Variant::OBJECT &&
                property_type != Variant::NIL &&
                !property_is_stats) {
                hash = hash_combine(hash, property_name.hash());
                hash = hash_combine(hash, feature->get(property_name).hash());
            }
        }
    }
    return hash;
}

bool MMAnimationLibrary::needs_baking() const {
    return schema_hash != compute_features_hash();
}

void MMAnimationLibrary::_normalize_data(PackedFloat32Array& p_data, size_t p_dim_count) const {
    ERR_FAIL_COND(p_data.size() % p_dim_count != 0);

    for (int64_t frame_index = 0; frame_index < p_data.size(); frame_index += p_dim_count) {

        int dim_index = 0;
        for (int64_t feature_index = 0; feature_index < features.size(); feature_index++) {
            const MMFeature* feature = Object::cast_to<MMFeature>(features[feature_index]);
            feature->normalize(p_data.ptrw() + frame_index + dim_index);
            dim_index += feature->get_dimension_count();
        }
    }
}

void MMAnimationLibrary::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::ARRAY, features, PROPERTY_HINT_TYPE_STRING, UtilityFunctions::str(Variant::OBJECT) + '/' + UtilityFunctions::str(Variant::BASIS) + ":MMFeature");
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::FLOAT, sampling_rate);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::PACKED_FLOAT32_ARRAY, motion_data, PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::PACKED_INT32_ARRAY, db_anim_index, PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::PACKED_FLOAT32_ARRAY, db_time_index, PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE);
    BINDER_PROPERTY_PARAMS(MMAnimationLibrary, Variant::INT, schema_hash, PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE);
}
