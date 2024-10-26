/**************************************************************************/
/*  open_xrapi_extension.hpp                                              */
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

#ifndef GODOT_CPP_OPEN_XRAPI_EXTENSION_HPP
#define GODOT_CPP_OPEN_XRAPI_EXTENSION_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/transform3d.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Array;
class OpenXRExtensionWrapperExtension;

class OpenXRAPIExtension : public RefCounted {
	GDEXTENSION_CLASS(OpenXRAPIExtension, RefCounted)

public:
	enum OpenXRAlphaBlendModeSupport {
		OPENXR_ALPHA_BLEND_MODE_SUPPORT_NONE = 0,
		OPENXR_ALPHA_BLEND_MODE_SUPPORT_REAL = 1,
		OPENXR_ALPHA_BLEND_MODE_SUPPORT_EMULATING = 2,
	};

	uint64_t get_instance();
	uint64_t get_system_id();
	uint64_t get_session();
	Transform3D transform_from_pose(const void *p_pose);
	bool xr_result(uint64_t p_result, const String &p_format, const Array &p_args);
	static bool openxr_is_enabled(bool p_check_run_in_editor);
	uint64_t get_instance_proc_addr(const String &p_name);
	String get_error_string(uint64_t p_result);
	String get_swapchain_format_name(int64_t p_swapchain_format);
	void set_object_name(int64_t p_object_type, uint64_t p_object_handle, const String &p_object_name);
	void begin_debug_label_region(const String &p_label_name);
	void end_debug_label_region();
	void insert_debug_label(const String &p_label_name);
	bool is_initialized();
	bool is_running();
	uint64_t get_play_space();
	int64_t get_predicted_display_time();
	int64_t get_next_frame_time();
	bool can_render();
	uint64_t get_hand_tracker(int32_t p_hand_index);
	void register_composition_layer_provider(OpenXRExtensionWrapperExtension *p_extension);
	void unregister_composition_layer_provider(OpenXRExtensionWrapperExtension *p_extension);
	void set_emulate_environment_blend_mode_alpha_blend(bool p_enabled);
	OpenXRAPIExtension::OpenXRAlphaBlendModeSupport is_environment_blend_mode_alpha_supported();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		RefCounted::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(OpenXRAPIExtension::OpenXRAlphaBlendModeSupport);

#endif // ! GODOT_CPP_OPEN_XRAPI_EXTENSION_HPP
