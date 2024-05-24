#include "mm_animation_player.h"

#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "mm_animation_library.h"
#include "mm_controller.h"
#include "spring.hpp"

using namespace godot;

MMAnimationPlayer::MMAnimationPlayer() : AnimationPlayer() {
}

MMAnimationPlayer::~MMAnimationPlayer() {
}

void MMAnimationPlayer::_ready() {
    AnimationPlayer::_ready();
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    set_callback_mode_process(
        godot::AnimationMixer::AnimationCallbackModeProcess::ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS);
    _default_halflife = halflife;

    NodePath skel_path =
        NodePath(UtilityFunctions::str(get_root_node()) + "/" + get_root_motion_track().get_concatenated_names());
    _skeleton = get_node<Skeleton3D>(skel_path);
    _skeleton_root_bone_path = get_root_motion_track().get_concatenated_subnames();
    _skeleton_root_bone_id = _skeleton->find_bone(_skeleton_root_bone_path);

    _skeleton->reset_bone_poses();
    _inertialize_reset();
    connect("animation_finished", Callable(this, "_on_animation_finished"));
}

void MMAnimationPlayer::_physics_process(double delta) {
    AnimationPlayer::_physics_process(delta);
    if (Engine::get_singleton()->is_editor_hint() || _last_animation.is_empty()) {
        return;
    }

    Ref<Animation> animation = get_current_animation().is_empty() ? nullptr : get_animation(get_current_animation());

    String skel_path = get_root_motion_track().get_concatenated_names();
    const auto motion_scale = _skeleton->get_motion_scale();

    const auto current_time = animation == nullptr
        ? 0.0
        : UtilityFunctions::clampf(get_current_animation_position(), 0.0, animation->get_length());
    const auto future_time =
        animation == nullptr ? delta : UtilityFunctions::clampf(current_time + delta, 0.0, animation->get_length());
    const auto delta_diff = abs(future_time - current_time);

    for (auto bone_id = 0; bone_id < _skeleton->get_bone_count(); ++bone_id) {
        const String bone_path = skel_path + String(":") + _skeleton->get_bone_name(bone_id);

        kform desired{};

        if (get_current_animation().is_empty()) {
            animation = get_animation(_last_animation);

            desired = _bones_kform[bone_id];

            const Transform3D bone_rest =
                _skeleton->get_bone_rest(bone_id).scaled_local(Vector3(1, 1, 1) * motion_scale);

            auto track_pos = animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
            if (track_pos != -1) {
                desired.pos = animation->position_track_interpolate(track_pos, _last_animation_time) * motion_scale;
            }
            auto track_rot = animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);
            if (track_rot != -1) {
                desired.rot = animation->rotation_track_interpolate(track_rot, _last_animation_time);
            }

            if (bone_id == _skeleton_root_bone_id) {
                desired.vel = desired.rot.xform_inv(desired.vel);
                desired.pos = Vector3();
                desired.rot = Quaternion();
            }

            // Spring::_simple_spring_damper_exact(_bones_kform.pos[bone_id], _bones_kform.vel[bone_id], desired.pos,
            //                                     halflife, delta);
            // Spring::_simple_spring_damper_exact(_bones_kform.rot[bone_id], _bones_kform.ang[bone_id], desired.rot,
            //                                     halflife, delta);
            // Spring::_decay_spring_damper_exact(_bones_offset.pos[bone_id], _bones_offset.vel[bone_id], halflife,
            // delta); Spring::_decay_spring_damper_exact(_bones_offset.rot[bone_id], _bones_offset.ang[bone_id],
            // halflife, delta);
            Spring::inertialize_update(_bones_kform.pos[bone_id],
                                       _bones_kform.vel[bone_id], // Current pos of the bone
                                       _bones_offset.pos[bone_id],
                                       _bones_offset.vel[bone_id], // Current Offset pos, get
                                                                   // reduced every frame
                                       desired.pos,
                                       desired.vel,                // Desired position from the animation
                                       halflife,                   // Stats on how the offset decay
                                       delta * get_speed_scale()); // delta time between frames
            Spring::inertialize_update(_bones_kform.rot[bone_id],
                                       _bones_kform.ang[bone_id], // Current rot of the bone
                                       _bones_offset.rot[bone_id],
                                       _bones_offset.ang[bone_id], // Current Offset rot, get
                                                                   // reduced every frame
                                       desired.rot,
                                       desired.ang,                // Desired rotation from the animation
                                       halflife,                   // Stats on how the offset decay
                                       delta * get_speed_scale()); // delta time between frames
        } else {
            desired.pos = _skeleton->get_bone_pose_position(bone_id);
            desired.vel = Vector3();
            desired.rot = _skeleton->get_bone_pose_rotation(bone_id);
            desired.ang = Vector3();

            const int track_pos = animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
            const int track_rot = animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);
            if (track_pos != -1) {
                desired.pos = animation->position_track_interpolate(track_pos, current_time) * motion_scale;
                desired.vel = UtilityFunctions::is_zero_approx(delta_diff)
                    ? Vector3()
                    : ((animation->position_track_interpolate(track_pos, future_time) * motion_scale) - desired.pos) /
                        delta_diff;
            }
            if (track_rot != -1) {
                desired.rot = animation->rotation_track_interpolate(track_rot, current_time);
                desired.ang = UtilityFunctions::is_zero_approx(delta_diff)
                    ? Vector3()
                    : Spring::quat_differentiate_angular_velocity(
                          animation->rotation_track_interpolate(track_rot, future_time), desired.rot, delta_diff);
            }

            if (bone_id == _skeleton_root_bone_id) {
                desired.vel = desired.rot.xform_inv(desired.vel);
                // desired_angular =
                // desired_rotation.xform_inv(desired_angular);
                desired.pos = Vector3();
                desired.rot = Quaternion();
            }
            Spring::inertialize_update(_bones_kform.pos[bone_id],
                                       _bones_kform.vel[bone_id], // Current pos of the bone
                                       _bones_offset.pos[bone_id],
                                       _bones_offset.vel[bone_id], // Current Offset pos, get
                                                                   // reduced every frame
                                       desired.pos,
                                       desired.vel,                // Desired position from the animation
                                       halflife,                   // Stats on how the offset decay
                                       delta * get_speed_scale()); // delta time between frames
            Spring::inertialize_update(_bones_kform.rot[bone_id],
                                       _bones_kform.ang[bone_id], // Current rot of the bone
                                       _bones_offset.rot[bone_id],
                                       _bones_offset.ang[bone_id], // Current Offset rot, get
                                                                   // reduced every frame
                                       desired.rot,
                                       desired.ang,                // Desired rotation from the animation
                                       halflife,                   // Stats on how the offset decay
                                       delta * get_speed_scale()); // delta time between frames
        }

        _skeleton->set_bone_pose_position(bone_id, _bones_kform.pos[bone_id]);
        _skeleton->set_bone_pose_rotation(bone_id, _bones_kform.rot[bone_id]);
        _skeleton->force_update_bone_child_transform(_skeleton_root_bone_id);
    }
}

