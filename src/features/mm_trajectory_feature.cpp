#include "mm_trajectory_feature.h"

#include "mm_root_velocity_feature.h"

MMTrajectoryFeature::MMTrajectoryFeature() {
}

MMTrajectoryFeature::~MMTrajectoryFeature() {
}

size_t MMTrajectoryFeature::get_dimension_count() const {
    return size_t();
}

void MMTrajectoryFeature::setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {
}

void MMTrajectoryFeature::setup_for_animation(Ref<Animation> animation) {
}

void MMTrajectoryFeature::_bind_methods() {
}

PackedFloat32Array MMTrajectoryFeature::bake_animation_pose(Ref<Animation> p_animation, float time) const {
    return PackedFloat32Array();
}

PackedFloat32Array MMTrajectoryFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    return PackedFloat32Array();
}
