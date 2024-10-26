/**************************************************************************/
/*  navigation_agent3d.cpp                                                */
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

// THIS FILE IS GENERATED. EDITS WILL BE LOST.

#include <godot_cpp/classes/navigation_agent3d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/navigation_path_query_result3d.hpp>

namespace godot {

RID NavigationAgent3D::get_rid() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_rid")._native_ptr(), 2944877500);
	CHECK_METHOD_BIND_RET(_gde_method_bind, RID());
	return internal::_call_native_mb_ret<RID>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_avoidance_enabled(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_avoidance_enabled")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

bool NavigationAgent3D::get_avoidance_enabled() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_avoidance_enabled")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_path_desired_distance(float p_desired_distance) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_path_desired_distance")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_desired_distance_encoded;
	PtrToArg<double>::encode(p_desired_distance, &p_desired_distance_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_desired_distance_encoded);
}

float NavigationAgent3D::get_path_desired_distance() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_path_desired_distance")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_target_desired_distance(float p_desired_distance) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_target_desired_distance")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_desired_distance_encoded;
	PtrToArg<double>::encode(p_desired_distance, &p_desired_distance_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_desired_distance_encoded);
}

float NavigationAgent3D::get_target_desired_distance() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_target_desired_distance")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_radius(float p_radius) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_radius")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_radius_encoded;
	PtrToArg<double>::encode(p_radius, &p_radius_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_radius_encoded);
}

float NavigationAgent3D::get_radius() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_radius")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_height(float p_height) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_height")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_height_encoded;
	PtrToArg<double>::encode(p_height, &p_height_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_height_encoded);
}

float NavigationAgent3D::get_height() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_height")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_path_height_offset(float p_path_height_offset) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_path_height_offset")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_path_height_offset_encoded;
	PtrToArg<double>::encode(p_path_height_offset, &p_path_height_offset_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path_height_offset_encoded);
}

float NavigationAgent3D::get_path_height_offset() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_path_height_offset")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_use_3d_avoidance(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_use_3d_avoidance")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

bool NavigationAgent3D::get_use_3d_avoidance() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_use_3d_avoidance")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_keep_y_velocity(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_keep_y_velocity")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

bool NavigationAgent3D::get_keep_y_velocity() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_keep_y_velocity")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_neighbor_distance(float p_neighbor_distance) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_neighbor_distance")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_neighbor_distance_encoded;
	PtrToArg<double>::encode(p_neighbor_distance, &p_neighbor_distance_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_neighbor_distance_encoded);
}

float NavigationAgent3D::get_neighbor_distance() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_neighbor_distance")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_max_neighbors(int32_t p_max_neighbors) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_max_neighbors")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_max_neighbors_encoded;
	PtrToArg<int64_t>::encode(p_max_neighbors, &p_max_neighbors_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_max_neighbors_encoded);
}

int32_t NavigationAgent3D::get_max_neighbors() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_max_neighbors")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_time_horizon_agents(float p_time_horizon) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_time_horizon_agents")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_time_horizon_encoded;
	PtrToArg<double>::encode(p_time_horizon, &p_time_horizon_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_time_horizon_encoded);
}

float NavigationAgent3D::get_time_horizon_agents() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_time_horizon_agents")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_time_horizon_obstacles(float p_time_horizon) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_time_horizon_obstacles")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_time_horizon_encoded;
	PtrToArg<double>::encode(p_time_horizon, &p_time_horizon_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_time_horizon_encoded);
}

float NavigationAgent3D::get_time_horizon_obstacles() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_time_horizon_obstacles")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_max_speed(float p_max_speed) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_max_speed")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_max_speed_encoded;
	PtrToArg<double>::encode(p_max_speed, &p_max_speed_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_max_speed_encoded);
}

float NavigationAgent3D::get_max_speed() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_max_speed")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_path_max_distance(float p_max_speed) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_path_max_distance")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_max_speed_encoded;
	PtrToArg<double>::encode(p_max_speed, &p_max_speed_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_max_speed_encoded);
}

float NavigationAgent3D::get_path_max_distance() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_path_max_distance")._native_ptr(), 191475506);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_navigation_layers(uint32_t p_navigation_layers) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_navigation_layers")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_navigation_layers_encoded;
	PtrToArg<int64_t>::encode(p_navigation_layers, &p_navigation_layers_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_navigation_layers_encoded);
}

