#pragma once

#include "circular_buffer.h"
#include "common.h"
#include "mm_character.h"
#include "mm_query.h"
#include "mm_trajectory_point.h"
#include "synchronizers/mm_synchronizer.h"

#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class MMCharacter : public CharacterBody3D {
    GDCLASS(MMCharacter, CharacterBody3D)
public:
    MMCharacter();
    virtual ~MMCharacter();

public:
    virtual void _ready() override;
    virtual void _physics_process(double delta) override;

    MMQueryOutput query(const MMQueryInput& p_query_input);

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

    TypedArray<Dictionary> get_skeleton_state() const {
        TypedArray<Dictionary> result;
        for (const BoneState& state : _skeleton_state.bone_states) {
            Dictionary data;
            data.get_or_add("position", state.pos);
            data.get_or_add("velocity", state.vel);
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

    AnimationMixer* get_animation_mixer() const;
    Skeleton3D* get_skeleton() const;

    // Trajectory
    GETSET(float, trajectory_delta_time, 0.5f);
    GETSET(float, history_delta_time, 0.5f);
    GETSET(uint32_t, trajectory_point_count, 10);
    GETSET(uint32_t, history_point_count, 3);
    GETSET(bool, check_environment, true);

    // Movement
    GETSET(float, halflife, 0.5f);
    GETSET(bool, is_strafing, false);
    GETSET(float, strafe_facing, 0.f);
    GETSET(Vector3, target_velocity);

    // Motion Matching
    GETSET(NodePath, skeleton_path)
    GETSET(NodePath, animation_player_path)
    GETSET(float, query_frequency, 2.0f)
    GETSET(Ref<MMSynchronizer>, synchronizer)

protected:
    static constexpr size_t HISTORY_BUFFER_SIZE{100}; // Around 1.6s
    static void _bind_methods();

private:
    void _update_character(float delta_t);

    // Trajectory
    Vector3 _update_trajectory(float p_delta_t);
    MMTrajectoryPoint _get_current_trajectory_point() const;
    void _generate_trajectory(const Vector3& p_current_velocity, float delta_time);
    void _update_history(double delta_t);
    void _update_point(MMTrajectoryPoint& point, float delta_t);
    void _fill_collision_state(const Ref<PhysicsTestMotionResult3D> collision_result, MMCollisionState& state);
    void _fall_to_floor(MMTrajectoryPoint& point, float delta_t);

    // Callbacks
    void _on_animation_finished(StringName p_animation_name);

    // Motion Matching
    void _fill_query_input(MMQueryInput& input);
    void _update_query(double delta_t);
    void _apply_root_motion();
    void _update_synchronizer(double delta_t);

    // Skeleton State
    void _fill_current_skeleton_state(SkeletonState& p_state) const;
    void _reset_skeleton_state();
    void _update_skeleton_state(double delta_t);

    static Dictionary _output_to_dict(const MMQueryOutput& output);

private:
    // Controller
    Vector3 _spring_acceleration;

    // Trajectory
    std::vector<MMTrajectoryPoint> _trajectory;
    std::vector<MMTrajectoryPoint> _trajectory_history;
    CircularBuffer<MMTrajectoryPoint> _history_buffer{HISTORY_BUFFER_SIZE};

    // Motion Matching
    Skeleton3D* _skeleton{nullptr};
    AnimationPlayer* _animation_player{nullptr};
    float _time_since_last_query{0.f};
    bool _force_transition{false};
    MMQueryOutput _last_query_output;

    // Skeleton State
    SkeletonState _skeleton_state;
    int32_t _root_bone_idx{-1};
};
