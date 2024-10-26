/**************************************************************************/
/*  xr_body_tracker.cpp                                                   */
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

#include <godot_cpp/classes/xr_body_tracker.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void XRBodyTracker::set_has_tracking_data(bool p_has_data) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("set_has_tracking_data")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_has_data_encoded;
	PtrToArg<bool>::encode(p_has_data, &p_has_data_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_has_data_encoded);
}

bool XRBodyTracker::get_has_tracking_data() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("get_has_tracking_data")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void XRBodyTracker::set_body_flags(BitField<XRBodyTracker::BodyFlags> p_flags) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("set_body_flags")._native_ptr(), 2103235750);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_flags);
}

BitField<XRBodyTracker::BodyFlags> XRBodyTracker::get_body_flags() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("get_body_flags")._native_ptr(), 3543166366);
	CHECK_METHOD_BIND_RET(_gde_method_bind, BitField<XRBodyTracker::BodyFlags>(0));
	return (int64_t)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void XRBodyTracker::set_joint_flags(XRBodyTracker::Joint p_joint, BitField<XRBodyTracker::JointFlags> p_flags) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("set_joint_flags")._native_ptr(), 592144999);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_joint, &p_flags);
}

BitField<XRBodyTracker::JointFlags> XRBodyTracker::get_joint_flags(XRBodyTracker::Joint p_joint) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("get_joint_flags")._native_ptr(), 1030162609);
	CHECK_METHOD_BIND_RET(_gde_method_bind, BitField<XRBodyTracker::JointFlags>(0));
	return (int64_t)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, &p_joint);
}

void XRBodyTracker::set_joint_transform(XRBodyTracker::Joint p_joint, const Transform3D &p_transform) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("set_joint_transform")._native_ptr(), 2635424328);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_joint, &p_transform);
}

Transform3D XRBodyTracker::get_joint_transform(XRBodyTracker::Joint p_joint) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(XRBodyTracker::get_class_static()._native_ptr(), StringName("get_joint_transform")._native_ptr(), 3474811534);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Transform3D());
	return internal::_call_native_mb_ret<Transform3D>(_gde_method_bind, _owner, &p_joint);
}

} // namespace godot
