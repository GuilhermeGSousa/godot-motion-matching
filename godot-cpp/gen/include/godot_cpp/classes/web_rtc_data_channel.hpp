/**************************************************************************/
/*  web_rtc_data_channel.hpp                                              */
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

#ifndef GODOT_CPP_WEB_RTC_DATA_CHANNEL_HPP
#define GODOT_CPP_WEB_RTC_DATA_CHANNEL_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/packet_peer.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/string.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class WebRTCDataChannel : public PacketPeer {
	GDEXTENSION_CLASS(WebRTCDataChannel, PacketPeer)

public:
	enum WriteMode {
		WRITE_MODE_TEXT = 0,
		WRITE_MODE_BINARY = 1,
	};

	enum ChannelState {
		STATE_CONNECTING = 0,
		STATE_OPEN = 1,
		STATE_CLOSING = 2,
		STATE_CLOSED = 3,
	};

	Error poll();
	void close();
	bool was_string_packet() const;
	void set_write_mode(WebRTCDataChannel::WriteMode p_write_mode);
	WebRTCDataChannel::WriteMode get_write_mode() const;
	WebRTCDataChannel::ChannelState get_ready_state() const;
	String get_label() const;
	bool is_ordered() const;
	int32_t get_id() const;
	int32_t get_max_packet_life_time() const;
	int32_t get_max_retransmits() const;
	String get_protocol() const;
	bool is_negotiated() const;
	int32_t get_buffered_amount() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		PacketPeer::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(WebRTCDataChannel::WriteMode);
VARIANT_ENUM_CAST(WebRTCDataChannel::ChannelState);

#endif // ! GODOT_CPP_WEB_RTC_DATA_CHANNEL_HPP