void MMAnimationPlayer::bake_library_data() {
    TypedArray<StringName> library_list = get_animation_library_list();

    NodePath skel_path =
        NodePath(UtilityFunctions::str(get_root_node()) + "/" + get_root_motion_track().get_concatenated_names());
    Skeleton3D* skeleton = get_node<Skeleton3D>(skel_path);

    for (size_t i = 0; i < library_list.size(); ++i) {
        const StringName& library_name = library_list[i];
        Ref<MMAnimationLibrary> library = get_animation_library(library_name);
        library->bake_data(this, skeleton);
    }
}

void MMAnimationPlayer::request_animation(const String& p_animation_name, float p_time) {
    const auto motion_scale = _skeleton->get_motion_scale();
    Ref<Animation> p_animation = get_animation(p_animation_name);

    if (p_animation.is_null()) {
        return;
    }

    // ERR_FAIL_NULL_V(p_animation, false);
    _bones_kform.reserve(_skeleton->get_bone_count());
    _bones_offset.reserve(_skeleton->get_bone_count());
    //
    const float time_error = 0.02;
    UtilityFunctions::print(get_current_animation());
    if (p_animation_name == get_current_animation() && abs(p_time - get_current_animation_position()) < time_error) {
        // We are already playing
        return;
    }

    _last_animation = p_animation_name;
    _last_animation_time = p_time;

    const double delta = 0.016;

    p_time = UtilityFunctions::clampf(p_time, 0.0, p_animation->get_length());
    const auto future_time = UtilityFunctions::clampf(p_time + delta, 0.0, p_animation->get_length());

    for (auto bone_id = 0; bone_id < _skeleton->get_bone_count(); ++bone_id) {
        const Transform3D bone_rest = _skeleton->get_bone_rest(bone_id);
        const String skel_path = get_root_motion_track().get_concatenated_names();
        const String bone_path = UtilityFunctions::str(skel_path) + String(":") + _skeleton->get_bone_name(bone_id);

        auto track_pos = p_animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
        auto track_rot = p_animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);

        // POSITION 3D
        Vector3 desired_position = _bones_kform.pos[bone_id], desired_linear_vel = _bones_kform.vel[bone_id];
        if (track_pos != -1) {
            desired_position = p_animation->position_track_interpolate(track_pos, p_time) * motion_scale;
            desired_linear_vel =
                ((p_animation->position_track_interpolate(track_pos, future_time) * motion_scale) - desired_position) /
                abs(future_time - p_time);
        }

        // ROTATION 3D
        Quaternion desired_rotation = _bones_kform.rot[bone_id]; //_skeleton->get_bone_pose_rotation(bone_id);
        Vector3 desired_angular_vel = _bones_kform.ang[bone_id]; //
        Vector3{};
        if (track_rot != -1) {
            desired_rotation = p_animation->rotation_track_interpolate(track_rot, p_time).normalized();
            Quaternion r1 = p_animation->rotation_track_interpolate(track_rot, future_time).normalized();
            desired_angular_vel =
                Spring::quat_differentiate_angular_velocity(r1, desired_rotation, abs(future_time - p_time))
                    .normalized();
        }

        // ROOT BONE
        // Root bone have a special process
        if (NodePath(bone_path) == get_root_motion_track()) {
            auto rooting = desired_rotation.inverse();
            desired_position = Vector3();
            desired_linear_vel = rooting.xform(desired_linear_vel);
            desired_rotation = Quaternion();
            // desired_angular_vel doesn't change
        }

        // Offset are calculated Between current pos of the bone and the desired
        // pose
        Spring::inertialize_transition(_bones_offset.pos[bone_id], _bones_offset.vel[bone_id],
                                       _bones_kform.pos[bone_id], _bones_kform.vel[bone_id], desired_position,
                                       desired_linear_vel);
        Spring::inertialize_transition(_bones_offset.rot[bone_id],
                                       _bones_offset.ang[bone_id], // Offset are calculated...
                                       _bones_kform.rot[bone_id],
                                       _bones_kform.ang[bone_id],              // Between current rot of the bone...
                                       desired_rotation, desired_angular_vel); // and the desired pose
    }

    play(p_animation_name);
    seek(p_time, false);
}

