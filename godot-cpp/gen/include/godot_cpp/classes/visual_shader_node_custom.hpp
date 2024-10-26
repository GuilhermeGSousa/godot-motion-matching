/**************************************************************************/
/*  visual_shader_node_custom.hpp                                         */
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

#ifndef GODOT_CPP_VISUAL_SHADER_NODE_CUSTOM_HPP
#define GODOT_CPP_VISUAL_SHADER_NODE_CUSTOM_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/shader.hpp>
#include <godot_cpp/classes/visual_shader.hpp>
#include <godot_cpp/classes/visual_shader_node.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class VisualShaderNodeCustom : public VisualShaderNode {
	GDEXTENSION_CLASS(VisualShaderNodeCustom, VisualShaderNode)

public:
	int32_t get_option_index(int32_t p_option) const;
	virtual String _get_name() const;
	virtual String _get_description() const;
	virtual String _get_category() const;
	virtual VisualShaderNode::PortType _get_return_icon_type() const;
	virtual int32_t _get_input_port_count() const;
	virtual VisualShaderNode::PortType _get_input_port_type(int32_t p_port) const;
	virtual String _get_input_port_name(int32_t p_port) const;
	virtual Variant _get_input_port_default_value(int32_t p_port) const;
	virtual int32_t _get_default_input_port(VisualShaderNode::PortType p_type) const;
	virtual int32_t _get_output_port_count() const;
	virtual VisualShaderNode::PortType _get_output_port_type(int32_t p_port) const;
	virtual String _get_output_port_name(int32_t p_port) const;
	virtual int32_t _get_property_count() const;
	virtual String _get_property_name(int32_t p_index) const;
	virtual int32_t _get_property_default_index(int32_t p_index) const;
	virtual PackedStringArray _get_property_options(int32_t p_index) const;
	virtual String _get_code(const TypedArray<String> &p_input_vars, const TypedArray<String> &p_output_vars, Shader::Mode p_mode, VisualShader::Type p_type) const;
	virtual String _get_func_code(Shader::Mode p_mode, VisualShader::Type p_type) const;
	virtual String _get_global_code(Shader::Mode p_mode) const;
	virtual bool _is_highend() const;
	virtual bool _is_available(Shader::Mode p_mode, VisualShader::Type p_type) const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		VisualShaderNode::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_get_name), decltype(&T::_get_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_description), decltype(&T::_get_description)>) {
			BIND_VIRTUAL_METHOD(T, _get_description);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_category), decltype(&T::_get_category)>) {
			BIND_VIRTUAL_METHOD(T, _get_category);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_return_icon_type), decltype(&T::_get_return_icon_type)>) {
			BIND_VIRTUAL_METHOD(T, _get_return_icon_type);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_input_port_count), decltype(&T::_get_input_port_count)>) {
			BIND_VIRTUAL_METHOD(T, _get_input_port_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_input_port_type), decltype(&T::_get_input_port_type)>) {
			BIND_VIRTUAL_METHOD(T, _get_input_port_type);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_input_port_name), decltype(&T::_get_input_port_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_input_port_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_input_port_default_value), decltype(&T::_get_input_port_default_value)>) {
			BIND_VIRTUAL_METHOD(T, _get_input_port_default_value);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_default_input_port), decltype(&T::_get_default_input_port)>) {
			BIND_VIRTUAL_METHOD(T, _get_default_input_port);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_output_port_count), decltype(&T::_get_output_port_count)>) {
			BIND_VIRTUAL_METHOD(T, _get_output_port_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_output_port_type), decltype(&T::_get_output_port_type)>) {
			BIND_VIRTUAL_METHOD(T, _get_output_port_type);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_output_port_name), decltype(&T::_get_output_port_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_output_port_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_property_count), decltype(&T::_get_property_count)>) {
			BIND_VIRTUAL_METHOD(T, _get_property_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_property_name), decltype(&T::_get_property_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_property_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_property_default_index), decltype(&T::_get_property_default_index)>) {
			BIND_VIRTUAL_METHOD(T, _get_property_default_index);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_property_options), decltype(&T::_get_property_options)>) {
			BIND_VIRTUAL_METHOD(T, _get_property_options);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_code), decltype(&T::_get_code)>) {
			BIND_VIRTUAL_METHOD(T, _get_code);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_func_code), decltype(&T::_get_func_code)>) {
			BIND_VIRTUAL_METHOD(T, _get_func_code);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_global_code), decltype(&T::_get_global_code)>) {
			BIND_VIRTUAL_METHOD(T, _get_global_code);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_highend), decltype(&T::_is_highend)>) {
			BIND_VIRTUAL_METHOD(T, _is_highend);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_available), decltype(&T::_is_available)>) {
			BIND_VIRTUAL_METHOD(T, _is_available);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_VISUAL_SHADER_NODE_CUSTOM_HPP
