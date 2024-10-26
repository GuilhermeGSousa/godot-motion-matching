/**************************************************************************/
/*  navigation_path_query_result2d.cpp                                    */
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

#include <godot_cpp/classes/navigation_path_query_result2d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void NavigationPathQueryResult2D::set_path(const PackedVector2Array &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("set_path")._native_ptr(), 1509147220);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path);
}

PackedVector2Array NavigationPathQueryResult2D::get_path() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("get_path")._native_ptr(), 2961356807);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedVector2Array());
	return internal::_call_native_mb_ret<PackedVector2Array>(_gde_method_bind, _owner);
}

void NavigationPathQueryResult2D::set_path_types(const PackedInt32Array &p_path_types) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("set_path_types")._native_ptr(), 3614634198);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path_types);
}

PackedInt32Array NavigationPathQueryResult2D::get_path_types() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("get_path_types")._native_ptr(), 1930428628);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedInt32Array());
	return internal::_call_native_mb_ret<PackedInt32Array>(_gde_method_bind, _owner);
}

void NavigationPathQueryResult2D::set_path_rids(const TypedArray<RID> &p_path_rids) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("set_path_rids")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path_rids);
}

TypedArray<RID> NavigationPathQueryResult2D::get_path_rids() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("get_path_rids")._native_ptr(), 3995934104);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<RID>());
	return internal::_call_native_mb_ret<TypedArray<RID>>(_gde_method_bind, _owner);
}

void NavigationPathQueryResult2D::set_path_owner_ids(const PackedInt64Array &p_path_owner_ids) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("set_path_owner_ids")._native_ptr(), 3709968205);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_path_owner_ids);
}

PackedInt64Array NavigationPathQueryResult2D::get_path_owner_ids() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("get_path_owner_ids")._native_ptr(), 235988956);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedInt64Array());
	return internal::_call_native_mb_ret<PackedInt64Array>(_gde_method_bind, _owner);
}

void NavigationPathQueryResult2D::reset() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(NavigationPathQueryResult2D::get_class_static()._native_ptr(), StringName("reset")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

} // namespace godot
