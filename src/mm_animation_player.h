#pragma once

#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>

#include "common.h"
#include "mm_bone_state.h"
#include "mm_query.h"

using namespace godot;

class MMController;

class MMAnimationPlayer : public AnimationPlayer {
    GDCLASS(MMAnimationPlayer, AnimationPlayer)

public:
    MMAnimationPlayer(/* args */);
    virtual ~MMAnimationPlayer();
    virtual void _ready() override;
    virtual void _physics_process(double delta) override;
    virtual void _process(double delta) override;

    void bake_library_data();
    void inertialize_transition(const String& p_animation_name, float p_time);
    void inertialize_update(float delta);
    const SkeletonState& get_skeleton_state() const {
        return _skeleton_state;
    }

    const Skeleton3D* get_skeleton() const {
        return _skeleton;
    }

    const Vector3& get_root_motion_linear_velocity() const;

    const Vector3& get_root_motion_angular_velocity() const;

    MMQueryOutput query(const MMQueryInput& p_query_input);

    GETSET(float, halflife, 0.1f);

protected:
    static void _bind_methods();

private:
    void _inertialize_reset(bool skeleton_to_rest = false);
    void _on_animation_finished(StringName p_animation_name);
    void _on_animation_changed(String p_animation_name);

private:
    float _default_halflife{0.1f};

    String _skeleton_root_bone_path;
    int32_t _skeleton_root_bone_id{-1};
    Skeleton3D* _skeleton{nullptr};

    SkeletonState _skeleton_state;
    SkeletonState _skeleton_offset;

    Quaternion _anim_root_rotation;
};
