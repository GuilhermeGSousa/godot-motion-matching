/**************************************************************************/
/*  mm_character.cpp                                                      */
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

#include "mm_character.h"

#include "math/spring.hpp"
#include "mm_animation_library.h"
#include <cstdint>

constexpr float QUERY_TIME_ERROR = 0.05;

MMCharacter::MMCharacter()
    : CharacterBody3D() {
}

MMCharacter::~MMCharacter() {
}

MMQueryOutput MMCharacter::query(const MMQueryInput& query_input) {

    List<StringName> animation_libraries;
    _animation_player->get_animation_library_list(&animation_libraries);
    MMQueryOutput result;

    bool found_anim_library = false;

    // We should do something more sophisticated here,
    // but for now we just use the first motion matching library we find
    for (int64_t i = 0; i < animation_libraries.size(); i++) {
        const StringName& library_name = animation_libraries.get(i);
        if (!library_name) {
            continue;
        }
        Ref<MMAnimationLibrary> library = _animation_player->get_animation_library(library_name);
        if (library.is_null()) {
            continue;
        }
        List<StringName> animation_list;
        library->get_animation_list(&animation_list);
        if (library.is_null() || animation_list.is_empty()) {
            continue;
        }

        result = library->query(query_input);
        result.animation_match = String(library_name) + "/" + result.animation_match;
        found_anim_library = true;
        break;
    }

    ERR_FAIL_COND_V_MSG(
        !found_anim_library,
        result,
        "No Motion Matching animation library found in the MMAnimationPlayer");

    ERR_FAIL_COND_V_MSG(
        result.animation_match.is_empty(),
        result,
        "No animation match found, check that your animation libraries aren't empty");

    return result;
}

void MMCharacter::_update_character(float delta_t) {
    Vector3 new_velocity = _update_trajectory(delta_t);
    set_velocity(new_velocity);

    // Rotate the character to face the direction of velocity
    if (!is_strafing) {
        Vector3 direction = new_velocity.normalized();
        set_rotation(Vector3(0.0f, Math::atan2(direction.x, direction.z), 0.0f));
    } else {
        set_rotation(Vector3(0.0f, strafe_facing, 0.0f));
    }
    move_and_slide();
}

Vector3 MMCharacter::_update_trajectory(float delta_t) {
    Vector3 current_velocity = get_velocity();
    Vector3 current_up_direction = get("up_direction");

    // Update the velocity.
    const Vector3 up_velocity = current_velocity.dot(current_up_direction) * current_up_direction;
    Vector3 ground_velocity = current_velocity - up_velocity;
    Array result = Spring::simple_spring_damper_exact(
        ground_velocity,
        _spring_acceleration,
        target_velocity,
        halflife,
        delta_t);
    Vector3 new_velocity = (Vector3)result[0] + up_velocity;
    _spring_acceleration = result[1];

    if (!is_on_floor()) {
        new_velocity += get_gravity() * delta_t;
    }

    _generate_trajectory(delta_t);

    _update_history(delta_t);

    return new_velocity;
}

MMTrajectoryPoint MMCharacter::_get_current_trajectory_point() const {
    MMTrajectoryPoint point;
    point.position = get_global_position();
    point.velocity = get_velocity();
    point.collision_state.on_floor = is_on_floor();
    point.collision_state.against_wall = is_on_wall();
    point.collision_state.floor_normal = get_floor_normal();
    point.collision_state.wall_normal = get_wall_normal();

    if (get_velocity().length_squared() > SMALL_NUMBER && !is_strafing) {
        Vector3 direction = get_velocity().normalized();
        point.facing_angle = Math::atan2(direction.x, direction.z);
    } else {
        point.facing_angle = strafe_facing;
    }
    return point;
}

