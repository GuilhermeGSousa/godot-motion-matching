#pragma once

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "circular_buffer.h"
#include "common.h"
#include "mm_trajectory_point.h"

using namespace godot;

class MMCharacterBody3D : public CharacterBody3D {
    GDCLASS(MMCharacterBody3D, CharacterBody3D)
public:
    MMCharacterBody3D();
    virtual ~MMCharacterBody3D();

public:
    void _ready() override;
    virtual void _physics_process(double delta) override;

    Vector3 update_trajectory(const Vector3 &p_current_velocity,
                              float p_delta_t);

    Array get_trajectory() const {
        Array trajectory;
        for (size_t i = 0; i < trajectory_buffer.size(); ++i) {
            trajectory.push_back(trajectory_buffer[i].get_position());
        }
        return trajectory;
    }

    GETSET(float, simulation_samples_per_second, 10.f);
    GETSET(float, friction, 1.f);
    GETSET(float, max_speed, 100.f);
    GETSET(size_t, trajectory_point_count, 10);

protected:
    static void _bind_methods();

private:
    void _update_history(const Vector3 &p_current_velocity,
                         const Vector3 &p_current_acceleration);

private:
    CircularBuffer<MMTrajectoryPoint> trajectory_buffer{trajectory_point_count};
};