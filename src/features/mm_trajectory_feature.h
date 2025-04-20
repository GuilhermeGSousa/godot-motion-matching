#ifndef MM_TRAJECTORY_FEATURE_H
#define MM_TRAJECTORY_FEATURE_H

#include "common.h"
#include "features/mm_feature.h"
#include <cstdint>

using namespace godot;

class MMTrajectoryFeature : public MMFeature {
    GDCLASS(MMTrajectoryFeature, MMFeature)

public:
    MMTrajectoryFeature(/* args */);
    virtual ~MMTrajectoryFeature();

    virtual int64_t get_dimension_count() const override;

    virtual void setup_skeleton(const MMCharacter* p_character, const AnimationMixer* p_player, const Skeleton3D* p_skeleton) override;

    virtual void setup_for_animation(Ref<Animation> animation) override;

    virtual PackedFloat32Array bake_animation_pose(Ref<Animation> p_animation, double time) const override;

    virtual PackedFloat32Array evaluate_runtime_data(const MMQueryInput& p_query_input) const override;

    virtual void display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const override;

    virtual float calculate_normalized_weight(int64_t p_feature_dim) const override;

    TypedArray<Dictionary> get_trajectory_points(const Transform3D& p_character_transform, const PackedFloat32Array& p_trajectory_data) const;

    GETSET(double, past_delta_time, 0.1);
    GETSET(int64_t, past_frames, 1);
    GETSET(double, future_delta_time, 0.1);
    GETSET(int64_t, future_frames, 5);

    bool include_height{false};
    bool get_include_height() const;
    void set_include_height(bool value);

    GETSET(float, height_weight, 1.0);

    bool include_facing{true};
    bool get_include_facing() const;
    void set_include_facing(bool value);

    GETSET(float, facing_weight, 1.0);

protected:
    void _validate_property(PropertyInfo& p_property) const;
    static void _bind_methods();

private:
    uint32_t _get_point_dimension_count() const;

    int _root_bone{-1};
    NodePath _root_bone_path;
    int _root_position_track{-1};
    int _root_rotation_track{-1};
};

#endif // MM_TRAJECTORY_FEATURE_H
