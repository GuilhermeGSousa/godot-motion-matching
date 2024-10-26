/**************************************************************************/
/*  gltf_state.cpp                                                        */
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

#include <godot_cpp/classes/gltf_state.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/gltf_accessor.hpp>
#include <godot_cpp/classes/gltf_animation.hpp>
#include <godot_cpp/classes/gltf_buffer_view.hpp>
#include <godot_cpp/classes/gltf_camera.hpp>
#include <godot_cpp/classes/gltf_light.hpp>
#include <godot_cpp/classes/gltf_mesh.hpp>
#include <godot_cpp/classes/gltf_node.hpp>
#include <godot_cpp/classes/gltf_skeleton.hpp>
#include <godot_cpp/classes/gltf_skin.hpp>
#include <godot_cpp/classes/gltf_texture.hpp>
#include <godot_cpp/classes/gltf_texture_sampler.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/string_name.hpp>

namespace godot {

void GLTFState::add_used_extension(const String &p_extension_name, bool p_required) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("add_used_extension")._native_ptr(), 2678287736);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_required_encoded;
	PtrToArg<bool>::encode(p_required, &p_required_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_extension_name, &p_required_encoded);
}

int32_t GLTFState::append_data_to_buffers(const PackedByteArray &p_data, bool p_deduplication) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("append_data_to_buffers")._native_ptr(), 1460416665);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	int8_t p_deduplication_encoded;
	PtrToArg<bool>::encode(p_deduplication, &p_deduplication_encoded);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, &p_data, &p_deduplication_encoded);
}

int32_t GLTFState::append_gltf_node(const Ref<GLTFNode> &p_gltf_node, Node *p_godot_scene_node, int32_t p_parent_node_index) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("append_gltf_node")._native_ptr(), 3562288551);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	int64_t p_parent_node_index_encoded;
	PtrToArg<int64_t>::encode(p_parent_node_index, &p_parent_node_index_encoded);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, (p_gltf_node != nullptr ? &p_gltf_node->_owner : nullptr), (p_godot_scene_node != nullptr ? &p_godot_scene_node->_owner : nullptr), &p_parent_node_index_encoded);
}

Dictionary GLTFState::get_json() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_json")._native_ptr(), 2382534195);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Dictionary());
	return internal::_call_native_mb_ret<Dictionary>(_gde_method_bind, _owner);
}

void GLTFState::set_json(const Dictionary &p_json) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_json")._native_ptr(), 4155329257);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_json);
}

int32_t GLTFState::get_major_version() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_major_version")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void GLTFState::set_major_version(int32_t p_major_version) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_major_version")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_major_version_encoded;
	PtrToArg<int64_t>::encode(p_major_version, &p_major_version_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_major_version_encoded);
}

int32_t GLTFState::get_minor_version() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_minor_version")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void GLTFState::set_minor_version(int32_t p_minor_version) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_minor_version")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_minor_version_encoded;
	PtrToArg<int64_t>::encode(p_minor_version, &p_minor_version_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_minor_version_encoded);
}

String GLTFState::get_copyright() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_copyright")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

void GLTFState::set_copyright(const String &p_copyright) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_copyright")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_copyright);
}

PackedByteArray GLTFState::get_glb_data() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_glb_data")._native_ptr(), 2115431945);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedByteArray());
	return internal::_call_native_mb_ret<PackedByteArray>(_gde_method_bind, _owner);
}

void GLTFState::set_glb_data(const PackedByteArray &p_glb_data) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_glb_data")._native_ptr(), 2971499966);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_glb_data);
}

bool GLTFState::get_use_named_skin_binds() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_use_named_skin_binds")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void GLTFState::set_use_named_skin_binds(bool p_use_named_skin_binds) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_use_named_skin_binds")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_use_named_skin_binds_encoded;
	PtrToArg<bool>::encode(p_use_named_skin_binds, &p_use_named_skin_binds_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_use_named_skin_binds_encoded);
}

TypedArray<GLTFNode> GLTFState::get_nodes() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_nodes")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFNode>());
	return internal::_call_native_mb_ret<TypedArray<GLTFNode>>(_gde_method_bind, _owner);
}

void GLTFState::set_nodes(const TypedArray<GLTFNode> &p_nodes) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_nodes")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_nodes);
}

TypedArray<PackedByteArray> GLTFState::get_buffers() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_buffers")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<PackedByteArray>());
	return internal::_call_native_mb_ret<TypedArray<PackedByteArray>>(_gde_method_bind, _owner);
}

void GLTFState::set_buffers(const TypedArray<PackedByteArray> &p_buffers) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_buffers")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_buffers);
}

