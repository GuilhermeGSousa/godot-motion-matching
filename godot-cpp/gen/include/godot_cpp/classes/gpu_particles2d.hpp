/**************************************************************************/
/*  gpu_particles2d.hpp                                                   */
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

#ifndef GODOT_CPP_GPU_PARTICLES2D_HPP
#define GODOT_CPP_GPU_PARTICLES2D_HPP

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/variant/rect2.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

struct Color;
class Material;
class Node;
class Texture2D;
struct Transform2D;
struct Vector2;

class GPUParticles2D : public Node2D {
	GDEXTENSION_CLASS(GPUParticles2D, Node2D)

public:
	enum DrawOrder {
		DRAW_ORDER_INDEX = 0,
		DRAW_ORDER_LIFETIME = 1,
		DRAW_ORDER_REVERSE_LIFETIME = 2,
	};

	enum EmitFlags {
		EMIT_FLAG_POSITION = 1,
		EMIT_FLAG_ROTATION_SCALE = 2,
		EMIT_FLAG_VELOCITY = 4,
		EMIT_FLAG_COLOR = 8,
		EMIT_FLAG_CUSTOM = 16,
	};

	void set_emitting(bool p_emitting);
	void set_amount(int32_t p_amount);
	void set_lifetime(double p_secs);
	void set_one_shot(bool p_secs);
	void set_pre_process_time(double p_secs);
	void set_explosiveness_ratio(float p_ratio);
	void set_randomness_ratio(float p_ratio);
	void set_visibility_rect(const Rect2 &p_visibility_rect);
	void set_use_local_coordinates(bool p_enable);
	void set_fixed_fps(int32_t p_fps);
	void set_fractional_delta(bool p_enable);
	void set_interpolate(bool p_enable);
	void set_process_material(const Ref<Material> &p_material);
	void set_speed_scale(double p_scale);
	void set_collision_base_size(float p_size);
	void set_interp_to_end(float p_interp);
	bool is_emitting() const;
	int32_t get_amount() const;
	double get_lifetime() const;
	bool get_one_shot() const;
	double get_pre_process_time() const;
	float get_explosiveness_ratio() const;
	float get_randomness_ratio() const;
	Rect2 get_visibility_rect() const;
	bool get_use_local_coordinates() const;
	int32_t get_fixed_fps() const;
	bool get_fractional_delta() const;
	bool get_interpolate() const;
	Ref<Material> get_process_material() const;
	double get_speed_scale() const;
	float get_collision_base_size() const;
	float get_interp_to_end() const;
	void set_draw_order(GPUParticles2D::DrawOrder p_order);
	GPUParticles2D::DrawOrder get_draw_order() const;
	void set_texture(const Ref<Texture2D> &p_texture);
	Ref<Texture2D> get_texture() const;
	Rect2 capture_rect() const;
	void restart();
	void set_sub_emitter(const NodePath &p_path);
	NodePath get_sub_emitter() const;
	void emit_particle(const Transform2D &p_xform, const Vector2 &p_velocity, const Color &p_color, const Color &p_custom, uint32_t p_flags);
	void set_trail_enabled(bool p_enabled);
	void set_trail_lifetime(double p_secs);
	bool is_trail_enabled() const;
	double get_trail_lifetime() const;
	void set_trail_sections(int32_t p_sections);
	int32_t get_trail_sections() const;
	void set_trail_section_subdivisions(int32_t p_subdivisions);
	int32_t get_trail_section_subdivisions() const;
	void convert_from_particles(Node *p_particles);
	void set_amount_ratio(float p_ratio);
	float get_amount_ratio() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Node2D::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(GPUParticles2D::DrawOrder);
VARIANT_ENUM_CAST(GPUParticles2D::EmitFlags);

#endif // ! GODOT_CPP_GPU_PARTICLES2D_HPP
