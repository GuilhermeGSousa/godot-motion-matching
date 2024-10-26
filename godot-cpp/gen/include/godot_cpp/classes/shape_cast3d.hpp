/**************************************************************************/
/*  shape_cast3d.hpp                                                      */
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

#ifndef GODOT_CPP_SHAPE_CAST3D_HPP
#define GODOT_CPP_SHAPE_CAST3D_HPP

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class CollisionObject3D;
class Object;
class Resource;
class Shape3D;

class ShapeCast3D : public Node3D {
	GDEXTENSION_CLASS(ShapeCast3D, Node3D)

public:
	void resource_changed(const Ref<Resource> &p_resource);
	void set_enabled(bool p_enabled);
	bool is_enabled() const;
	void set_shape(const Ref<Shape3D> &p_shape);
	Ref<Shape3D> get_shape() const;
	void set_target_position(const Vector3 &p_local_point);
	Vector3 get_target_position() const;
	void set_margin(float p_margin);
	float get_margin() const;
	void set_max_results(int32_t p_max_results);
	int32_t get_max_results() const;
	bool is_colliding() const;
	int32_t get_collision_count() const;
	void force_shapecast_update();
	Object *get_collider(int32_t p_index) const;
	RID get_collider_rid(int32_t p_index) const;
	int32_t get_collider_shape(int32_t p_index) const;
	Vector3 get_collision_point(int32_t p_index) const;
	Vector3 get_collision_normal(int32_t p_index) const;
	float get_closest_collision_safe_fraction() const;
	float get_closest_collision_unsafe_fraction() const;
	void add_exception_rid(const RID &p_rid);
	void add_exception(CollisionObject3D *p_node);
	void remove_exception_rid(const RID &p_rid);
	void remove_exception(CollisionObject3D *p_node);
	void clear_exceptions();
	void set_collision_mask(uint32_t p_mask);
	uint32_t get_collision_mask() const;
	void set_collision_mask_value(int32_t p_layer_number, bool p_value);
	bool get_collision_mask_value(int32_t p_layer_number) const;
	void set_exclude_parent_body(bool p_mask);
	bool get_exclude_parent_body() const;
	void set_collide_with_areas(bool p_enable);
	bool is_collide_with_areas_enabled() const;
	void set_collide_with_bodies(bool p_enable);
	bool is_collide_with_bodies_enabled() const;
	Array get_collision_result() const;
	void set_debug_shape_custom_color(const Color &p_debug_shape_custom_color);
	Color get_debug_shape_custom_color() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Node3D::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_SHAPE_CAST3D_HPP
