/**************************************************************************/
/*  editor_file_dialog.cpp                                                */
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

#include <godot_cpp/classes/editor_file_dialog.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/line_edit.hpp>
#include <godot_cpp/classes/v_box_container.hpp>

namespace godot {

void EditorFileDialog::clear_filters() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("clear_filters")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

void EditorFileDialog::add_filter(const String &p_filter, const String &p_description) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("add_filter")._native_ptr(), 3388804757);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_filter, &p_description);
}

void EditorFileDialog::set_filters(const PackedStringArray &p_filters) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_filters")._native_ptr(), 4015028928);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_filters);
}

PackedStringArray EditorFileDialog::get_filters() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_filters")._native_ptr(), 1139954409);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedStringArray());
	return internal::_call_native_mb_ret<PackedStringArray>(_gde_method_bind, _owner);
}

String EditorFileDialog::get_option_name(int32_t p_option) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_option_name")._native_ptr(), 844755477);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	int64_t p_option_encoded;
	PtrToArg<int64_t>::encode(p_option, &p_option_encoded);
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner, &p_option_encoded);
}

PackedStringArray EditorFileDialog::get_option_values(int32_t p_option) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_option_values")._native_ptr(), 647634434);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedStringArray());
	int64_t p_option_encoded;
	PtrToArg<int64_t>::encode(p_option, &p_option_encoded);
	return internal::_call_native_mb_ret<PackedStringArray>(_gde_method_bind, _owner, &p_option_encoded);
}

int32_t EditorFileDialog::get_option_default(int32_t p_option) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_option_default")._native_ptr(), 923996154);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	int64_t p_option_encoded;
	PtrToArg<int64_t>::encode(p_option, &p_option_encoded);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, &p_option_encoded);
}

void EditorFileDialog::set_option_name(int32_t p_option, const String &p_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_option_name")._native_ptr(), 501894301);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_option_encoded;
	PtrToArg<int64_t>::encode(p_option, &p_option_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_option_encoded, &p_name);
}

void EditorFileDialog::set_option_values(int32_t p_option, const PackedStringArray &p_values) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_option_values")._native_ptr(), 3353661094);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_option_encoded;
	PtrToArg<int64_t>::encode(p_option, &p_option_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_option_encoded, &p_values);
}

void EditorFileDialog::set_option_default(int32_t p_option, int32_t p_default_value_index) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_option_default")._native_ptr(), 3937882851);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_option_encoded;
	PtrToArg<int64_t>::encode(p_option, &p_option_encoded);
	int64_t p_default_value_index_encoded;
	PtrToArg<int64_t>::encode(p_default_value_index, &p_default_value_index_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_option_encoded, &p_default_value_index_encoded);
}

void EditorFileDialog::set_option_count(int32_t p_count) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_option_count")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_count_encoded;
	PtrToArg<int64_t>::encode(p_count, &p_count_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_count_encoded);
}

int32_t EditorFileDialog::get_option_count() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_option_count")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void EditorFileDialog::add_option(const String &p_name, const PackedStringArray &p_values, int32_t p_default_value_index) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("add_option")._native_ptr(), 149592325);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_default_value_index_encoded;
	PtrToArg<int64_t>::encode(p_default_value_index, &p_default_value_index_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_name, &p_values, &p_default_value_index_encoded);
}

Dictionary EditorFileDialog::get_selected_options() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_selected_options")._native_ptr(), 3102165223);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Dictionary());
	return internal::_call_native_mb_ret<Dictionary>(_gde_method_bind, _owner);
}

String EditorFileDialog::get_current_dir() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_current_dir")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

String EditorFileDialog::get_current_file() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_current_file")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

String EditorFileDialog::get_current_path() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_current_path")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

void EditorFileDialog::set_current_dir(const String &p_dir) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_current_dir")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_dir);
}

void EditorFileDialog::set_current_file(const String &p_file) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_current_file")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_file);
}

void EditorFileDialog::set_current_path(const String &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_current_path")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path);
}

void EditorFileDialog::set_file_mode(EditorFileDialog::FileMode p_mode) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_file_mode")._native_ptr(), 274150415);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_mode);
}

EditorFileDialog::FileMode EditorFileDialog::get_file_mode() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_file_mode")._native_ptr(), 2681044145);
	CHECK_METHOD_BIND_RET(_gde_method_bind, EditorFileDialog::FileMode(0));
	return (EditorFileDialog::FileMode)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

VBoxContainer *EditorFileDialog::get_vbox() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_vbox")._native_ptr(), 915758477);
	CHECK_METHOD_BIND_RET(_gde_method_bind, nullptr);
	return internal::_call_native_mb_ret_obj<VBoxContainer>(_gde_method_bind, _owner);
}

LineEdit *EditorFileDialog::get_line_edit() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_line_edit")._native_ptr(), 4071694264);
	CHECK_METHOD_BIND_RET(_gde_method_bind, nullptr);
	return internal::_call_native_mb_ret_obj<LineEdit>(_gde_method_bind, _owner);
}

void EditorFileDialog::set_access(EditorFileDialog::Access p_access) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_access")._native_ptr(), 3882893764);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_access);
}

EditorFileDialog::Access EditorFileDialog::get_access() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_access")._native_ptr(), 778734016);
	CHECK_METHOD_BIND_RET(_gde_method_bind, EditorFileDialog::Access(0));
	return (EditorFileDialog::Access)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void EditorFileDialog::set_show_hidden_files(bool p_show) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_show_hidden_files")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_show_encoded;
	PtrToArg<bool>::encode(p_show, &p_show_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_show_encoded);
}

bool EditorFileDialog::is_showing_hidden_files() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("is_showing_hidden_files")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void EditorFileDialog::set_display_mode(EditorFileDialog::DisplayMode p_mode) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_display_mode")._native_ptr(), 3049004050);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_mode);
}

EditorFileDialog::DisplayMode EditorFileDialog::get_display_mode() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("get_display_mode")._native_ptr(), 3517174669);
	CHECK_METHOD_BIND_RET(_gde_method_bind, EditorFileDialog::DisplayMode(0));
	return (EditorFileDialog::DisplayMode)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void EditorFileDialog::set_disable_overwrite_warning(bool p_disable) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("set_disable_overwrite_warning")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_disable_encoded;
	PtrToArg<bool>::encode(p_disable, &p_disable_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_disable_encoded);
}

bool EditorFileDialog::is_overwrite_warning_disabled() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("is_overwrite_warning_disabled")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void EditorFileDialog::add_side_menu(Control *p_menu, const String &p_title) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("add_side_menu")._native_ptr(), 402368861);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_menu != nullptr ? &p_menu->_owner : nullptr), &p_title);
}

void EditorFileDialog::popup_file_dialog() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("popup_file_dialog")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

void EditorFileDialog::invalidate() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(EditorFileDialog::get_class_static()._native_ptr(), StringName("invalidate")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

} // namespace godot
