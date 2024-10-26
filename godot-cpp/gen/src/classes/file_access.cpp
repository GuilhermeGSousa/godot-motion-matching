/**************************************************************************/
/*  file_access.cpp                                                       */
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

#include <godot_cpp/classes/file_access.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/error_macros.hpp>

namespace godot {

Ref<FileAccess> FileAccess::open(const String &p_path, FileAccess::ModeFlags p_flags) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("open")._native_ptr(), 1247358404);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<FileAccess>());
	return Ref<FileAccess>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<FileAccess>(_gde_method_bind, nullptr, &p_path, &p_flags));
}

Ref<FileAccess> FileAccess::open_encrypted(const String &p_path, FileAccess::ModeFlags p_mode_flags, const PackedByteArray &p_key) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("open_encrypted")._native_ptr(), 1482131466);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<FileAccess>());
	return Ref<FileAccess>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<FileAccess>(_gde_method_bind, nullptr, &p_path, &p_mode_flags, &p_key));
}

Ref<FileAccess> FileAccess::open_encrypted_with_pass(const String &p_path, FileAccess::ModeFlags p_mode_flags, const String &p_pass) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("open_encrypted_with_pass")._native_ptr(), 790283377);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<FileAccess>());
	return Ref<FileAccess>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<FileAccess>(_gde_method_bind, nullptr, &p_path, &p_mode_flags, &p_pass));
}

Ref<FileAccess> FileAccess::open_compressed(const String &p_path, FileAccess::ModeFlags p_mode_flags, FileAccess::CompressionMode p_compression_mode) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("open_compressed")._native_ptr(), 3686439335);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Ref<FileAccess>());
	return Ref<FileAccess>::_gde_internal_constructor(internal::_call_native_mb_ret_obj<FileAccess>(_gde_method_bind, nullptr, &p_path, &p_mode_flags, &p_compression_mode));
}

Error FileAccess::get_open_error() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_open_error")._native_ptr(), 166280745);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, nullptr);
}

PackedByteArray FileAccess::get_file_as_bytes(const String &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_file_as_bytes")._native_ptr(), 659035735);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedByteArray());
	return internal::_call_native_mb_ret<PackedByteArray>(_gde_method_bind, nullptr, &p_path);
}

String FileAccess::get_file_as_string(const String &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_file_as_string")._native_ptr(), 1703090593);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, nullptr, &p_path);
}

Error FileAccess::resize(int64_t p_length) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("resize")._native_ptr(), 844576869);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	int64_t p_length_encoded;
	PtrToArg<int64_t>::encode(p_length, &p_length_encoded);
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner, &p_length_encoded);
}

void FileAccess::flush() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("flush")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

String FileAccess::get_path() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_path")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

String FileAccess::get_path_absolute() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_path_absolute")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

bool FileAccess::is_open() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("is_open")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void FileAccess::seek(uint64_t p_position) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("seek")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_position_encoded;
	PtrToArg<int64_t>::encode(p_position, &p_position_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_position_encoded);
}

void FileAccess::seek_end(int64_t p_position) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("seek_end")._native_ptr(), 1995695955);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_position_encoded;
	PtrToArg<int64_t>::encode(p_position, &p_position_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_position_encoded);
}

uint64_t FileAccess::get_position() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_position")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner);
}

uint64_t FileAccess::get_length() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_length")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner);
}

bool FileAccess::eof_reached() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("eof_reached")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

uint8_t FileAccess::get_8() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_8")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

uint16_t FileAccess::get_16() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_16")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

uint32_t FileAccess::get_32() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_32")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

uint64_t FileAccess::get_64() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_64")._native_ptr(), 3905245786);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, _owner);
}

float FileAccess::get_float() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_float")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

double FileAccess::get_double() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_double")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

float FileAccess::get_real() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_real")._native_ptr(), 1740695150);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0.0);
	return internal::_call_native_mb_ret<double>(_gde_method_bind, _owner);
}

PackedByteArray FileAccess::get_buffer(int64_t p_length) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_buffer")._native_ptr(), 4131300905);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedByteArray());
	int64_t p_length_encoded;
	PtrToArg<int64_t>::encode(p_length, &p_length_encoded);
	return internal::_call_native_mb_ret<PackedByteArray>(_gde_method_bind, _owner, &p_length_encoded);
}

String FileAccess::get_line() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_line")._native_ptr(), 201670096);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

PackedStringArray FileAccess::get_csv_line(const String &p_delim) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_csv_line")._native_ptr(), 2358116058);
	CHECK_METHOD_BIND_RET(_gde_method_bind, PackedStringArray());
	return internal::_call_native_mb_ret<PackedStringArray>(_gde_method_bind, _owner, &p_delim);
}

String FileAccess::get_as_text(bool p_skip_cr) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_as_text")._native_ptr(), 1162154673);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	int8_t p_skip_cr_encoded;
	PtrToArg<bool>::encode(p_skip_cr, &p_skip_cr_encoded);
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner, &p_skip_cr_encoded);
}

String FileAccess::get_md5(const String &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_md5")._native_ptr(), 1703090593);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, nullptr, &p_path);
}

String FileAccess::get_sha256(const String &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_sha256")._native_ptr(), 1703090593);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, nullptr, &p_path);
}

bool FileAccess::is_big_endian() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("is_big_endian")._native_ptr(), 36873697);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, _owner);
}

