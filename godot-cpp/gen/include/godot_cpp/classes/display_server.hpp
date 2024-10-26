/**************************************************************************/
/*  display_server.hpp                                                    */
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

#ifndef GODOT_CPP_DISPLAY_SERVER_HPP
#define GODOT_CPP_DISPLAY_SERVER_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_int32_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/rect2.hpp>
#include <godot_cpp/variant/rect2i.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/variant/vector3i.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Image;
class PackedVector2Array;
class RID;
class Resource;
class Texture2D;

class DisplayServer : public Object {
	GDEXTENSION_CLASS(DisplayServer, Object)

	static DisplayServer *singleton;

public:
	enum Feature {
		FEATURE_GLOBAL_MENU = 0,
		FEATURE_SUBWINDOWS = 1,
		FEATURE_TOUCHSCREEN = 2,
		FEATURE_MOUSE = 3,
		FEATURE_MOUSE_WARP = 4,
		FEATURE_CLIPBOARD = 5,
		FEATURE_VIRTUAL_KEYBOARD = 6,
		FEATURE_CURSOR_SHAPE = 7,
		FEATURE_CUSTOM_CURSOR_SHAPE = 8,
		FEATURE_NATIVE_DIALOG = 9,
		FEATURE_IME = 10,
		FEATURE_WINDOW_TRANSPARENCY = 11,
		FEATURE_HIDPI = 12,
		FEATURE_ICON = 13,
		FEATURE_NATIVE_ICON = 14,
		FEATURE_ORIENTATION = 15,
		FEATURE_SWAP_BUFFERS = 16,
		FEATURE_CLIPBOARD_PRIMARY = 18,
		FEATURE_TEXT_TO_SPEECH = 19,
		FEATURE_EXTEND_TO_TITLE = 20,
		FEATURE_SCREEN_CAPTURE = 21,
		FEATURE_STATUS_INDICATOR = 22,
		FEATURE_NATIVE_HELP = 23,
		FEATURE_NATIVE_DIALOG_INPUT = 24,
		FEATURE_NATIVE_DIALOG_FILE = 25,
	};

	enum MouseMode {
		MOUSE_MODE_VISIBLE = 0,
		MOUSE_MODE_HIDDEN = 1,
		MOUSE_MODE_CAPTURED = 2,
		MOUSE_MODE_CONFINED = 3,
		MOUSE_MODE_CONFINED_HIDDEN = 4,
	};

	enum ScreenOrientation {
		SCREEN_LANDSCAPE = 0,
		SCREEN_PORTRAIT = 1,
		SCREEN_REVERSE_LANDSCAPE = 2,
		SCREEN_REVERSE_PORTRAIT = 3,
		SCREEN_SENSOR_LANDSCAPE = 4,
		SCREEN_SENSOR_PORTRAIT = 5,
		SCREEN_SENSOR = 6,
	};

	enum VirtualKeyboardType {
		KEYBOARD_TYPE_DEFAULT = 0,
		KEYBOARD_TYPE_MULTILINE = 1,
		KEYBOARD_TYPE_NUMBER = 2,
		KEYBOARD_TYPE_NUMBER_DECIMAL = 3,
		KEYBOARD_TYPE_PHONE = 4,
		KEYBOARD_TYPE_EMAIL_ADDRESS = 5,
		KEYBOARD_TYPE_PASSWORD = 6,
		KEYBOARD_TYPE_URL = 7,
	};

	enum CursorShape {
		CURSOR_ARROW = 0,
		CURSOR_IBEAM = 1,
		CURSOR_POINTING_HAND = 2,
		CURSOR_CROSS = 3,
		CURSOR_WAIT = 4,
		CURSOR_BUSY = 5,
		CURSOR_DRAG = 6,
		CURSOR_CAN_DROP = 7,
		CURSOR_FORBIDDEN = 8,
		CURSOR_VSIZE = 9,
		CURSOR_HSIZE = 10,
		CURSOR_BDIAGSIZE = 11,
		CURSOR_FDIAGSIZE = 12,
		CURSOR_MOVE = 13,
		CURSOR_VSPLIT = 14,
		CURSOR_HSPLIT = 15,
		CURSOR_HELP = 16,
		CURSOR_MAX = 17,
	};

