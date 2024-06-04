#include "mm_feature.h"

#include <godot_cpp/core/error_macros.hpp>

MMFeature::MMFeature() {
}

MMFeature::~MMFeature() {
}

void MMFeature::normalize(PackedFloat32Array& p_data) const {
    ERR_FAIL_COND(p_data.size() != get_dimension_count());

    for (int i = 0; i < p_data.size(); ++i) {
        if (std_devs[i] < SMALL_NUMBER) {
            continue;
        }
        p_data.set(i, (p_data[i] - means[i]) / std_devs[i]);
    }
}

void MMFeature::denormalize(PackedFloat32Array& p_data) const {
    ERR_FAIL_COND(p_data.size() != get_dimension_count());

    for (int i = 0; i < p_data.size(); ++i) {
        if (std_devs[i] < SMALL_NUMBER) {
            continue;
        }
        p_data.set(i, p_data[i] * std_devs[i] + means[i]);
    }
}

void MMFeature::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_dimension_count"), &MMFeature::get_dimension_count);

    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, means);
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, std_devs);
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, maxes);
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::PACKED_FLOAT32_ARRAY, mins);
}