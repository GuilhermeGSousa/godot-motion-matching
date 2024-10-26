/**************************************************************************/
/*  animation_node_animation.cpp                                          */
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

#include <godot_cpp/classes/animation_node_animation.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

void AnimationNodeAnimation::set_animation(const StringName &p_name) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("set_animation")._native_ptr(), 3304788590);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_name);
}

StringName AnimationNodeAnimation::get_animation() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("get_animation")._native_ptr(), 2002593661);
	CHECK_METHOD_BIND_RET(_gde_method_bind, StringName());
	return internal::_call_native_mb_ret<StringName>(_gde_method_bind, _owner);
}

void AnimationNodeAnimation::set_play_mode(AnimationNodeAnimation::PlayMode p_mode) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("set_play_mode")._native_ptr(), 3347718873);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_mode);
}

AnimationNodeAnimation::PlayMode AnimationNodeAnimation::get_play_mode() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("get_play_mode")._native_ptr(), 2061244637);
	CHECK_METHOD_BIND_RET(_gde_method_bind, AnimationNodeAnimation::PlayMode(0));
	return (AnimationNodeAnimation::PlayMode)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void AnimationNodeAnimation::set_use_custom_timeline(bool p_use_custom_timeline) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("set_use_custom_timeline")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_use_custom_timeline_encoded;
	PtrToArg<bool>::encode(p_use_custom_timeline, &p_use_custom_timeline_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_use_custom_timeline_encoded);
}

bool AnimationNodeAnimation::is_using_custom_timeline() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("is_using_custom_timeline")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void AnimationNodeAnimation::set_timeline_length(double p_timeline_length) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("set_timeline_length")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_timeline_length_encoded;
	PtrToArg<double>::encode(p_timeline_length, &p_timeline_length_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_timeline_length_encoded);
}

double AnimationNodeAnimation::get_timeline_length() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("get_timeline_length")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void AnimationNodeAnimation::set_stretch_time_scale(bool p_stretch_time_scale) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("set_stretch_time_scale")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_stretch_time_scale_encoded;
	PtrToArg<bool>::encode(p_stretch_time_scale, &p_stretch_time_scale_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_stretch_time_scale_encoded);
}

bool AnimationNodeAnimation::is_stretching_time_scale() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("is_stretching_time_scale")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void AnimationNodeAnimation::set_start_offset(double p_start_offset) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("set_start_offset")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_start_offset_encoded;
	PtrToArg<double>::encode(p_start_offset, &p_start_offset_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_start_offset_encoded);
}

double AnimationNodeAnimation::get_start_offset() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("get_start_offset")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

void AnimationNodeAnimation::set_loop_mode(Animation::LoopMode p_loop_mode) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("set_loop_mode")._native_ptr(), 3155355575);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_loop_mode);
}

Animation::LoopMode AnimationNodeAnimation::get_loop_mode() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(AnimationNodeAnimation::get_class_static()._native_ptr(), StringName("get_loop_mode")._native_ptr(), 1988889481);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Animation::LoopMode(0));
	return (Animation::LoopMode)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

} // namespace godot