void MMCharacter::_generate_trajectory(float delta_time) {
    const float delta_t = trajectory_delta_time;

    MMTrajectoryPoint point = _get_current_trajectory_point();

    Vector3 spring_acceleration = _spring_acceleration;

    // The first point represents the player's current position, and is not considered part
    // of the trajectory for motion matching
    for (size_t i = 0; i < trajectory_point_count + 1; i++) {
        _trajectory[i] = point;

        Vector3 current_up_direction = get("up_direction");

        // Update velocity
        const Vector3 up_velocity = point.velocity.dot(current_up_direction) * current_up_direction;
        Vector3 ground_velocity = point.velocity - up_velocity;
        Array result = Spring::simple_spring_damper_exact(ground_velocity, spring_acceleration, target_velocity, halflife, delta_t);
        point.velocity = (Vector3)result[0] + up_velocity;
        spring_acceleration = result[1];

        // Update facing
        if (point.velocity.length_squared() > SMALL_NUMBER && !is_strafing) {
            Vector3 direction = point.velocity.normalized();
            point.facing_angle = Math::atan2(direction.x, direction.z);
        } else {
            point.facing_angle = strafe_facing;
        }

        if (check_environment) {
            // Update point with environment
            _move_with_collisions(point, delta_t);
            _fall_to_floor(point, delta_t);
        } else {
            point.position += point.velocity * delta_t;
        }
    }
}

void MMCharacter::_update_history(double delta_t) {
    if (!_history_buffer.is_empty()) {
        float time_in_past = 0.f;
        uint32_t current_index = 0;
        for (int i = _history_buffer.size() - 1; i >= 0; --i) {
            if (time_in_past >= history_delta_time) {
                _trajectory_history[current_index] = _history_buffer[i];
                time_in_past = 0.f;
                current_index++;
            }

            if (current_index >= history_point_count) {
                break;
            }

            time_in_past += delta_t;
        }
    }

    _history_buffer.push(_get_current_trajectory_point());
}

void MMCharacter::_move_with_collisions(MMTrajectoryPoint& point, float delta_t) {
    const Vector3 motion = point.velocity * delta_t;

    Ref<PhysicsTestMotionParameters3D> params;
    params.instantiate();
    Vector3 current_up_direction = get("up_direction");
    params->set_from(point.get_transform(current_up_direction));
    params->set_motion(motion);
    params->set_max_collisions(6);
    params->set_recovery_as_collision_enabled(false);

    Ref<PhysicsTestMotionResult3D> collision_result;
    collision_result.instantiate();

    bool is_colliding = PhysicsServer3D::get_singleton()->body_test_motion(
        get_rid(),
        params->get_parameters(),
        collision_result->get_result_ptr());

    if (!is_colliding) {
        // We move in the direction of motion as usual
        point.position += motion;

        // We reset the collision state
        point.collision_state.reset();
        return;
    }

    _fill_collision_state(collision_result, point.collision_state);

    // Update final position
    Vector3 result_velocity = point.velocity;
    point.position += collision_result->get_travel();

    if (point.collision_state.against_wall) {

        result_velocity = result_velocity.slide(point.collision_state.wall_normal);
        // Slide must be horizontal, no climbing walls!
        // Note: This would be a good place to add a climbing feature
        result_velocity.y = 0.0;
    }

    if (point.collision_state.on_floor) {
        result_velocity = result_velocity.slide(point.collision_state.floor_normal);
    }

    point.velocity = result_velocity;
    // Move the remaining part of motion
    point.position += point.velocity * delta_t * (1.0 - collision_result->get_collision_safe_fraction());
}

void MMCharacter::_fill_collision_state(const Ref<PhysicsTestMotionResult3D> collision_result, MMCollisionState& state) {
    real_t wall_depth = -1.0;
    real_t floor_depth = -1.0;

    state.on_floor = false;
    for (int i = collision_result->get_collision_count() - 1; i >= 0; i--) {
        Vector3 current_up_direction = get("up_direction");
        real_t floor_angle = Math::acos(collision_result->get_collision_normal(i).dot(current_up_direction));
        if (floor_angle <= get_floor_max_angle() && collision_result->get_collision_depth(i) > floor_depth) {
            state.on_floor = true;
            state.floor_normal = collision_result->get_collision_normal(i);
            state.floor_position = collision_result->get_collision_point(i);
            floor_depth = collision_result->get_collision_depth(i);
            continue;
        }

        state.against_wall = true;
        if (collision_result->get_collision_depth(i) > wall_depth) {
            state.against_wall = true;
            state.wall_normal = collision_result->get_collision_normal(i);
            wall_depth = collision_result->get_collision_depth(i);
        }
    }
}

