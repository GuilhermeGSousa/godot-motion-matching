/**************************************************************************/
/*  camera_feed.cpp                                                       */
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

#include <godot_cpp/classes/camera_feed.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/variant/dictionary.hpp>

namespace godot {

int32_t CameraFeed::get_id() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("get_id")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

bool CameraFeed::is_active() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("is_active")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void CameraFeed::set_active(bool p_active) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("set_active")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_active_encoded;
	PtrToArg<bool>::encode(p_active, &p_active_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_active_encoded);
}

String CameraFeed::get_name() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("get_name")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

void CameraFeed::set_name(const String &p_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("set_name")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_name);
}

CameraFeed::FeedPosition CameraFeed::get_position() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("get_position")._native_ptr(), 2711679033);
	CHECK_METHOD_BIND_RET(_gde_method_bind, CameraFeed::FeedPosition(0));
	return (CameraFeed::FeedPosition)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void CameraFeed::set_position(CameraFeed::FeedPosition p_position) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("set_position")._native_ptr(), 611162623);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_position);
}

Transform2D CameraFeed::get_transform() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("get_transform")._native_ptr(), 3814499831);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Transform2D());
	return internal::_call_native_mb_ret<Transform2D>(_gde_method_bind, _owner);
}

void CameraFeed::set_transform(const Transform2D &p_transform) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("set_transform")._native_ptr(), 2761652528);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_transform);
}

void CameraFeed::set_rgb_image(const Ref<Image> &p_rgb_image) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("set_rgb_image")._native_ptr(), 532598488);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_rgb_image != nullptr ? &p_rgb_image->_owner : nullptr));
}

void CameraFeed::set_ycbcr_image(const Ref<Image> &p_ycbcr_image) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("set_ycbcr_image")._native_ptr(), 532598488);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_ycbcr_image != nullptr ? &p_ycbcr_image->_owner : nullptr));
}

CameraFeed::FeedDataType CameraFeed::get_datatype() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("get_datatype")._native_ptr(), 1477782850);
	CHECK_METHOD_BIND_RET(_gde_method_bind, CameraFeed::FeedDataType(0));
	return (CameraFeed::FeedDataType)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

Array CameraFeed::get_formats() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("get_formats")._native_ptr(), 3995934104);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Array());
	return internal::_call_native_mb_ret<Array>(_gde_method_bind, _owner);
}

bool CameraFeed::set_format(int32_t p_index, const Dictionary &p_parameters) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(CameraFeed::get_class_static()._native_ptr(), StringName("set_format")._native_ptr(), 31872775);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	int64_t p_index_encoded;
	PtrToArg<int64_t>::encode(p_index, &p_index_encoded);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner, &p_index_encoded, &p_parameters);
}

} // namespace godot
