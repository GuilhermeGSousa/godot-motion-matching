#pragma once

#include "common.h"
#include "mm_animation_player.h"

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/variant/node_path.hpp>

using namespace godot;

class MMCharacter : public CharacterBody3D {
    GDCLASS(MMCharacter, CharacterBody3D)

public:
    void _ready() override;
    virtual void _physics_process(double delta) override;

    GETSET(NodePath, animation_player_path);

protected:
    static void _bind_methods();

private:
    MMAnimationPlayer* _animation_player{nullptr};
};