	enum FileDialogMode {
		FILE_DIALOG_MODE_OPEN_FILE = 0,
		FILE_DIALOG_MODE_OPEN_FILES = 1,
		FILE_DIALOG_MODE_OPEN_DIR = 2,
		FILE_DIALOG_MODE_OPEN_ANY = 3,
		FILE_DIALOG_MODE_SAVE_FILE = 4,
	};

	enum WindowMode {
		WINDOW_MODE_WINDOWED = 0,
		WINDOW_MODE_MINIMIZED = 1,
		WINDOW_MODE_MAXIMIZED = 2,
		WINDOW_MODE_FULLSCREEN = 3,
		WINDOW_MODE_EXCLUSIVE_FULLSCREEN = 4,
	};

	enum WindowFlags {
		WINDOW_FLAG_RESIZE_DISABLED = 0,
		WINDOW_FLAG_BORDERLESS = 1,
		WINDOW_FLAG_ALWAYS_ON_TOP = 2,
		WINDOW_FLAG_TRANSPARENT = 3,
		WINDOW_FLAG_NO_FOCUS = 4,
		WINDOW_FLAG_POPUP = 5,
		WINDOW_FLAG_EXTEND_TO_TITLE = 6,
		WINDOW_FLAG_MOUSE_PASSTHROUGH = 7,
		WINDOW_FLAG_MAX = 8,
	};

	enum WindowEvent {
		WINDOW_EVENT_MOUSE_ENTER = 0,
		WINDOW_EVENT_MOUSE_EXIT = 1,
		WINDOW_EVENT_FOCUS_IN = 2,
		WINDOW_EVENT_FOCUS_OUT = 3,
		WINDOW_EVENT_CLOSE_REQUEST = 4,
		WINDOW_EVENT_GO_BACK_REQUEST = 5,
		WINDOW_EVENT_DPI_CHANGE = 6,
		WINDOW_EVENT_TITLEBAR_CHANGE = 7,
	};

	enum VSyncMode {
		VSYNC_DISABLED = 0,
		VSYNC_ENABLED = 1,
		VSYNC_ADAPTIVE = 2,
		VSYNC_MAILBOX = 3,
	};

	enum HandleType {
		DISPLAY_HANDLE = 0,
		WINDOW_HANDLE = 1,
		WINDOW_VIEW = 2,
		OPENGL_CONTEXT = 3,
	};

	enum TTSUtteranceEvent {
		TTS_UTTERANCE_STARTED = 0,
		TTS_UTTERANCE_ENDED = 1,
		TTS_UTTERANCE_CANCELED = 2,
		TTS_UTTERANCE_BOUNDARY = 3,
	};

	static const int SCREEN_WITH_MOUSE_FOCUS = -4;
	static const int SCREEN_WITH_KEYBOARD_FOCUS = -3;
	static const int SCREEN_PRIMARY = -2;
	static const int SCREEN_OF_MAIN_WINDOW = -1;
	static const int MAIN_WINDOW_ID = 0;
	static const int INVALID_WINDOW_ID = -1;
	static const int INVALID_INDICATOR_ID = -1;

	static DisplayServer *get_singleton();

