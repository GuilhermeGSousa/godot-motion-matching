#pragma once

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class MMFeature : public Resource {
  GDCLASS(MMFeature, Resource)

 public:
  MMFeature(/* args */);
  virtual ~MMFeature();

 protected:
  static void _bind_methods();
};