uint32_t NavigationAgent3D::get_navigation_layers() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_navigation_layers")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_navigation_layer_value(int32_t p_layer_number, bool p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_navigation_layer_value")._native_ptr(), 300928843);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_layer_number_encoded;
	PtrToArg<int64_t>::encode(p_layer_number, &p_layer_number_encoded);
	int8_t p_value_encoded;
	PtrToArg<bool>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_layer_number_encoded, &p_value_encoded);
}

bool NavigationAgent3D::get_navigation_layer_value(int32_t p_layer_number) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_navigation_layer_value")._native_ptr(), 1116898809);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	int64_t p_layer_number_encoded;
	PtrToArg<int64_t>::encode(p_layer_number, &p_layer_number_encoded);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner, &p_layer_number_encoded);
}

void NavigationAgent3D::set_pathfinding_algorithm(NavigationPathQueryParameters3D::PathfindingAlgorithm p_pathfinding_algorithm) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_pathfinding_algorithm")._native_ptr(), 394560454);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_pathfinding_algorithm);
}

NavigationPathQueryParameters3D::PathfindingAlgorithm NavigationAgent3D::get_pathfinding_algorithm() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_pathfinding_algorithm")._native_ptr(), 3398491350);
	CHECK_METHOD_BIND_RET(_gde_method_bind, NavigationPathQueryParameters3D::PathfindingAlgorithm(0));
	return (NavigationPathQueryParameters3D::PathfindingAlgorithm)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_path_postprocessing(NavigationPathQueryParameters3D::PathPostProcessing p_path_postprocessing) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_path_postprocessing")._native_ptr(), 2267362344);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path_postprocessing);
}

NavigationPathQueryParameters3D::PathPostProcessing NavigationAgent3D::get_path_postprocessing() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_path_postprocessing")._native_ptr(), 3883858360);
	CHECK_METHOD_BIND_RET(_gde_method_bind, NavigationPathQueryParameters3D::PathPostProcessing(0));
	return (NavigationPathQueryParameters3D::PathPostProcessing)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_path_metadata_flags(BitField<NavigationPathQueryParameters3D::PathMetadataFlags> p_flags) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_path_metadata_flags")._native_ptr(), 2713846708);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_flags);
}

BitField<NavigationPathQueryParameters3D::PathMetadataFlags> NavigationAgent3D::get_path_metadata_flags() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_path_metadata_flags")._native_ptr(), 1582332802);
	CHECK_METHOD_BIND_RET(_gde_method_bind, BitField<NavigationPathQueryParameters3D::PathMetadataFlags>(0));
	return (int64_t)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_navigation_map(const RID &p_navigation_map) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_navigation_map")._native_ptr(), 2722037293);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_navigation_map);
}

RID NavigationAgent3D::get_navigation_map() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_navigation_map")._native_ptr(), 2944877500);
	CHECK_METHOD_BIND_RET(_gde_method_bind, RID());
	return internal::_call_native_mb_ret<RID>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_target_position(const Vector3 &p_position) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_target_position")._native_ptr(), 3460891852);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_position);
}

Vector3 NavigationAgent3D::get_target_position() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_target_position")._native_ptr(), 3360562783);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector3());
	return internal::_call_native_mb_ret<Vector3>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_simplify_path(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_simplify_path")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

bool NavigationAgent3D::get_simplify_path() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_simplify_path")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_simplify_epsilon(float p_epsilon) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_simplify_epsilon")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_epsilon_encoded;
	PtrToArg<double>::encode(p_epsilon, &p_epsilon_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_epsilon_encoded);
}

float NavigationAgent3D::get_simplify_epsilon() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_simplify_epsilon")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

Vector3 NavigationAgent3D::get_next_path_position() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_next_path_position")._native_ptr(), 3783033775);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector3());
	return internal::_call_native_mb_ret<Vector3>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_velocity_forced(const Vector3 &p_velocity) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_velocity_forced")._native_ptr(), 3460891852);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_velocity);
}

void NavigationAgent3D::set_velocity(const Vector3 &p_velocity) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_velocity")._native_ptr(), 3460891852);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_velocity);
}

Vector3 NavigationAgent3D::get_velocity() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_velocity")._native_ptr(), 3783033775);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector3());
	return internal::_call_native_mb_ret<Vector3>(_gde_method_bind, _owner);
}

float NavigationAgent3D::distance_to_target() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("distance_to_target")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

