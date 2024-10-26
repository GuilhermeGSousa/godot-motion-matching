/**************************************************************************/
/*  physics_direct_space_state3d.hpp                                      */
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

#ifndef GODOT_CPP_PHYSICS_DIRECT_SPACE_STATE3D_HPP
#define GODOT_CPP_PHYSICS_DIRECT_SPACE_STATE3D_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class PhysicsPointQueryParameters3D;
class PhysicsRayQueryParameters3D;
class PhysicsShapeQueryParameters3D;

class PhysicsDirectSpaceState3D : public Object {
	GDEXTENSION_CLASS(PhysicsDirectSpaceState3D, Object)

public:
	TypedArray<Dictionary> intersect_point(const Ref<PhysicsPointQueryParameters3D> &p_parameters, int32_t p_max_results = 32);
	Dictionary intersect_ray(const Ref<PhysicsRayQueryParameters3D> &p_parameters);
	TypedArray<Dictionary> intersect_shape(const Ref<PhysicsShapeQueryParameters3D> &p_parameters, int32_t p_max_results = 32);
	PackedFloat32Array cast_motion(const Ref<PhysicsShapeQueryParameters3D> &p_parameters);
	TypedArray<Vector3> collide_shape(const Ref<PhysicsShapeQueryParameters3D> &p_parameters, int32_t p_max_results = 32);
	Dictionary get_rest_info(const Ref<PhysicsShapeQueryParameters3D> &p_parameters);

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Object::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_PHYSICS_DIRECT_SPACE_STATE3D_HPP
