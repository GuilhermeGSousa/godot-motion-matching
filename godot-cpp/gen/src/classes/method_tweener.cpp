/**************************************************************************/
/*  method_tweener.cpp                                                    */
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

#include <godot_cpp/classes/method_tweener.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

Ref<MethodTweener> MethodTweener::set_delay(double p_delay) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(MethodTweener::get_class_static()._native_ptr(), StringName("set_delay")._native_ptr(), 266477812);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<MethodTweener>());
	double p_delay_encoded;
	PtrToArg<double>::encode(p_delay, &p_delay_encoded);
	return Ref<MethodTweener>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<MethodTweener>(_gde_method_bind, _owner, &p_delay_encoded));
}

Ref<MethodTweener> MethodTweener::set_trans(Tween::TransitionType p_trans) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(MethodTweener::get_class_static()._native_ptr(), StringName("set_trans")._native_ptr(), 3740975367);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<MethodTweener>());
	return Ref<MethodTweener>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<MethodTweener>(_gde_method_bind, _owner, &p_trans));
}

Ref<MethodTweener> MethodTweener::set_ease(Tween::EaseType p_ease) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(MethodTweener::get_class_static()._native_ptr(), StringName("set_ease")._native_ptr(), 315540545);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<MethodTweener>());
	return Ref<MethodTweener>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<MethodTweener>(_gde_method_bind, _owner, &p_ease));
}

} // namespace godot
