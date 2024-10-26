/**************************************************************************/
/*  label_settings.cpp                                                    */
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

#include <godot_cpp/classes/label_settings.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/font.hpp>

namespace godot {

void LabelSettings::set_line_spacing(float p_spacing) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_line_spacing")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_spacing_encoded;
	PtrToArg<double>::encode(p_spacing, &p_spacing_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_spacing_encoded);
}

float LabelSettings::get_line_spacing() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_line_spacing")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void LabelSettings::set_font(const Ref<Font> &p_font) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_font")._native_ptr(), 1262170328);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_font != nullptr ? &p_font->_owner : nullptr));
}

Ref<Font> LabelSettings::get_font() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_font")._native_ptr(), 3229501585);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<Font>());
	return Ref<Font>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<Font>(_gde_method_bind, _owner));
}

void LabelSettings::set_font_size(int32_t p_size) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_font_size")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_size_encoded;
	PtrToArg<int64_t>::encode(p_size, &p_size_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_size_encoded);
}

int32_t LabelSettings::get_font_size() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_font_size")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void LabelSettings::set_font_color(const Color &p_color) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_font_color")._native_ptr(), 2920490490);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_color);
}

Color LabelSettings::get_font_color() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_font_color")._native_ptr(), 3444240500);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Color());
	return internal::_call_native_mb_ret<Color>(_gde_method_bind, _owner);
}

void LabelSettings::set_outline_size(int32_t p_size) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_outline_size")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_size_encoded;
	PtrToArg<int64_t>::encode(p_size, &p_size_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_size_encoded);
}

int32_t LabelSettings::get_outline_size() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_outline_size")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void LabelSettings::set_outline_color(const Color &p_color) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_outline_color")._native_ptr(), 2920490490);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_color);
}

Color LabelSettings::get_outline_color() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_outline_color")._native_ptr(), 3444240500);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Color());
	return internal::_call_native_mb_ret<Color>(_gde_method_bind, _owner);
}

void LabelSettings::set_shadow_size(int32_t p_size) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_shadow_size")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_size_encoded;
	PtrToArg<int64_t>::encode(p_size, &p_size_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_size_encoded);
}

int32_t LabelSettings::get_shadow_size() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_shadow_size")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void LabelSettings::set_shadow_color(const Color &p_color) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_shadow_color")._native_ptr(), 2920490490);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_color);
}

Color LabelSettings::get_shadow_color() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_shadow_color")._native_ptr(), 3444240500);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Color());
	return internal::_call_native_mb_ret<Color>(_gde_method_bind, _owner);
}

void LabelSettings::set_shadow_offset(const Vector2 &p_offset) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("set_shadow_offset")._native_ptr(), 743155724);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_offset);
}

Vector2 LabelSettings::get_shadow_offset() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(LabelSettings::get_class_static()._native_ptr(), StringName("get_shadow_offset")._native_ptr(), 3341600327);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Vector2());
	return internal::_call_native_mb_ret<Vector2>(_gde_method_bind, _owner);
}

} // namespace godot
