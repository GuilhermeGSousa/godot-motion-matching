#pragma once

#include <godot_cpp/classes/animation_player.hpp>

using namespace godot;

class MMAnimationPlayer : public AnimationPlayer {
  GDCLASS(MMAnimationPlayer, AnimationPlayer)

 public:
  MMAnimationPlayer(/* args */);
  virtual ~MMAnimationPlayer();

 protected:
  static void _bind_methods();
};
