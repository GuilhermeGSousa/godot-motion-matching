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
        return _trajectory;
    }

    TypedArray<MMTrajectoryPointRC> get_trajectory_typed_array() const {
        TypedArray<MMTrajectoryPointRC> result;
        for (const MMTrajectoryPoint& point : _trajectory) {
            result.push_back(memnew(MMTrajectoryPointRC(point)));
        }
        return result;
    }

    TypedArray<MMTrajectoryPointRC> get_previous_trajectory_typed_array() const {
        TypedArray<MMTrajectoryPointRC> result;
        for (const MMTrajectoryPoint& point : _previous_trajectory) {
            result.push_back(memnew(MMTrajectoryPointRC(point)));
        }
        return result;
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
    static constexpr size_t HISTORY_BUFFER_SIZE{100}; // Around 1.6s
    static void _bind_methods();

private:
    MMTrajectoryPoint _get_current_trajectory_point() const;
    void _generate_trajectory(const Vector3& p_current_velocity, const Vector3& p_current_acceleration,
                              float delta_time);
    void _update_history();

private:
    Node3D* _camera_pivot{nullptr};
    float _camera_pivot_height{0.f};
    std::vector<MMTrajectoryPoint> _trajectory{trajectory_point_count};
    std::vector<MMTrajectoryPoint> _previous_trajectory{history_point_count};
    CircularBuffer<MMTrajectoryPoint> _history_buffer{HISTORY_BUFFER_SIZE};
};