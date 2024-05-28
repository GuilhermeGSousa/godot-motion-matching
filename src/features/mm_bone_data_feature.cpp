#include "features/mm_bone_data_feature.h"
#include "mm_bone_data_feature.h"

#include "mm_bone_state.h"

void MMBoneDataFeature::setup_skeleton(const MMAnimationPlayer* p_player, const Skeleton3D* p_skeleton) {
}

void MMBoneDataFeature::setup_for_animation(Ref<Animation> animation) {
}

size_t MMBoneDataFeature::get_dimension_count() const {
    return bone_names.size() * 3;
}

PackedFloat32Array MMBoneDataFeature::bake_animation_pose(Ref<Animation> p_animation, float time) const {
    return PackedFloat32Array();
}

PackedFloat32Array MMBoneDataFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    return PackedFloat32Array();
}

void MMBoneDataFeature::debug_gizmo(Ref<EditorNode3DGizmo> gizmo, const PackedFloat32Array data,
                                    godot::Transform3D tr) {
}

void MMBoneDataFeature::_bind_methods() {
    BINDER_PROPERTY_PARAMS(MMBoneDataFeature, Variant::PACKED_STRING_ARRAY, bone_names);
}