void MMCharacter::_fall_to_floor(MMTrajectoryPoint& point, float delta_t) {
    const Vector3 motion = get_gravity() * delta_t * delta_t;
    Ref<PhysicsTestMotionParameters3D> params;
    params.instantiate();
    Vector3 current_up_direction = get("up_direction");
    params->set_from(point.get_transform(current_up_direction));
    params->set_motion(motion);

    Ref<PhysicsTestMotionResult3D> collision_result;
    collision_result.instantiate();

    if (PhysicsServer3D::get_singleton()->body_test_motion(
            get_rid(),
            params->get_parameters(),
            collision_result->get_result_ptr())) {
        point.position += collision_result->get_travel();
        point.velocity.y = 0.0;
        point.collision_state.on_floor = true;
        point.collision_state.floor_normal = collision_result->get_collision_normal();
    } else {
        point.position += motion;
        point.velocity += get_gravity() * delta_t;
        point.collision_state.on_floor = false;
    }
}

void MMCharacter::_on_animation_finished(StringName p_animation_name) {
    _force_transition = true;
}

void MMCharacter::_fill_query_input(MMQueryInput& input) {
    input.controller_velocity = get_velocity();
    input.trajectory = get_trajectory();
    input.trajectory_history = get_trajectory_history();
    input.controller_transform = get_global_transform();
    input.character_transform = _skeleton->get_global_transform();
    input.skeleton_state = _skeleton_state;
}

void MMCharacter::_update_query(double delta_t) {
    const bool should_query = (_time_since_last_query > (1.0 / query_frequency)) || _force_transition;
    if (should_query) {
        _time_since_last_query = 0.f;
        _force_transition = false;

        // Fill query_input with data from the controller
        MMQueryInput query_input;
        _fill_query_input(query_input);

        // Run query
        const MMQueryOutput result = query(query_input);

        // Play selected animation
        // TODO: It would be nice if we could use _animation_player->get_current_animation() here instead
        // but that sometimes returns an empty string :/

        const bool has_current_animation = !_animation_player->get_current_animation().is_empty();
        const bool is_same_animation = has_current_animation && result.animation_match == _last_query_output.animation_match;
        const bool is_same_time = has_current_animation && abs(result.time_match - _animation_player->get_current_animation_position()) < QUERY_TIME_ERROR;

        if (!is_same_animation || !is_same_time) {
            _animation_player->play(result.animation_match);
            _animation_player->seek(result.time_match);
            emit_signal("on_query_result", _output_to_dict(result));
            _last_query_output = result;
        }
    }
    _time_since_last_query += delta_t;
}

void MMCharacter::_apply_root_motion() {
    _skeleton->set_quaternion(
        _skeleton->get_quaternion() * _animation_player->get_root_motion_rotation());

    const Vector3 movement_delta = (_animation_player->get_root_motion_rotation_accumulator().inverse() * _skeleton->get_quaternion()).xform(_animation_player->get_root_motion_position());

    _skeleton->set_global_position(_skeleton->get_global_position() + movement_delta);
}

void MMCharacter::_update_synchronizer(double delta_t) {
    if (synchronizer.is_null()) {
        return;
    }

    // TODO: This is wrong, we should not be changing the character position directly!
    // See #33 for more information
    MMSyncResult sync_result = synchronizer->sync(this, _skeleton, delta_t);
    set_global_position(sync_result.controller_position);
    set_quaternion(sync_result.controller_rotation);
    _skeleton->set_global_position(sync_result.character_position);
    _skeleton->set_quaternion(sync_result.character_rotation);
}

void MMCharacter::_fill_current_skeleton_state(SkeletonState& p_state) const {
    Transform3D root_bone_pose = _skeleton->get_bone_global_pose(_root_bone_idx);

    for (int b = 0; b < _skeleton->get_bone_count(); ++b) {
        Transform3D bone_pose = _skeleton->get_bone_global_pose(b);
        p_state[b].pos = root_bone_pose.xform(bone_pose.origin);
        p_state[b].vel = Vector3();
        p_state[b].rot = bone_pose.basis.get_rotation_quaternion();
        p_state[b].ang_vel = Vector3();
        p_state[b].scl = bone_pose.basis.get_scale();
        p_state[b].scl_vel = Vector3();
    }
}

void MMCharacter::_reset_skeleton_state() {
    _fill_current_skeleton_state(_skeleton_state);
    _skeleton_state.reset_velocities();
}

