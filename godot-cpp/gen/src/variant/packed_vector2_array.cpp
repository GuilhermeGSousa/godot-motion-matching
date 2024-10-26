/**************************************************************************/
/*  packed_vector2_array.cpp                                              */
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

#include <godot_cpp/variant/packed_vector2_array.hpp>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/godot.hpp>

#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/transform2d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/vector2.hpp>

#include <godot_cpp/core/builtin_ptrcall.hpp>

#include <utility>

namespace godot {

PackedVector2Array::_MethodBindings PackedVector2Array::_method_bindings;

void PackedVector2Array::_init_bindings_constructors_destructor() {
	_method_bindings.from_variant_constructor = internal::gdextension_interface_get_variant_to_type_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
	_method_bindings.constructor_0 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, 0);
	_method_bindings.constructor_1 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, 1);
	_method_bindings.constructor_2 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, 2);
	_method_bindings.destructor = internal::gdextension_interface_variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
}
void PackedVector2Array::init_bindings() {
	PackedVector2Array::_init_bindings_constructors_destructor();
	StringName _gde_name;
	_gde_name = StringName("get");
	_method_bindings.method_get = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 2609058838);
	_gde_name = StringName("size");
	_method_bindings.method_size = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3173160232);
	_gde_name = StringName("is_empty");
	_method_bindings.method_is_empty = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("set");
	_method_bindings.method_set = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 635767250);
	_gde_name = StringName("push_back");
	_method_bindings.method_push_back = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 4188891560);
	_gde_name = StringName("append");
	_method_bindings.method_append = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 4188891560);
	_gde_name = StringName("append_array");
	_method_bindings.method_append_array = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3887534835);
	_gde_name = StringName("remove_at");
	_method_bindings.method_remove_at = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 2823966027);
	_gde_name = StringName("insert");
	_method_bindings.method_insert = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 2225629369);
	_gde_name = StringName("fill");
	_method_bindings.method_fill = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3790411178);
	_gde_name = StringName("resize");
	_method_bindings.method_resize = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 848867239);
	_gde_name = StringName("clear");
	_method_bindings.method_clear = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3218959716);
	_gde_name = StringName("has");
	_method_bindings.method_has = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3190634762);
	_gde_name = StringName("reverse");
	_method_bindings.method_reverse = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3218959716);
	_gde_name = StringName("slice");
	_method_bindings.method_slice = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3864005350);
	_gde_name = StringName("to_byte_array");
	_method_bindings.method_to_byte_array = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("sort");
	_method_bindings.method_sort = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3218959716);
	_gde_name = StringName("bsearch");
	_method_bindings.method_bsearch = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3778035805);
	_gde_name = StringName("duplicate");
	_method_bindings.method_duplicate = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 3763646812);
	_gde_name = StringName("find");
	_method_bindings.method_find = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 1469606149);
	_gde_name = StringName("rfind");
	_method_bindings.method_rfind = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 1469606149);
	_gde_name = StringName("count");
	_method_bindings.method_count = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, _gde_name._native_ptr(), 2798848307);
	_method_bindings.indexed_setter = internal::gdextension_interface_variant_get_ptr_indexed_setter(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
	_method_bindings.indexed_getter = internal::gdextension_interface_variant_get_ptr_indexed_getter(GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
	_method_bindings.operator_equal_Variant = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_not_equal_Variant = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_not = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_multiply_Transform2D = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MULTIPLY, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_TRANSFORM2D);
	_method_bindings.operator_in_Dictionary = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_DICTIONARY);
	_method_bindings.operator_in_Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_ARRAY);
	_method_bindings.operator_equal_PackedVector2Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
	_method_bindings.operator_not_equal_PackedVector2Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT_EQUAL, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
	_method_bindings.operator_add_PackedVector2Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_ADD, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
}

PackedVector2Array::PackedVector2Array(const Variant *p_variant) {
	_method_bindings.from_variant_constructor(&opaque, p_variant->_native_ptr());
}

PackedVector2Array::PackedVector2Array() {
	internal::_call_builtin_constructor(_method_bindings.constructor_0, &opaque);
}

PackedVector2Array::PackedVector2Array(const PackedVector2Array &p_from) {
	internal::_call_builtin_constructor(_method_bindings.constructor_1, &opaque, &p_from);
}

PackedVector2Array::PackedVector2Array(const Array &p_from) {
	internal::_call_builtin_constructor(_method_bindings.constructor_2, &opaque, &p_from);
}

PackedVector2Array::PackedVector2Array(PackedVector2Array &&p_other) {
	std::swap(opaque, p_other.opaque);
}

PackedVector2Array::~PackedVector2Array() {
	_method_bindings.destructor(&opaque);
}

Vector2 PackedVector2Array::get(int64_t p_index) const {
	int64_t p_index_encoded;
	PtrToArg<int64_t>::encode(p_index, &p_index_encoded);
	return internal::_call_builtin_method_ptr_ret<Vector2>(_method_bindings.method_get, (GDExtensionTypePtr)&opaque, &p_index_encoded);
}

int64_t PackedVector2Array::size() const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_size, (GDExtensionTypePtr)&opaque);
}

bool PackedVector2Array::is_empty() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_empty, (GDExtensionTypePtr)&opaque);
}

