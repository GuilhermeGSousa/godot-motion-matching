#pragma once

#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/skeleton3d.hpp>

#include "common.h"
#include "kform.hpp"
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

    void bake_library_data();
    void request_animation(const String& p_animation_name, float p_time);
    MMQueryResult query(const MMQueryInput& p_query_input);

    Vector3 get_root_motion_velocity() const;
    Quaternion get_root_motion_rotation_delta(float delta) const;

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

    String _last_animation = "";
    float _last_animation_time{0.f};

    Vector3 _root_motion_positon_delta;
    Quaternion _root_motion_rotation_delta;

    kforms _bones_kform{0}, _bones_offset{0};
};
