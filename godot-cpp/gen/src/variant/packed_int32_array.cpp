/**************************************************************************/
/*  packed_int32_array.cpp                                                */
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

#include <godot_cpp/variant/packed_int32_array.hpp>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/godot.hpp>

#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/core/builtin_ptrcall.hpp>

#include <utility>

namespace godot {

PackedInt32Array::_MethodBindings PackedInt32Array::_method_bindings;

void PackedInt32Array::_init_bindings_constructors_destructor() {
	_method_bindings.from_variant_constructor = internal::gdextension_interface_get_variant_to_type_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
	_method_bindings.constructor_0 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, 0);
	_method_bindings.constructor_1 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, 1);
	_method_bindings.constructor_2 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, 2);
	_method_bindings.destructor = internal::gdextension_interface_variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
}
void PackedInt32Array::init_bindings() {
	PackedInt32Array::_init_bindings_constructors_destructor();
	StringName _gde_name;
	_gde_name = StringName("get");
	_method_bindings.method_get = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 4103005248);
	_gde_name = StringName("size");
	_method_bindings.method_size = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 3173160232);
	_gde_name = StringName("is_empty");
	_method_bindings.method_is_empty = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("set");
	_method_bindings.method_set = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 3638975848);
	_gde_name = StringName("push_back");
	_method_bindings.method_push_back = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 694024632);
	_gde_name = StringName("append");
	_method_bindings.method_append = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 694024632);
	_gde_name = StringName("append_array");
	_method_bindings.method_append_array = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 1087733270);
	_gde_name = StringName("remove_at");
	_method_bindings.method_remove_at = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 2823966027);
	_gde_name = StringName("insert");
	_method_bindings.method_insert = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 1487112728);
	_gde_name = StringName("fill");
	_method_bindings.method_fill = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 2823966027);
	_gde_name = StringName("resize");
	_method_bindings.method_resize = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 848867239);
	_gde_name = StringName("clear");
	_method_bindings.method_clear = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 3218959716);
	_gde_name = StringName("has");
	_method_bindings.method_has = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 931488181);
	_gde_name = StringName("reverse");
	_method_bindings.method_reverse = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 3218959716);
	_gde_name = StringName("slice");
	_method_bindings.method_slice = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 1216021098);
	_gde_name = StringName("to_byte_array");
	_method_bindings.method_to_byte_array = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("sort");
	_method_bindings.method_sort = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 3218959716);
	_gde_name = StringName("bsearch");
	_method_bindings.method_bsearch = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 3380005890);
	_gde_name = StringName("duplicate");
	_method_bindings.method_duplicate = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 1997843129);
	_gde_name = StringName("find");
	_method_bindings.method_find = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 2984303840);
	_gde_name = StringName("rfind");
	_method_bindings.method_rfind = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 2984303840);
	_gde_name = StringName("count");
	_method_bindings.method_count = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, _gde_name._native_ptr(), 4103005248);
	_method_bindings.indexed_setter = internal::gdextension_interface_variant_get_ptr_indexed_setter(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
	_method_bindings.indexed_getter = internal::gdextension_interface_variant_get_ptr_indexed_getter(GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
	_method_bindings.operator_equal_Variant = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_not_equal_Variant = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_not = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_in_Dictionary = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_DICTIONARY);
	_method_bindings.operator_in_Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_ARRAY);
	_method_bindings.operator_equal_PackedInt32Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
	_method_bindings.operator_not_equal_PackedInt32Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
	_method_bindings.operator_add_PackedInt32Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_ADD, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
}

PackedInt32Array::PackedInt32Array(const Variant *p_variant) {
	_method_bindings.from_variant_constructor(&opaque, p_variant->_native_ptr());
}

PackedInt32Array::PackedInt32Array() {
	internal::_call_builtin_constructor(_method_bindings.constructor_0, &opaque);
}

PackedInt32Array::PackedInt32Array(const PackedInt32Array &p_from) {
	internal::_call_builtin_constructor(_method_bindings.constructor_1, &opaque, &p_from);
}

PackedInt32Array::PackedInt32Array(const Array &p_from) {
	internal::_call_builtin_constructor(_method_bindings.constructor_2, &opaque, &p_from);
}

PackedInt32Array::PackedInt32Array(PackedInt32Array &&p_other) {
	std::swap(opaque, p_other.opaque);
}

PackedInt32Array::~PackedInt32Array() {
	_method_bindings.destructor(&opaque);
}

int64_t PackedInt32Array::get(int64_t p_index) const {
	int64_t p_index_encoded;
	PtrToArg<int64_t>::encode(p_index, &p_index_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_get, (GDExtensionTypePtr)&opaque, &p_index_encoded);
}

int64_t PackedInt32Array::size() const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_size, (GDExtensionTypePtr)&opaque);
}

bool PackedInt32Array::is_empty() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_empty, (GDExtensionTypePtr)&opaque);
}

