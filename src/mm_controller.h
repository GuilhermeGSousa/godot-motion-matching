#pragma once

#include "circular_buffer.h"
#include "common.h"
#include "mm_trajectory_point.h"

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class MMController : public CharacterBody3D {
    GDCLASS(MMController, CharacterBody3D)
public:
    MMController();
    virtual ~MMController();

public:
    virtual void _ready() override;
    virtual void _process(double delta) override;
    virtual void _physics_process(double delta) override;
    virtual void _input(const Ref<InputEvent>& event) override;

    Vector3 update_trajectory(const Vector3& p_current_velocity, float p_delta_t);

    const std::vector<MMTrajectoryPoint>& get_trajectory() const {
        return _trajectory_buffer;
    }

    const std::vector<MMTrajectoryPoint>& get_history() const {
        return _history_buffer.to_vector();
    }

    TypedArray<Vector3> get_trajectory_positions() const {
        TypedArray<Vector3> positions;
        for (const auto& point : _trajectory_buffer) {
            positions.append(point.position);
        }
        return positions;
    }

    TypedArray<Vector3> get_history_positions() const {
        TypedArray<Vector3> positions;
        for (size_t i = 0; i < _history_buffer.size(); i++) {
            positions.append(_history_buffer[i].position);
        }
        return positions;
    }

    TypedArray<float> get_trajectory_facing_angles() const {
        TypedArray<float> facing_angles;
        for (const auto& point : _trajectory_buffer) {
            facing_angles.append(point.facing_angle);
        }
        return facing_angles;
    }

    GETSET(NodePath, camera_pivot);
    GETSET(float, simulation_samples_per_second, 10.f);
    GETSET(float, friction, 1.f);
    GETSET(float, max_speed, 100.f);
    GETSET(float, max_acceleration, 5.f);
    GETSET(float, mouse_sensitivity, 1.f);
    GETSET(bool, is_strafing, false);
    GETSET(size_t, trajectory_point_count, 10);
    GETSET(size_t, history_point_count, 3);

protected:
    static void _bind_methods();

private:
    void _generate_trajectory(const Vector3& p_current_velocity, const Vector3& p_current_acceleration);
    void _update_history();

private:
    Node3D* _camera_pivot{nullptr};
    float _camera_pivot_height{0.f};
    std::vector<MMTrajectoryPoint> _trajectory_buffer{trajectory_point_count};
    CircularBuffer<MMTrajectoryPoint> _history_buffer{history_point_count};
    float _time_until_next_history_point{0.f};
};