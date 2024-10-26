/**************************************************************************/
/*  script_extension.hpp                                                  */
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

#ifndef GODOT_CPP_SCRIPT_EXTENSION_HPP
#define GODOT_CPP_SCRIPT_EXTENSION_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Object;
class ScriptLanguage;

class ScriptExtension : public Script {
	GDEXTENSION_CLASS(ScriptExtension, Script)

public:
	virtual bool _editor_can_reload_from_file();
	virtual void _placeholder_erased(void *p_placeholder);
	virtual bool _can_instantiate() const;
	virtual Ref<Script> _get_base_script() const;
	virtual StringName _get_global_name() const;
	virtual bool _inherits_script(const Ref<Script> &p_script) const;
	virtual StringName _get_instance_base_type() const;
	virtual void *_instance_create(Object *p_for_object) const;
	virtual void *_placeholder_instance_create(Object *p_for_object) const;
	virtual bool _instance_has(Object *p_object) const;
	virtual bool _has_source_code() const;
	virtual String _get_source_code() const;
	virtual void _set_source_code(const String &p_code);
	virtual Error _reload(bool p_keep_state);
	virtual TypedArray<Dictionary> _get_documentation() const;
	virtual String _get_class_icon_path() const;
	virtual bool _has_method(const StringName &p_method) const;
	virtual bool _has_static_method(const StringName &p_method) const;
	virtual Variant _get_script_method_argument_count(const StringName &p_method) const;
	virtual Dictionary _get_method_info(const StringName &p_method) const;
	virtual bool _is_tool() const;
	virtual bool _is_valid() const;
	virtual bool _is_abstract() const;
	virtual ScriptLanguage *_get_language() const;
	virtual bool _has_script_signal(const StringName &p_signal) const;
	virtual TypedArray<Dictionary> _get_script_signal_list() const;
	virtual bool _has_property_default_value(const StringName &p_property) const;
	virtual Variant _get_property_default_value(const StringName &p_property) const;
	virtual void _update_exports();
	virtual TypedArray<Dictionary> _get_script_method_list() const;
	virtual TypedArray<Dictionary> _get_script_property_list() const;
	virtual int32_t _get_member_line(const StringName &p_member) const;
	virtual Dictionary _get_constants() const;
	virtual TypedArray<StringName> _get_members() const;
	virtual bool _is_placeholder_fallback_enabled() const;
	virtual Variant _get_rpc_config() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Script::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_editor_can_reload_from_file), decltype(&T::_editor_can_reload_from_file)>) {
			BIND_VIRTUAL_METHOD(T, _editor_can_reload_from_file);
		}
		if constexpr (!std::is_same_v<decltype(&B::_placeholder_erased), decltype(&T::_placeholder_erased)>) {
			BIND_VIRTUAL_METHOD(T, _placeholder_erased);
		}
		if constexpr (!std::is_same_v<decltype(&B::_can_instantiate), decltype(&T::_can_instantiate)>) {
			BIND_VIRTUAL_METHOD(T, _can_instantiate);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_base_script), decltype(&T::_get_base_script)>) {
			BIND_VIRTUAL_METHOD(T, _get_base_script);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_global_name), decltype(&T::_get_global_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_global_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_inherits_script), decltype(&T::_inherits_script)>) {
			BIND_VIRTUAL_METHOD(T, _inherits_script);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_instance_base_type), decltype(&T::_get_instance_base_type)>) {
			BIND_VIRTUAL_METHOD(T, _get_instance_base_type);
		}
		if constexpr (!std::is_same_v<decltype(&B::_instance_create), decltype(&T::_instance_create)>) {
			BIND_VIRTUAL_METHOD(T, _instance_create);
		}
		if constexpr (!std::is_same_v<decltype(&B::_placeholder_instance_create), decltype(&T::_placeholder_instance_create)>) {
			BIND_VIRTUAL_METHOD(T, _placeholder_instance_create);
		}
		if constexpr (!std::is_same_v<decltype(&B::_instance_has), decltype(&T::_instance_has)>) {
			BIND_VIRTUAL_METHOD(T, _instance_has);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has_source_code), decltype(&T::_has_source_code)>) {
			BIND_VIRTUAL_METHOD(T, _has_source_code);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_source_code), decltype(&T::_get_source_code)>) {
			BIND_VIRTUAL_METHOD(T, _get_source_code);
		}
		if constexpr (!std::is_same_v<decltype(&B::_set_source_code), decltype(&T::_set_source_code)>) {
			BIND_VIRTUAL_METHOD(T, _set_source_code);
		}
		if constexpr (!std::is_same_v<decltype(&B::_reload), decltype(&T::_reload)>) {
			BIND_VIRTUAL_METHOD(T, _reload);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_documentation), decltype(&T::_get_documentation)>) {
			BIND_VIRTUAL_METHOD(T, _get_documentation);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_class_icon_path), decltype(&T::_get_class_icon_path)>) {
			BIND_VIRTUAL_METHOD(T, _get_class_icon_path);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has_method), decltype(&T::_has_method)>) {
			BIND_VIRTUAL_METHOD(T, _has_method);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has_static_method), decltype(&T::_has_static_method)>) {
			BIND_VIRTUAL_METHOD(T, _has_static_method);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_script_method_argument_count), decltype(&T::_get_script_method_argument_count)>) {
			BIND_VIRTUAL_METHOD(T, _get_script_method_argument_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_method_info), decltype(&T::_get_method_info)>) {
			BIND_VIRTUAL_METHOD(T, _get_method_info);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_tool), decltype(&T::_is_tool)>) {
			BIND_VIRTUAL_METHOD(T, _is_tool);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_valid), decltype(&T::_is_valid)>) {
			BIND_VIRTUAL_METHOD(T, _is_valid);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_abstract), decltype(&T::_is_abstract)>) {
			BIND_VIRTUAL_METHOD(T, _is_abstract);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_language), decltype(&T::_get_language)>) {
			BIND_VIRTUAL_METHOD(T, _get_language);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has_script_signal), decltype(&T::_has_script_signal)>) {
			BIND_VIRTUAL_METHOD(T, _has_script_signal);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_script_signal_list), decltype(&T::_get_script_signal_list)>) {
			BIND_VIRTUAL_METHOD(T, _get_script_signal_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has_property_default_value), decltype(&T::_has_property_default_value)>) {
			BIND_VIRTUAL_METHOD(T, _has_property_default_value);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_property_default_value), decltype(&T::_get_property_default_value)>) {
			BIND_VIRTUAL_METHOD(T, _get_property_default_value);
		}
		if constexpr (!std::is_same_v<decltype(&B::_update_exports), decltype(&T::_update_exports)>) {
			BIND_VIRTUAL_METHOD(T, _update_exports);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_script_method_list), decltype(&T::_get_script_method_list)>) {
			BIND_VIRTUAL_METHOD(T, _get_script_method_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_script_property_list), decltype(&T::_get_script_property_list)>) {
			BIND_VIRTUAL_METHOD(T, _get_script_property_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_member_line), decltype(&T::_get_member_line)>) {
			BIND_VIRTUAL_METHOD(T, _get_member_line);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_constants), decltype(&T::_get_constants)>) {
			BIND_VIRTUAL_METHOD(T, _get_constants);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_members), decltype(&T::_get_members)>) {
			BIND_VIRTUAL_METHOD(T, _get_members);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_placeholder_fallback_enabled), decltype(&T::_is_placeholder_fallback_enabled)>) {
			BIND_VIRTUAL_METHOD(T, _is_placeholder_fallback_enabled);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_rpc_config), decltype(&T::_get_rpc_config)>) {
			BIND_VIRTUAL_METHOD(T, _get_rpc_config);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_SCRIPT_EXTENSION_HPP
