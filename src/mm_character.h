#ifndef MM_CHARACTER_H
#define MM_CHARACTER_H

#include "circular_buffer.h"
#include "common.h"
#include "mm_character.h"
#include "mm_query.h"
#include "mm_trajectory_point.h"
#include "synchronizers/mm_synchronizer.h"

#include <godot_cpp/classes/animation_tree.hpp>
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
    const std::vector<MMTrajectoryPoint>& get_trajectory() const {
        return _trajectory;
    }

    const std::vector<MMTrajectoryPoint>& get_trajectory_history() const {
        return _trajectory_history;
    }

    TypedArray<Dictionary> get_skeleton_state() const {
        TypedArray<Dictionary> result;
        for (const BoneState& state : _skeleton_state.bone_states) {
            Dictionary character_data;
            character_data.get_or_add("position", state.pos);
            character_data.get_or_add("velocity", state.vel);
            result.push_back(character_data);
        }
        return result;
    }

    TypedArray<Dictionary> get_trajectory_typed_array() const {
        return trajectory_to_dict(_trajectory);
    }

    TypedArray<Dictionary> get_trajectory_history_typed_array() const {
        return trajectory_to_dict(_trajectory_history);
    }

    TypedArray<Dictionary> trajectory_to_dict(const std::vector<MMTrajectoryPoint>& p_trajectory) const {
        TypedArray<Dictionary> result;
        for (const MMTrajectoryPoint& point : p_trajectory) {
            Dictionary trajectory_data;
            trajectory_data.get_or_add("position", point.position);
            trajectory_data.get_or_add("velocity", point.velocity);
            trajectory_data.get_or_add("facing", point.facing_angle);
            trajectory_data.get_or_add("on_floor", point.collision_state.on_floor);
            result.push_back(trajectory_data);
        }
        return result;
    }

    AnimationMixer* get_animation_mixer() const;

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
    GETSET(Skeleton3D*, skeleton);
    GETSET(AnimationTree*, animation_tree);
    GETSET(Ref<MMSynchronizer>, synchronizer);

    // Debug
    GETSET(bool, emit_result_signal, false);

protected:
    static constexpr size_t HISTORY_BUFFER_SIZE{100}; // Around 1.6s
    static void _bind_methods();

public:
    void _notification(int p_what);

private:
    void _update_character(float delta_t);

    // Trajectory
    Vector3 _update_trajectory(float p_delta_t);
    MMTrajectoryPoint _get_current_trajectory_point() const;
    void _generate_trajectory(float delta_time);
    void _update_history(double delta_t);
    void _move_with_collisions(MMTrajectoryPoint& point, float delta_t);
    void _fill_collision_state(const Ref<PhysicsTestMotionResult3D> collision_result, MMCollisionState& state);
    void _fall_to_floor(MMTrajectoryPoint& point, float delta_t);

    // Motion Matching
    void _fill_query_input(MMQueryInput& input);
    void _update_query();
    void _apply_root_motion();
    void _update_synchronizer(double delta_t);

    // Skeleton State
    void _fill_current_skeleton_state(SkeletonState& p_state) const;
    void _reset_skeleton_state();
    void _update_skeleton_state(double delta_t);

    void _on_query_result(const MMQueryOutput& output);

    static Dictionary _output_to_dict(const MMQueryOutput& output);

private:
    // Controller
    Vector3 _spring_acceleration;

    // Trajectory
    std::vector<MMTrajectoryPoint> _trajectory;
    std::vector<MMTrajectoryPoint> _trajectory_history;
    CircularBuffer<MMTrajectoryPoint> _history_buffer{HISTORY_BUFFER_SIZE};

    // Skeleton State
    SkeletonState _skeleton_state;
    int32_t _root_bone_idx{-1};

    // Motion Matching parameters
    List<StringName> _mm_input_params;
};

#endif // MM_CHARACTER_H
