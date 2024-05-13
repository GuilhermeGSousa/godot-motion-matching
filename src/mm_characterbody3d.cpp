#include "mm_characterbody3d.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/core/property_info.hpp>

using namespace godot;

Vector3 clamp_max_magnitude(const Vector3 &vector, float maxMagnitude) {
  float magnitude = vector.length();
  if (magnitude > maxMagnitude) {
    return vector.normalized() * maxMagnitude;
  } else {
    return vector;
  }
}

MMCharacterBody3D::MMCharacterBody3D() : CharacterBody3D() {}

MMCharacterBody3D::~MMCharacterBody3D() {}

void MMCharacterBody3D::_ready() {
  trajectory_buffer.resize(trajectory_point_count);
}

void godot::MMCharacterBody3D::_physics_process(double delta) {
  if (Engine::get_singleton()->is_editor_hint()) {
    return;
  }
  Vector3 new_velocity = update_trajectory(get_velocity(), delta);
  set_velocity(new_velocity);
  move_and_slide();
}

Vector3 MMCharacterBody3D::update_trajectory(const Vector3 &current_velocity,
                                             float delta_t) {
  Vector3 new_velocity = current_velocity;

  const Vector2 stick_input =
      Input::get_singleton()->get_vector("down", "up", "left", "right", 0.1f);

  // Get the world space acceleration vector.
  const Vector3 stick_input_world = get_global_transform().basis.xform(
      Vector3(stick_input.x, 0.f, stick_input.y));

  const Vector3 acceleration = stick_input_world * 10.0f;

  // Update the velocity.
  new_velocity += acceleration * delta_t;
  new_velocity -= new_velocity * friction * delta_t;
  new_velocity = clamp_max_magnitude(new_velocity, max_speed);

  _update_history(new_velocity, acceleration);

  return new_velocity;
}

void godot::MMCharacterBody3D::_update_history(
    const Vector3 &p_current_velocity, const Vector3 &p_current_acceleration) {
  const float delta_t = 1.0f / simulation_samples_per_second;

  Vector3 current_position = get_global_transform().origin;
  Vector3 current_velocity = p_current_velocity;
  Vector3 current_acceleration = p_current_acceleration;

  for (size_t i = 0; i < trajectory_point_count; i++) {
    MMTrajectoryPoint point;
    point.position = current_position;
    point.velocity = current_velocity;

    trajectory_buffer.push(point);

    // Update velocity
    current_velocity += current_acceleration * delta_t;
    current_velocity -= current_velocity * friction * delta_t;
    current_velocity = clamp_max_magnitude(current_velocity, max_speed);

    // Update position
    current_position += current_velocity * delta_t;
  }
}

void MMCharacterBody3D::_bind_methods() {
  ClassDB::bind_method(
      D_METHOD("update_trajectory", "current_velocity", "delta_t"),
      &MMCharacterBody3D::update_trajectory);

  ClassDB::bind_method(D_METHOD("get_trajectory"),
                       &MMCharacterBody3D::get_trajectory);
  BINDER_PROPERTY_PARAMS(MMCharacterBody3D, Variant::FLOAT, friction);
  BINDER_PROPERTY_PARAMS(MMCharacterBody3D, Variant::INT,
                         trajectory_point_count);
  BINDER_PROPERTY_PARAMS(MMCharacterBody3D, Variant::FLOAT,
                         simulation_samples_per_second);
  BINDER_PROPERTY_PARAMS(MMCharacterBody3D, Variant::FLOAT, max_speed);
}