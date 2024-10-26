/**************************************************************************/
/*  visual_shader_node_int_parameter.hpp                                  */
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

#ifndef GODOT_CPP_VISUAL_SHADER_NODE_INT_PARAMETER_HPP
#define GODOT_CPP_VISUAL_SHADER_NODE_INT_PARAMETER_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/visual_shader_node_parameter.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class VisualShaderNodeIntParameter : public VisualShaderNodeParameter {
	GDEXTENSION_CLASS(VisualShaderNodeIntParameter, VisualShaderNodeParameter)

public:
	enum Hint {
		HINT_NONE = 0,
		HINT_RANGE = 1,
		HINT_RANGE_STEP = 2,
		HINT_ENUM = 3,
		HINT_MAX = 4,
	};

	void set_hint(VisualShaderNodeIntParameter::Hint p_hint);
	VisualShaderNodeIntParameter::Hint get_hint() const;
	void set_min(int32_t p_value);
	int32_t get_min() const;
	void set_max(int32_t p_value);
	int32_t get_max() const;
	void set_step(int32_t p_value);
	int32_t get_step() const;
	void set_enum_names(const PackedStringArray &p_names);
	PackedStringArray get_enum_names() const;
	void set_default_value_enabled(bool p_enabled);
	bool is_default_value_enabled() const;
	void set_default_value(int32_t p_value);
	int32_t get_default_value() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		VisualShaderNodeParameter::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(VisualShaderNodeIntParameter::Hint);

#endif // ! GODOT_CPP_VISUAL_SHADER_NODE_INT_PARAMETER_HPP
