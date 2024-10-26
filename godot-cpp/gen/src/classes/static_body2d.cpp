/**************************************************************************/
/*  static_body2d.cpp                                                     */
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

#include <godot_cpp/classes/static_body2d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/physics_material.hpp>

namespace godot {

void StaticBody2D::set_constant_linear_velocity(const Vector2 &p_vel) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StaticBody2D::get_class_static()._native_ptr(), StringName("set_constant_linear_velocity")._native_ptr(), 743155724);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_vel);
}

void StaticBody2D::set_constant_angular_velocity(float p_vel) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StaticBody2D::get_class_static()._native_ptr(), StringName("set_constant_angular_velocity")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_vel_encoded;
	PtrToArg<double>::encode(p_vel, &p_vel_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_vel_encoded);
}

Vector2 StaticBody2D::get_constant_linear_velocity() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StaticBody2D::get_class_static()._native_ptr(), StringName("get_constant_linear_velocity")._native_ptr(), 3341600327);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector2());
	return internal::_call_native_mb_ret<Vector2>(_gde_method_bind, _owner);
}

float StaticBody2D::get_constant_angular_velocity() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StaticBody2D::get_class_static()._native_ptr(), StringName("get_constant_angular_velocity")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void StaticBody2D::set_physics_material_override(const Ref<PhysicsMaterial> &p_physics_material_override) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StaticBody2D::get_class_static()._native_ptr(), StringName("set_physics_material_override")._native_ptr(), 1784508650);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_physics_material_override != nullptr ? &p_physics_material_override->_owner : nullptr));
}

Ref<PhysicsMaterial> StaticBody2D::get_physics_material_override() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StaticBody2D::get_class_static()._native_ptr(), StringName("get_physics_material_override")._native_ptr(), 2521850424);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<PhysicsMaterial>());
	return Ref<PhysicsMaterial>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<PhysicsMaterial>(_gde_method_bind, _owner));
}

} // namespace godot
