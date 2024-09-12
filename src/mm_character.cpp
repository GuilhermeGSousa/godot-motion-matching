#include "mm_character.h"

#include "math/spring.hpp"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event_mouse_motion.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/physics_server3d.hpp>
#include <godot_cpp/classes/physics_test_motion_parameters3d.hpp>
#include <godot_cpp/classes/physics_test_motion_result3d.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/shape3d.hpp>
#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/core/property_info.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "math/spring.hpp"

using namespace godot;

constexpr float QUERY_TIME_ERROR = 0.05;

MMCharacter::MMCharacter()
    : CharacterBody3D() {
}

MMCharacter::~MMCharacter() {
}

void MMCharacter::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    while (!_history_buffer.is_full()) {
        _history_buffer.push(_get_current_trajectory_point());
    }

    _trajectory.resize(trajectory_point_count);
    _trajectory_history.resize(history_point_count);

    _skeleton = get_node<Skeleton3D>(skeleton_path);
    _skeleton->set_as_top_level(true);
    _animation_player = get_node<MMAnimationPlayer>(animation_player_path);
    _animation_player->connect("animation_finished", Callable(this, "_on_animation_finished"));
    _animation_player->set_callback_mode_process(AnimationMixer::AnimationCallbackModeProcess::ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS);
}

void MMCharacter::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    _update_character(delta);

    if (!_skeleton) {
        return;
    }

    _update_query(delta);

    _apply_root_motion();

    _update_synchronizer(delta);
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

    // Update the velocity.
    Array result = Spring::simple_spring_damper_exact(
        current_velocity,
        _spring_acceleration,
        target_velocity,
        halflife,
        delta_t);
    Vector3 new_velocity = result[0];
    _spring_acceleration = result[1];

    if (!is_on_floor()) {
        new_velocity += get_gravity() * delta_t;
    }

    _generate_trajectory(new_velocity, delta_t);

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

void MMCharacter::_generate_trajectory(const Vector3& p_current_velocity, float delta_time) {
    const float delta_t = trajectory_delta_time;

    MMTrajectoryPoint point = _get_current_trajectory_point();

    Vector3 spring_acceleration = _spring_acceleration;

    // The first point represents the player's current position, and is not considered part
    // of the trajectory for motion matching
    for (size_t i = 0; i < trajectory_point_count + 1; i++) {
        _trajectory[i] = point;

        // Update velocity
        const Vector3 up_velocity = point.velocity.dot(get_up_direction()) * get_up_direction();
        Vector3 ground_velocity = point.velocity - up_velocity;
        Array result = Spring::simple_spring_damper_exact(ground_velocity, spring_acceleration, target_velocity, halflife, delta_t);
        point.velocity = result[0];
        spring_acceleration = result[1];

        if (!point.collision_state.on_floor) {
            point.velocity += up_velocity + get_gravity() * delta_t;
        }

        // Update facing
        if (point.velocity.length_squared() > SMALL_NUMBER && !is_strafing) {
            Vector3 direction = point.velocity.normalized();
            point.facing_angle = Math::atan2(direction.x, direction.z);
        } else {
            point.facing_angle = strafe_facing;
        }

        if (check_environment) {
            // Update point with environment
            _update_point(point, delta_t);
        } else {
            point.position += point.velocity * delta_t;
        }
    }
}

