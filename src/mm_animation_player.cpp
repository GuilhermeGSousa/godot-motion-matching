#include "mm_animation_player.h"

#include "math/spring.hpp"
#include "mm_animation_library.h"
#include "mm_character.h"

#include <godot_cpp/classes/animation.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

MMAnimationPlayer::MMAnimationPlayer()
    : AnimationPlayer() {
}

MMAnimationPlayer::~MMAnimationPlayer() {
}

void MMAnimationPlayer::_ready() {
    AnimationPlayer::_ready();
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    _default_halflife = halflife;

    NodePath skel_path = NodePath(UtilityFunctions::str(get_root_node()) + "/" + get_root_motion_track().get_concatenated_names());
    _skeleton = get_node<Skeleton3D>(skel_path);
    _skeleton_root_bone_path = get_root_motion_track().get_concatenated_subnames();
    _skeleton_root_bone_id = _skeleton->find_bone(_skeleton_root_bone_path);

    _skeleton->reset_bone_poses();
    _inertialize_reset();

    connect("animation_finished", Callable(this, "_on_animation_finished"));
}

void MMAnimationPlayer::_physics_process(double delta) {
    AnimationPlayer::_physics_process(delta);
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    if (get_callback_mode_process() == AnimationMixer::AnimationCallbackModeProcess::ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS) {
        inertialize_update(delta);
    }
}

void MMAnimationPlayer::_process(double delta) {
    AnimationPlayer::_process(delta);
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    if (get_callback_mode_process() == AnimationMixer::AnimationCallbackModeProcess::ANIMATION_CALLBACK_MODE_PROCESS_IDLE) {
        inertialize_update(delta);
    }
}

void MMAnimationPlayer::bake_library_data() {
    TypedArray<StringName> library_list = get_animation_library_list();

    NodePath skel_path = NodePath(UtilityFunctions::str(get_root_node()) + "/" + get_root_motion_track().get_concatenated_names());
    Skeleton3D* skeleton = get_node<Skeleton3D>(skel_path);

    for (size_t i = 0; i < library_list.size(); ++i) {
        const StringName& library_name = library_list[i];
        Ref<MMAnimationLibrary> library = get_animation_library(library_name);
        library->bake_data(this, skeleton);
    }
}

void MMAnimationPlayer::inertialize_transition(const String& p_animation_name, float p_time) {
    const auto motion_scale = _skeleton->get_motion_scale();
    const Ref<Animation> animation = get_animation(p_animation_name);

    if (animation.is_null()) {
        return;
    }

    const float time = Math::clamp<float>(p_time, 0.0f, animation->get_length());
    const float past_delta = 0.01f;

    for (auto bone_id = 0; bone_id < _skeleton->get_bone_count(); ++bone_id) {
        Vector3 desired_pos = _skeleton_state[bone_id].pos;
        Vector3 desired_vel = _skeleton_state[bone_id].vel;
        Quaternion desired_rot = _skeleton_state[bone_id].rot;
        Vector3 desired_ang = _skeleton_state[bone_id].ang_vel;

        const String skel_path = get_root_motion_track().get_concatenated_names();
        const String bone_path = UtilityFunctions::str(skel_path) + String(":") + _skeleton->get_bone_name(bone_id);

        const int32_t pos_track = animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
        const int32_t rot_track = animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);

        if (pos_track != -1) {
            desired_pos = animation->position_track_interpolate(pos_track, time);
            if (time >= past_delta) {
                Vector3 previous_pos = animation->position_track_interpolate(pos_track, time - past_delta);
                desired_vel = (desired_pos - previous_pos) / past_delta;
            }
        }

        if (rot_track != -1) {
            desired_rot = animation->rotation_track_interpolate(rot_track, time);
            if (time >= past_delta) {
                Quaternion previous_rot = animation->rotation_track_interpolate(rot_track, time - past_delta);
                desired_ang = Spring::quat_differentiate_angular_velocity(desired_rot, previous_rot, past_delta);
            }
        }

        if (bone_id == _skeleton_root_bone_id) {
            desired_pos = Vector3();
            desired_rot = Quaternion();
            desired_vel = Vector3();
        }

        Spring::inertialize_transition(_skeleton_offset[bone_id].pos, _skeleton_offset[bone_id].vel, _skeleton_state[bone_id].pos, _skeleton_state[bone_id].vel, desired_pos, desired_vel);
        Spring::inertialize_transition(_skeleton_offset[bone_id].rot, _skeleton_offset[bone_id].ang_vel, _skeleton_state[bone_id].rot, _skeleton_state[bone_id].ang_vel, desired_rot, desired_ang);
    }
    play(p_animation_name);
    seek(time);
}

