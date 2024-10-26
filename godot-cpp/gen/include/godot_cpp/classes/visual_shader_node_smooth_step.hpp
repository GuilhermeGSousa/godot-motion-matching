/**************************************************************************/
/*  visual_shader_node_smooth_step.hpp                                    */
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

#ifndef GODOT_CPP_VISUAL_SHADER_NODE_SMOOTH_STEP_HPP
#define GODOT_CPP_VISUAL_SHADER_NODE_SMOOTH_STEP_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/visual_shader_node.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class VisualShaderNodeSmoothStep : public VisualShaderNode {
	GDEXTENSION_CLASS(VisualShaderNodeSmoothStep, VisualShaderNode)

public:
	enum OpType {
		OP_TYPE_SCALAR = 0,
		OP_TYPE_VECTOR_2D = 1,
		OP_TYPE_VECTOR_2D_SCALAR = 2,
		OP_TYPE_VECTOR_3D = 3,
		OP_TYPE_VECTOR_3D_SCALAR = 4,
		OP_TYPE_VECTOR_4D = 5,
		OP_TYPE_VECTOR_4D_SCALAR = 6,
		OP_TYPE_MAX = 7,
	};

	void set_op_type(VisualShaderNodeSmoothStep::OpType p_op_type);
	VisualShaderNodeSmoothStep::OpType get_op_type() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		VisualShaderNode::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(VisualShaderNodeSmoothStep::OpType);

#endif // ! GODOT_CPP_VISUAL_SHADER_NODE_SMOOTH_STEP_HPP