void MMCharacter::_update_history(double delta_t) {
    if (!_history_buffer.is_empty()) {
        float time_in_past = 0.f;
        int current_index = 0;
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

void MMCharacter::_update_point(MMTrajectoryPoint& point, float delta_t) {
    const real_t margin = 0.001;
    const Vector3 motion = point.velocity * delta_t;

    Ref<PhysicsTestMotionParameters3D> params;
    params.instantiate();
    params->set_from(point.get_transform(get_up_direction()));
    params->set_motion(motion);
    params->set_max_collisions(6);

    Ref<PhysicsTestMotionResult3D> collision_result;
    collision_result.instantiate();

    bool is_colliding = PhysicsServer3D::get_singleton()->body_test_motion(
        get_rid(),
        params,
        collision_result);

    if (!is_colliding) {
        // We move in the direction of motion as usual
        point.position += motion;

        // We reset the collision state
        point.collision_state = MMCollisionState();

        _fall_to_floor(point, delta_t);
        return;
    }

    _fill_collision_state(collision_result, point.collision_state);

    // Update final position
    Vector3 result_velocity = point.velocity;
    if (point.collision_state.against_wall) {
        result_velocity = result_velocity.slide(point.collision_state.wall_normal);
    }

    if (point.collision_state.on_floor) {
        result_velocity = result_velocity.slide(point.collision_state.floor_normal);
    }

    point.velocity = result_velocity;
    point.position += point.velocity * delta_t;

    _fall_to_floor(point, delta_t);
}

void MMCharacter::_fill_collision_state(const Ref<PhysicsTestMotionResult3D> collision_result, MMCollisionState& state) {
    real_t wall_depth = -1.0;
    real_t floor_depth = -1.0;

    state.on_floor = false;
    for (int i = collision_result->get_collision_count() - 1; i >= 0; i--) {
        real_t floor_angle = Math::acos(collision_result->get_collision_normal(i).dot(get_up_direction()));
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
    const Vector3 up_velocity = point.velocity.dot(get_up_direction()) * get_up_direction() + get_gravity() * delta_t;

    Ref<PhysicsTestMotionParameters3D> params;
    params.instantiate();
    params->set_from(point.get_transform(get_up_direction()));
    params->set_motion(up_velocity * delta_t);

    Ref<PhysicsTestMotionResult3D> collision_result;
    collision_result.instantiate();

    if (PhysicsServer3D::get_singleton()->body_test_motion(
            get_rid(),
            params,
            collision_result)) {
        point.position = collision_result->get_collision_point();
        point.collision_state.on_floor = true;
        point.collision_state.floor_normal = collision_result->get_collision_normal();
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
    input.skeleton_state = _animation_player->get_skeleton_state();
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
        const MMQueryOutput result = _animation_player->query(query_input);

        // Play selected animation
        // TODO: It would be nice if we could use _animation_player->get_current_animation() here instead
        // but that somtimes returns an empty string :/
        const bool has_current_animation = !_animation_player->get_current_animation().is_empty();
        const bool is_same_animation = has_current_animation && result.animation_match == _last_query_output.animation_match;
        const bool is_same_time = has_current_animation && abs(result.time_match - _animation_player->get_current_animation_position()) < QUERY_TIME_ERROR;

        if (!is_same_animation || !is_same_time) {
            // Non blending alternative, will probably be used once we have a better way to blend animations
            // _animation_player->play(result.animation_match);
            // _animation_player->seek(result.time_match);
            _animation_player->inertialize_transition(result.animation_match, result.time_match);
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

Dictionary MMCharacter::_output_to_dict(const MMQueryOutput& output) {
    Dictionary result;

    result.get_or_add("animation", output.animation_match);
    result.get_or_add("time", output.time_match);
    result.get_or_add("frame_data", output.matched_frame_data);
    result.merge(output.feature_costs);
    result.get_or_add("total_cost", output.cost);

    return result;
}

MMAnimationPlayer* MMCharacter::get_animation_player() const {
    return get_node<MMAnimationPlayer>(animation_player_path);
}

void MMCharacter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_trajectory"), &MMCharacter::get_trajectory_typed_array);
    ClassDB::bind_method(D_METHOD("get_previous_trajectory"), &MMCharacter::get_previous_trajectory_typed_array);
    ClassDB::bind_method(D_METHOD("_on_animation_finished", "anim"), &MMCharacter::_on_animation_finished);

    ADD_SIGNAL(MethodInfo("on_query_result", PropertyInfo(Variant::DICTIONARY, "data")));

    ADD_GROUP("Motion Matching", "");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::NODE_PATH, skeleton_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Skeleton3D");
    BINDER_PROPERTY_PARAMS(MMCharacter, Variant::NODE_PATH, animation_player_path, PROPERTY_HINT_NODE_PATH_VALID_TYPES, "MMAnimationPlayer");
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