void MMCharacter::_update_skeleton_state(double delta_t) {
    SkeletonState current_state(_skeleton);
    _fill_current_skeleton_state(current_state);

    for (int b = 0; b < _skeleton->get_bone_count(); ++b) {
        BoneState& state = _skeleton_state[b];
        const BoneState& current = current_state[b];

        state.vel = (current.pos - state.pos) / delta_t;
        state.ang_vel = Spring::quat_differentiate_angular_velocity(current.rot, state.rot, delta_t);
        state.scl_vel = (current.scl - state.scl) / delta_t;

        state.pos = current.pos;
        state.rot = current.rot;
        state.scl = current.scl;
    }
}

Dictionary MMCharacter::_output_to_dict(const MMQueryOutput& output) {
    Dictionary result;

    result.get_or_add("animation", output.animation_match);
    result.get_or_add("time", output.time_match);
    result.get_or_add("frame_data", output.matched_frame_data);
    result.merge(output.feature_costs);
    result.get_or_add("total_cost", output.cost);

    return result;
}

AnimationMixer* MMCharacter::get_animation_mixer() const {
    Node* current_node = get_node(animation_player_path);
    return cast_to<AnimationMixer>(current_node);
}

Skeleton3D* MMCharacter::get_skeleton() const {
    Node* current_skeleton = get_node(skeleton_path);
    return cast_to<Skeleton3D>(current_skeleton);
}

void MMCharacter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_trajectory"), &MMCharacter::get_trajectory_typed_array);
    ClassDB::bind_method(D_METHOD("get_previous_trajectory"), &MMCharacter::get_previous_trajectory_typed_array);
    ClassDB::bind_method(D_METHOD("_on_animation_finished", "anim"), &MMCharacter::_on_animation_finished);
    ClassDB::bind_method(D_METHOD("get_skeleton_state"), &MMCharacter::get_skeleton_state);

    ADD_SIGNAL(MethodInfo("on_query_result", PropertyInfo(Variant::DICTIONARY, "data")));

    ADD_GROUP("Motion Matching", "");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::NODE_PATH, skeleton_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Skeleton3D");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::NODE_PATH, animation_player_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES, "AnimationPlayer");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::FLOAT, query_frequency);
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::OBJECT, synchronizer, PROPERTY_HINT_RESOURCE_TYPE, "MMSynchronizer");

    ADD_GROUP("Movement", "");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::FLOAT, halflife, PROPERTY_HINT_RANGE, "0.0,1.0,0.01,or_greater");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::BOOL, is_strafing);
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::FLOAT, strafe_facing, PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE);
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::VECTOR3, target_velocity, PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE);

    ADD_GROUP("Trajectory", "");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::BOOL, check_environment);
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::INT, trajectory_point_count);
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::FLOAT, trajectory_delta_time);
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::INT, history_point_count);
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::FLOAT, history_delta_time);
}

void MMCharacter::_notification(int p_what) {
    switch (p_what) {
    case NOTIFICATION_PHYSICS_PROCESS: {

        if (Engine::get_singleton()->is_editor_hint()) {
            return;
        }
        double delta = get_physics_process_delta_time();

        _update_character(delta);

        if (!_skeleton) {
            return;
        }

        _update_skeleton_state(delta);

        _update_query(delta);

        _apply_root_motion();

        _update_synchronizer(delta);
    } break;
    case NOTIFICATION_READY: {
        set_physics_process(true);

        if (Engine::get_singleton()->is_editor_hint()) {
            return;
        }

        while (!_history_buffer.is_full()) {
            _history_buffer.push(_get_current_trajectory_point());
        }

        _trajectory.resize(trajectory_point_count + 1);
        _trajectory_history.resize(history_point_count);

        _animation_player = cast_to<AnimationPlayer>(get_node(animation_player_path));
        if (_animation_player) {
            _animation_player->connect("animation_finished", Callable(this, "_on_animation_finished"));
            _animation_player->set_callback_mode_process(AnimationMixer::AnimationCallbackModeProcess::ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS);
        }

        _skeleton = cast_to<Skeleton3D>(get_node(skeleton_path));
        if (_skeleton && _animation_player) {
            StringName root_node_path = _animation_player->get_root_motion_track().get_concatenated_subnames();
            _root_bone_idx = _skeleton->find_bone(root_node_path);

            _skeleton->set_as_top_level(true);
            _skeleton->reset_bone_poses();

            _skeleton_state = SkeletonState(_skeleton);
            _reset_skeleton_state();
        }
    } break;
    }
}
