#include "mm_animation_library.h"

#include <godot_cpp/variant/utility_functions.hpp>

#include "common.h"
#include "features/mm_feature.h"

MMAnimationLibrary::MMAnimationLibrary() : AnimationLibrary() {}

MMAnimationLibrary::~MMAnimationLibrary() {}

void MMAnimationLibrary::bake_data() { UtilityFunctions::print("Baking data"); }

void MMAnimationLibrary::_bind_methods() {
  ClassDB::bind_method(D_METHOD("bake_data"), &MMAnimationLibrary::bake_data);

  BINDER_PROPERTY_PARAMS(
      MMAnimationLibrary, Variant::ARRAY, features, PROPERTY_HINT_TYPE_STRING,
      UtilityFunctions::str(Variant::OBJECT) + '/' +
          UtilityFunctions::str(Variant::BASIS) + ":MMFeature",
      PROPERTY_USAGE_DEFAULT);
}