TypedArray<GLTFBufferView> GLTFState::get_buffer_views() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_buffer_views")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFBufferView>());
	return internal::_call_native_mb_ret<TypedArray<GLTFBufferView>>(_gde_method_bind, _owner);
}

void GLTFState::set_buffer_views(const TypedArray<GLTFBufferView> &p_buffer_views) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_buffer_views")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_buffer_views);
}

TypedArray<GLTFAccessor> GLTFState::get_accessors() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_accessors")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFAccessor>());
	return internal::_call_native_mb_ret<TypedArray<GLTFAccessor>>(_gde_method_bind, _owner);
}

void GLTFState::set_accessors(const TypedArray<GLTFAccessor> &p_accessors) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_accessors")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_accessors);
}

TypedArray<GLTFMesh> GLTFState::get_meshes() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_meshes")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFMesh>());
	return internal::_call_native_mb_ret<TypedArray<GLTFMesh>>(_gde_method_bind, _owner);
}

void GLTFState::set_meshes(const TypedArray<GLTFMesh> &p_meshes) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_meshes")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_meshes);
}

int32_t GLTFState::get_animation_players_count(int32_t p_idx) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_animation_players_count")._native_ptr(), 3744713108);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	int64_t p_idx_encoded;
	PtrToArg<int64_t>::encode(p_idx, &p_idx_encoded);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, &p_idx_encoded);
}

AnimationPlayer *GLTFState::get_animation_player(int32_t p_idx) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_animation_player")._native_ptr(), 925043400);
	CHECK_METHOD_BIND_RET(_gde_method_bind, nullptr);
	int64_t p_idx_encoded;
	PtrToArg<int64_t>::encode(p_idx, &p_idx_encoded);
	return internal::_call_native_mb_ret_obj<AnimationPlayer>(_gde_method_bind, _owner, &p_idx_encoded);
}

TypedArray<Material> GLTFState::get_materials() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_materials")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<Material>());
	return internal::_call_native_mb_ret<TypedArray<Material>>(_gde_method_bind, _owner);
}

void GLTFState::set_materials(const TypedArray<Material> &p_materials) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_materials")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_materials);
}

String GLTFState::get_scene_name() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_scene_name")._native_ptr(), 2841200299);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

void GLTFState::set_scene_name(const String &p_scene_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_scene_name")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_scene_name);
}

String GLTFState::get_base_path() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_base_path")._native_ptr(), 2841200299);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

void GLTFState::set_base_path(const String &p_base_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_base_path")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_base_path);
}

String GLTFState::get_filename() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_filename")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

void GLTFState::set_filename(const String &p_filename) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_filename")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_filename);
}

PackedInt32Array GLTFState::get_root_nodes() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_root_nodes")._native_ptr(), 969006518);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedInt32Array());
	return internal::_call_native_mb_ret<PackedInt32Array>(_gde_method_bind, _owner);
}

void GLTFState::set_root_nodes(const PackedInt32Array &p_root_nodes) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_root_nodes")._native_ptr(), 3614634198);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_root_nodes);
}

TypedArray<GLTFTexture> GLTFState::get_textures() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_textures")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFTexture>());
	return internal::_call_native_mb_ret<TypedArray<GLTFTexture>>(_gde_method_bind, _owner);
}

void GLTFState::set_textures(const TypedArray<GLTFTexture> &p_textures) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_textures")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_textures);
}

TypedArray<GLTFTextureSampler> GLTFState::get_texture_samplers() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_texture_samplers")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFTextureSampler>());
	return internal::_call_native_mb_ret<TypedArray<GLTFTextureSampler>>(_gde_method_bind, _owner);
}

void GLTFState::set_texture_samplers(const TypedArray<GLTFTextureSampler> &p_texture_samplers) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_texture_samplers")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_texture_samplers);
}

TypedArray<Texture2D> GLTFState::get_images() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_images")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<Texture2D>());
	return internal::_call_native_mb_ret<TypedArray<Texture2D>>(_gde_method_bind, _owner);
}

void GLTFState::set_images(const TypedArray<Texture2D> &p_images) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_images")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_images);
}

TypedArray<GLTFSkin> GLTFState::get_skins() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_skins")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFSkin>());
	return internal::_call_native_mb_ret<TypedArray<GLTFSkin>>(_gde_method_bind, _owner);
}

void GLTFState::set_skins(const TypedArray<GLTFSkin> &p_skins) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_skins")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_skins);
}

