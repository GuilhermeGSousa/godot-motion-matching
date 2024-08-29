#include "mm_controller.h"

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

Vector3 clamp_max_magnitude(const Vector3& vector, float maxMagnitude) {
    float magnitude = vector.length();
    if (magnitude > maxMagnitude) {
        return vector.normalized() * maxMagnitude;
    } else {
        return vector;
    }
}

MMController::MMController()
    : CharacterBody3D() {
}

MMController::~MMController() {
}

void MMController::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    _camera_pivot = get_node<Node3D>(camera_pivot);
    _camera_pivot_height = _camera_pivot->get_global_position().y;
    Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);

    while (!_history_buffer.is_full()) {
        _history_buffer.push(_get_current_trajectory_point());
    }
}

void MMController::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    Vector3 camera_pivot_position = get_global_position();
    camera_pivot_position.y += _camera_pivot_height;
    _camera_pivot->set_global_position(camera_pivot_position);
}

void MMController::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    Vector3 new_velocity = update_trajectory(delta);
    set_velocity(new_velocity);

    // Rotate the character to face the direction of velocity
    if (!is_strafing) {
        Vector3 direction = new_velocity.normalized();
        set_rotation(Vector3(0.0f, Math::atan2(direction.x, direction.z), 0.0f));
    } else {
        set_rotation(Vector3(0.0f, _camera_pivot->get_rotation().y, 0.0f));
    }
    move_and_slide();
}

void MMController::_input(const Ref<InputEvent>& event) {
    InputEventMouseMotion* mouse_event = Object::cast_to<InputEventMouseMotion>(*event);
    if (mouse_event) {
        const Vector2 rotation = mouse_event->get_relative() * mouse_sensitivity * -1.0;

        Vector3 current_pivot_rotation = _camera_pivot->get_rotation_degrees();
        current_pivot_rotation.x += rotation.y;
        current_pivot_rotation.x = UtilityFunctions::clampf(current_pivot_rotation.x, -30.f, 30.f);
        current_pivot_rotation.y += rotation.x;
        _camera_pivot->set_rotation_degrees(current_pivot_rotation);
    }
}

Vector3 MMController::update_trajectory(float delta_t) {
    Vector3 current_velocity = get_velocity();

    const Vector2 stick_input = Input::get_singleton()->get_vector("left", "right", "down", "up", 0.1f).rotated(_camera_pivot->get_rotation().y);

    // Get the world space acceleration vector.
    const Vector3 stick_input_world = Vector3(-stick_input.x, 0.f, stick_input.y);
    const Vector3 target_velocity = stick_input_world * max_speed;
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

    _generate_trajectory(new_velocity, target_velocity, delta_t);

    _update_history();

    return new_velocity;
}

MMTrajectoryPoint MMController::_get_current_trajectory_point() const {
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
        point.facing_angle = _camera_pivot->get_rotation().y;
    }
    return point;
}

void MMController::_generate_trajectory(const Vector3& p_current_velocity, const Vector3& p_target_velocity, float delta_time) {
    const float delta_t = 1.0f / simulation_samples_per_second;

    MMTrajectoryPoint point = _get_current_trajectory_point();

    Vector3 spring_acceleration = _spring_acceleration;

    for (size_t i = 0; i < trajectory_point_count; i++) {
        _trajectory[i] = point;

        // Update velocity
        const Vector3 up_velocity = point.velocity.dot(get_up_direction()) * get_up_direction();
        Vector3 ground_velocity = point.velocity - up_velocity;
        Array result = Spring::simple_spring_damper_exact(ground_velocity, spring_acceleration, p_target_velocity, halflife, delta_t);
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
            point.facing_angle = _camera_pivot->get_rotation().y;
        }

        // Update point with environment
        _update_point(point, delta_t);
    }

    if (_history_buffer.is_empty()) {
        return;
    }

    float time_in_past = 0.f;
    int current_index = 0;
    for (int i = _history_buffer.size() - 1; i >= 0; --i) {
        if (time_in_past >= (1.0 / simulation_samples_per_second)) {
            _previous_trajectory[current_index] = _history_buffer[i];
            time_in_past = 0.f;
            current_index++;
        }

        if (current_index >= history_point_count) {
            break;
        }

        time_in_past += delta_time;
    }
}

void MMController::_update_history() {
    _history_buffer.push(_get_current_trajectory_point());
}

void MMController::_update_point(MMTrajectoryPoint& point, float delta_t) {
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

void MMController::_fill_collision_state(const Ref<PhysicsTestMotionResult3D> collision_result, MMCollisionState& state) {
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

void MMController::_fall_to_floor(MMTrajectoryPoint& point, float delta_t) {
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

void MMController::_bind_methods() {
    ClassDB::bind_method(D_METHOD("update_trajectory", "current_velocity", "delta_t"), &MMController::update_trajectory);
    ClassDB::bind_method(D_METHOD("get_trajectory"), &MMController::get_trajectory_typed_array);
    ClassDB::bind_method(D_METHOD("get_previous_trajectory"), &MMController::get_previous_trajectory_typed_array);

    BINDER_PROPERTY_PARAMS(MMController, Variant::NODE_PATH, camera_pivot, PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Node3D");
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, halflife, PROPERTY_HINT_RANGE, "0.0,1.0,0.01,or_greater");
    BINDER_PROPERTY_PARAMS(MMController, Variant::INT, trajectory_point_count);
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, simulation_samples_per_second);
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, max_speed);
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, mouse_sensitivity);
    BINDER_PROPERTY_PARAMS(MMController, Variant::BOOL, is_strafing);
}