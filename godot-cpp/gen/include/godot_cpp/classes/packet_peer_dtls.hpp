/**************************************************************************/
/*  packet_peer_dtls.hpp                                                  */
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

#ifndef GODOT_CPP_PACKET_PEER_DTLS_HPP
#define GODOT_CPP_PACKET_PEER_DTLS_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/packet_peer.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/tls_options.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class PacketPeerUDP;
class String;

class PacketPeerDTLS : public PacketPeer {
	GDEXTENSION_CLASS(PacketPeerDTLS, PacketPeer)

public:
	enum Status {
		STATUS_DISCONNECTED = 0,
		STATUS_HANDSHAKING = 1,
		STATUS_CONNECTED = 2,
		STATUS_ERROR = 3,
		STATUS_ERROR_HOSTNAME_MISMATCH = 4,
	};

	void poll();
	Error connect_to_peer(const Ref<PacketPeerUDP> &p_packet_peer, const String &p_hostname, const Ref<TLSOptions> &p_client_options = nullptr);
	PacketPeerDTLS::Status get_status() const;
	void disconnect_from_peer();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		PacketPeer::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(PacketPeerDTLS::Status);

#endif // ! GODOT_CPP_PACKET_PEER_DTLS_HPP
