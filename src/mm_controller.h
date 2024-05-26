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

    Array get_trajectory() const {
        Array trajectory;
        for (size_t i = 0; i < trajectory_buffer.size(); ++i) {
            trajectory.push_back(trajectory_buffer[i].get_position());
        }
        return trajectory;
    }

    GETSET(NodePath, camera_pivot);
    GETSET(float, simulation_samples_per_second, 10.f);
    GETSET(float, friction, 1.f);
    GETSET(float, max_speed, 100.f);
    GETSET(float, mouse_sensitivity, 1.f);
    GETSET(bool, is_strafing, false);
    GETSET(size_t, trajectory_point_count, 10);

protected:
    static void _bind_methods();

private:
    void _update_history(const Vector3& p_current_velocity, const Vector3& p_current_acceleration);

private:
    Node3D* _camera_pivot{nullptr};
    float _camera_pivot_height{0.f};
    CircularBuffer<MMTrajectoryPoint> trajectory_buffer{trajectory_point_count};
};