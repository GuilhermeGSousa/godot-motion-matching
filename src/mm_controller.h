#pragma once

#include "circular_buffer.h"
#include "common.h"
#include "mm_animation_player.h"
#include "mm_controller.h"
#include "mm_trajectory_point.h"
#include "synchronizers/mm_synchronizer.h"

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
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

    const std::vector<MMTrajectoryPoint>& get_trajectory() const {
        return _trajectory;
    }

    const std::vector<MMTrajectoryPoint>& get_trajectory_history() const {
        return _trajectory_history;
    }

    TypedArray<Dictionary> get_trajectory_typed_array() const {
        TypedArray<Dictionary> result;
        for (const MMTrajectoryPoint& point : _trajectory) {
            Dictionary data;
            data.get_or_add("position", point.position);
            data.get_or_add("velocity", point.velocity);
            data.get_or_add("facing", point.facing_angle);
            data.get_or_add("on_floor", point.collision_state.on_floor);
            result.push_back(data);
        }
        return result;
    }

    TypedArray<Dictionary> get_previous_trajectory_typed_array() const {
        TypedArray<Dictionary> result;
        for (const MMTrajectoryPoint& point : _trajectory_history) {
            Dictionary data;
            data.get_or_add("position", point.position);
            data.get_or_add("velocity", point.velocity);
            data.get_or_add("facing", point.facing_angle);
            data.get_or_add("on_floor", point.collision_state.on_floor);
            result.push_back(data);
        }
        return result;
    }

    MMAnimationPlayer* get_animation_player() const;

    GETSET(NodePath, skeleton_path)
    GETSET(NodePath, animation_player_path)
    GETSET(float, query_frequency, 2.0f)
    GETSET(Ref<MMSynchronizer>, synchronizer)
    GETSET(NodePath, camera_pivot);
    GETSET(float, trajectory_delta_time, 0.5f);
    GETSET(float, history_delta_time, 0.5f);
    GETSET(float, max_speed, 100.f);
    GETSET(float, halflife, 0.5f);
    GETSET(float, mouse_sensitivity, 1.f);
    GETSET(bool, is_strafing, false);
    GETSET(uint32_t, trajectory_point_count, 10);
    GETSET(uint32_t, history_point_count, 3);

protected:
    static constexpr size_t HISTORY_BUFFER_SIZE{100}; // Around 1.6s
    static void _bind_methods();

private:
    void _update_controller(float delta_t);
    Vector3 _update_trajectory(float p_delta_t);
    MMTrajectoryPoint _get_current_trajectory_point() const;
    void _generate_trajectory(const Vector3& p_current_velocity, const Vector3& p_target_velocity, float delta_time);
    void _update_history(double delta_t);
    void _update_point(MMTrajectoryPoint& point, float delta_t);
    void _fill_collision_state(const Ref<PhysicsTestMotionResult3D> collision_result, MMCollisionState& state);
    void _fall_to_floor(MMTrajectoryPoint& point, float delta_t);
    void _on_animation_finished(StringName p_animation_name);

    // Motion Matching
    void _fill_query_input(MMQueryInput& input);
    void _update_query(double delta_t);
    void _apply_root_motion();
    void _update_synchronizer(double delta_t);

    static Dictionary _output_to_dict(const MMQueryOutput& output);

private:
    // Controller
    Vector3 _spring_acceleration;

    // Camera
    Node3D* _camera_pivot{nullptr};
    float _camera_pivot_height{0.f};

    // Trajectory
    std::vector<MMTrajectoryPoint> _trajectory;
    std::vector<MMTrajectoryPoint> _trajectory_history;
    CircularBuffer<MMTrajectoryPoint> _history_buffer{HISTORY_BUFFER_SIZE};

    // Motion Matching
    Skeleton3D* _skeleton{nullptr};
    MMAnimationPlayer* _animation_player{nullptr};
    float _time_since_last_query{0.f};
    bool _force_transition{false};
    MMQueryOutput _last_query_output;
};
