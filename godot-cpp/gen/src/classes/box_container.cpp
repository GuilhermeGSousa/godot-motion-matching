/**************************************************************************/
/*  box_container.cpp                                                     */
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

#include <godot_cpp/classes/box_container.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/control.hpp>

namespace godot {

Control *BoxContainer::add_spacer(bool p_begin) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(BoxContainer::get_class_static()._native_ptr(), StringName("add_spacer")._native_ptr(), 1326660695);
	CHECK_METHOD_BIND_RET(_gde_method_bind, nullptr);
	int8_t p_begin_encoded;
	PtrToArg<bool>::encode(p_begin, &p_begin_encoded);
	return internal::_call_native_mb_ret_obj<Control>(_gde_method_bind, _owner, &p_begin_encoded);
}

void BoxContainer::set_alignment(BoxContainer::AlignmentMode p_alignment) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(BoxContainer::get_class_static()._native_ptr(), StringName("set_alignment")._native_ptr(), 2456745134);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_alignment);
}

BoxContainer::AlignmentMode BoxContainer::get_alignment() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(BoxContainer::get_class_static()._native_ptr(), StringName("get_alignment")._native_ptr(), 1915476527);
	CHECK_METHOD_BIND_RET(_gde_method_bind, BoxContainer::AlignmentMode(0));
	return (BoxContainer::AlignmentMode)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void BoxContainer::set_vertical(bool p_vertical) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(BoxContainer::get_class_static()._native_ptr(), StringName("set_vertical")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_vertical_encoded;
	PtrToArg<bool>::encode(p_vertical, &p_vertical_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_vertical_encoded);
}

bool BoxContainer::is_vertical() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(BoxContainer::get_class_static()._native_ptr(), StringName("is_vertical")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

} // namespace godot
