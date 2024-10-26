/**************************************************************************/
/*  audio_effect_hard_limiter.cpp                                         */
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

#include <godot_cpp/classes/audio_effect_hard_limiter.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void AudioEffectHardLimiter::set_ceiling_db(float p_ceiling) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AudioEffectHardLimiter::get_class_static()._native_ptr(), StringName("set_ceiling_db")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_ceiling_encoded;
	PtrToArg<double>::encode(p_ceiling, &p_ceiling_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_ceiling_encoded);
}

float AudioEffectHardLimiter::get_ceiling_db() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AudioEffectHardLimiter::get_class_static()._native_ptr(), StringName("get_ceiling_db")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void AudioEffectHardLimiter::set_pre_gain_db(float p_pre_gain) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AudioEffectHardLimiter::get_class_static()._native_ptr(), StringName("set_pre_gain_db")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_pre_gain_encoded;
	PtrToArg<double>::encode(p_pre_gain, &p_pre_gain_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_pre_gain_encoded);
}

float AudioEffectHardLimiter::get_pre_gain_db() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AudioEffectHardLimiter::get_class_static()._native_ptr(), StringName("get_pre_gain_db")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void AudioEffectHardLimiter::set_release(float p_release) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AudioEffectHardLimiter::get_class_static()._native_ptr(), StringName("set_release")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_release_encoded;
	PtrToArg<double>::encode(p_release, &p_release_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_release_encoded);
}

float AudioEffectHardLimiter::get_release() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AudioEffectHardLimiter::get_class_static()._native_ptr(), StringName("get_release")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

} // namespace godot
