/**************************************************************************/
/*  web_rtc_multiplayer_peer.hpp                                          */
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

#ifndef GODOT_CPP_WEB_RTC_MULTIPLAYER_PEER_HPP
#define GODOT_CPP_WEB_RTC_MULTIPLAYER_PEER_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/multiplayer_peer.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class WebRTCPeerConnection;

class WebRTCMultiplayerPeer : public MultiplayerPeer {
	GDEXTENSION_CLASS(WebRTCMultiplayerPeer, MultiplayerPeer)

public:
	Error create_server(const Array &p_channels_config = Array());
	Error create_client(int32_t p_peer_id, const Array &p_channels_config = Array());
	Error create_mesh(int32_t p_peer_id, const Array &p_channels_config = Array());
	Error add_peer(const Ref<WebRTCPeerConnection> &p_peer, int32_t p_peer_id, int32_t p_unreliable_lifetime = 1);
	void remove_peer(int32_t p_peer_id);
	bool has_peer(int32_t p_peer_id);
	Dictionary get_peer(int32_t p_peer_id);
	Dictionary get_peers();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		MultiplayerPeer::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_WEB_RTC_MULTIPLAYER_PEER_HPP
