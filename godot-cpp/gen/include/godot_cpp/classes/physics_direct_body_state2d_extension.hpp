/**************************************************************************/
/*  physics_direct_body_state2d_extension.hpp                             */
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

#ifndef GODOT_CPP_PHYSICS_DIRECT_BODY_STATE2D_EXTENSION_HPP
#define GODOT_CPP_PHYSICS_DIRECT_BODY_STATE2D_EXTENSION_HPP

#include <godot_cpp/classes/physics_direct_body_state2d.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/variant/transform2d.hpp>
#include <godot_cpp/variant/vector2.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Object;
class PhysicsDirectSpaceState2D;

class PhysicsDirectBodyState2DExtension : public PhysicsDirectBodyState2D {
	GDEXTENSION_CLASS(PhysicsDirectBodyState2DExtension, PhysicsDirectBodyState2D)

public:
	virtual Vector2 _get_total_gravity() const;
	virtual float _get_total_linear_damp() const;
	virtual float _get_total_angular_damp() const;
	virtual Vector2 _get_center_of_mass() const;
	virtual Vector2 _get_center_of_mass_local() const;
	virtual float _get_inverse_mass() const;
	virtual float _get_inverse_inertia() const;
	virtual void _set_linear_velocity(const Vector2 &p_velocity);
	virtual Vector2 _get_linear_velocity() const;
	virtual void _set_angular_velocity(float p_velocity);
	virtual float _get_angular_velocity() const;
	virtual void _set_transform(const Transform2D &p_transform);
	virtual Transform2D _get_transform() const;
	virtual Vector2 _get_velocity_at_local_position(const Vector2 &p_local_position) const;
	virtual void _apply_central_impulse(const Vector2 &p_impulse);
	virtual void _apply_impulse(const Vector2 &p_impulse, const Vector2 &p_position);
	virtual void _apply_torque_impulse(float p_impulse);
	virtual void _apply_central_force(const Vector2 &p_force);
	virtual void _apply_force(const Vector2 &p_force, const Vector2 &p_position);
	virtual void _apply_torque(float p_torque);
	virtual void _add_constant_central_force(const Vector2 &p_force);
	virtual void _add_constant_force(const Vector2 &p_force, const Vector2 &p_position);
	virtual void _add_constant_torque(float p_torque);
	virtual void _set_constant_force(const Vector2 &p_force);
	virtual Vector2 _get_constant_force() const;
	virtual void _set_constant_torque(float p_torque);
	virtual float _get_constant_torque() const;
	virtual void _set_sleep_state(bool p_enabled);
	virtual bool _is_sleeping() const;
	virtual int32_t _get_contact_count() const;
	virtual Vector2 _get_contact_local_position(int32_t p_contact_idx) const;
	virtual Vector2 _get_contact_local_normal(int32_t p_contact_idx) const;
	virtual int32_t _get_contact_local_shape(int32_t p_contact_idx) const;
	virtual Vector2 _get_contact_local_velocity_at_position(int32_t p_contact_idx) const;
	virtual RID _get_contact_collider(int32_t p_contact_idx) const;
	virtual Vector2 _get_contact_collider_position(int32_t p_contact_idx) const;
	virtual uint64_t _get_contact_collider_id(int32_t p_contact_idx) const;
	virtual Object *_get_contact_collider_object(int32_t p_contact_idx) const;
	virtual int32_t _get_contact_collider_shape(int32_t p_contact_idx) const;
	virtual Vector2 _get_contact_collider_velocity_at_position(int32_t p_contact_idx) const;
	virtual Vector2 _get_contact_impulse(int32_t p_contact_idx) const;
	virtual float _get_step() const;
	virtual void _integrate_forces();
	virtual PhysicsDirectSpaceState2D *_get_space_state();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		PhysicsDirectBodyState2D::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_get_total_gravity), decltype(&T::_get_total_gravity)>) {
			BIND_VIRTUAL_METHOD(T, _get_total_gravity);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_total_linear_damp), decltype(&T::_get_total_linear_damp)>) {
			BIND_VIRTUAL_METHOD(T, _get_total_linear_damp);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_total_angular_damp), decltype(&T::_get_total_angular_damp)>) {
			BIND_VIRTUAL_METHOD(T, _get_total_angular_damp);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_center_of_mass), decltype(&T::_get_center_of_mass)>) {
			BIND_VIRTUAL_METHOD(T, _get_center_of_mass);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_center_of_mass_local), decltype(&T::_get_center_of_mass_local)>) {
			BIND_VIRTUAL_METHOD(T, _get_center_of_mass_local);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_inverse_mass), decltype(&T::_get_inverse_mass)>) {
			BIND_VIRTUAL_METHOD(T, _get_inverse_mass);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_inverse_inertia), decltype(&T::_get_inverse_inertia)>) {
			BIND_VIRTUAL_METHOD(T, _get_inverse_inertia);
		}
		if constexpr (!std::is_same_v<decltype(&B::_set_linear_velocity), decltype(&T::_set_linear_velocity)>) {
			BIND_VIRTUAL_METHOD(T, _set_linear_velocity);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_linear_velocity), decltype(&T::_get_linear_velocity)>) {
			BIND_VIRTUAL_METHOD(T, _get_linear_velocity);
		}
		if constexpr (!std::is_same_v<decltype(&B::_set_angular_velocity), decltype(&T::_set_angular_velocity)>) {
			BIND_VIRTUAL_METHOD(T, _set_angular_velocity);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_angular_velocity), decltype(&T::_get_angular_velocity)>) {
			BIND_VIRTUAL_METHOD(T, _get_angular_velocity);
		}
		if constexpr (!std::is_same_v<decltype(&B::_set_transform), decltype(&T::_set_transform)>) {
			BIND_VIRTUAL_METHOD(T, _set_transform);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_transform), decltype(&T::_get_transform)>) {
			BIND_VIRTUAL_METHOD(T, _get_transform);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_velocity_at_local_position), decltype(&T::_get_velocity_at_local_position)>) {
			BIND_VIRTUAL_METHOD(T, _get_velocity_at_local_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_apply_central_impulse), decltype(&T::_apply_central_impulse)>) {
			BIND_VIRTUAL_METHOD(T, _apply_central_impulse);
		}
		if constexpr (!std::is_same_v<decltype(&B::_apply_impulse), decltype(&T::_apply_impulse)>) {
			BIND_VIRTUAL_METHOD(T, _apply_impulse);
		}
		if constexpr (!std::is_same_v<decltype(&B::_apply_torque_impulse), decltype(&T::_apply_torque_impulse)>) {
			BIND_VIRTUAL_METHOD(T, _apply_torque_impulse);
		}
		if constexpr (!std::is_same_v<decltype(&B::_apply_central_force), decltype(&T::_apply_central_force)>) {
			BIND_VIRTUAL_METHOD(T, _apply_central_force);
		}
		if constexpr (!std::is_same_v<decltype(&B::_apply_force), decltype(&T::_apply_force)>) {
			BIND_VIRTUAL_METHOD(T, _apply_force);
		}
		if constexpr (!std::is_same_v<decltype(&B::_apply_torque), decltype(&T::_apply_torque)>) {
			BIND_VIRTUAL_METHOD(T, _apply_torque);
		}
		if constexpr (!std::is_same_v<decltype(&B::_add_constant_central_force), decltype(&T::_add_constant_central_force)>) {
			BIND_VIRTUAL_METHOD(T, _add_constant_central_force);
		}
		if constexpr (!std::is_same_v<decltype(&B::_add_constant_force), decltype(&T::_add_constant_force)>) {
			BIND_VIRTUAL_METHOD(T, _add_constant_force);
		}
		if constexpr (!std::is_same_v<decltype(&B::_add_constant_torque), decltype(&T::_add_constant_torque)>) {
			BIND_VIRTUAL_METHOD(T, _add_constant_torque);
		}
		if constexpr (!std::is_same_v<decltype(&B::_set_constant_force), decltype(&T::_set_constant_force)>) {
			BIND_VIRTUAL_METHOD(T, _set_constant_force);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_constant_force), decltype(&T::_get_constant_force)>) {
			BIND_VIRTUAL_METHOD(T, _get_constant_force);
		}
		if constexpr (!std::is_same_v<decltype(&B::_set_constant_torque), decltype(&T::_set_constant_torque)>) {
			BIND_VIRTUAL_METHOD(T, _set_constant_torque);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_constant_torque), decltype(&T::_get_constant_torque)>) {
			BIND_VIRTUAL_METHOD(T, _get_constant_torque);
		}
		if constexpr (!std::is_same_v<decltype(&B::_set_sleep_state), decltype(&T::_set_sleep_state)>) {
			BIND_VIRTUAL_METHOD(T, _set_sleep_state);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_sleeping), decltype(&T::_is_sleeping)>) {
			BIND_VIRTUAL_METHOD(T, _is_sleeping);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_count), decltype(&T::_get_contact_count)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_local_position), decltype(&T::_get_contact_local_position)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_local_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_local_normal), decltype(&T::_get_contact_local_normal)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_local_normal);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_local_shape), decltype(&T::_get_contact_local_shape)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_local_shape);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_local_velocity_at_position), decltype(&T::_get_contact_local_velocity_at_position)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_local_velocity_at_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_collider), decltype(&T::_get_contact_collider)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_collider);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_collider_position), decltype(&T::_get_contact_collider_position)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_collider_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_collider_id), decltype(&T::_get_contact_collider_id)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_collider_id);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_collider_object), decltype(&T::_get_contact_collider_object)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_collider_object);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_collider_shape), decltype(&T::_get_contact_collider_shape)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_collider_shape);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_collider_velocity_at_position), decltype(&T::_get_contact_collider_velocity_at_position)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_collider_velocity_at_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_contact_impulse), decltype(&T::_get_contact_impulse)>) {
			BIND_VIRTUAL_METHOD(T, _get_contact_impulse);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_step), decltype(&T::_get_step)>) {
			BIND_VIRTUAL_METHOD(T, _get_step);
		}
		if constexpr (!std::is_same_v<decltype(&B::_integrate_forces), decltype(&T::_integrate_forces)>) {
			BIND_VIRTUAL_METHOD(T, _integrate_forces);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_space_state), decltype(&T::_get_space_state)>) {
			BIND_VIRTUAL_METHOD(T, _get_space_state);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_PHYSICS_DIRECT_BODY_STATE2D_EXTENSION_HPP