Ref<NavigationPathQueryResult3D> NavigationAgent3D::get_current_navigation_result() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_current_navigation_result")._native_ptr(), 728825684);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<NavigationPathQueryResult3D>());
	return Ref<NavigationPathQueryResult3D>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<NavigationPathQueryResult3D>(_gde_method_bind, _owner));
}

PackedVector3Array NavigationAgent3D::get_current_navigation_path() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_current_navigation_path")._native_ptr(), 497664490);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedVector3Array());
	return internal::_call_native_mb_ret<PackedVector3Array>(_gde_method_bind, _owner);
}

int32_t NavigationAgent3D::get_current_navigation_path_index() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_current_navigation_path_index")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

bool NavigationAgent3D::is_target_reached() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("is_target_reached")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

bool NavigationAgent3D::is_target_reachable() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("is_target_reachable")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

bool NavigationAgent3D::is_navigation_finished() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("is_navigation_finished")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

Vector3 NavigationAgent3D::get_final_position() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_final_position")._native_ptr(), 3783033775);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector3());
	return internal::_call_native_mb_ret<Vector3>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_avoidance_layers(uint32_t p_layers) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_avoidance_layers")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_layers_encoded;
	PtrToArg<int64_t>::encode(p_layers, &p_layers_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_layers_encoded);
}

uint32_t NavigationAgent3D::get_avoidance_layers() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_avoidance_layers")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_avoidance_mask(uint32_t p_mask) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_avoidance_mask")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_mask_encoded;
	PtrToArg<int64_t>::encode(p_mask, &p_mask_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_mask_encoded);
}

uint32_t NavigationAgent3D::get_avoidance_mask() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_avoidance_mask")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_avoidance_layer_value(int32_t p_layer_number, bool p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_avoidance_layer_value")._native_ptr(), 300928843);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_layer_number_encoded;
	PtrToArg<int64_t>::encode(p_layer_number, &p_layer_number_encoded);
	int8_t p_value_encoded;
	PtrToArg<bool>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_layer_number_encoded, &p_value_encoded);
}

bool NavigationAgent3D::get_avoidance_layer_value(int32_t p_layer_number) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_avoidance_layer_value")._native_ptr(), 1116898809);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	int64_t p_layer_number_encoded;
	PtrToArg<int64_t>::encode(p_layer_number, &p_layer_number_encoded);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner, &p_layer_number_encoded);
}

void NavigationAgent3D::set_avoidance_mask_value(int32_t p_mask_number, bool p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_avoidance_mask_value")._native_ptr(), 300928843);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_mask_number_encoded;
	PtrToArg<int64_t>::encode(p_mask_number, &p_mask_number_encoded);
	int8_t p_value_encoded;
	PtrToArg<bool>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_mask_number_encoded, &p_value_encoded);
}

bool NavigationAgent3D::get_avoidance_mask_value(int32_t p_mask_number) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_avoidance_mask_value")._native_ptr(), 1116898809);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	int64_t p_mask_number_encoded;
	PtrToArg<int64_t>::encode(p_mask_number, &p_mask_number_encoded);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner, &p_mask_number_encoded);
}

void NavigationAgent3D::set_avoidance_priority(float p_priority) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_avoidance_priority")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_priority_encoded;
	PtrToArg<double>::encode(p_priority, &p_priority_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_priority_encoded);
}

float NavigationAgent3D::get_avoidance_priority() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_avoidance_priority")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_debug_enabled(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_debug_enabled")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

bool NavigationAgent3D::get_debug_enabled() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_debug_enabled")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_debug_use_custom(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_debug_use_custom")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

bool NavigationAgent3D::get_debug_use_custom() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_debug_use_custom")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_debug_path_custom_color(const Color &p_color) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_debug_path_custom_color")._native_ptr(), 2920490490);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_color);
}

Color NavigationAgent3D::get_debug_path_custom_color() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_debug_path_custom_color")._native_ptr(), 3444240500);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Color());
	return internal::_call_native_mb_ret<Color>(_gde_method_bind, _owner);
}

void NavigationAgent3D::set_debug_path_custom_point_size(float p_point_size) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("set_debug_path_custom_point_size")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_point_size_encoded;
	PtrToArg<double>::encode(p_point_size, &p_point_size_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_point_size_encoded);
}

float NavigationAgent3D::get_debug_path_custom_point_size() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationAgent3D::get_class_static()._native_ptr(), StringName("get_debug_path_custom_point_size")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

} // namespace godot
