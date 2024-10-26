/**************************************************************************/
/*  input_event_with_modifiers.hpp                                        */
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

#ifndef GODOT_CPP_INPUT_EVENT_WITH_MODIFIERS_HPP
#define GODOT_CPP_INPUT_EVENT_WITH_MODIFIERS_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/input_event_from_window.hpp>
#include <godot_cpp/classes/ref.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class InputEventWithModifiers : public InputEventFromWindow {
	GDEXTENSION_CLASS(InputEventWithModifiers, InputEventFromWindow)

public:
	void set_command_or_control_autoremap(bool p_enable);
	bool is_command_or_control_autoremap() const;
	bool is_command_or_control_pressed() const;
	void set_alt_pressed(bool p_pressed);
	bool is_alt_pressed() const;
	void set_shift_pressed(bool p_pressed);
	bool is_shift_pressed() const;
	void set_ctrl_pressed(bool p_pressed);
	bool is_ctrl_pressed() const;
	void set_meta_pressed(bool p_pressed);
	bool is_meta_pressed() const;
	BitField<KeyModifierMask> get_modifiers_mask() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		InputEventFromWindow::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_INPUT_EVENT_WITH_MODIFIERS_HPP
