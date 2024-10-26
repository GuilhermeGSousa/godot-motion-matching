/**************************************************************************/
/*  audio_effect_pitch_shift.hpp                                          */
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

#ifndef GODOT_CPP_AUDIO_EFFECT_PITCH_SHIFT_HPP
#define GODOT_CPP_AUDIO_EFFECT_PITCH_SHIFT_HPP

#include <godot_cpp/classes/audio_effect.hpp>
#include <godot_cpp/classes/ref.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class AudioEffectPitchShift : public AudioEffect {
	GDEXTENSION_CLASS(AudioEffectPitchShift, AudioEffect)

public:
	enum FFTSize {
		FFT_SIZE_256 = 0,
		FFT_SIZE_512 = 1,
		FFT_SIZE_1024 = 2,
		FFT_SIZE_2048 = 3,
		FFT_SIZE_4096 = 4,
		FFT_SIZE_MAX = 5,
	};

	void set_pitch_scale(float p_rate);
	float get_pitch_scale() const;
	void set_oversampling(int32_t p_amount);
	int32_t get_oversampling() const;
	void set_fft_size(AudioEffectPitchShift::FFTSize p_size);
	AudioEffectPitchShift::FFTSize get_fft_size() const;

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		AudioEffect::register_virtuals<T, B>();
	}

public:
};

} // namespace godot

VARIANT_ENUM_CAST(AudioEffectPitchShift::FFTSize);

#endif // ! GODOT_CPP_AUDIO_EFFECT_PITCH_SHIFT_HPP
