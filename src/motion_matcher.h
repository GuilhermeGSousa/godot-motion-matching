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

    GETSET(NodePath, controller_path)
    GETSET(NodePath, animation_player_path)
protected:
    static void _bind_methods();

private:
    MMController* _controller{nullptr};
    MMAnimationPlayer* _animation_player{nullptr};
};