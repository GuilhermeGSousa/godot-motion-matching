/**************************************************************************/
/*  navigation_path_query_parameters3d.cpp                                */
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

#include <godot_cpp/classes/navigation_path_query_parameters3d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void NavigationPathQueryParameters3D::set_pathfinding_algorithm(NavigationPathQueryParameters3D::PathfindingAlgorithm p_pathfinding_algorithm) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_pathfinding_algorithm")._native_ptr(), 394560454);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_pathfinding_algorithm);
}

NavigationPathQueryParameters3D::PathfindingAlgorithm NavigationPathQueryParameters3D::get_pathfinding_algorithm() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_pathfinding_algorithm")._native_ptr(), 3398491350);
	CHECK_METHOD_BIND_RET(_gde_method_bind, NavigationPathQueryParameters3D::PathfindingAlgorithm(0));
	return (NavigationPathQueryParameters3D::PathfindingAlgorithm)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_path_postprocessing(NavigationPathQueryParameters3D::PathPostProcessing p_path_postprocessing) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_path_postprocessing")._native_ptr(), 2267362344);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path_postprocessing);
}

NavigationPathQueryParameters3D::PathPostProcessing NavigationPathQueryParameters3D::get_path_postprocessing() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_path_postprocessing")._native_ptr(), 3883858360);
	CHECK_METHOD_BIND_RET(_gde_method_bind, NavigationPathQueryParameters3D::PathPostProcessing(0));
	return (NavigationPathQueryParameters3D::PathPostProcessing)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_map(const RID &p_map) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_map")._native_ptr(), 2722037293);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_map);
}

RID NavigationPathQueryParameters3D::get_map() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_map")._native_ptr(), 2944877500);
	CHECK_METHOD_BIND_RET(_gde_method_bind, RID());
	return internal::_call_native_mb_ret<RID>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_start_position(const Vector3 &p_start_position) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_start_position")._native_ptr(), 3460891852);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_start_position);
}

Vector3 NavigationPathQueryParameters3D::get_start_position() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_start_position")._native_ptr(), 3360562783);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector3());
	return internal::_call_native_mb_ret<Vector3>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_target_position(const Vector3 &p_target_position) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_target_position")._native_ptr(), 3460891852);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_target_position);
}

Vector3 NavigationPathQueryParameters3D::get_target_position() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_target_position")._native_ptr(), 3360562783);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector3());
	return internal::_call_native_mb_ret<Vector3>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_navigation_layers(uint32_t p_navigation_layers) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_navigation_layers")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_navigation_layers_encoded;
	PtrToArg<int64_t>::encode(p_navigation_layers, &p_navigation_layers_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_navigation_layers_encoded);
}

uint32_t NavigationPathQueryParameters3D::get_navigation_layers() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_navigation_layers")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_metadata_flags(BitField<NavigationPathQueryParameters3D::PathMetadataFlags> p_flags) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_metadata_flags")._native_ptr(), 2713846708);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_flags);
}

BitField<NavigationPathQueryParameters3D::PathMetadataFlags> NavigationPathQueryParameters3D::get_metadata_flags() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_metadata_flags")._native_ptr(), 1582332802);
	CHECK_METHOD_BIND_RET(_gde_method_bind, BitField<NavigationPathQueryParameters3D::PathMetadataFlags>(0));
	return (int64_t)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_simplify_path(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_simplify_path")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

bool NavigationPathQueryParameters3D::get_simplify_path() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_simplify_path")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void NavigationPathQueryParameters3D::set_simplify_epsilon(float p_epsilon) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("set_simplify_epsilon")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_epsilon_encoded;
	PtrToArg<double>::encode(p_epsilon, &p_epsilon_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_epsilon_encoded);
}

float NavigationPathQueryParameters3D::get_simplify_epsilon() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryParameters3D::get_class_static()._native_ptr(), StringName("get_simplify_epsilon")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

} // namespace godot
