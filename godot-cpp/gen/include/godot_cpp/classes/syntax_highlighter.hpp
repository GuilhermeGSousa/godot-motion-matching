/**************************************************************************/
/*  syntax_highlighter.hpp                                                */
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

#ifndef GODOT_CPP_SYNTAX_HIGHLIGHTER_HPP
#define GODOT_CPP_SYNTAX_HIGHLIGHTER_HPP

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/dictionary.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class TextEdit;

class SyntaxHighlighter : public Resource {
	GDEXTENSION_CLASS(SyntaxHighlighter, Resource)

public:
	Dictionary get_line_syntax_highlighting(int32_t p_line);
	void update_cache();
	void clear_highlighting_cache();
	TextEdit *get_text_edit() const;
	virtual Dictionary _get_line_syntax_highlighting(int32_t p_line) const;
	virtual void _clear_highlighting_cache();
	virtual void _update_cache();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Resource::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_get_line_syntax_highlighting), decltype(&T::_get_line_syntax_highlighting)>) {
			BIND_VIRTUAL_METHOD(T, _get_line_syntax_highlighting);
		}
		if constexpr (!std::is_same_v<decltype(&B::_clear_highlighting_cache), decltype(&T::_clear_highlighting_cache)>) {
			BIND_VIRTUAL_METHOD(T, _clear_highlighting_cache);
		}
		if constexpr (!std::is_same_v<decltype(&B::_update_cache), decltype(&T::_update_cache)>) {
			BIND_VIRTUAL_METHOD(T, _update_cache);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_SYNTAX_HIGHLIGHTER_HPP
