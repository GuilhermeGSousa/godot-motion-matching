#include "mm_feature.h"

MMFeature::MMFeature() {
}

MMFeature::~MMFeature() {
}

void MMFeature::normalize(PackedFloat32Array& p_data) const {
    for (int i = 0; i < p_data.size(); ++i) {
        p_data.set(i, (p_data[i] - mean) / std_dev);
    }
}

void MMFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::FLOAT, mean);
    BINDER_PROPERTY_PARAMS(MMFeature, Variant::FLOAT, std_dev);
}