TypedArray<GLTFCamera> GLTFState::get_cameras() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_cameras")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFCamera>());
	return internal::_call_native_mb_ret<TypedArray<GLTFCamera>>(_gde_method_bind, _owner);
}

void GLTFState::set_cameras(const TypedArray<GLTFCamera> &p_cameras) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_cameras")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_cameras);
}

TypedArray<GLTFLight> GLTFState::get_lights() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_lights")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFLight>());
	return internal::_call_native_mb_ret<TypedArray<GLTFLight>>(_gde_method_bind, _owner);
}

void GLTFState::set_lights(const TypedArray<GLTFLight> &p_lights) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_lights")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_lights);
}

TypedArray<String> GLTFState::get_unique_names() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_unique_names")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<String>());
	return internal::_call_native_mb_ret<TypedArray<String>>(_gde_method_bind, _owner);
}

void GLTFState::set_unique_names(const TypedArray<String> &p_unique_names) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_unique_names")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_unique_names);
}

TypedArray<String> GLTFState::get_unique_animation_names() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_unique_animation_names")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<String>());
	return internal::_call_native_mb_ret<TypedArray<String>>(_gde_method_bind, _owner);
}

void GLTFState::set_unique_animation_names(const TypedArray<String> &p_unique_animation_names) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_unique_animation_names")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_unique_animation_names);
}

TypedArray<GLTFSkeleton> GLTFState::get_skeletons() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_skeletons")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFSkeleton>());
	return internal::_call_native_mb_ret<TypedArray<GLTFSkeleton>>(_gde_method_bind, _owner);
}

void GLTFState::set_skeletons(const TypedArray<GLTFSkeleton> &p_skeletons) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_skeletons")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_skeletons);
}

bool GLTFState::get_create_animations() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_create_animations")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void GLTFState::set_create_animations(bool p_create_animations) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_create_animations")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_create_animations_encoded;
	PtrToArg<bool>::encode(p_create_animations, &p_create_animations_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_create_animations_encoded);
}

bool GLTFState::get_import_as_skeleton_bones() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_import_as_skeleton_bones")._native_ptr(), 2240911060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void GLTFState::set_import_as_skeleton_bones(bool p_import_as_skeleton_bones) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_import_as_skeleton_bones")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_import_as_skeleton_bones_encoded;
	PtrToArg<bool>::encode(p_import_as_skeleton_bones, &p_import_as_skeleton_bones_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_import_as_skeleton_bones_encoded);
}

TypedArray<GLTFAnimation> GLTFState::get_animations() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_animations")._native_ptr(), 2915620761);
	CHECK_METHOD_BIND_RET(_gde_method_bind, TypedArray<GLTFAnimation>());
	return internal::_call_native_mb_ret<TypedArray<GLTFAnimation>>(_gde_method_bind, _owner);
}

void GLTFState::set_animations(const TypedArray<GLTFAnimation> &p_animations) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_animations")._native_ptr(), 381264803);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_animations);
}

Node *GLTFState::get_scene_node(int32_t p_idx) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_scene_node")._native_ptr(), 4253421667);
	CHECK_METHOD_BIND_RET(_gde_method_bind, nullptr);
	int64_t p_idx_encoded;
	PtrToArg<int64_t>::encode(p_idx, &p_idx_encoded);
	return internal::_call_native_mb_ret_obj<Node>(_gde_method_bind, _owner, &p_idx_encoded);
}

int32_t GLTFState::get_node_index(Node *p_scene_node) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_node_index")._native_ptr(), 1205807060);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, (p_scene_node != nullptr ? &p_scene_node->_owner : nullptr));
}

Variant GLTFState::get_additional_data(const StringName &p_extension_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_additional_data")._native_ptr(), 2138907829);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Variant());
	return internal::_call_native_mb_ret<Variant>(_gde_method_bind, _owner, &p_extension_name);
}

void GLTFState::set_additional_data(const StringName &p_extension_name, const Variant &p_additional_data) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_additional_data")._native_ptr(), 3776071444);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_extension_name, &p_additional_data);
}

int32_t GLTFState::get_handle_binary_image() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_handle_binary_image")._native_ptr(), 2455072627);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void GLTFState::set_handle_binary_image(int32_t p_method) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_handle_binary_image")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_method_encoded;
	PtrToArg<int64_t>::encode(p_method, &p_method_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_method_encoded);
}

void GLTFState::set_bake_fps(double p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("set_bake_fps")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_value_encoded;
	PtrToArg<double>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

double GLTFState::get_bake_fps() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(GLTFState::get_class_static()._native_ptr(), StringName("get_bake_fps")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

} // namespace godot
