/**************************************************************************/
/*  visual_instance3d.hpp                                                 */
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

#ifndef GODOT_CPP_VISUAL_INSTANCE3D_HPP
#define GODOT_CPP_VISUAL_INSTANCE3D_HPP

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/rid.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class VisualInstance3D : public Node3D {
	GDEXTENSION_CLASS(VisualInstance3D, Node3D)

public:
	void set_base(const RID &p_base);
	RID get_base() const;
	RID get_instance() const;
	void set_layer_mask(uint32_t p_mask);
	uint32_t get_layer_mask() const;
	void set_layer_mask_value(int32_t p_layer_number, bool p_value);
	bool get_layer_mask_value(int32_t p_layer_number) const;
	void set_sorting_offset(float p_offset);
	float get_sorting_offset() const;
	void set_sorting_use_aabb_center(bool p_enabled);
	bool is_sorting_use_aabb_center() const;
	AABB get_aabb() const;
	virtual AABB _get_aabb() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Node3D::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_get_aabb), decltype(&T::_get_aabb)>) {
			BIND_VIRTUAL_METHOD(T, _get_aabb);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_VISUAL_INSTANCE3D_HPP