	bool has_feature(DisplayServer::Feature p_feature) const;
	String get_name() const;
	void help_set_search_callbacks(const Callable &p_search_callback, const Callable &p_action_callback);
	void global_menu_set_popup_callbacks(const String &p_menu_root, const Callable &p_open_callback, const Callable &p_close_callback);
	int32_t global_menu_add_submenu_item(const String &p_menu_root, const String &p_label, const String &p_submenu, int32_t p_index = -1);
	int32_t global_menu_add_item(const String &p_menu_root, const String &p_label, const Callable &p_callback = Callable(), const Callable &p_key_callback = Callable(), const Variant &p_tag = nullptr, Key p_accelerator = (Key)0, int32_t p_index = -1);
	int32_t global_menu_add_check_item(const String &p_menu_root, const String &p_label, const Callable &p_callback = Callable(), const Callable &p_key_callback = Callable(), const Variant &p_tag = nullptr, Key p_accelerator = (Key)0, int32_t p_index = -1);
	int32_t global_menu_add_icon_item(const String &p_menu_root, const Ref<Texture2D> &p_icon, const String &p_label, const Callable &p_callback = Callable(), const Callable &p_key_callback = Callable(), const Variant &p_tag = nullptr, Key p_accelerator = (Key)0, int32_t p_index = -1);
	int32_t global_menu_add_icon_check_item(const String &p_menu_root, const Ref<Texture2D> &p_icon, const String &p_label, const Callable &p_callback = Callable(), const Callable &p_key_callback = Callable(), const Variant &p_tag = nullptr, Key p_accelerator = (Key)0, int32_t p_index = -1);
	int32_t global_menu_add_radio_check_item(const String &p_menu_root, const String &p_label, const Callable &p_callback = Callable(), const Callable &p_key_callback = Callable(), const Variant &p_tag = nullptr, Key p_accelerator = (Key)0, int32_t p_index = -1);
	int32_t global_menu_add_icon_radio_check_item(const String &p_menu_root, const Ref<Texture2D> &p_icon, const String &p_label, const Callable &p_callback = Callable(), const Callable &p_key_callback = Callable(), const Variant &p_tag = nullptr, Key p_accelerator = (Key)0, int32_t p_index = -1);
	int32_t global_menu_add_multistate_item(const String &p_menu_root, const String &p_label, int32_t p_max_states, int32_t p_default_state, const Callable &p_callback = Callable(), const Callable &p_key_callback = Callable(), const Variant &p_tag = nullptr, Key p_accelerator = (Key)0, int32_t p_index = -1);
	int32_t global_menu_add_separator(const String &p_menu_root, int32_t p_index = -1);
	int32_t global_menu_get_item_index_from_text(const String &p_menu_root, const String &p_text) const;
	int32_t global_menu_get_item_index_from_tag(const String &p_menu_root, const Variant &p_tag) const;
	bool global_menu_is_item_checked(const String &p_menu_root, int32_t p_idx) const;
	bool global_menu_is_item_checkable(const String &p_menu_root, int32_t p_idx) const;
	bool global_menu_is_item_radio_checkable(const String &p_menu_root, int32_t p_idx) const;
	Callable global_menu_get_item_callback(const String &p_menu_root, int32_t p_idx) const;
	Callable global_menu_get_item_key_callback(const String &p_menu_root, int32_t p_idx) const;
	Variant global_menu_get_item_tag(const String &p_menu_root, int32_t p_idx) const;
	String global_menu_get_item_text(const String &p_menu_root, int32_t p_idx) const;
	String global_menu_get_item_submenu(const String &p_menu_root, int32_t p_idx) const;
	Key global_menu_get_item_accelerator(const String &p_menu_root, int32_t p_idx) const;
	bool global_menu_is_item_disabled(const String &p_menu_root, int32_t p_idx) const;
	bool global_menu_is_item_hidden(const String &p_menu_root, int32_t p_idx) const;
	String global_menu_get_item_tooltip(const String &p_menu_root, int32_t p_idx) const;
	int32_t global_menu_get_item_state(const String &p_menu_root, int32_t p_idx) const;
	int32_t global_menu_get_item_max_states(const String &p_menu_root, int32_t p_idx) const;
	Ref<Texture2D> global_menu_get_item_icon(const String &p_menu_root, int32_t p_idx) const;
	int32_t global_menu_get_item_indentation_level(const String &p_menu_root, int32_t p_idx) const;
	void global_menu_set_item_checked(const String &p_menu_root, int32_t p_idx, bool p_checked);
	void global_menu_set_item_checkable(const String &p_menu_root, int32_t p_idx, bool p_checkable);
	void global_menu_set_item_radio_checkable(const String &p_menu_root, int32_t p_idx, bool p_checkable);
	void global_menu_set_item_callback(const String &p_menu_root, int32_t p_idx, const Callable &p_callback);
	void global_menu_set_item_hover_callbacks(const String &p_menu_root, int32_t p_idx, const Callable &p_callback);
	void global_menu_set_item_key_callback(const String &p_menu_root, int32_t p_idx, const Callable &p_key_callback);
	void global_menu_set_item_tag(const String &p_menu_root, int32_t p_idx, const Variant &p_tag);
	void global_menu_set_item_text(const String &p_menu_root, int32_t p_idx, const String &p_text);
	void global_menu_set_item_submenu(const String &p_menu_root, int32_t p_idx, const String &p_submenu);
	void global_menu_set_item_accelerator(const String &p_menu_root, int32_t p_idx, Key p_keycode);
	void global_menu_set_item_disabled(const String &p_menu_root, int32_t p_idx, bool p_disabled);
	void global_menu_set_item_hidden(const String &p_menu_root, int32_t p_idx, bool p_hidden);
	void global_menu_set_item_tooltip(const String &p_menu_root, int32_t p_idx, const String &p_tooltip);
	void global_menu_set_item_state(const String &p_menu_root, int32_t p_idx, int32_t p_state);
	void global_menu_set_item_max_states(const String &p_menu_root, int32_t p_idx, int32_t p_max_states);
	void global_menu_set_item_icon(const String &p_menu_root, int32_t p_idx, const Ref<Texture2D> &p_icon);
	void global_menu_set_item_indentation_level(const String &p_menu_root, int32_t p_idx, int32_t p_level);
	int32_t global_menu_get_item_count(const String &p_menu_root) const;
	void global_menu_remove_item(const String &p_menu_root, int32_t p_idx);
	void global_menu_clear(const String &p_menu_root);
	Dictionary global_menu_get_system_menu_roots() const;
	bool tts_is_speaking() const;
	bool tts_is_paused() const;
	TypedArray<Dictionary> tts_get_voices() const;
	PackedStringArray tts_get_voices_for_language(const String &p_language) const;
	void tts_speak(const String &p_text, const String &p_voice, int32_t p_volume = 50, float p_pitch = 1.0, float p_rate = 1.0, int32_t p_utterance_id = 0, bool p_interrupt = false);
	void tts_pause();
	void tts_resume();
	void tts_stop();
	void tts_set_utterance_callback(DisplayServer::TTSUtteranceEvent p_event, const Callable &p_callable);
	bool is_dark_mode_supported() const;
	bool is_dark_mode() const;
	Color get_accent_color() const;
	Color get_base_color() const;
	void set_system_theme_change_callback(const Callable &p_callable);
	void mouse_set_mode(DisplayServer::MouseMode p_mouse_mode);
	DisplayServer::MouseMode mouse_get_mode() const;
	void warp_mouse(const Vector2i &p_position);
	Vector2i mouse_get_position() const;
	BitField<MouseButtonMask> mouse_get_button_state() const;
	void clipboard_set(const String &p_clipboard);
	String clipboard_get() const;
	Ref<Image> clipboard_get_image() const;
	bool clipboard_has() const;
	bool clipboard_has_image() const;
	void clipboard_set_primary(const String &p_clipboard_primary);
	String clipboard_get_primary() const;
	TypedArray<Rect2> get_display_cutouts() const;
	Rect2i get_display_safe_area() const;
	int32_t get_screen_count() const;
	int32_t get_primary_screen() const;
	int32_t get_keyboard_focus_screen() const;
	int32_t get_screen_from_rect(const Rect2 &p_rect) const;
	Vector2i screen_get_position(int32_t p_screen = -1) const;
	Vector2i screen_get_size(int32_t p_screen = -1) const;
	Rect2i screen_get_usable_rect(int32_t p_screen = -1) const;
	int32_t screen_get_dpi(int32_t p_screen = -1) const;
	float screen_get_scale(int32_t p_screen = -1) const;
	bool is_touchscreen_available() const;
	float screen_get_max_scale() const;
	float screen_get_refresh_rate(int32_t p_screen = -1) const;
	Color screen_get_pixel(const Vector2i &p_position) const;
	Ref<Image> screen_get_image(int32_t p_screen = -1) const;
	void screen_set_orientation(DisplayServer::ScreenOrientation p_orientation, int32_t p_screen = -1);
	DisplayServer::ScreenOrientation screen_get_orientation(int32_t p_screen = -1) const;
	void screen_set_keep_on(bool p_enable);
	bool screen_is_kept_on() const;
	PackedInt32Array get_window_list() const;
	int32_t get_window_at_screen_position(const Vector2i &p_position) const;
	int64_t window_get_native_handle(DisplayServer::HandleType p_handle_type, int32_t p_window_id = 0) const;
	int32_t window_get_active_popup() const;
	void window_set_popup_safe_rect(int32_t p_window, const Rect2i &p_rect);
	Rect2i window_get_popup_safe_rect(int32_t p_window) const;
	void window_set_title(const String &p_title, int32_t p_window_id = 0);
	Vector2i window_get_title_size(const String &p_title, int32_t p_window_id = 0) const;
	void window_set_mouse_passthrough(const PackedVector2Array &p_region, int32_t p_window_id = 0);
	int32_t window_get_current_screen(int32_t p_window_id = 0) const;
	void window_set_current_screen(int32_t p_screen, int32_t p_window_id = 0);
	Vector2i window_get_position(int32_t p_window_id = 0) const;
	Vector2i window_get_position_with_decorations(int32_t p_window_id = 0) const;
	void window_set_position(const Vector2i &p_position, int32_t p_window_id = 0);
	Vector2i window_get_size(int32_t p_window_id = 0) const;
	void window_set_size(const Vector2i &p_size, int32_t p_window_id = 0);
	void window_set_rect_changed_callback(const Callable &p_callback, int32_t p_window_id = 0);
	void window_set_window_event_callback(const Callable &p_callback, int32_t p_window_id = 0);
	void window_set_input_event_callback(const Callable &p_callback, int32_t p_window_id = 0);
	void window_set_input_text_callback(const Callable &p_callback, int32_t p_window_id = 0);
	void window_set_drop_files_callback(const Callable &p_callback, int32_t p_window_id = 0);
	uint64_t window_get_attached_instance_id(int32_t p_window_id = 0) const;
	Vector2i window_get_max_size(int32_t p_window_id = 0) const;
	void window_set_max_size(const Vector2i &p_max_size, int32_t p_window_id = 0);
	Vector2i window_get_min_size(int32_t p_window_id = 0) const;
	void window_set_min_size(const Vector2i &p_min_size, int32_t p_window_id = 0);
	Vector2i window_get_size_with_decorations(int32_t p_window_id = 0) const;
	DisplayServer::WindowMode window_get_mode(int32_t p_window_id = 0) const;
	void window_set_mode(DisplayServer::WindowMode p_mode, int32_t p_window_id = 0);
	void window_set_flag(DisplayServer::WindowFlags p_flag, bool p_enabled, int32_t p_window_id = 0);
	bool window_get_flag(DisplayServer::WindowFlags p_flag, int32_t p_window_id = 0) const;
	void window_set_window_buttons_offset(const Vector2i &p_offset, int32_t p_window_id = 0);
	Vector3i window_get_safe_title_margins(int32_t p_window_id = 0) const;
	void window_request_attention(int32_t p_window_id = 0);
	void window_move_to_foreground(int32_t p_window_id = 0);
	bool window_is_focused(int32_t p_window_id = 0) const;
	bool window_can_draw(int32_t p_window_id = 0) const;
	void window_set_transient(int32_t p_window_id, int32_t p_parent_window_id);
	void window_set_exclusive(int32_t p_window_id, bool p_exclusive);
	void window_set_ime_active(bool p_active, int32_t p_window_id = 0);
	void window_set_ime_position(const Vector2i &p_position, int32_t p_window_id = 0);
	void window_set_vsync_mode(DisplayServer::VSyncMode p_vsync_mode, int32_t p_window_id = 0);
	DisplayServer::VSyncMode window_get_vsync_mode(int32_t p_window_id = 0) const;
	bool window_is_maximize_allowed(int32_t p_window_id = 0) const;
	bool window_maximize_on_title_dbl_click() const;
	bool window_minimize_on_title_dbl_click() const;
	Vector2i ime_get_selection() const;
	String ime_get_text() const;
	void virtual_keyboard_show(const String &p_existing_text, const Rect2 &p_position = Rect2(0, 0, 0, 0), DisplayServer::VirtualKeyboardType p_type = (DisplayServer::VirtualKeyboardType)0, int32_t p_max_length = -1, int32_t p_cursor_start = -1, int32_t p_cursor_end = -1);
	void virtual_keyboard_hide();
	int32_t virtual_keyboard_get_height() const;
	bool has_hardware_keyboard() const;
	void cursor_set_shape(DisplayServer::CursorShape p_shape);
	DisplayServer::CursorShape cursor_get_shape() const;
	void cursor_set_custom_image(const Ref<Resource> &p_cursor, DisplayServer::CursorShape p_shape = (DisplayServer::CursorShape)0, const Vector2 &p_hotspot = Vector2(0, 0));
	bool get_swap_cancel_ok();
	void enable_for_stealing_focus(int64_t p_process_id);
	Error dialog_show(const String &p_title, const String &p_description, const PackedStringArray &p_buttons, const Callable &p_callback);
	Error dialog_input_text(const String &p_title, const String &p_description, const String &p_existing_text, const Callable &p_callback);
	Error file_dialog_show(const String &p_title, const String &p_current_directory, const String &p_filename, bool p_show_hidden, DisplayServer::FileDialogMode p_mode, const PackedStringArray &p_filters, const Callable &p_callback);
	Error file_dialog_with_options_show(const String &p_title, const String &p_current_directory, const String &p_root, const String &p_filename, bool p_show_hidden, DisplayServer::FileDialogMode p_mode, const PackedStringArray &p_filters, const TypedArray<Dictionary> &p_options, const Callable &p_callback);
	int32_t keyboard_get_layout_count() const;
	int32_t keyboard_get_current_layout() const;
	void keyboard_set_current_layout(int32_t p_index);
	String keyboard_get_layout_language(int32_t p_index) const;
	String keyboard_get_layout_name(int32_t p_index) const;
	Key keyboard_get_keycode_from_physical(Key p_keycode) const;
	Key keyboard_get_label_from_physical(Key p_keycode) const;
	void process_events();
	void force_process_and_drop_events();
	void set_native_icon(const String &p_filename);
	void set_icon(const Ref<Image> &p_image);
	int32_t create_status_indicator(const Ref<Texture2D> &p_icon, const String &p_tooltip, const Callable &p_callback);
	void status_indicator_set_icon(int32_t p_id, const Ref<Texture2D> &p_icon);
	void status_indicator_set_tooltip(int32_t p_id, const String &p_tooltip);
	void status_indicator_set_menu(int32_t p_id, const RID &p_menu_rid);
	void status_indicator_set_callback(int32_t p_id, const Callable &p_callback);
	Rect2 status_indicator_get_rect(int32_t p_id) const;
	void delete_status_indicator(int32_t p_id);
	int32_t tablet_get_driver_count() const;
	String tablet_get_driver_name(int32_t p_idx) const;
	String tablet_get_current_driver() const;
	void tablet_set_current_driver(const String &p_name);
	bool is_window_transparency_available() const;
	void register_additional_output(Object *p_object);
	void unregister_additional_output(Object *p_object);
	bool has_additional_outputs() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Object::register_virtuals<T, B>();
	}

	~DisplayServer();

public:
};

} // namespace godot

VARIANT_ENUM_CAST(DisplayServer::Feature);
VARIANT_ENUM_CAST(DisplayServer::MouseMode);
VARIANT_ENUM_CAST(DisplayServer::ScreenOrientation);
VARIANT_ENUM_CAST(DisplayServer::VirtualKeyboardType);
VARIANT_ENUM_CAST(DisplayServer::CursorShape);
VARIANT_ENUM_CAST(DisplayServer::FileDialogMode);
VARIANT_ENUM_CAST(DisplayServer::WindowMode);
VARIANT_ENUM_CAST(DisplayServer::WindowFlags);
VARIANT_ENUM_CAST(DisplayServer::WindowEvent);
VARIANT_ENUM_CAST(DisplayServer::VSyncMode);
VARIANT_ENUM_CAST(DisplayServer::HandleType);
VARIANT_ENUM_CAST(DisplayServer::TTSUtteranceEvent);

#endif // ! GODOT_CPP_DISPLAY_SERVER_HPP
