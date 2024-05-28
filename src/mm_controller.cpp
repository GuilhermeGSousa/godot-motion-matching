#include "mm_controller.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event_mouse_motion.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/core/property_info.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Vector3 clamp_max_magnitude(const Vector3& vector, float maxMagnitude) {
    float magnitude = vector.length();
    if (magnitude > maxMagnitude) {
        return vector.normalized() * maxMagnitude;
    } else {
        return vector;
    }
}

MMController::MMController() : CharacterBody3D() {
}

MMController::~MMController() {
}

void MMController::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    _camera_pivot = get_node<Node3D>(camera_pivot);
    _camera_pivot_height = _camera_pivot->get_global_position().y;
    _trajectory_buffer.resize(trajectory_point_count);
    Input::get_singleton()->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);
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
    Vector3 new_velocity = update_trajectory(get_velocity(), delta);
    set_velocity(new_velocity);

    // Rotate the character to face the direction of velocity
    if (new_velocity.length_squared() > 0.1 && !is_strafing) {
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

Vector3 MMController::update_trajectory(const Vector3& current_velocity, float delta_t) {
    Vector3 new_velocity = current_velocity;

    const Vector2 stick_input = Input::get_singleton()
                                    ->get_vector("left", "right", "down", "up", 0.1f)
                                    .rotated(_camera_pivot->get_rotation().y);

    // Get the world space acceleration vector.
    const Vector3 stick_input_world = Vector3(-stick_input.x, 0.f, stick_input.y);

    const Vector3 acceleration = stick_input_world * 10.0f;

    // Update the velocity.
    new_velocity += acceleration * delta_t;
    new_velocity -= new_velocity * friction * delta_t;
    new_velocity = clamp_max_magnitude(new_velocity, max_speed);

    _generate_trajectory(new_velocity, acceleration);
    _update_history();

    return new_velocity;
}

void MMController::_generate_trajectory(const Vector3& p_current_velocity, const Vector3& p_current_acceleration) {
    const float delta_t = 1.0f / simulation_samples_per_second;

    Vector3 current_position = get_global_transform().origin;
    Vector3 current_velocity = p_current_velocity;
    Vector3 current_acceleration = p_current_acceleration;
    _trajectory_buffer.clear();
    _trajectory_buffer.reserve(trajectory_point_count);

    for (size_t i = 0; i < trajectory_point_count; i++) {
        MMTrajectoryPoint point;
        point.position = current_position;
        point.velocity = current_velocity;

        _trajectory_buffer.push_back(point);

        // Update velocity
        current_velocity += current_acceleration * delta_t;
        current_velocity -= current_velocity * friction * delta_t;
        current_velocity = clamp_max_magnitude(current_velocity, max_speed);

        // Update position
        current_position += current_velocity * delta_t;
    }
}

void MMController::_update_history() {
}

void MMController::_bind_methods() {
    ClassDB::bind_method(D_METHOD("update_trajectory", "current_velocity", "delta_t"),
                         &MMController::update_trajectory);

    ClassDB::bind_method(D_METHOD("get_trajectory_positions"), &MMController::get_trajectory_positions);

    BINDER_PROPERTY_PARAMS(MMController, Variant::NODE_PATH, camera_pivot, PROPERTY_HINT_NODE_PATH_VALID_TYPES,
                           "Node3D");
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, friction);
    BINDER_PROPERTY_PARAMS(MMController, Variant::INT, trajectory_point_count);
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, simulation_samples_per_second);
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, max_speed);
    BINDER_PROPERTY_PARAMS(MMController, Variant::FLOAT, mouse_sensitivity);
    BINDER_PROPERTY_PARAMS(MMController, Variant::BOOL, is_strafing);
}