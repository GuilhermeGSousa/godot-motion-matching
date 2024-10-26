/**************************************************************************/
/*  stream_peer_tcp.cpp                                                   */
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

#include <godot_cpp/classes/stream_peer_tcp.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

Error StreamPeerTCP::bind(int32_t p_port, const String &p_host) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("bind")._native_ptr(), 3167955072);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	int64_t p_port_encoded;
	PtrToArg<int64_t>::encode(p_port, &p_port_encoded);
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, &p_port_encoded, &p_host);
}

Error StreamPeerTCP::connect_to_host(const String &p_host, int32_t p_port) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("connect_to_host")._native_ptr(), 993915709);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	int64_t p_port_encoded;
	PtrToArg<int64_t>::encode(p_port, &p_port_encoded);
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, &p_host, &p_port_encoded);
}

Error StreamPeerTCP::poll() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("poll")._native_ptr(), 166280745);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

StreamPeerTCP::Status StreamPeerTCP::get_status() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("get_status")._native_ptr(), 859471121);
	CHECK_METHOD_BIND_RET(_gde_method_bind, StreamPeerTCP::Status(0));
	return (StreamPeerTCP::Status)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

String StreamPeerTCP::get_connected_host() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("get_connected_host")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

int32_t StreamPeerTCP::get_connected_port() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("get_connected_port")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

int32_t StreamPeerTCP::get_local_port() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("get_local_port")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void StreamPeerTCP::disconnect_from_host() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("disconnect_from_host")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

void StreamPeerTCP::set_no_delay(bool p_enabled) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(StreamPeerTCP::get_class_static()._native_ptr(), StringName("set_no_delay")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_enabled_encoded;
	PtrToArg<bool>::encode(p_enabled, &p_enabled_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_enabled_encoded);
}

} // namespace godot