void PackedVector2Array::set(int64_t p_index, const Vector2 &p_value) {
	int64_t p_index_encoded;
	PtrToArg<int64_t>::encode(p_index, &p_index_encoded);
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_set, (GDExtensionTypePtr)&opaque, &p_index_encoded, &p_value);
}

bool PackedVector2Array::push_back(const Vector2 &p_value) {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_push_back, (GDExtensionTypePtr)&opaque, &p_value);
}

bool PackedVector2Array::append(const Vector2 &p_value) {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_append, (GDExtensionTypePtr)&opaque, &p_value);
}

void PackedVector2Array::append_array(const PackedVector2Array &p_array) {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_append_array, (GDExtensionTypePtr)&opaque, &p_array);
}

void PackedVector2Array::remove_at(int64_t p_index) {
	int64_t p_index_encoded;
	PtrToArg<int64_t>::encode(p_index, &p_index_encoded);
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_remove_at, (GDExtensionTypePtr)&opaque, &p_index_encoded);
}

int64_t PackedVector2Array::insert(int64_t p_at_index, const Vector2 &p_value) {
	int64_t p_at_index_encoded;
	PtrToArg<int64_t>::encode(p_at_index, &p_at_index_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_insert, (GDExtensionTypePtr)&opaque, &p_at_index_encoded, &p_value);
}

void PackedVector2Array::fill(const Vector2 &p_value) {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_fill, (GDExtensionTypePtr)&opaque, &p_value);
}

int64_t PackedVector2Array::resize(int64_t p_new_size) {
	int64_t p_new_size_encoded;
	PtrToArg<int64_t>::encode(p_new_size, &p_new_size_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_resize, (GDExtensionTypePtr)&opaque, &p_new_size_encoded);
}

void PackedVector2Array::clear() {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_clear, (GDExtensionTypePtr)&opaque);
}

bool PackedVector2Array::has(const Vector2 &p_value) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_has, (GDExtensionTypePtr)&opaque, &p_value);
}

void PackedVector2Array::reverse() {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_reverse, (GDExtensionTypePtr)&opaque);
}

PackedVector2Array PackedVector2Array::slice(int64_t p_begin, int64_t p_end) const {
	int64_t p_begin_encoded;
	PtrToArg<int64_t>::encode(p_begin, &p_begin_encoded);
	int64_t p_end_encoded;
	PtrToArg<int64_t>::encode(p_end, &p_end_encoded);
	return internal::_call_builtin_method_ptr_ret<PackedVector2Array>(_method_bindings.method_slice, (GDExtensionTypePtr)&opaque, &p_begin_encoded, &p_end_encoded);
}

PackedByteArray PackedVector2Array::to_byte_array() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_to_byte_array, (GDExtensionTypePtr)&opaque);
}

void PackedVector2Array::sort() {
	internal::_call_builtin_method_ptr_no_ret(_method_bindings.method_sort, (GDExtensionTypePtr)&opaque);
}

int64_t PackedVector2Array::bsearch(const Vector2 &p_value, bool p_before) {
	int8_t p_before_encoded;
	PtrToArg<bool>::encode(p_before, &p_before_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_bsearch, (GDExtensionTypePtr)&opaque, &p_value, &p_before_encoded);
}

PackedVector2Array PackedVector2Array::duplicate() {
	return internal::_call_builtin_method_ptr_ret<PackedVector2Array>(_method_bindings.method_duplicate, (GDExtensionTypePtr)&opaque);
}

int64_t PackedVector2Array::find(const Vector2 &p_value, int64_t p_from) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_find, (GDExtensionTypePtr)&opaque, &p_value, &p_from_encoded);
}

int64_t PackedVector2Array::rfind(const Vector2 &p_value, int64_t p_from) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_rfind, (GDExtensionTypePtr)&opaque, &p_value, &p_from_encoded);
}

int64_t PackedVector2Array::count(const Vector2 &p_value) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_count, (GDExtensionTypePtr)&opaque, &p_value);
}

bool PackedVector2Array::operator==(const Variant &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_Variant, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool PackedVector2Array::operator!=(const Variant &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not_equal_Variant, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool PackedVector2Array::operator!() const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr) nullptr);
}

PackedVector2Array PackedVector2Array::operator*(const Transform2D &p_other) const {
	return internal::_call_builtin_operator_ptr<PackedVector2Array>(_method_bindings.operator_multiply_Transform2D, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool PackedVector2Array::operator==(const PackedVector2Array &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_PackedVector2Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool PackedVector2Array::operator!=(const PackedVector2Array &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not_equal_PackedVector2Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

PackedVector2Array PackedVector2Array::operator+(const PackedVector2Array &p_other) const {
	return internal::_call_builtin_operator_ptr<PackedVector2Array>(_method_bindings.operator_add_PackedVector2Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

PackedVector2Array &PackedVector2Array::operator=(const PackedVector2Array &p_other) {
	_method_bindings.destructor(&opaque);
	internal::_call_builtin_constructor(_method_bindings.constructor_1, &opaque, &p_other);
	return *this;
}

PackedVector2Array &PackedVector2Array::operator=(PackedVector2Array &&p_other) {
	std::swap(opaque, p_other.opaque);
	return *this;
}

} //namespace godot
