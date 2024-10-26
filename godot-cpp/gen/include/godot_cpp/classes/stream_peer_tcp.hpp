/**************************************************************************/
/*  stream_peer_tcp.hpp                                                   */
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

#ifndef GODOT_CPP_STREAM_PEER_TCP_HPP
#define GODOT_CPP_STREAM_PEER_TCP_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/stream_peer.hpp>
#include <godot_cpp/variant/string.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class StreamPeerTCP : public StreamPeer {
	GDEXTENSION_CLASS(StreamPeerTCP, StreamPeer)

public:
	enum Status {
		STATUS_NONE = 0,
		STATUS_CONNECTING = 1,
		STATUS_CONNECTED = 2,
		STATUS_ERROR = 3,
	};

	Error bind(int32_t p_port, const String &p_host = "*");
	Error connect_to_host(const String &p_host, int32_t p_port);
	Error poll();
	StreamPeerTCP::Status get_status() const;
	String get_connected_host() const;
	int32_t get_connected_port() const;
	int32_t get_local_port() const;
	void disconnect_from_host();
	void set_no_delay(bool p_enabled);

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		StreamPeer::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(StreamPeerTCP::Status);

#endif // ! GODOT_CPP_STREAM_PEER_TCP_HPP
