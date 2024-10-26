/**************************************************************************/
/*  hinge_joint3d.cpp                                                     */
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

#include <godot_cpp/classes/hinge_joint3d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void HingeJoint3D::set_param(HingeJoint3D::Param p_param, float p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(HingeJoint3D::get_class_static()._native_ptr(), StringName("set_param")._native_ptr(), 3082977519);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_value_encoded;
	PtrToArg<double>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_param, &p_value_encoded);
}

float HingeJoint3D::get_param(HingeJoint3D::Param p_param) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(HingeJoint3D::get_class_static()._native_ptr(), StringName("get_param")._native_ptr(), 4066002676);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner, &p_param);
}

void HingeJoint3D::set_flag(HingeJoint3D::Flag p_flag, bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(HingeJoint3D::get_class_static()._native_ptr(), StringName("set_flag")._native_ptr(), 1083494620);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_flag, &p_enabled_encoded);
}

bool HingeJoint3D::get_flag(HingeJoint3D::Flag p_flag) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(HingeJoint3D::get_class_static()._native_ptr(), StringName("get_flag")._native_ptr(), 2841369610);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner, &p_flag);
}

} // namespace godot