void MMAnimationPlayer::inertialize_update(float delta) {
    Ref<Animation> animation = get_current_animation().is_empty() ? nullptr : get_animation(get_current_animation());
    if (animation.is_null()) {
        return;
    }

    const float current_time = UtilityFunctions::clampf(get_current_animation_position(), 0.0, animation->get_length());
    for (auto bone_id = 0; bone_id < _skeleton->get_bone_count(); ++bone_id) {
        Vector3 desired_pos = _skeleton_state[bone_id].pos;
        Vector3 desired_vel = _skeleton_state[bone_id].vel;
        Quaternion desired_rot = _skeleton_state[bone_id].rot;
        Vector3 desired_ang = _skeleton_state[bone_id].ang_vel;

        const String skel_path = get_root_motion_track().get_concatenated_names();
        const String bone_path = UtilityFunctions::str(skel_path) + String(":") + _skeleton->get_bone_name(bone_id);

        const int32_t pos_track = animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
        if (pos_track != -1) {
            desired_pos = animation->position_track_interpolate(pos_track, current_time);
            if (current_time >= delta) {
                float previous_time = current_time - delta;
                Vector3 previous_pos = animation->position_track_interpolate(pos_track, previous_time);
                desired_vel = (desired_pos - previous_pos) / delta;
            }
        }

        const int32_t rot_track = animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);
        if (rot_track != -1) {
            desired_rot = animation->rotation_track_interpolate(rot_track, current_time);
            if (current_time >= delta) {
                Quaternion previous_rot = animation->rotation_track_interpolate(rot_track, current_time - delta);
                desired_ang = Spring::quat_differentiate_angular_velocity(desired_rot, previous_rot, delta);
            }
        }

        if (bone_id == _skeleton_root_bone_id) {
            desired_pos = Vector3();
            desired_rot = Quaternion();
            desired_vel = Vector3();
        }

        Spring::inertialize_update(_skeleton_state[bone_id].pos, _skeleton_state[bone_id].vel, _skeleton_offset[bone_id].pos, _skeleton_offset[bone_id].vel, desired_pos, desired_vel, get_halflife(), delta);
        Spring::inertialize_update(_skeleton_state[bone_id].rot, _skeleton_state[bone_id].ang_vel, _skeleton_offset[bone_id].rot, _skeleton_offset[bone_id].ang_vel, desired_rot, desired_ang, get_halflife(), delta);
    }

    for (auto bone_id = 0; bone_id < _skeleton->get_bone_count(); ++bone_id) {
        _skeleton->set_bone_pose_position(bone_id, _skeleton_state[bone_id].pos);
        _skeleton->set_bone_pose_rotation(bone_id, _skeleton_state[bone_id].rot);
        _skeleton->force_update_bone_child_transform(bone_id);
    }
}

MMQueryOutput MMAnimationPlayer::query(const MMQueryInput& p_query_input) {
    StringName library_name = get_animation_library_list()[0];

    Ref<MMAnimationLibrary> library = get_animation_library(library_name);
    MMQueryOutput result = library->query(p_query_input);
    result.animation_match = UtilityFunctions::str(library_name) + "/" + result.animation_match;
    return result;
}

void MMAnimationPlayer::_inertialize_reset(bool skeleton_to_rest) {
    if (skeleton_to_rest) {
        _skeleton->reset_bone_poses();
    }

    _skeleton_state = SkeletonState(_skeleton);
    _skeleton_offset = SkeletonState(_skeleton);
    const auto bone_count = _skeleton->get_bone_count();
    for (int b = 0; b < bone_count; ++b) {
        _skeleton_state[b].pos = _skeleton->get_bone_pose_position(b);
        _skeleton_state[b].rot = _skeleton->get_bone_pose_rotation(b);
        _skeleton_state[b].scl = _skeleton->get_bone_pose_scale(b);
        _skeleton_offset[b].reset();
    }
}

void MMAnimationPlayer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("bake_library_data"), &MMAnimationPlayer::bake_library_data);
    ClassDB::bind_method(D_METHOD("inertialize_transition", "animation_name", "time"), &MMAnimationPlayer::inertialize_transition, (0.0f));

    BINDER_PROPERTY_PARAMS(MMAnimationPlayer, Variant::FLOAT, halflife, PROPERTY_HINT_RANGE, "0.0,1.0,0.01,or_greater");
}
