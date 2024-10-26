/**************************************************************************/
/*  image_format_loader_extension.hpp                                     */
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

#ifndef GODOT_CPP_IMAGE_FORMAT_LOADER_EXTENSION_HPP
#define GODOT_CPP_IMAGE_FORMAT_LOADER_EXTENSION_HPP

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/image_format_loader.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class FileAccess;
class Image;

class ImageFormatLoaderExtension : public ImageFormatLoader {
	GDEXTENSION_CLASS(ImageFormatLoaderExtension, ImageFormatLoader)

public:
	void add_format_loader();
	void remove_format_loader();
	virtual PackedStringArray _get_recognized_extensions() const;
	virtual Error _load_image(const Ref<Image> &p_image, const Ref<FileAccess> &p_fileaccess, BitField<ImageFormatLoader::LoaderFlags> p_flags, float p_scale);

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		ImageFormatLoader::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_get_recognized_extensions), decltype(&T::_get_recognized_extensions)>) {
			BIND_VIRTUAL_METHOD(T, _get_recognized_extensions);
		}
		if constexpr (!std::is_same_v<decltype(&B::_load_image), decltype(&T::_load_image)>) {
			BIND_VIRTUAL_METHOD(T, _load_image);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_IMAGE_FORMAT_LOADER_EXTENSION_HPP
