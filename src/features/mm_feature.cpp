/**************************************************************************/
/*  mm_feature.cpp                                                        */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "mm_feature.h"

MMFeature::MMFeature() {
}

MMFeature::~MMFeature() {
}

void MMFeature::normalize(float* p_data) const {
    if (!p_data) {
        ERR_PRINT_ONCE("Invalid data provided in normalize.");
        return;
    }
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
    if (!p_data) {
        ERR_PRINT_ONCE("Invalid data provided in denormalize.");
        return;
    }
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
    for (int64_t i = 0; i < get_dimension_count(); ++i) {
        float diff = p_motion_data[i] - p_query_data[i];
        cost += diff * diff;
    }
    return cost / get_dimension_count();
}

void MMFeature::_normalize_minmax(float* p_data) const {
    if (!p_data) {
        ERR_PRINT_ONCE("Invalid data provided in _normalize_minmax.");
        return;
    }
    for (int64_t i = 0; i < get_dimension_count(); ++i) {
        p_data[i] = (p_data[i] - mins[i]) / (maxes[i] - mins[i]);
    }
}

void MMFeature::_denormalize_minmax(float* p_data) const {
    if (!p_data) {
        ERR_PRINT_ONCE("Invalid data provided in _denormalize_minmax.");
        return;
    }
    for (int64_t i = 0; i < get_dimension_count(); ++i) {
        p_data[i] = (p_data[i] * (maxes[i] - mins[i])) + mins[i];
    }
}

void MMFeature::_normalize_standard(float* p_data) const {
    if (!p_data) {
        ERR_PRINT_ONCE("Invalid data provided in _normalize_standard.");
        return;
    }
    for (int64_t i = 0; i < get_dimension_count(); ++i) {
        if (std_devs[i] < SMALL_NUMBER) {
            continue;
        }
        p_data[i] = (p_data[i] - means[i]) / std_devs[i];
    }
}

void MMFeature::_denormalize_standard(float* p_data) const {
    if (!p_data) {
        ERR_PRINT_ONCE("Invalid data provided in _denormalize_standard.");
        return;
    }
    for (int64_t i = 0; i < get_dimension_count(); ++i) {
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
