/**************************************************************************/
/*  open_xrapi_extension.cpp                                              */
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

#include <godot_cpp/classes/open_xrapi_extension.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/open_xr_extension_wrapper_extension.hpp>
#include <godot_cpp/variant/array.hpp>

namespace godot {

uint64_t OpenXRAPIExtension::get_instance() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_instance")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner);
}

uint64_t OpenXRAPIExtension::get_system_id() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_system_id")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner);
}

uint64_t OpenXRAPIExtension::get_session() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_session")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner);
}

Transform3D OpenXRAPIExtension::transform_from_pose(const void *p_pose) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("transform_from_pose")._native_ptr(), 3255299855);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Transform3D());
	return internal::_call_native_mb_ret<Transform3D>(_gde_method_bind, _owner, &p_pose);
}

bool OpenXRAPIExtension::xr_result(uint64_t p_result, const String &p_format, const Array &p_args) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("xr_result")._native_ptr(), 3886436197);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	int64_t p_result_encoded;
	PtrToArg<int64_t>::encode(p_result, &p_result_encoded);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner, &p_result_encoded, &p_format, &p_args);
}

bool OpenXRAPIExtension::openxr_is_enabled(bool p_check_run_in_editor) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("openxr_is_enabled")._native_ptr(), 2703660260);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	int8_t p_check_run_in_editor_encoded;
	PtrToArg<bool>::encode(p_check_run_in_editor, &p_check_run_in_editor_encoded);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, nullptr, &p_check_run_in_editor_encoded);
}

uint64_t OpenXRAPIExtension::get_instance_proc_addr(const String &p_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_instance_proc_addr")._native_ptr(), 1597066294);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner, &p_name);
}

String OpenXRAPIExtension::get_error_string(uint64_t p_result) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_error_string")._native_ptr(), 990163283);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	int64_t p_result_encoded;
	PtrToArg<int64_t>::encode(p_result, &p_result_encoded);
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner, &p_result_encoded);
}

String OpenXRAPIExtension::get_swapchain_format_name(int64_t p_swapchain_format) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_swapchain_format_name")._native_ptr(), 990163283);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	int64_t p_swapchain_format_encoded;
	PtrToArg<int64_t>::encode(p_swapchain_format, &p_swapchain_format_encoded);
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner, &p_swapchain_format_encoded);
}

void OpenXRAPIExtension::set_object_name(int64_t p_object_type, uint64_t p_object_handle, const String &p_object_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("set_object_name")._native_ptr(), 2285447957);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_object_type_encoded;
	PtrToArg<int64_t>::encode(p_object_type, &p_object_type_encoded);
	int64_t p_object_handle_encoded;
	PtrToArg<int64_t>::encode(p_object_handle, &p_object_handle_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_object_type_encoded, &p_object_handle_encoded, &p_object_name);
}

void OpenXRAPIExtension::begin_debug_label_region(const String &p_label_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("begin_debug_label_region")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_label_name);
}

void OpenXRAPIExtension::end_debug_label_region() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("end_debug_label_region")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

void OpenXRAPIExtension::insert_debug_label(const String &p_label_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("insert_debug_label")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_label_name);
}

bool OpenXRAPIExtension::is_initialized() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("is_initialized")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

bool OpenXRAPIExtension::is_running() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("is_running")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

uint64_t OpenXRAPIExtension::get_play_space() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_play_space")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner);
}

int64_t OpenXRAPIExtension::get_predicted_display_time() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_predicted_display_time")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

int64_t OpenXRAPIExtension::get_next_frame_time() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_next_frame_time")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

bool OpenXRAPIExtension::can_render() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("can_render")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

uint64_t OpenXRAPIExtension::get_hand_tracker(int32_t p_hand_index) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("get_hand_tracker")._native_ptr(), 3744713108);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	int64_t p_hand_index_encoded;
	PtrToArg<int64_t>::encode(p_hand_index, &p_hand_index_encoded);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner, &p_hand_index_encoded);
}

void OpenXRAPIExtension::register_composition_layer_provider(OpenXRExtensionWrapperExtension *p_extension) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("register_composition_layer_provider")._native_ptr(), 1997997368);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_extension != nullptr ? &p_extension->_owner : nullptr));
}

void OpenXRAPIExtension::unregister_composition_layer_provider(OpenXRExtensionWrapperExtension *p_extension) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("unregister_composition_layer_provider")._native_ptr(), 1997997368);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_extension != nullptr ? &p_extension->_owner : nullptr));
}

void OpenXRAPIExtension::set_emulate_environment_blend_mode_alpha_blend(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("set_emulate_environment_blend_mode_alpha_blend")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

OpenXRAPIExtension::OpenXRAlphaBlendModeSupport OpenXRAPIExtension::is_environment_blend_mode_alpha_supported() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(OpenXRAPIExtension::get_class_static()._native_ptr(), StringName("is_environment_blend_mode_alpha_supported")._native_ptr(), 1579290861);
	CHECK_METHOD_BIND_RET(_gde_method_bind, OpenXRAPIExtension::OpenXRAlphaBlendModeSupport(0));
	return (OpenXRAPIExtension::OpenXRAlphaBlendModeSupport)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

} // namespace godot
