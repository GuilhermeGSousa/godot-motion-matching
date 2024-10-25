#include "mm_feature.h"

MMFeature::MMFeature() {
}

MMFeature::~MMFeature() {
}

void MMFeature::normalize(float* p_data) const {
    switch (normalization_mode) {
    case Standard:
        _normalize_standard(p_data);
        break;
    case MinMax:
        _normalize_minmax(p_data);
        break;
    case Raw:
    default:
        break;
    }
}

void MMFeature::denormalize(float* p_data) const {

    switch (normalization_mode) {
    case Standard:
        _denormalize_standard(p_data);
        break;
    case MinMax:
        _denormalize_minmax(p_data);
        break;
    case Raw:
    default:
        break;
    }
}

float MMFeature::compute_cost(const float* p_motion_data, const float* p_query_data) const {
    float cost = 0.0f;
    for (int i = 0; i < get_dimension_count(); ++i) {
        float diff = p_motion_data[i] - p_query_data[i];
        cost += diff * diff;
    }
    return cost / get_dimension_count();
}

void MMFeature::_normalize_minmax(float* p_data) const {
    for (int i = 0; i < get_dimension_count(); ++i) {
        p_data[i] = (p_data[i] - mins[i]) / (maxes[i] - mins[i]);
    }
}

void MMFeature::_denormalize_minmax(float* p_data) const {
    for (int i = 0; i < get_dimension_count(); ++i) {
        p_data[i] = (p_data[i] * (maxes[i] - mins[i])) + mins[i];
    }
}

void MMFeature::_normalize_standard(float* p_data) const {
    for (int i = 0; i < get_dimension_count(); ++i) {
        if (std_devs[i] < SMALL_NUMBER) {
            continue;
        }
        p_data[i] = (p_data[i] - means[i]) / std_devs[i];
    }
}

void MMFeature::_denormalize_standard(float* p_data) const {
    for (int i = 0; i < get_dimension_count(); ++i) {
        if (std_devs[i] < SMALL_NUMBER) {
            continue;
        }
        p_data[i] = (p_data[i] * std_devs[i]) + means[i];
    }
}

void MMFeature::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_dimension_count"), &MMFeature::get_dimension_count);

    ClassDB::bind_method(D_METHOD("set_normalization_mode", "value"), &MMFeature::set_normalization_mode, DEFVAL(MMFeature::NormalizationMode::Standard));

    ClassDB::bind_method(D_METHOD("get_normalization_mode"), &MMFeature::get_normalization_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "normalization_mode", PROPERTY_HINT_ENUM, "Raw,Standard,MinMax", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_ALWAYS_DUPLICATE), "set_normalization_mode", "get_normalization_mode");

    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, means);
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, std_devs);
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, maxes);
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, mins);

    BIND_ENUM_CONSTANT(Raw);
    BIND_ENUM_CONSTANT(Standard);
    BIND_ENUM_CONSTANT(MinMax);
}

VARIANT_ENUM_CAST(MMFeature::NormalizationMode);