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
        godot::AnimationMixer::AnimationCallbackModeProcess::ANIMATION_CALLBACK_MODE_PROCESS_MANUAL);
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
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
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

void MMAnimationPlayer::inertialize_transition(const String& p_animation_name, float p_time) {
    const auto motion_scale = _skeleton->get_motion_scale();
    const Ref<Animation> animation = get_animation(p_animation_name);

    if (animation.is_null()) {
        return;
    }

    const float time = Math::clamp<float>(p_time, 0.0f, animation->get_length());
    const float past_delta = 0.01f;

    for (auto bone_id = 0; bone_id < _skeleton->get_bone_count(); ++bone_id) {
        Vector3 desired_pos;
        Vector3 desired_vel;
        Quaternion desired_rot;
        Vector3 desired_ang;

        const String skel_path = get_root_motion_track().get_concatenated_names();
        const String bone_path = UtilityFunctions::str(skel_path) + String(":") + _skeleton->get_bone_name(bone_id);

        const int32_t pos_track = animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
        const int32_t rot_track = animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);

        if (bone_id == _skeleton_root_bone_id) {
        } else {

            if (pos_track != -1) {
                desired_pos = animation->position_track_interpolate(pos_track, time);
                if (time < past_delta) {
                    desired_vel = Vector3(0, 0, 0);
                } else {
                    Vector3 previous_pos = animation->position_track_interpolate(pos_track, time - past_delta);
                    desired_vel = (desired_pos - previous_pos) / past_delta;
                }
            }

            if (rot_track != -1) {
                desired_rot = animation->rotation_track_interpolate(rot_track, time);
                if (time < past_delta) {
                    desired_ang = Vector3(0, 0, 0);
                } else {
                    Quaternion previous_rot = animation->rotation_track_interpolate(rot_track, time - past_delta);
                    desired_ang = Spring::quat_differentiate_angular_velocity(desired_rot, previous_rot, past_delta);
                }
            }
            Spring::inertialize_transition(_skeleton_offset[bone_id].pos, _skeleton_offset[bone_id].vel,
                                           _skeleton_state[bone_id].pos, _skeleton_state[bone_id].vel, desired_pos,
                                           desired_vel);
            Spring::inertialize_transition(_skeleton_offset[bone_id].rot, _skeleton_offset[bone_id].ang_vel,
                                           _skeleton_state[bone_id].rot, _skeleton_state[bone_id].ang_vel, desired_rot,
                                           desired_ang);
        }
    }
    play(p_animation_name);
    seek(time);
}

void MMAnimationPlayer::inertialize_update(float delta) {
    Ref<Animation> animation = get_current_animation().is_empty() ? nullptr : get_animation(get_current_animation());
    if (animation.is_null()) {
        return;
    }

    advance(delta);
    const float current_time = UtilityFunctions::clampf(get_current_animation_position(), 0.0, animation->get_length());
    for (auto bone_id = 0; bone_id < _skeleton->get_bone_count(); ++bone_id) {
        if (bone_id == _skeleton_root_bone_id) {
        } else {
            Vector3 desired_pos;
            Vector3 desired_vel;

            Quaternion desired_rot;
            Vector3 desired_ang;

            const String skel_path = get_root_motion_track().get_concatenated_names();
            const String bone_path = UtilityFunctions::str(skel_path) + String(":") + _skeleton->get_bone_name(bone_id);

            const int32_t pos_track = animation->find_track(bone_path, Animation::TrackType::TYPE_POSITION_3D);
            if (pos_track != -1) {
                desired_pos = animation->position_track_interpolate(pos_track, current_time);
                if (current_time < delta) {
                    desired_vel = Vector3(0, 0, 0);
                } else {
                    float previous_time = current_time - delta;
                    Vector3 previous_pos = animation->position_track_interpolate(pos_track, previous_time);
                    desired_vel = (desired_pos - previous_pos) / delta;
                }
            }

            const int32_t rot_track = animation->find_track(bone_path, Animation::TrackType::TYPE_ROTATION_3D);
            if (rot_track != -1) {
                desired_rot = animation->rotation_track_interpolate(rot_track, current_time);
                if (current_time < delta) {
                    desired_ang = Vector3(0, 0, 0);
                } else {
                    Quaternion previous_rot = animation->rotation_track_interpolate(rot_track, current_time - delta);
                    desired_ang = Spring::quat_differentiate_angular_velocity(desired_rot, previous_rot, delta);
                }
            }

            Spring::inertialize_update(_skeleton_state[bone_id].pos, _skeleton_state[bone_id].vel,
                                       _skeleton_offset[bone_id].pos, _skeleton_offset[bone_id].vel, desired_pos,
                                       desired_vel, get_halflife(), delta);
            Spring::inertialize_update(_skeleton_state[bone_id].rot, _skeleton_state[bone_id].ang_vel,
                                       _skeleton_offset[bone_id].rot, _skeleton_offset[bone_id].ang_vel, desired_rot,
                                       desired_ang, get_halflife(), delta);
        }

        // _skeleton->set_bone_pose_position(bone_id, _skeleton_state[bone_id].pos);
        // _skeleton->set_bone_pose_rotation(bone_id, _skeleton_state[bone_id].rot);
        // _skeleton->force_update_bone_child_transform(bone_id);
    }
}

MMQueryResult MMAnimationPlayer::query(const MMQueryInput& p_query_input) {
    StringName library_name = get_animation_library_list()[0];

    Ref<MMAnimationLibrary> library = get_animation_library(library_name);
    return library->query(p_query_input);
}

void MMAnimationPlayer::_inertialize_reset(bool skeleton_to_rest) {
    if (skeleton_to_rest) {
        _skeleton->reset_bone_poses();
    }

    const auto bone_count = _skeleton->get_bone_count();
    _skeleton_state = SkeletonState(bone_count);
    _skeleton_offset = SkeletonState(bone_count);
    for (int b = 0; b < bone_count; ++b) {
        _skeleton_state[b].pos = _skeleton->get_bone_pose_position(b);
        _skeleton_state[b].rot = _skeleton->get_bone_pose_rotation(b);
        _skeleton_state[b].scl = _skeleton->get_bone_pose_scale(b);
        _skeleton_offset[b].reset();
    }
}

void MMAnimationPlayer::_on_animation_finished(StringName p_animation_name) {
}

void MMAnimationPlayer::_on_animation_changed(String p_animation_name) {
}

void MMAnimationPlayer::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_animation_changed", "anim"), &MMAnimationPlayer::_on_animation_changed);
    ClassDB::bind_method(D_METHOD("_on_animation_finished", "anim"), &MMAnimationPlayer::_on_animation_finished);
    ClassDB::bind_method(D_METHOD("bake_library_data"), &MMAnimationPlayer::bake_library_data);
    ClassDB::bind_method(D_METHOD("inertialize_transition", "animation_name", "time"),
                         &MMAnimationPlayer::inertialize_transition, (0.0f));

    BINDER_PROPERTY_PARAMS(MMAnimationPlayer, Variant::FLOAT, halflife, PROPERTY_HINT_RANGE, "0.0,1.0,0.01,or_greater");
}
