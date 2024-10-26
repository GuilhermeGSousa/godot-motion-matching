/**************************************************************************/
/*  packet_peer_stream.cpp                                                */
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

#include <godot_cpp/classes/packet_peer_stream.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/stream_peer.hpp>

namespace godot {

void PacketPeerStream::set_stream_peer(const Ref<StreamPeer> &p_peer) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerStream::get_class_static()._native_ptr(), StringName("set_stream_peer")._native_ptr(), 3281897016);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, (p_peer != nullptr ? &p_peer->_owner : nullptr));
}

Ref<StreamPeer> PacketPeerStream::get_stream_peer() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerStream::get_class_static()._native_ptr(), StringName("get_stream_peer")._native_ptr(), 2741655269);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<StreamPeer>());
	return Ref<StreamPeer>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<StreamPeer>(_gde_method_bind, _owner));
}

void PacketPeerStream::set_input_buffer_max_size(int32_t p_max_size_bytes) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerStream::get_class_static()._native_ptr(), StringName("set_input_buffer_max_size")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_max_size_bytes_encoded;
	PtrToArg<int64_t>::encode(p_max_size_bytes, &p_max_size_bytes_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_max_size_bytes_encoded);
}

void PacketPeerStream::set_output_buffer_max_size(int32_t p_max_size_bytes) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerStream::get_class_static()._native_ptr(), StringName("set_output_buffer_max_size")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_max_size_bytes_encoded;
	PtrToArg<int64_t>::encode(p_max_size_bytes, &p_max_size_bytes_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_max_size_bytes_encoded);
}

int32_t PacketPeerStream::get_input_buffer_max_size() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerStream::get_class_static()._native_ptr(), StringName("get_input_buffer_max_size")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

int32_t PacketPeerStream::get_output_buffer_max_size() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerStream::get_class_static()._native_ptr(), StringName("get_output_buffer_max_size")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

} // namespace godot
