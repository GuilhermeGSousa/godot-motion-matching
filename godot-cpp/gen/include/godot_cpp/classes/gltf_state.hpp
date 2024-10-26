/**************************************************************************/
/*  gltf_state.hpp                                                        */
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

#ifndef GODOT_CPP_GLTF_STATE_HPP
#define GODOT_CPP_GLTF_STATE_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/packed_int32_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class AnimationPlayer;
class GLTFAccessor;
class GLTFAnimation;
class GLTFBufferView;
class GLTFCamera;
class GLTFLight;
class GLTFMesh;
class GLTFNode;
class GLTFSkeleton;
class GLTFSkin;
class GLTFTexture;
class GLTFTextureSampler;
class Material;
class Node;
class StringName;
class Texture2D;

class GLTFState : public Resource {
	GDEXTENSION_CLASS(GLTFState, Resource)

public:
	static const int HANDLE_BINARY_DISCARD_TEXTURES = 0;
	static const int HANDLE_BINARY_EXTRACT_TEXTURES = 1;
	static const int HANDLE_BINARY_EMBED_AS_BASISU = 2;
	static const int HANDLE_BINARY_EMBED_AS_UNCOMPRESSED = 3;

	void add_used_extension(const String &p_extension_name, bool p_required);
	int32_t append_data_to_buffers(const PackedByteArray &p_data, bool p_deduplication);
	int32_t append_gltf_node(const Ref<GLTFNode> &p_gltf_node, Node *p_godot_scene_node, int32_t p_parent_node_index);
	Dictionary get_json();
	void set_json(const Dictionary &p_json);
	int32_t get_major_version();
	void set_major_version(int32_t p_major_version);
	int32_t get_minor_version();
	void set_minor_version(int32_t p_minor_version);
	String get_copyright() const;
	void set_copyright(const String &p_copyright);
	PackedByteArray get_glb_data();
	void set_glb_data(const PackedByteArray &p_glb_data);
	bool get_use_named_skin_binds();
	void set_use_named_skin_binds(bool p_use_named_skin_binds);
	TypedArray<GLTFNode> get_nodes();
	void set_nodes(const TypedArray<GLTFNode> &p_nodes);
	TypedArray<PackedByteArray> get_buffers();
	void set_buffers(const TypedArray<PackedByteArray> &p_buffers);
	TypedArray<GLTFBufferView> get_buffer_views();
	void set_buffer_views(const TypedArray<GLTFBufferView> &p_buffer_views);
	TypedArray<GLTFAccessor> get_accessors();
	void set_accessors(const TypedArray<GLTFAccessor> &p_accessors);
	TypedArray<GLTFMesh> get_meshes();
	void set_meshes(const TypedArray<GLTFMesh> &p_meshes);
	int32_t get_animation_players_count(int32_t p_idx);
	AnimationPlayer *get_animation_player(int32_t p_idx);
	TypedArray<Material> get_materials();
	void set_materials(const TypedArray<Material> &p_materials);
	String get_scene_name();
	void set_scene_name(const String &p_scene_name);
	String get_base_path();
	void set_base_path(const String &p_base_path);
	String get_filename() const;
	void set_filename(const String &p_filename);
	PackedInt32Array get_root_nodes();
	void set_root_nodes(const PackedInt32Array &p_root_nodes);
	TypedArray<GLTFTexture> get_textures();
	void set_textures(const TypedArray<GLTFTexture> &p_textures);
	TypedArray<GLTFTextureSampler> get_texture_samplers();
	void set_texture_samplers(const TypedArray<GLTFTextureSampler> &p_texture_samplers);
	TypedArray<Texture2D> get_images();
	void set_images(const TypedArray<Texture2D> &p_images);
	TypedArray<GLTFSkin> get_skins();
	void set_skins(const TypedArray<GLTFSkin> &p_skins);
	TypedArray<GLTFCamera> get_cameras();
	void set_cameras(const TypedArray<GLTFCamera> &p_cameras);
	TypedArray<GLTFLight> get_lights();
	void set_lights(const TypedArray<GLTFLight> &p_lights);
	TypedArray<String> get_unique_names();
	void set_unique_names(const TypedArray<String> &p_unique_names);
	TypedArray<String> get_unique_animation_names();
	void set_unique_animation_names(const TypedArray<String> &p_unique_animation_names);
	TypedArray<GLTFSkeleton> get_skeletons();
	void set_skeletons(const TypedArray<GLTFSkeleton> &p_skeletons);
	bool get_create_animations();
	void set_create_animations(bool p_create_animations);
	bool get_import_as_skeleton_bones();
	void set_import_as_skeleton_bones(bool p_import_as_skeleton_bones);
	TypedArray<GLTFAnimation> get_animations();
	void set_animations(const TypedArray<GLTFAnimation> &p_animations);
	Node *get_scene_node(int32_t p_idx);
	int32_t get_node_index(Node *p_scene_node);
	Variant get_additional_data(const StringName &p_extension_name);
	void set_additional_data(const StringName &p_extension_name, const Variant &p_additional_data);
	int32_t get_handle_binary_image();
	void set_handle_binary_image(int32_t p_method);
	void set_bake_fps(double p_value);
	double get_bake_fps() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Resource::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_GLTF_STATE_HPP
