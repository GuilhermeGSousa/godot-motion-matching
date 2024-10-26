/**************************************************************************/
/*  rd_pipeline_rasterization_state.hpp                                   */
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

#ifndef GODOT_CPP_RD_PIPELINE_RASTERIZATION_STATE_HPP
#define GODOT_CPP_RD_PIPELINE_RASTERIZATION_STATE_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/rendering_device.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class RDPipelineRasterizationState : public RefCounted {
	GDEXTENSION_CLASS(RDPipelineRasterizationState, RefCounted)

public:
	void set_enable_depth_clamp(bool p_member);
	bool get_enable_depth_clamp() const;
	void set_discard_primitives(bool p_member);
	bool get_discard_primitives() const;
	void set_wireframe(bool p_member);
	bool get_wireframe() const;
	void set_cull_mode(RenderingDevice::PolygonCullMode p_member);
	RenderingDevice::PolygonCullMode get_cull_mode() const;
	void set_front_face(RenderingDevice::PolygonFrontFace p_member);
	RenderingDevice::PolygonFrontFace get_front_face() const;
	void set_depth_bias_enabled(bool p_member);
	bool get_depth_bias_enabled() const;
	void set_depth_bias_constant_factor(float p_member);
	float get_depth_bias_constant_factor() const;
	void set_depth_bias_clamp(float p_member);
	float get_depth_bias_clamp() const;
	void set_depth_bias_slope_factor(float p_member);
	float get_depth_bias_slope_factor() const;
	void set_line_width(float p_member);
	float get_line_width() const;
	void set_patch_control_points(uint32_t p_member);
	uint32_t get_patch_control_points() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		RefCounted::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_RD_PIPELINE_RASTERIZATION_STATE_HPP
