/**************************************************************************/
/*  navigation_agent3d.hpp                                                */
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

// THIS FILE IS GENERATED. EDITS WILL BE LOST.

#ifndef GODOT_CPP_NAVIGATION_AGENT3D_HPP
#define GODOT_CPP_NAVIGATION_AGENT3D_HPP

#include <godot_cpp/classes/navigation_path_query_parameters3d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/packed_vector3_array.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/variant/vector3.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class NavigationPathQueryResult3D;

class NavigationAgent3D : public Node {
	GDEXTENSION_CLASS(NavigationAgent3D, Node)

public:
	RID get_rid() const;
	void set_avoidance_enabled(bool p_enabled);
	bool get_avoidance_enabled() const;
	void set_path_desired_distance(float p_desired_distance);
	float get_path_desired_distance() const;
	void set_target_desired_distance(float p_desired_distance);
	float get_target_desired_distance() const;
	void set_radius(float p_radius);
	float get_radius() const;
	void set_height(float p_height);
	float get_height() const;
	void set_path_height_offset(float p_path_height_offset);
	float get_path_height_offset() const;
	void set_use_3d_avoidance(bool p_enabled);
	bool get_use_3d_avoidance() const;
	void set_keep_y_velocity(bool p_enabled);
	bool get_keep_y_velocity() const;
	void set_neighbor_distance(float p_neighbor_distance);
	float get_neighbor_distance() const;
	void set_max_neighbors(int32_t p_max_neighbors);
	int32_t get_max_neighbors() const;
	void set_time_horizon_agents(float p_time_horizon);
	float get_time_horizon_agents() const;
	void set_time_horizon_obstacles(float p_time_horizon);
	float get_time_horizon_obstacles() const;
	void set_max_speed(float p_max_speed);
	float get_max_speed() const;
	void set_path_max_distance(float p_max_speed);
	float get_path_max_distance();
	void set_navigation_layers(uint32_t p_navigation_layers);
	uint32_t get_navigation_layers() const;
	void set_navigation_layer_value(int32_t p_layer_number, bool p_value);
	bool get_navigation_layer_value(int32_t p_layer_number) const;
	void set_pathfinding_algorithm(NavigationPathQueryParameters3D::PathfindingAlgorithm p_pathfinding_algorithm);
	NavigationPathQueryParameters3D::PathfindingAlgorithm get_pathfinding_algorithm() const;
	void set_path_postprocessing(NavigationPathQueryParameters3D::PathPostProcessing p_path_postprocessing);
	NavigationPathQueryParameters3D::PathPostProcessing get_path_postprocessing() const;
	void set_path_metadata_flags(BitField<NavigationPathQueryParameters3D::PathMetadataFlags> p_flags);
	BitField<NavigationPathQueryParameters3D::PathMetadataFlags> get_path_metadata_flags() const;
	void set_navigation_map(const RID &p_navigation_map);
	RID get_navigation_map() const;
	void set_target_position(const Vector3 &p_position);
	Vector3 get_target_position() const;
	void set_simplify_path(bool p_enabled);
	bool get_simplify_path() const;
	void set_simplify_epsilon(float p_epsilon);
	float get_simplify_epsilon() const;
	Vector3 get_next_path_position();
	void set_velocity_forced(const Vector3 &p_velocity);
	void set_velocity(const Vector3 &p_velocity);
	Vector3 get_velocity();
	float distance_to_target() const;
	Ref<NavigationPathQueryResult3D> get_current_navigation_result() const;
	PackedVector3Array get_current_navigation_path() const;
	int32_t get_current_navigation_path_index() const;
	bool is_target_reached() const;
	bool is_target_reachable();
	bool is_navigation_finished();
	Vector3 get_final_position();
	void set_avoidance_layers(uint32_t p_layers);
	uint32_t get_avoidance_layers() const;
	void set_avoidance_mask(uint32_t p_mask);
	uint32_t get_avoidance_mask() const;
	void set_avoidance_layer_value(int32_t p_layer_number, bool p_value);
	bool get_avoidance_layer_value(int32_t p_layer_number) const;
	void set_avoidance_mask_value(int32_t p_mask_number, bool p_value);
	bool get_avoidance_mask_value(int32_t p_mask_number) const;
	void set_avoidance_priority(float p_priority);
	float get_avoidance_priority() const;
	void set_debug_enabled(bool p_enabled);
	bool get_debug_enabled() const;
	void set_debug_use_custom(bool p_enabled);
	bool get_debug_use_custom() const;
	void set_debug_path_custom_color(const Color &p_color);
	Color get_debug_path_custom_color() const;
	void set_debug_path_custom_point_size(float p_point_size);
	float get_debug_path_custom_point_size() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Node::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_NAVIGATION_AGENT3D_HPP
