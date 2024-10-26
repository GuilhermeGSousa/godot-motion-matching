/**************************************************************************/
/*  gltf_document_extension.hpp                                           */
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

#ifndef GODOT_CPP_GLTF_DOCUMENT_EXTENSION_HPP
#define GODOT_CPP_GLTF_DOCUMENT_EXTENSION_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/string.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Dictionary;
class GLTFNode;
class GLTFState;
class GLTFTexture;
class Image;
class Node;
class Node3D;

class GLTFDocumentExtension : public Resource {
	GDEXTENSION_CLASS(GLTFDocumentExtension, Resource)

public:
	virtual Error _import_preflight(const Ref<GLTFState> &p_state, const PackedStringArray &p_extensions);
	virtual PackedStringArray _get_supported_extensions();
	virtual Error _parse_node_extensions(const Ref<GLTFState> &p_state, const Ref<GLTFNode> &p_gltf_node, const Dictionary &p_extensions);
	virtual Error _parse_image_data(const Ref<GLTFState> &p_state, const PackedByteArray &p_image_data, const String &p_mime_type, const Ref<Image> &p_ret_image);
	virtual String _get_image_file_extension();
	virtual Error _parse_texture_json(const Ref<GLTFState> &p_state, const Dictionary &p_texture_json, const Ref<GLTFTexture> &p_ret_gltf_texture);
	virtual Error _import_post_parse(const Ref<GLTFState> &p_state);
	virtual Error _import_pre_generate(const Ref<GLTFState> &p_state);
	virtual Node3D *_generate_scene_node(const Ref<GLTFState> &p_state, const Ref<GLTFNode> &p_gltf_node, Node *p_scene_parent);
	virtual Error _import_node(const Ref<GLTFState> &p_state, const Ref<GLTFNode> &p_gltf_node, const Dictionary &p_json, Node *p_node);
	virtual Error _import_post(const Ref<GLTFState> &p_state, Node *p_root);
	virtual Error _export_preflight(const Ref<GLTFState> &p_state, Node *p_root);
	virtual void _convert_scene_node(const Ref<GLTFState> &p_state, const Ref<GLTFNode> &p_gltf_node, Node *p_scene_node);
	virtual Error _export_post_convert(const Ref<GLTFState> &p_state, Node *p_root);
	virtual Error _export_preserialize(const Ref<GLTFState> &p_state);
	virtual PackedStringArray _get_saveable_image_formats();
	virtual PackedByteArray _serialize_image_to_bytes(const Ref<GLTFState> &p_state, const Ref<Image> &p_image, const Dictionary &p_image_dict, const String &p_image_format, float p_lossy_quality);
	virtual Error _save_image_at_path(const Ref<GLTFState> &p_state, const Ref<Image> &p_image, const String &p_file_path, const String &p_image_format, float p_lossy_quality);
	virtual Error _serialize_texture_json(const Ref<GLTFState> &p_state, const Dictionary &p_texture_json, const Ref<GLTFTexture> &p_gltf_texture, const String &p_image_format);
	virtual Error _export_node(const Ref<GLTFState> &p_state, const Ref<GLTFNode> &p_gltf_node, const Dictionary &p_json, Node *p_node);
	virtual Error _export_post(const Ref<GLTFState> &p_state);

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Resource::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_import_preflight), decltype(&T::_import_preflight)>) {
			BIND_VIRTUAL_METHOD(T, _import_preflight);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_supported_extensions), decltype(&T::_get_supported_extensions)>) {
			BIND_VIRTUAL_METHOD(T, _get_supported_extensions);
		}
		if constexpr (!std::is_same_v<decltype(&B::_parse_node_extensions), decltype(&T::_parse_node_extensions)>) {
			BIND_VIRTUAL_METHOD(T, _parse_node_extensions);
		}
		if constexpr (!std::is_same_v<decltype(&B::_parse_image_data), decltype(&T::_parse_image_data)>) {
			BIND_VIRTUAL_METHOD(T, _parse_image_data);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_image_file_extension), decltype(&T::_get_image_file_extension)>) {
			BIND_VIRTUAL_METHOD(T, _get_image_file_extension);
		}
		if constexpr (!std::is_same_v<decltype(&B::_parse_texture_json), decltype(&T::_parse_texture_json)>) {
			BIND_VIRTUAL_METHOD(T, _parse_texture_json);
		}
		if constexpr (!std::is_same_v<decltype(&B::_import_post_parse), decltype(&T::_import_post_parse)>) {
			BIND_VIRTUAL_METHOD(T, _import_post_parse);
		}
		if constexpr (!std::is_same_v<decltype(&B::_import_pre_generate), decltype(&T::_import_pre_generate)>) {
			BIND_VIRTUAL_METHOD(T, _import_pre_generate);
		}
		if constexpr (!std::is_same_v<decltype(&B::_generate_scene_node), decltype(&T::_generate_scene_node)>) {
			BIND_VIRTUAL_METHOD(T, _generate_scene_node);
		}
		if constexpr (!std::is_same_v<decltype(&B::_import_node), decltype(&T::_import_node)>) {
			BIND_VIRTUAL_METHOD(T, _import_node);
		}
		if constexpr (!std::is_same_v<decltype(&B::_import_post), decltype(&T::_import_post)>) {
			BIND_VIRTUAL_METHOD(T, _import_post);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_preflight), decltype(&T::_export_preflight)>) {
			BIND_VIRTUAL_METHOD(T, _export_preflight);
		}
		if constexpr (!std::is_same_v<decltype(&B::_convert_scene_node), decltype(&T::_convert_scene_node)>) {
			BIND_VIRTUAL_METHOD(T, _convert_scene_node);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_post_convert), decltype(&T::_export_post_convert)>) {
			BIND_VIRTUAL_METHOD(T, _export_post_convert);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_preserialize), decltype(&T::_export_preserialize)>) {
			BIND_VIRTUAL_METHOD(T, _export_preserialize);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_saveable_image_formats), decltype(&T::_get_saveable_image_formats)>) {
			BIND_VIRTUAL_METHOD(T, _get_saveable_image_formats);
		}
		if constexpr (!std::is_same_v<decltype(&B::_serialize_image_to_bytes), decltype(&T::_serialize_image_to_bytes)>) {
			BIND_VIRTUAL_METHOD(T, _serialize_image_to_bytes);
		}
		if constexpr (!std::is_same_v<decltype(&B::_save_image_at_path), decltype(&T::_save_image_at_path)>) {
			BIND_VIRTUAL_METHOD(T, _save_image_at_path);
		}
		if constexpr (!std::is_same_v<decltype(&B::_serialize_texture_json), decltype(&T::_serialize_texture_json)>) {
			BIND_VIRTUAL_METHOD(T, _serialize_texture_json);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_node), decltype(&T::_export_node)>) {
			BIND_VIRTUAL_METHOD(T, _export_node);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_post), decltype(&T::_export_post)>) {
			BIND_VIRTUAL_METHOD(T, _export_post);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_GLTF_DOCUMENT_EXTENSION_HPP
