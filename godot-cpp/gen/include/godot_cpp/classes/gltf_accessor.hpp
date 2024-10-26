/**************************************************************************/
/*  gltf_accessor.hpp                                                     */
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

#ifndef GODOT_CPP_GLTF_ACCESSOR_HPP
#define GODOT_CPP_GLTF_ACCESSOR_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/packed_float64_array.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class GLTFAccessor : public Resource {
	GDEXTENSION_CLASS(GLTFAccessor, Resource)

public:
	enum GLTFAccessorType {
		TYPE_SCALAR = 0,
		TYPE_VEC2 = 1,
		TYPE_VEC3 = 2,
		TYPE_VEC4 = 3,
		TYPE_MAT2 = 4,
		TYPE_MAT3 = 5,
		TYPE_MAT4 = 6,
	};

	int32_t get_buffer_view();
	void set_buffer_view(int32_t p_buffer_view);
	int32_t get_byte_offset();
	void set_byte_offset(int32_t p_byte_offset);
	int32_t get_component_type();
	void set_component_type(int32_t p_component_type);
	bool get_normalized();
	void set_normalized(bool p_normalized);
	int32_t get_count();
	void set_count(int32_t p_count);
	GLTFAccessor::GLTFAccessorType get_accessor_type();
	void set_accessor_type(GLTFAccessor::GLTFAccessorType p_accessor_type);
	int32_t get_type();
	void set_type(int32_t p_type);
	PackedFloat64Array get_min();
	void set_min(const PackedFloat64Array &p_min);
	PackedFloat64Array get_max();
	void set_max(const PackedFloat64Array &p_max);
	int32_t get_sparse_count();
	void set_sparse_count(int32_t p_sparse_count);
	int32_t get_sparse_indices_buffer_view();
	void set_sparse_indices_buffer_view(int32_t p_sparse_indices_buffer_view);
	int32_t get_sparse_indices_byte_offset();
	void set_sparse_indices_byte_offset(int32_t p_sparse_indices_byte_offset);
	int32_t get_sparse_indices_component_type();
	void set_sparse_indices_component_type(int32_t p_sparse_indices_component_type);
	int32_t get_sparse_values_buffer_view();
	void set_sparse_values_buffer_view(int32_t p_sparse_values_buffer_view);
	int32_t get_sparse_values_byte_offset();
	void set_sparse_values_byte_offset(int32_t p_sparse_values_byte_offset);

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Resource::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(GLTFAccessor::GLTFAccessorType);

#endif // ! GODOT_CPP_GLTF_ACCESSOR_HPP
