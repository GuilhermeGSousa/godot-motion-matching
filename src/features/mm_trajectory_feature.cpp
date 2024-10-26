/**************************************************************************/
/*  mm_trajectory_feature.cpp                                             */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "mm_trajectory_feature.h"

#include "math/transforms.h"
#include "scene/animation/animation_player.h"
#include "scene/resources/3d/primitive_meshes.h"
#include "scene/resources/material.h"
#include "scene/resources/mesh.h"
#include <cstdint>

#ifdef TOOLS_ENABLED
#include "editor/plugins/node_3d_editor_gizmos.h"
#endif

MMTrajectoryFeature::MMTrajectoryFeature() {
}

MMTrajectoryFeature::~MMTrajectoryFeature() {
}

int64_t MMTrajectoryFeature::get_dimension_count() const {
    return _get_point_dimension_count() * (past_frames + future_frames);
}

void MMTrajectoryFeature::setup_skeleton(const AnimationMixer* p_player, const Skeleton3D* p_skeleton) {
    const StringName skel_path = p_player->get_root_motion_track().get_concatenated_names();
    const StringName root_bone_name = p_player->get_root_motion_track().get_concatenated_subnames();
    _root_bone = p_skeleton->find_bone(root_bone_name);

    _root_bone_path = String(skel_path) + ":" + String(root_bone_name);
}

void MMTrajectoryFeature::setup_for_animation(Ref<Animation> animation) {
    _root_position_track = animation->find_track(_root_bone_path, Animation::TrackType::TYPE_POSITION_3D);
    _root_rotation_track = animation->find_track(_root_bone_path, Animation::TrackType::TYPE_ROTATION_3D);
}

PackedFloat32Array MMTrajectoryFeature::bake_animation_pose(Ref<Animation> p_animation, double time) const {
    PackedFloat32Array result;

    const Vector3 current_pos =
        _root_position_track == -1 ? Vector3() : p_animation->position_track_interpolate(_root_position_track, time);

    const Quaternion current_rotation =
        _root_rotation_track == -1 ? Quaternion() : p_animation->rotation_track_interpolate(_root_rotation_track, time);

    auto add_frame = [this, &result, &p_animation, &current_pos, &current_rotation](double p_time) {
        Vector3 position;
        Quaternion rotation;
        if (_root_position_track != -1) {
            position = p_animation->position_track_interpolate(_root_position_track, p_time) - current_pos;
            position = current_rotation.xform_inv(position);
        }

        if (_root_rotation_track != -1) {
            rotation = p_animation->rotation_track_interpolate(_root_rotation_track, p_time) * current_rotation.inverse();
        }

        result.append(position.x);

        if (include_height) {
            result.append(position.y);
        }

        result.append(position.z);

        if (include_facing) {
            const Vector3 facing = rotation.get_euler();
            result.append(facing.y);
        }
    };

    // We do not include the first frame
    for (int64_t i = 1; i < future_frames + 1; i++) {
        const double future_time = CLAMP(time + future_delta_time * i, 0.0f, p_animation->get_length());

        add_frame(future_time);
    }

    for (int64_t i = 1; i < past_frames + 1; i++) {
        const double past_time = CLAMP(time - past_delta_time * i, 0.0f, p_animation->get_length());

        add_frame(past_time);
    }

    return result;
}

PackedFloat32Array MMTrajectoryFeature::evaluate_runtime_data(const MMQueryInput& p_query_input) const {
    const Transform3D& character_transform = p_query_input.character_transform;

    // Get the trajectory points in local space
    PackedFloat32Array result;
    auto add_point = [this, &character_transform, &result](int index, const MMTrajectoryPoint& trajectory_point) {
        const Vector3 local_position = character_transform.basis.xform_inv(trajectory_point.position - character_transform.origin);

        result.append(local_position.x);
        if (include_height) {
            result.append(local_position.y);
        }
        result.append(local_position.z);
        if (include_facing) {
            result.append(global_to_local_facing_angle(trajectory_point.facing_angle, character_transform));
        }
    };

    // The first point of the trajectory represents the player's current state
    // We do not match the first point of the trajectory (character position)
    for (int64_t i = 1; i < future_frames + 1; i++) {
        add_point(i, p_query_input.trajectory[i]);
    }

    for (int64_t i = 0; i < past_frames; i++) {
        add_point(i, p_query_input.trajectory_history[i]);
    }

    return result;
}

