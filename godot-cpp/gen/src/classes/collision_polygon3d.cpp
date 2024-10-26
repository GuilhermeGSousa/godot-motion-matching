/**************************************************************************/
/*  collision_polygon3d.cpp                                               */
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

#include <godot_cpp/classes/collision_polygon3d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void CollisionPolygon3D::set_depth(float p_depth) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("set_depth")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_depth_encoded;
	PtrToArg<double>::encode(p_depth, &p_depth_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_depth_encoded);
}

float CollisionPolygon3D::get_depth() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("get_depth")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void CollisionPolygon3D::set_polygon(const PackedVector2Array &p_polygon) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("set_polygon")._native_ptr(), 1509147220);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_polygon);
}

PackedVector2Array CollisionPolygon3D::get_polygon() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("get_polygon")._native_ptr(), 2961356807);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedVector2Array());
	return internal::_call_native_mb_ret<PackedVector2Array>(_gde_method_bind, _owner);
}

void CollisionPolygon3D::set_disabled(bool p_disabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("set_disabled")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_disabled_encoded;
	PtrToArg<bool>::encode(p_disabled, &p_disabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_disabled_encoded);
}

bool CollisionPolygon3D::is_disabled() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("is_disabled")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void CollisionPolygon3D::set_margin(float p_margin) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("set_margin")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_margin_encoded;
	PtrToArg<double>::encode(p_margin, &p_margin_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_margin_encoded);
}

float CollisionPolygon3D::get_margin() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CollisionPolygon3D::get_class_static()._native_ptr(), StringName("get_margin")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

} // namespace godot
