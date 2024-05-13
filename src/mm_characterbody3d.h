#pragma once

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "circular_buffer.h"
#include "common.h"
#include "mm_trajectory_point.h"

namespace godot {

class MMCharacterBody3D : public CharacterBody3D {
  GDCLASS(MMCharacterBody3D, CharacterBody3D)
 public:
  MMCharacterBody3D();
  virtual ~MMCharacterBody3D();

 public:
  void _ready() override;
  virtual void _physics_process(double delta) override;

  Vector3 update_trajectory(const Vector3& p_current_velocity, float p_delta_t);

  float get_simulation_samples_per_second() const {
    return simulation_samples_per_second;
  }
  void set_simulation_samples_per_second(
      float p_simulation_samples_per_second) {
    simulation_samples_per_second = p_simulation_samples_per_second;
  }
  float get_friction() const { return friction; }
  void set_friction(float p_friction) { friction = p_friction; }
  size_t get_trajectory_point_count() const { return trajectory_point_count; }
  void set_trajectory_point_count(size_t p_trajectory_point_count) {
    trajectory_point_count = p_trajectory_point_count;
    trajectory_buffer.resize(trajectory_point_count);
  }
  float get_max_speed() const { return max_speed; }
  void set_max_speed(float p_max_speed) { max_speed = p_max_speed; }

  Array get_trajectory() const {
    Array trajectory;
    for (size_t i = 0; i < trajectory_buffer.size(); ++i) {
      trajectory.push_back(trajectory_buffer[i].get_position());
    }
    return trajectory;
  }

 protected:
  static void _bind_methods();

 private:
  void _update_history(const Vector3& p_current_velocity,
                       const Vector3& p_current_acceleration);

 private:
  float simulation_samples_per_second = 10.0f;
  float friction = 0.1f;
  float max_speed = 100.0f;
  size_t trajectory_point_count = 10;
  CircularBuffer<MMTrajectoryPoint> trajectory_buffer{trajectory_point_count};
};
}  // namespace godot