/**************************************************************************/
/*  remote_transform2d.cpp                                                */
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

#include <godot_cpp/classes/remote_transform2d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void RemoteTransform2D::set_remote_node(const NodePath &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("set_remote_node")._native_ptr(), 1348162250);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path);
}

NodePath RemoteTransform2D::get_remote_node() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("get_remote_node")._native_ptr(), 4075236667);
	CHECK_METHOD_BIND_RET(_gde_method_bind, NodePath());
	return internal::_call_native_mb_ret<NodePath>(_gde_method_bind, _owner);
}

void RemoteTransform2D::force_update_cache() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("force_update_cache")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

void RemoteTransform2D::set_use_global_coordinates(bool p_use_global_coordinates) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("set_use_global_coordinates")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_use_global_coordinates_encoded;
	PtrToArg<bool>::encode(p_use_global_coordinates, &p_use_global_coordinates_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_use_global_coordinates_encoded);
}

bool RemoteTransform2D::get_use_global_coordinates() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("get_use_global_coordinates")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void RemoteTransform2D::set_update_position(bool p_update_remote_position) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("set_update_position")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_update_remote_position_encoded;
	PtrToArg<bool>::encode(p_update_remote_position, &p_update_remote_position_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_update_remote_position_encoded);
}

bool RemoteTransform2D::get_update_position() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("get_update_position")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void RemoteTransform2D::set_update_rotation(bool p_update_remote_rotation) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("set_update_rotation")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_update_remote_rotation_encoded;
	PtrToArg<bool>::encode(p_update_remote_rotation, &p_update_remote_rotation_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_update_remote_rotation_encoded);
}

bool RemoteTransform2D::get_update_rotation() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("get_update_rotation")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void RemoteTransform2D::set_update_scale(bool p_update_remote_scale) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("set_update_scale")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_update_remote_scale_encoded;
	PtrToArg<bool>::encode(p_update_remote_scale, &p_update_remote_scale_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_update_remote_scale_encoded);
}

bool RemoteTransform2D::get_update_scale() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(RemoteTransform2D::get_class_static()._native_ptr(), StringName("get_update_scale")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

} // namespace godot
