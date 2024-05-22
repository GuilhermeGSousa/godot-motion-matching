#include "mm_trajectory_feature.h"

#include "mm_root_velocity_feature.h"

MMTrajectoryFeature::MMTrajectoryFeature() {
}

MMTrajectoryFeature::~MMTrajectoryFeature() {
}

size_t MMTrajectoryFeature::get_dimension_count() const {
    return size_t();
}

void MMTrajectoryFeature::setup_skeleton(const Node3D *p_animation_root,
                                         const Skeleton3D *p_skeleton,
                                         const String &p_root_bone) {
}

void MMTrajectoryFeature::setup_for_animation(Ref<Animation> animation) {
}

void MMTrajectoryFeature::_bind_methods() {
}

PackedFloat32Array
MMTrajectoryFeature::bake_animation_pose(Ref<Animation> p_animation,
                                         float time) const {
    return PackedFloat32Array();
}

PackedFloat32Array MMTrajectoryFeature::evaluate_runtime_data() const {
    return PackedFloat32Array();
}
