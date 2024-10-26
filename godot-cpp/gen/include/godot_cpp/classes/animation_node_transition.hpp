/**************************************************************************/
/*  animation_node_transition.hpp                                         */
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

#ifndef GODOT_CPP_ANIMATION_NODE_TRANSITION_HPP
#define GODOT_CPP_ANIMATION_NODE_TRANSITION_HPP

#include <godot_cpp/classes/animation_node_sync.hpp>
#include <godot_cpp/classes/ref.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Curve;

class AnimationNodeTransition : public AnimationNodeSync {
	GDEXTENSION_CLASS(AnimationNodeTransition, AnimationNodeSync)

public:
	void set_input_count(int32_t p_input_count);
	void set_input_as_auto_advance(int32_t p_input, bool p_enable);
	bool is_input_set_as_auto_advance(int32_t p_input) const;
	void set_input_break_loop_at_end(int32_t p_input, bool p_enable);
	bool is_input_loop_broken_at_end(int32_t p_input) const;
	void set_input_reset(int32_t p_input, bool p_enable);
	bool is_input_reset(int32_t p_input) const;
	void set_xfade_time(double p_time);
	double get_xfade_time() const;
	void set_xfade_curve(const Ref<Curve> &p_curve);
	Ref<Curve> get_xfade_curve() const;
	void set_allow_transition_to_self(bool p_enable);
	bool is_allow_transition_to_self() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		AnimationNodeSync::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_ANIMATION_NODE_TRANSITION_HPP
