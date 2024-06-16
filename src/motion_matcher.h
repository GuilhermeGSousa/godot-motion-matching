#pragma once

#include <godot_cpp/classes/node.hpp>

#include "mm_animation_player.h"
#include "mm_controller.h"

using namespace godot;

class MotionMatcher : public Node {
    GDCLASS(MotionMatcher, Node)

public:
    void _ready() override;
    void _physics_process(double delta) override;

    const PackedFloat32Array& get_last_query_result() const {
        return _last_query_result;
    }

    GETSET(NodePath, controller_path)
    GETSET(NodePath, character_path)
    GETSET(NodePath, animation_player_path)
    GETSET(float, query_frequency, 2.0f)

protected:
    static void _bind_methods();

    void _on_animation_finished(StringName p_animation_name);

private:
    MMController* _controller{nullptr};
    CharacterBody3D* _character{nullptr};
    MMAnimationPlayer* _animation_player{nullptr};
    float _time_since_last_query{0.f};
    bool _force_transition{false};

    PackedFloat32Array _last_query_result;
    MMQueryInput _last_query_input;
};