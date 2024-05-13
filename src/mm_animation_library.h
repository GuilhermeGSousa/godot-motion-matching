#pragma once

#include <godot_cpp/classes/animation_library.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/typed_array.hpp>

using namespace godot;

class MMFeature;

class MMAnimationLibrary : public AnimationLibrary {
  GDCLASS(MMAnimationLibrary, AnimationLibrary)

 public:
  MMAnimationLibrary(/* args */);
  virtual ~MMAnimationLibrary();

  TypedArray<MMFeature> get_features() const { return features; }
  void set_features(const TypedArray<MMFeature>& p_features) {
    features = p_features;
  }

  void bake_data();

 protected:
  static void _bind_methods();

 private:
  TypedArray<MMFeature> features;
};