void FileAccess::set_big_endian(bool p_big_endian) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("set_big_endian")._native_ptr(), 2586408642);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_big_endian_encoded;
	PtrToArg<bool>::encode(p_big_endian, &p_big_endian_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_big_endian_encoded);
}

Error FileAccess::get_error() const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_error")._native_ptr(), 3185525595);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, _owner);
}

Variant FileAccess::get_var(bool p_allow_objects) const {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_var")._native_ptr(), 189129690);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Variant());
	int8_t p_allow_objects_encoded;
	PtrToArg<bool>::encode(p_allow_objects, &p_allow_objects_encoded);
	return internal::_call_native_mb_ret<Variant>(_gde_method_bind, _owner, &p_allow_objects_encoded);
}

void FileAccess::store_8(uint8_t p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_8")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

void FileAccess::store_16(uint16_t p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_16")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

void FileAccess::store_32(uint32_t p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_32")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

void FileAccess::store_64(uint64_t p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_64")._native_ptr(), 1286410249);
	CHECK_METHOD_BIND(_gde_method_bind);
	int64_t p_value_encoded;
	PtrToArg<int64_t>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

void FileAccess::store_float(float p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_float")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_value_encoded;
	PtrToArg<double>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

void FileAccess::store_double(double p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_double")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_value_encoded;
	PtrToArg<double>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

void FileAccess::store_real(float p_value) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_real")._native_ptr(), 373806689);
	CHECK_METHOD_BIND(_gde_method_bind);
	double p_value_encoded;
	PtrToArg<double>::encode(p_value, &p_value_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value_encoded);
}

void FileAccess::store_buffer(const PackedByteArray &p_buffer) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_buffer")._native_ptr(), 2971499966);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_buffer);
}

void FileAccess::store_line(const String &p_line) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_line")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_line);
}

void FileAccess::store_csv_line(const PackedStringArray &p_values, const String &p_delim) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_csv_line")._native_ptr(), 2173791505);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_values, &p_delim);
}

void FileAccess::store_string(const String &p_string) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_string")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_string);
}

void FileAccess::store_var(const Variant &p_value, bool p_full_objects) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_var")._native_ptr(), 738511890);
	CHECK_METHOD_BIND(_gde_method_bind);
	int8_t p_full_objects_encoded;
	PtrToArg<bool>::encode(p_full_objects, &p_full_objects_encoded);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_value, &p_full_objects_encoded);
}

void FileAccess::store_pascal_string(const String &p_string) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("store_pascal_string")._native_ptr(), 83702148);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner, &p_string);
}

String FileAccess::get_pascal_string() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_pascal_string")._native_ptr(), 2841200299);
	CHECK_METHOD_BIND_RET(_gde_method_bind, String());
	return internal::_call_native_mb_ret<String>(_gde_method_bind, _owner);
}

void FileAccess::close() {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("close")._native_ptr(), 3218959716);
	CHECK_METHOD_BIND(_gde_method_bind);
	internal::_call_native_mb_no_ret(_gde_method_bind, _owner);
}

bool FileAccess::file_exists(const String &p_path) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("file_exists")._native_ptr(), 2323990056);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, nullptr, &p_path);
}

uint64_t FileAccess::get_modified_time(const String &p_file) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_modified_time")._native_ptr(), 1597066294);
	CHECK_METHOD_BIND_RET(_gde_method_bind, 0);
	return internal::_call_native_mb_ret<uint64_t>(_gde_method_bind, nullptr, &p_file);
}

BitField<FileAccess::UnixPermissionFlags> FileAccess::get_unix_permissions(const String &p_file) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_unix_permissions")._native_ptr(), 524341837);
	CHECK_METHOD_BIND_RET(_gde_method_bind, BitField<FileAccess::UnixPermissionFlags>(0));
	return (int64_t)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, nullptr, &p_file);
}

Error FileAccess::set_unix_permissions(const String &p_file, BitField<FileAccess::UnixPermissionFlags> p_permissions) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("set_unix_permissions")._native_ptr(), 846038644);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, nullptr, &p_file, &p_permissions);
}

bool FileAccess::get_hidden_attribute(const String &p_file) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_hidden_attribute")._native_ptr(), 2323990056);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, nullptr, &p_file);
}

Error FileAccess::set_hidden_attribute(const String &p_file, bool p_hidden) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("set_hidden_attribute")._native_ptr(), 2892558115);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	int8_t p_hidden_encoded;
	PtrToArg<bool>::encode(p_hidden, &p_hidden_encoded);
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, nullptr, &p_file, &p_hidden_encoded);
}

Error FileAccess::set_read_only_attribute(const String &p_file, bool p_ro) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("set_read_only_attribute")._native_ptr(), 2892558115);
	CHECK_METHOD_BIND_RET(_gde_method_bind, Error(0));
	int8_t p_ro_encoded;
	PtrToArg<bool>::encode(p_ro, &p_ro_encoded);
	return (Error)internal::_call_native_mb_ret<int64_t>(_gde_method_bind, nullptr, &p_file, &p_ro_encoded);
}

bool FileAccess::get_read_only_attribute(const String &p_file) {
	static GDExtensionMethodBindPtr _gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(FileAccess::get_class_static()._native_ptr(), StringName("get_read_only_attribute")._native_ptr(), 2323990056);
	CHECK_METHOD_BIND_RET(_gde_method_bind, false);
	return internal::_call_native_mb_ret<int8_t>(_gde_method_bind, nullptr, &p_file);
}

} // namespace godot
