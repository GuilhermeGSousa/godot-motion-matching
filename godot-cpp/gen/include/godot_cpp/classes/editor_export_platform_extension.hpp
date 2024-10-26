/**************************************************************************/
/*  editor_export_platform_extension.hpp                                  */
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

#ifndef GODOT_CPP_EDITOR_EXPORT_PLATFORM_EXTENSION_HPP
#define GODOT_CPP_EDITOR_EXPORT_PLATFORM_EXTENSION_HPP

#include <godot_cpp/classes/editor_export_platform.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/typed_array.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class EditorExportPreset;
class ImageTexture;
class StringName;
class Texture2D;

class EditorExportPlatformExtension : public EditorExportPlatform {
	GDEXTENSION_CLASS(EditorExportPlatformExtension, EditorExportPlatform)

public:
	void set_config_error(const String &p_error_text) const;
	String get_config_error() const;
	void set_config_missing_templates(bool p_missing_templates) const;
	bool get_config_missing_templates() const;
	virtual PackedStringArray _get_preset_features(const Ref<EditorExportPreset> &p_preset) const;
	virtual bool _is_executable(const String &p_path) const;
	virtual TypedArray<Dictionary> _get_export_options() const;
	virtual bool _should_update_export_options();
	virtual bool _get_export_option_visibility(const Ref<EditorExportPreset> &p_preset, const String &p_option) const;
	virtual String _get_export_option_warning(const Ref<EditorExportPreset> &p_preset, const StringName &p_option) const;
	virtual String _get_os_name() const;
	virtual String _get_name() const;
	virtual Ref<Texture2D> _get_logo() const;
	virtual bool _poll_export();
	virtual int32_t _get_options_count() const;
	virtual String _get_options_tooltip() const;
	virtual Ref<ImageTexture> _get_option_icon(int32_t p_device) const;
	virtual String _get_option_label(int32_t p_device) const;
	virtual String _get_option_tooltip(int32_t p_device) const;
	virtual String _get_device_architecture(int32_t p_device) const;
	virtual void _cleanup();
	virtual Error _run(const Ref<EditorExportPreset> &p_preset, int32_t p_device, BitField<EditorExportPlatform::DebugFlags> p_debug_flags);
	virtual Ref<Texture2D> _get_run_icon() const;
	virtual bool _can_export(const Ref<EditorExportPreset> &p_preset, bool p_debug) const;
	virtual bool _has_valid_export_configuration(const Ref<EditorExportPreset> &p_preset, bool p_debug) const;
	virtual bool _has_valid_project_configuration(const Ref<EditorExportPreset> &p_preset) const;
	virtual PackedStringArray _get_binary_extensions(const Ref<EditorExportPreset> &p_preset) const;
	virtual Error _export_project(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, BitField<EditorExportPlatform::DebugFlags> p_flags);
	virtual Error _export_pack(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, BitField<EditorExportPlatform::DebugFlags> p_flags);
	virtual Error _export_zip(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, BitField<EditorExportPlatform::DebugFlags> p_flags);
	virtual Error _export_pack_patch(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, const PackedStringArray &p_patches, BitField<EditorExportPlatform::DebugFlags> p_flags);
	virtual Error _export_zip_patch(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, const PackedStringArray &p_patches, BitField<EditorExportPlatform::DebugFlags> p_flags);
	virtual PackedStringArray _get_platform_features() const;
	virtual String _get_debug_protocol() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		EditorExportPlatform::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_get_preset_features), decltype(&T::_get_preset_features)>) {
			BIND_VIRTUAL_METHOD(T, _get_preset_features);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_executable), decltype(&T::_is_executable)>) {
			BIND_VIRTUAL_METHOD(T, _is_executable);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_export_options), decltype(&T::_get_export_options)>) {
			BIND_VIRTUAL_METHOD(T, _get_export_options);
		}
		if constexpr (!std::is_same_v<decltype(&B::_should_update_export_options), decltype(&T::_should_update_export_options)>) {
			BIND_VIRTUAL_METHOD(T, _should_update_export_options);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_export_option_visibility), decltype(&T::_get_export_option_visibility)>) {
			BIND_VIRTUAL_METHOD(T, _get_export_option_visibility);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_export_option_warning), decltype(&T::_get_export_option_warning)>) {
			BIND_VIRTUAL_METHOD(T, _get_export_option_warning);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_os_name), decltype(&T::_get_os_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_os_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_name), decltype(&T::_get_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_logo), decltype(&T::_get_logo)>) {
			BIND_VIRTUAL_METHOD(T, _get_logo);
		}
		if constexpr (!std::is_same_v<decltype(&B::_poll_export), decltype(&T::_poll_export)>) {
			BIND_VIRTUAL_METHOD(T, _poll_export);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_options_count), decltype(&T::_get_options_count)>) {
			BIND_VIRTUAL_METHOD(T, _get_options_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_options_tooltip), decltype(&T::_get_options_tooltip)>) {
			BIND_VIRTUAL_METHOD(T, _get_options_tooltip);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_option_icon), decltype(&T::_get_option_icon)>) {
			BIND_VIRTUAL_METHOD(T, _get_option_icon);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_option_label), decltype(&T::_get_option_label)>) {
			BIND_VIRTUAL_METHOD(T, _get_option_label);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_option_tooltip), decltype(&T::_get_option_tooltip)>) {
			BIND_VIRTUAL_METHOD(T, _get_option_tooltip);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_device_architecture), decltype(&T::_get_device_architecture)>) {
			BIND_VIRTUAL_METHOD(T, _get_device_architecture);
		}
		if constexpr (!std::is_same_v<decltype(&B::_cleanup), decltype(&T::_cleanup)>) {
			BIND_VIRTUAL_METHOD(T, _cleanup);
		}
		if constexpr (!std::is_same_v<decltype(&B::_run), decltype(&T::_run)>) {
			BIND_VIRTUAL_METHOD(T, _run);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_run_icon), decltype(&T::_get_run_icon)>) {
			BIND_VIRTUAL_METHOD(T, _get_run_icon);
		}
		if constexpr (!std::is_same_v<decltype(&B::_can_export), decltype(&T::_can_export)>) {
			BIND_VIRTUAL_METHOD(T, _can_export);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has_valid_export_configuration), decltype(&T::_has_valid_export_configuration)>) {
			BIND_VIRTUAL_METHOD(T, _has_valid_export_configuration);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has_valid_project_configuration), decltype(&T::_has_valid_project_configuration)>) {
			BIND_VIRTUAL_METHOD(T, _has_valid_project_configuration);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_binary_extensions), decltype(&T::_get_binary_extensions)>) {
			BIND_VIRTUAL_METHOD(T, _get_binary_extensions);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_project), decltype(&T::_export_project)>) {
			BIND_VIRTUAL_METHOD(T, _export_project);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_pack), decltype(&T::_export_pack)>) {
			BIND_VIRTUAL_METHOD(T, _export_pack);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_zip), decltype(&T::_export_zip)>) {
			BIND_VIRTUAL_METHOD(T, _export_zip);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_pack_patch), decltype(&T::_export_pack_patch)>) {
			BIND_VIRTUAL_METHOD(T, _export_pack_patch);
		}
		if constexpr (!std::is_same_v<decltype(&B::_export_zip_patch), decltype(&T::_export_zip_patch)>) {
			BIND_VIRTUAL_METHOD(T, _export_zip_patch);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_platform_features), decltype(&T::_get_platform_features)>) {
			BIND_VIRTUAL_METHOD(T, _get_platform_features);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_debug_protocol), decltype(&T::_get_debug_protocol)>) {
			BIND_VIRTUAL_METHOD(T, _get_debug_protocol);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_EDITOR_EXPORT_PLATFORM_EXTENSION_HPP