void PackedInt32Array::set(int64_t p_index, int64_t p_value) {
	int64_t p_index_encoded;
	PtrToArg<int64_t>::encode(p_index, &p_index_encoded);
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_set, (GDExtensionTypePtr)&opaque, &p_index_encoded, &p_value_encoded);
}

bool PackedInt32Array::push_back(int64_t p_value) {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_push_back, (GDExtensionTypePtr)&opaque, &p_value_encoded);
}

bool PackedInt32Array::append(int64_t p_value) {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_append, (GDExtensionTypePtr)&opaque, &p_value_encoded);
}

void PackedInt32Array::append_array(const PackedInt32Array &p_array) {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_append_array, (GDExtensionTypePtr)&opaque, &p_array);
}

void PackedInt32Array::remove_at(int64_t p_index) {
	int64_t p_index_encoded;
	PtrToArg<int64_t>::encode(p_index, &p_index_encoded);
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_remove_at, (GDExtensionTypePtr)&opaque, &p_index_encoded);
}

int64_t PackedInt32Array::insert(int64_t p_at_index, int64_t p_value) {
	int64_t p_at_index_encoded;
	PtrToArg<int64_t>::encode(p_at_index, &p_at_index_encoded);
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_insert, (GDExtensionTypePtr)&opaque, &p_at_index_encoded, &p_value_encoded);
}

void PackedInt32Array::fill(int64_t p_value) {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_fill, (GDExtensionTypePtr)&opaque, &p_value_encoded);
}

int64_t PackedInt32Array::resize(int64_t p_new_size) {
	int64_t p_new_size_encoded;
	PtrToArg<int64_t>::encode(p_new_size, &p_new_size_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_resize, (GDExtensionTypePtr)&opaque, &p_new_size_encoded);
}

void PackedInt32Array::clear() {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_clear, (GDExtensionTypePtr)&opaque);
}

bool PackedInt32Array::has(int64_t p_value) const {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_has, (GDExtensionTypePtr)&opaque, &p_value_encoded);
}

void PackedInt32Array::reverse() {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_reverse, (GDExtensionTypePtr)&opaque);
}

PackedInt32Array PackedInt32Array::slice(int64_t p_begin, int64_t p_end) const {
	int64_t p_begin_encoded;
	PtrToArg<int64_t>::encode(p_begin, &p_begin_encoded);
	int64_t p_end_encoded;
	PtrToArg<int64_t>::encode(p_end, &p_end_encoded);
	return internal::_call_builtin_method_ptr_ret<PackedInt32Array>(_method_bindings.method_slice, (GDExtensionTypePtr)&opaque, &p_begin_encoded, &p_end_encoded);
}

PackedByteArray PackedInt32Array::to_byte_array() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_to_byte_array, (GDExtensionTypePtr)&opaque);
}

void PackedInt32Array::sort() {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_sort, (GDExtensionTypePtr)&opaque);
}

int64_t PackedInt32Array::bsearch(int64_t p_value, bool p_before) {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	int8_t p_before_encoded;
	PtrToArg<bool>::encode(p_before, &p_before_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_bsearch, (GDExtensionTypePtr)&opaque, &p_value_encoded, &p_before_encoded);
}

PackedInt32Array PackedInt32Array::duplicate() {
	return internal::_call_builtin_method_ptr_ret<PackedInt32Array>(_method_bindings.method_duplicate, (GDExtensionTypePtr)&opaque);
}

int64_t PackedInt32Array::find(int64_t p_value, int64_t p_from) const {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_find, (GDExtensionTypePtr)&opaque, &p_value_encoded, &p_from_encoded);
}

int64_t PackedInt32Array::rfind(int64_t p_value, int64_t p_from) const {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_rfind, (GDExtensionTypePtr)&opaque, &p_value_encoded, &p_from_encoded);
}

int64_t PackedInt32Array::count(int64_t p_value) const {
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_count, (GDExtensionTypePtr)&opaque, &p_value_encoded);
}

bool PackedInt32Array::operator==(const Variant &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_Variant, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool PackedInt32Array::operator!=(const Variant &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not_equal_Variant, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool PackedInt32Array::operator!() const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr) nullptr);
}

bool PackedInt32Array::operator==(const PackedInt32Array &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_PackedInt32Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool PackedInt32Array::operator!=(const PackedInt32Array &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not_equal_PackedInt32Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

PackedInt32Array PackedInt32Array::operator+(const PackedInt32Array &p_other) const {
	return internal::_call_builtin_operator_ptr<PackedInt32Array>(_method_bindings.operator_add_PackedInt32Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

PackedInt32Array &PackedInt32Array::operator=(const PackedInt32Array &p_other) {
	_method_bindings.destructor(&opaque);
	internal::_call_builtin_constructor(_method_bindings.constructor_1, &opaque, &p_other);
	return *this;
}

PackedInt32Array &PackedInt32Array::operator=(PackedInt32Array &&p_other) {
	std::swap(opaque, p_other.opaque);
	return *this;
}

} //namespace godot
