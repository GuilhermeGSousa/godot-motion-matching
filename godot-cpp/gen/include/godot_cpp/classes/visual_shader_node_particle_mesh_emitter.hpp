/**************************************************************************/
/*  visual_shader_node_particle_mesh_emitter.hpp                          */
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

#ifndef GODOT_CPP_VISUAL_SHADER_NODE_PARTICLE_MESH_EMITTER_HPP
#define GODOT_CPP_VISUAL_SHADER_NODE_PARTICLE_MESH_EMITTER_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/visual_shader_node_particle_emitter.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Mesh;

class VisualShaderNodeParticleMeshEmitter : public VisualShaderNodeParticleEmitter {
	GDEXTENSION_CLASS(VisualShaderNodeParticleMeshEmitter, VisualShaderNodeParticleEmitter)

public:
	void set_mesh(const Ref<Mesh> &p_mesh);
	Ref<Mesh> get_mesh() const;
	void set_use_all_surfaces(bool p_enabled);
	bool is_use_all_surfaces() const;
	void set_surface_index(int32_t p_surface_index);
	int32_t get_surface_index() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		VisualShaderNodeParticleEmitter::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_VISUAL_SHADER_NODE_PARTICLE_MESH_EMITTER_HPP
