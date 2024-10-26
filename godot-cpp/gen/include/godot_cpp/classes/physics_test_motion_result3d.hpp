/**************************************************************************/
/*  physics_test_motion_result3d.hpp                                      */
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

#ifndef GODOT_CPP_PHYSICS_TEST_MOTION_RESULT3D_HPP
#define GODOT_CPP_PHYSICS_TEST_MOTION_RESULT3D_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Object;

class PhysicsTestMotionResult3D : public RefCounted {
	GDEXTENSION_CLASS(PhysicsTestMotionResult3D, RefCounted)

public:
	Vector3 get_travel() const;
	Vector3 get_remainder() const;
	float get_collision_safe_fraction() const;
	float get_collision_unsafe_fraction() const;
	int32_t get_collision_count() const;
	Vector3 get_collision_point(int32_t p_collision_index = 0) const;
	Vector3 get_collision_normal(int32_t p_collision_index = 0) const;
	Vector3 get_collider_velocity(int32_t p_collision_index = 0) const;
	uint64_t get_collider_id(int32_t p_collision_index = 0) const;
	RID get_collider_rid(int32_t p_collision_index = 0) const;
	Object *get_collider(int32_t p_collision_index = 0) const;
	int32_t get_collider_shape(int32_t p_collision_index = 0) const;
	int32_t get_collision_local_shape(int32_t p_collision_index = 0) const;
	float get_collision_depth(int32_t p_collision_index = 0) const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		RefCounted::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_PHYSICS_TEST_MOTION_RESULT3D_HPP