#ifdef TOOLS_ENABLED
void MMTrajectoryFeature::display_data(const Ref<EditorNode3DGizmo>& p_gizmo, const Transform3D p_transform, const float* p_data) const {

    Ref<StandardMaterial3D> material = p_gizmo->get_plugin()->get_material("main", p_gizmo);
    if (material.is_null()) {
        p_gizmo->get_plugin()->create_material("main", Color(1, 0, 0, 1));
        material = p_gizmo->get_plugin()->get_material("main", p_gizmo);
    }

    float* dernomalized_data = new float[get_dimension_count()];
    memcpy(dernomalized_data, p_data, sizeof(float) * get_dimension_count());
    denormalize(dernomalized_data);

    int64_t i = 0;
    for (; i < future_frames * _get_point_dimension_count(); i += _get_point_dimension_count()) {
        Ref<SphereMesh> sphere_mesh;
        sphere_mesh.instantiate();
        sphere_mesh->set_radius(0.10);
        sphere_mesh->set_height(0.10);
        sphere_mesh->set_material(material);

        MMTrajectoryPoint point;
        point.position = Vector3(dernomalized_data[i], include_height ? dernomalized_data[i + 1] : 0, include_height ? dernomalized_data[i + 2] : dernomalized_data[i + 1]);
        point.position = p_transform.xform(point.position);

        Transform3D point_transform = Transform3D();
        point_transform.origin = point.position;
        p_gizmo->add_mesh(sphere_mesh, material, point_transform, nullptr);
    }

    for (; i < get_dimension_count(); i += _get_point_dimension_count()) {
        Ref<SphereMesh> sphere_mesh;
        sphere_mesh.instantiate();
        sphere_mesh->set_radius(0.10);
        sphere_mesh->set_height(0.10);
        sphere_mesh->set_material(material);

        MMTrajectoryPoint point;
        point.position = Vector3(dernomalized_data[i], include_height ? dernomalized_data[i + 1] : 0, include_height ? dernomalized_data[i + 2] : dernomalized_data[i + 1]);
        point.position = p_transform.xform(point.position);

        Transform3D point_transform = Transform3D();
        point_transform.origin = point.position;
        p_gizmo->add_mesh(sphere_mesh, material, point_transform, nullptr);
    }

    delete[] dernomalized_data;
}
#endif

TypedArray<Dictionary> MMTrajectoryFeature::get_trajectory_points(const Transform3D& p_character_transform, const PackedFloat32Array& p_trajectory_data) const {
    ERR_FAIL_COND_V(p_trajectory_data.is_empty(), TypedArray<Dictionary>());

    PackedFloat32Array denormalized_data = PackedFloat32Array(p_trajectory_data);
    denormalize(denormalized_data.ptrw());

    TypedArray<Dictionary> result;
    const int offset = _get_point_dimension_count();
    for (int i = 0; i < future_frames * offset; i += offset) {
        MMTrajectoryPoint point;
        point.position = Vector3(denormalized_data[i], include_height ? denormalized_data[i + 1] : 0, include_height ? denormalized_data[i + 2] : denormalized_data[i + 1]);
        point.position = p_character_transform.xform(point.position);

        if (include_facing) {
            // const float local_facing_angle = denormalized_data[i + (include_height ? 3 : 2)];
            point.facing_angle = 0.0; // TODO
        }

        Dictionary data;
        data.get_or_add("position", point.position);
        data.get_or_add("facing", point.facing_angle);

        result.push_back(data);
    }
    return result;
}

void MMTrajectoryFeature::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_trajectory_points", "character_transform", "trajectory_data"), &MMTrajectoryFeature::get_trajectory_points);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, past_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, past_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::FLOAT, future_delta_time);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::INT, future_frames);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::BOOL, include_height);
    BINDER_PROPERTY_PARAMS(MMTrajectoryFeature, Variant::BOOL, include_facing);
}

uint32_t MMTrajectoryFeature::_get_point_dimension_count() const {
    size_t dimensions = 2; // x, z
    if (include_height) {
        dimensions++; // y
    }
    if (include_facing) {
        dimensions++; // facing
    }
    return dimensions;
}
