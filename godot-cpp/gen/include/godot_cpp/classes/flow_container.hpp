/**************************************************************************/
/*  flow_container.hpp                                                    */
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

#ifndef GODOT_CPP_FLOW_CONTAINER_HPP
#define GODOT_CPP_FLOW_CONTAINER_HPP

#include <godot_cpp/classes/container.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class FlowContainer : public Container {
	GDEXTENSION_CLASS(FlowContainer, Container)

public:
	enum AlignmentMode {
		ALIGNMENT_BEGIN = 0,
		ALIGNMENT_CENTER = 1,
		ALIGNMENT_END = 2,
	};

	enum LastWrapAlignmentMode {
		LAST_WRAP_ALIGNMENT_INHERIT = 0,
		LAST_WRAP_ALIGNMENT_BEGIN = 1,
		LAST_WRAP_ALIGNMENT_CENTER = 2,
		LAST_WRAP_ALIGNMENT_END = 3,
	};

	int32_t get_line_count() const;
	void set_alignment(FlowContainer::AlignmentMode p_alignment);
	FlowContainer::AlignmentMode get_alignment() const;
	void set_last_wrap_alignment(FlowContainer::LastWrapAlignmentMode p_last_wrap_alignment);
	FlowContainer::LastWrapAlignmentMode get_last_wrap_alignment() const;
	void set_vertical(bool p_vertical);
	bool is_vertical() const;
	void set_reverse_fill(bool p_reverse_fill);
	bool is_reverse_fill() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Container::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(FlowContainer::AlignmentMode);
VARIANT_ENUM_CAST(FlowContainer::LastWrapAlignmentMode);

#endif // ! GODOT_CPP_FLOW_CONTAINER_HPP
