#pragma once

#include "features/mm_feature.h"

using namespace godot;

class MMTrajectoryFeature : public MMFeature {
  GDCLASS(MMTrajectoryFeature, MMFeature)

 public:
  MMTrajectoryFeature(/* args */);
  virtual ~MMTrajectoryFeature();

 protected:
  static void _bind_methods();
};