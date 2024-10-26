/**************************************************************************/
/*  packet_peer_dtls.cpp                                                  */
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

#include <godot_cpp/classes/packet_peer_dtls.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/packet_peer_udp.hpp>
#include <godot_cpp/variant/string.hpp>

namespace godot {

void PacketPeerDTLS::poll() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerDTLS::get_class_static()._native_ptr(), StringName("poll")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

Error PacketPeerDTLS::connect_to_peer(const Ref<PacketPeerUDP> &p_packet_peer, const String &p_hostname, const Ref<TLSOptions> &p_client_options) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerDTLS::get_class_static()._native_ptr(), StringName("connect_to_peer")._native_ptr(), 2880188099);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, (p_packet_peer != nullptr ? &p_packet_peer->_owner : nullptr), &p_hostname, (p_client_options != nullptr ? &p_client_options->_owner : nullptr));
}

PacketPeerDTLS::Status PacketPeerDTLS::get_status() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerDTLS::get_class_static()._native_ptr(), StringName("get_status")._native_ptr(), 3248654679);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PacketPeerDTLS::Status(0));
	return (PacketPeerDTLS::Status)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

void PacketPeerDTLS::disconnect_from_peer() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(PacketPeerDTLS::get_class_static()._native_ptr(), StringName("disconnect_from_peer")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

} // namespace godot
