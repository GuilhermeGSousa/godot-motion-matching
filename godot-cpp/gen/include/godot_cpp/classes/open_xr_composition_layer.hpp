/**************************************************************************/
/*  open_xr_composition_layer.hpp                                         */
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

#ifndef GODOT_CPP_OPEN_XR_COMPOSITION_LAYER_HPP
#define GODOT_CPP_OPEN_XR_COMPOSITION_LAYER_HPP

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector2i.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class JavaObject;
class SubViewport;
struct Vector3;

class OpenXRCompositionLayer : public Node3D {
	GDEXTENSION_CLASS(OpenXRCompositionLayer, Node3D)

public:
	void set_layer_viewport(SubViewport *p_viewport);
	SubViewport *get_layer_viewport() const;
	void set_use_android_surface(bool p_enable);
	bool get_use_android_surface() const;
	void set_android_surface_size(const Vector2i &p_size);
	Vector2i get_android_surface_size() const;
	void set_enable_hole_punch(bool p_enable);
	bool get_enable_hole_punch() const;
	void set_sort_order(int32_t p_order);
	int32_t get_sort_order() const;
	void set_alpha_blend(bool p_enabled);
	bool get_alpha_blend() const;
	Ref<JavaObject> get_android_surface();
	bool is_natively_supported() const;
	Vector2 intersects_ray(const Vector3 &p_origin, const Vector3 &p_direction) const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Node3D::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_OPEN_XR_COMPOSITION_LAYER_HPP