void MMAnimationPlayer::request_pose(StringName p_animation_name, float p_time) {
    _last_animation = p_animation_name;
    _last_animation_time = p_time;
    // stop();
}

MMQueryResult MMAnimationPlayer::query(const MMQueryInput& p_query_input) {
    StringName library_name = get_animation_library_list()[0];

    Ref<MMAnimationLibrary> library = get_animation_library(library_name);
    return library->query(p_query_input);
}

Vector3 MMAnimationPlayer::get_root_motion_velocity() const {
    if (_skeleton_root_bone_id < 0) {
        return {};
    }
    return _bones_kform.vel[_skeleton_root_bone_id] * get_speed_scale();
}

Quaternion MMAnimationPlayer::get_root_motion_rotation_delta(float delta) const {
    if (_skeleton_root_bone_id < 0) {
        return {};
    }
    return Spring::quat_from_scaled_angle_axis(_bones_kform.ang[_skeleton_root_bone_id] * delta * get_playing_speed());
}

void MMAnimationPlayer::_inertialize_reset(bool skeleton_to_rest) {
    if (skeleton_to_rest) {
        _skeleton->reset_bone_poses();
    }

    const auto bone_count = _skeleton->get_bone_count();
    _bones_kform = kforms(bone_count);
    _bones_offset = kforms(bone_count);
    for (int b = 0; b < bone_count; ++b) {
        _bones_kform.reset(b);
        _bones_kform.pos[b] = _skeleton->get_bone_pose_position(b);
        _bones_kform.rot[b] = _skeleton->get_bone_pose_rotation(b);
        _bones_kform.scl[b] = _skeleton->get_bone_pose_scale(b);

        _bones_offset.reset(b);
    }
}

void MMAnimationPlayer::_on_animation_finished(StringName p_animation_name) {
    UtilityFunctions::print("Animation finished: " + p_animation_name);
    set_halflife(_default_halflife);
    auto p_animation = get_animation(p_animation_name);
    auto p_time = p_animation->get_length();

    _last_animation = p_animation_name;
    _last_animation_time = p_time;
}

void MMAnimationPlayer::_on_animation_changed(String p_animation_name) {
    UtilityFunctions::print("Animation changed: " + p_animation_name);
}

void MMAnimationPlayer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_animation_changed", "anim"), &MMAnimationPlayer::_on_animation_changed);
    ClassDB::bind_method(D_METHOD("_on_animation_finished", "anim"), &MMAnimationPlayer::_on_animation_finished);
    ClassDB::bind_method(D_METHOD("bake_library_data"), &MMAnimationPlayer::bake_library_data);
    ClassDB::bind_method(D_METHOD("request_animation", "animation_name", "time"), &MMAnimationPlayer::request_animation,
                         (0.0f));
    ClassDB::bind_method(D_METHOD("get_root_motion_velocity"), &MMAnimationPlayer::get_root_motion_velocity);
    ClassDB::bind_method(D_METHOD("get_root_motion_rotation_delta", "delta"),
                         &MMAnimationPlayer::get_root_motion_rotation_delta);

    BINDER_PROPERTY_PARAMS(MMAnimationPlayer, Variant::FLOAT, halflife, PROPERTY_HINT_RANGE, "0.0,1.0,0.01,or_greater");
}
