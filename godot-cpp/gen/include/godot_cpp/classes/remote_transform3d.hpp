/**************************************************************************/
/*  remote_transform3d.hpp                                                */
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

#ifndef GODOT_CPP_REMOTE_TRANSFORM3D_HPP
#define GODOT_CPP_REMOTE_TRANSFORM3D_HPP

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/node_path.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class RemoteTransform3D : public Node3D {
	GDEXTENSION_CLASS(RemoteTransform3D, Node3D)

public:
	void set_remote_node(const NodePath &p_path);
	NodePath get_remote_node() const;
	void force_update_cache();
	void set_use_global_coordinates(bool p_use_global_coordinates);
	bool get_use_global_coordinates() const;
	void set_update_position(bool p_update_remote_position);
	bool get_update_position() const;
	void set_update_rotation(bool p_update_remote_rotation);
	bool get_update_rotation() const;
	void set_update_scale(bool p_update_remote_scale);
	bool get_update_scale() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Node3D::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_REMOTE_TRANSFORM3D_HPP
