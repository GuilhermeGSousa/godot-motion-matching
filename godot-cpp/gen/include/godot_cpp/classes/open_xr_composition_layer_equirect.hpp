/**************************************************************************/
/*  open_xr_composition_layer_equirect.hpp                                */
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

#ifndef GODOT_CPP_OPEN_XR_COMPOSITION_LAYER_EQUIRECT_HPP
#define GODOT_CPP_OPEN_XR_COMPOSITION_LAYER_EQUIRECT_HPP

#include <godot_cpp/classes/open_xr_composition_layer.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class OpenXRCompositionLayerEquirect : public OpenXRCompositionLayer {
	GDEXTENSION_CLASS(OpenXRCompositionLayerEquirect, OpenXRCompositionLayer)

public:
	void set_radius(float p_radius);
	float get_radius() const;
	void set_central_horizontal_angle(float p_angle);
	float get_central_horizontal_angle() const;
	void set_upper_vertical_angle(float p_angle);
	float get_upper_vertical_angle() const;
	void set_lower_vertical_angle(float p_angle);
	float get_lower_vertical_angle() const;
	void set_fallback_segments(uint32_t p_segments);
	uint32_t get_fallback_segments() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		OpenXRCompositionLayer::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_OPEN_XR_COMPOSITION_LAYER_EQUIRECT_HPP
