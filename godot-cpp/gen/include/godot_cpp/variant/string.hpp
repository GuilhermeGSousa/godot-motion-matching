/**************************************************************************/
/*  string.hpp                                                            */
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

#ifndef GODOT_CPP_STRING_HPP
#define GODOT_CPP_STRING_HPP

#include <godot_cpp/core/defs.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/variant/char_string.hpp>
#include <godot_cpp/variant/char_utils.hpp>

#include <gdextension_interface.h>

namespace godot {

struct AABB;
class Array;
struct Basis;
class Callable;
struct Color;
class Dictionary;
class NodePath;
class Object;
class PackedByteArray;
class PackedColorArray;
class PackedFloat32Array;
class PackedFloat64Array;
class PackedInt32Array;
class PackedInt64Array;
class PackedStringArray;
class PackedVector2Array;
class PackedVector3Array;
class PackedVector4Array;
struct Plane;
struct Projection;
struct Quaternion;
struct Rect2;
struct Rect2i;
class Signal;
class StringName;
struct Transform2D;
struct Transform3D;
class Variant;
struct Vector2;
struct Vector2i;
struct Vector3;
struct Vector3i;
struct Vector4;
struct Vector4i;

class String {
	static constexpr size_t STRING_SIZE = 8;
	uint8_t opaque[STRING_SIZE] = {};

	friend class Variant;
	friend class StringName;

	static struct _MethodBindings {
		GDExtensionTypeFromVariantConstructorFunc from_variant_constructor;
		GDExtensionPtrConstructor constructor_0;
		GDExtensionPtrConstructor constructor_1;
		GDExtensionPtrConstructor constructor_2;
		GDExtensionPtrConstructor constructor_3;
		GDExtensionPtrDestructor destructor;
		GDExtensionPtrBuiltInMethod method_casecmp_to;
		GDExtensionPtrBuiltInMethod method_nocasecmp_to;
		GDExtensionPtrBuiltInMethod method_naturalcasecmp_to;
		GDExtensionPtrBuiltInMethod method_naturalnocasecmp_to;
		GDExtensionPtrBuiltInMethod method_filecasecmp_to;
		GDExtensionPtrBuiltInMethod method_filenocasecmp_to;
		GDExtensionPtrBuiltInMethod method_length;
		GDExtensionPtrBuiltInMethod method_substr;
		GDExtensionPtrBuiltInMethod method_get_slice;
		GDExtensionPtrBuiltInMethod method_get_slicec;
		GDExtensionPtrBuiltInMethod method_get_slice_count;
		GDExtensionPtrBuiltInMethod method_find;
		GDExtensionPtrBuiltInMethod method_findn;
		GDExtensionPtrBuiltInMethod method_count;
		GDExtensionPtrBuiltInMethod method_countn;
		GDExtensionPtrBuiltInMethod method_rfind;
		GDExtensionPtrBuiltInMethod method_rfindn;
		GDExtensionPtrBuiltInMethod method_match;
		GDExtensionPtrBuiltInMethod method_matchn;
		GDExtensionPtrBuiltInMethod method_begins_with;
		GDExtensionPtrBuiltInMethod method_ends_with;
		GDExtensionPtrBuiltInMethod method_is_subsequence_of;
		GDExtensionPtrBuiltInMethod method_is_subsequence_ofn;
		GDExtensionPtrBuiltInMethod method_bigrams;
		GDExtensionPtrBuiltInMethod method_similarity;
		GDExtensionPtrBuiltInMethod method_format;
		GDExtensionPtrBuiltInMethod method_replace;
		GDExtensionPtrBuiltInMethod method_replacen;
		GDExtensionPtrBuiltInMethod method_repeat;
		GDExtensionPtrBuiltInMethod method_reverse;
		GDExtensionPtrBuiltInMethod method_insert;
		GDExtensionPtrBuiltInMethod method_erase;
		GDExtensionPtrBuiltInMethod method_capitalize;
		GDExtensionPtrBuiltInMethod method_to_camel_case;
		GDExtensionPtrBuiltInMethod method_to_pascal_case;
		GDExtensionPtrBuiltInMethod method_to_snake_case;
		GDExtensionPtrBuiltInMethod method_split;
		GDExtensionPtrBuiltInMethod method_rsplit;
		GDExtensionPtrBuiltInMethod method_split_floats;
		GDExtensionPtrBuiltInMethod method_join;
		GDExtensionPtrBuiltInMethod method_to_upper;
		GDExtensionPtrBuiltInMethod method_to_lower;
		GDExtensionPtrBuiltInMethod method_left;
		GDExtensionPtrBuiltInMethod method_right;
		GDExtensionPtrBuiltInMethod method_strip_edges;
		GDExtensionPtrBuiltInMethod method_strip_escapes;
		GDExtensionPtrBuiltInMethod method_lstrip;
		GDExtensionPtrBuiltInMethod method_rstrip;
		GDExtensionPtrBuiltInMethod method_get_extension;
		GDExtensionPtrBuiltInMethod method_get_basename;
		GDExtensionPtrBuiltInMethod method_path_join;
		GDExtensionPtrBuiltInMethod method_unicode_at;
		GDExtensionPtrBuiltInMethod method_indent;
		GDExtensionPtrBuiltInMethod method_dedent;
		GDExtensionPtrBuiltInMethod method_hash;
		GDExtensionPtrBuiltInMethod method_md5_text;
		GDExtensionPtrBuiltInMethod method_sha1_text;
		GDExtensionPtrBuiltInMethod method_sha256_text;
		GDExtensionPtrBuiltInMethod method_md5_buffer;
		GDExtensionPtrBuiltInMethod method_sha1_buffer;
		GDExtensionPtrBuiltInMethod method_sha256_buffer;
		GDExtensionPtrBuiltInMethod method_is_empty;
		GDExtensionPtrBuiltInMethod method_contains;
		GDExtensionPtrBuiltInMethod method_containsn;
		GDExtensionPtrBuiltInMethod method_is_absolute_path;
		GDExtensionPtrBuiltInMethod method_is_relative_path;
		GDExtensionPtrBuiltInMethod method_simplify_path;
		GDExtensionPtrBuiltInMethod method_get_base_dir;
		GDExtensionPtrBuiltInMethod method_get_file;
		GDExtensionPtrBuiltInMethod method_xml_escape;
		GDExtensionPtrBuiltInMethod method_xml_unescape;
		GDExtensionPtrBuiltInMethod method_uri_encode;
		GDExtensionPtrBuiltInMethod method_uri_decode;
		GDExtensionPtrBuiltInMethod method_c_escape;
		GDExtensionPtrBuiltInMethod method_c_unescape;
		GDExtensionPtrBuiltInMethod method_json_escape;
		GDExtensionPtrBuiltInMethod method_validate_node_name;
		GDExtensionPtrBuiltInMethod method_validate_filename;
		GDExtensionPtrBuiltInMethod method_is_valid_ascii_identifier;
		GDExtensionPtrBuiltInMethod method_is_valid_unicode_identifier;
		GDExtensionPtrBuiltInMethod method_is_valid_identifier;
		GDExtensionPtrBuiltInMethod method_is_valid_int;
		GDExtensionPtrBuiltInMethod method_is_valid_float;
		GDExtensionPtrBuiltInMethod method_is_valid_hex_number;
		GDExtensionPtrBuiltInMethod method_is_valid_html_color;
		GDExtensionPtrBuiltInMethod method_is_valid_ip_address;
		GDExtensionPtrBuiltInMethod method_is_valid_filename;
		GDExtensionPtrBuiltInMethod method_to_int;
		GDExtensionPtrBuiltInMethod method_to_float;
		GDExtensionPtrBuiltInMethod method_hex_to_int;
		GDExtensionPtrBuiltInMethod method_bin_to_int;
		GDExtensionPtrBuiltInMethod method_lpad;
		GDExtensionPtrBuiltInMethod method_rpad;
		GDExtensionPtrBuiltInMethod method_pad_decimals;
		GDExtensionPtrBuiltInMethod method_pad_zeros;
		GDExtensionPtrBuiltInMethod method_trim_prefix;
		GDExtensionPtrBuiltInMethod method_trim_suffix;
		GDExtensionPtrBuiltInMethod method_to_ascii_buffer;
		GDExtensionPtrBuiltInMethod method_to_utf8_buffer;
		GDExtensionPtrBuiltInMethod method_to_utf16_buffer;
		GDExtensionPtrBuiltInMethod method_to_utf32_buffer;
		GDExtensionPtrBuiltInMethod method_hex_decode;
		GDExtensionPtrBuiltInMethod method_to_wchar_buffer;
		GDExtensionPtrBuiltInMethod method_num_scientific;
		GDExtensionPtrBuiltInMethod method_num;
		GDExtensionPtrBuiltInMethod method_num_int64;
		GDExtensionPtrBuiltInMethod method_num_uint64;
		GDExtensionPtrBuiltInMethod method_chr;
		GDExtensionPtrBuiltInMethod method_humanize_size;
		GDExtensionPtrIndexedSetter indexed_setter;
		GDExtensionPtrIndexedGetter indexed_getter;
		GDExtensionPtrOperatorEvaluator operator_equal_Variant;
		GDExtensionPtrOperatorEvaluator operator_not_equal_Variant;
		GDExtensionPtrOperatorEvaluator operator_module_Variant;
		GDExtensionPtrOperatorEvaluator operator_not;
		GDExtensionPtrOperatorEvaluator operator_module_bool;
		GDExtensionPtrOperatorEvaluator operator_module_int;
		GDExtensionPtrOperatorEvaluator operator_module_float;
		GDExtensionPtrOperatorEvaluator operator_equal_String;
		GDExtensionPtrOperatorEvaluator operator_not_equal_String;
		GDExtensionPtrOperatorEvaluator operator_less_String;
		GDExtensionPtrOperatorEvaluator operator_less_equal_String;
		GDExtensionPtrOperatorEvaluator operator_greater_String;
		GDExtensionPtrOperatorEvaluator operator_greater_equal_String;
		GDExtensionPtrOperatorEvaluator operator_add_String;
		GDExtensionPtrOperatorEvaluator operator_module_String;
		GDExtensionPtrOperatorEvaluator operator_in_String;
		GDExtensionPtrOperatorEvaluator operator_module_Vector2;
		GDExtensionPtrOperatorEvaluator operator_module_Vector2i;
		GDExtensionPtrOperatorEvaluator operator_module_Rect2;
		GDExtensionPtrOperatorEvaluator operator_module_Rect2i;
		GDExtensionPtrOperatorEvaluator operator_module_Vector3;
		GDExtensionPtrOperatorEvaluator operator_module_Vector3i;
		GDExtensionPtrOperatorEvaluator operator_module_Transform2D;
		GDExtensionPtrOperatorEvaluator operator_module_Vector4;
		GDExtensionPtrOperatorEvaluator operator_module_Vector4i;
		GDExtensionPtrOperatorEvaluator operator_module_Plane;
		GDExtensionPtrOperatorEvaluator operator_module_Quaternion;
		GDExtensionPtrOperatorEvaluator operator_module_AABB;
		GDExtensionPtrOperatorEvaluator operator_module_Basis;
		GDExtensionPtrOperatorEvaluator operator_module_Transform3D;
		GDExtensionPtrOperatorEvaluator operator_module_Projection;
		GDExtensionPtrOperatorEvaluator operator_module_Color;
		GDExtensionPtrOperatorEvaluator operator_equal_StringName;
		GDExtensionPtrOperatorEvaluator operator_not_equal_StringName;
		GDExtensionPtrOperatorEvaluator operator_add_StringName;
		GDExtensionPtrOperatorEvaluator operator_module_StringName;
		GDExtensionPtrOperatorEvaluator operator_in_StringName;
		GDExtensionPtrOperatorEvaluator operator_module_NodePath;
		GDExtensionPtrOperatorEvaluator operator_module_Object;
		GDExtensionPtrOperatorEvaluator operator_in_Object;
		GDExtensionPtrOperatorEvaluator operator_module_Callable;
		GDExtensionPtrOperatorEvaluator operator_module_Signal;
		GDExtensionPtrOperatorEvaluator operator_module_Dictionary;
		GDExtensionPtrOperatorEvaluator operator_in_Dictionary;
		GDExtensionPtrOperatorEvaluator operator_module_Array;
		GDExtensionPtrOperatorEvaluator operator_in_Array;
		GDExtensionPtrOperatorEvaluator operator_module_PackedByteArray;
		GDExtensionPtrOperatorEvaluator operator_module_PackedInt32Array;
		GDExtensionPtrOperatorEvaluator operator_module_PackedInt64Array;
		GDExtensionPtrOperatorEvaluator operator_module_PackedFloat32Array;
		GDExtensionPtrOperatorEvaluator operator_module_PackedFloat64Array;
		GDExtensionPtrOperatorEvaluator operator_module_PackedStringArray;
		GDExtensionPtrOperatorEvaluator operator_in_PackedStringArray;
		GDExtensionPtrOperatorEvaluator operator_module_PackedVector2Array;
		GDExtensionPtrOperatorEvaluator operator_module_PackedVector3Array;
		GDExtensionPtrOperatorEvaluator operator_module_PackedColorArray;
		GDExtensionPtrOperatorEvaluator operator_module_PackedVector4Array;
	} _method_bindings;

	static void init_bindings();
	static void _init_bindings_constructors_destructor();

	String(const Variant *p_variant);

public:
	_FORCE_INLINE_ GDExtensionTypePtr _native_ptr() const { return const_cast<uint8_t(*)[STRING_SIZE]>(&opaque); }
	String();
	String(const String &p_from);
	String(const StringName &p_from);
	String(const NodePath &p_from);
	String(String &&p_other);
	String(const char *p_from);
	String(const wchar_t *p_from);
	String(const char16_t *p_from);
	String(const char32_t *p_from);
	~String();
	int64_t casecmp_to(const String &p_to) const;
	int64_t nocasecmp_to(const String &p_to) const;
	int64_t naturalcasecmp_to(const String &p_to) const;
	int64_t naturalnocasecmp_to(const String &p_to) const;
	int64_t filecasecmp_to(const String &p_to) const;
	int64_t filenocasecmp_to(const String &p_to) const;
	int64_t length() const;
	String substr(int64_t p_from, int64_t p_len = -1) const;
	String get_slice(const String &p_delimiter, int64_t p_slice) const;
	String get_slicec(int64_t p_delimiter, int64_t p_slice) const;
	int64_t get_slice_count(const String &p_delimiter) const;
	int64_t find(const String &p_what, int64_t p_from = 0) const;
	int64_t findn(const String &p_what, int64_t p_from = 0) const;
	int64_t count(const String &p_what, int64_t p_from = 0, int64_t p_to = 0) const;
	int64_t countn(const String &p_what, int64_t p_from = 0, int64_t p_to = 0) const;
	int64_t rfind(const String &p_what, int64_t p_from = -1) const;
	int64_t rfindn(const String &p_what, int64_t p_from = -1) const;
	bool match(const String &p_expr) const;
	bool matchn(const String &p_expr) const;
	bool begins_with(const String &p_text) const;
	bool ends_with(const String &p_text) const;
	bool is_subsequence_of(const String &p_text) const;
	bool is_subsequence_ofn(const String &p_text) const;
	PackedStringArray bigrams() const;
	double similarity(const String &p_text) const;
	String format(const Variant &p_values, const String &p_placeholder = "{_}") const;
	String replace(const String &p_what, const String &p_forwhat) const;
	String replacen(const String &p_what, const String &p_forwhat) const;
	String repeat(int64_t p_count) const;
	String reverse() const;
	String insert(int64_t p_position, const String &p_what) const;
	String erase(int64_t p_position, int64_t p_chars = 1) const;
	String capitalize() const;
	String to_camel_case() const;
	String to_pascal_case() const;
	String to_snake_case() const;
	PackedStringArray split(const String &p_delimiter = String(), bool p_allow_empty = true, int64_t p_maxsplit = 0) const;
	PackedStringArray rsplit(const String &p_delimiter = String(), bool p_allow_empty = true, int64_t p_maxsplit = 0) const;
	PackedFloat64Array split_floats(const String &p_delimiter, bool p_allow_empty = true) const;
	String join(const PackedStringArray &p_parts) const;
	String to_upper() const;
	String to_lower() const;
	String left(int64_t p_length) const;
	String right(int64_t p_length) const;
	String strip_edges(bool p_left = true, bool p_right = true) const;
	String strip_escapes() const;
	String lstrip(const String &p_chars) const;
	String rstrip(const String &p_chars) const;
	String get_extension() const;
	String get_basename() const;
	String path_join(const String &p_file) const;
	int64_t unicode_at(int64_t p_at) const;
	String indent(const String &p_prefix) const;
	String dedent() const;
	int64_t hash() const;
	String md5_text() const;
	String sha1_text() const;
	String sha256_text() const;
	PackedByteArray md5_buffer() const;
	PackedByteArray sha1_buffer() const;
	PackedByteArray sha256_buffer() const;
	bool is_empty() const;
	bool contains(const String &p_what) const;
	bool containsn(const String &p_what) const;
	bool is_absolute_path() const;
	bool is_relative_path() const;
	String simplify_path() const;
	String get_base_dir() const;
	String get_file() const;
	String xml_escape(bool p_escape_quotes = false) const;
	String xml_unescape() const;
	String uri_encode() const;
	String uri_decode() const;
	String c_escape() const;
	String c_unescape() const;
	String json_escape() const;
	String validate_node_name() const;
	String validate_filename() const;
	bool is_valid_ascii_identifier() const;
	bool is_valid_unicode_identifier() const;
	bool is_valid_identifier() const;
	bool is_valid_int() const;
	bool is_valid_float() const;
	bool is_valid_hex_number(bool p_with_prefix = false) const;
	bool is_valid_html_color() const;
	bool is_valid_ip_address() const;
	bool is_valid_filename() const;
	int64_t to_int() const;
	double to_float() const;
	int64_t hex_to_int() const;
	int64_t bin_to_int() const;
	String lpad(int64_t p_min_length, const String &p_character = " ") const;
	String rpad(int64_t p_min_length, const String &p_character = " ") const;
	String pad_decimals(int64_t p_digits) const;
	String pad_zeros(int64_t p_digits) const;
	String trim_prefix(const String &p_prefix) const;
	String trim_suffix(const String &p_suffix) const;
	PackedByteArray to_ascii_buffer() const;
	PackedByteArray to_utf8_buffer() const;
	PackedByteArray to_utf16_buffer() const;
	PackedByteArray to_utf32_buffer() const;
	PackedByteArray hex_decode() const;
	PackedByteArray to_wchar_buffer() const;
	static String num_scientific(double p_number);
	static String num(double p_number, int64_t p_decimals = -1);
	static String num_int64(int64_t p_number, int64_t p_base = 10, bool p_capitalize_hex = false);
	static String num_uint64(int64_t p_number, int64_t p_base = 10, bool p_capitalize_hex = false);
	static String chr(int64_t p_char);
	static String humanize_size(int64_t p_size);
	static String utf8(const char *p_from, int64_t p_len = -1);
	Error parse_utf8(const char *p_from, int64_t p_len = -1);
	static String utf16(const char16_t *p_from, int64_t p_len = -1);
	Error parse_utf16(const char16_t *p_from, int64_t p_len = -1, bool p_default_little_endian = true);
	CharString utf8() const;
	CharString ascii() const;
	Char16String utf16() const;
	Char32String utf32() const;
	CharWideString wide_string() const;
	static String num_real(double p_num, bool p_trailing = true);
	Error resize(int64_t p_size);
	bool operator==(const Variant &p_other) const;
	bool operator!=(const Variant &p_other) const;
	String operator%(const Variant &p_other) const;
	bool operator!() const;
	String operator%(bool p_other) const;
	String operator%(int64_t p_other) const;
	String operator%(double p_other) const;
	bool operator==(const String &p_other) const;
	bool operator!=(const String &p_other) const;
	bool operator<(const String &p_other) const;
	bool operator<=(const String &p_other) const;
	bool operator>(const String &p_other) const;
	bool operator>=(const String &p_other) const;
	String operator+(const String &p_other) const;
	String operator%(const String &p_other) const;
	String operator%(const Vector2 &p_other) const;
	String operator%(const Vector2i &p_other) const;
	String operator%(const Rect2 &p_other) const;
	String operator%(const Rect2i &p_other) const;
	String operator%(const Vector3 &p_other) const;
	String operator%(const Vector3i &p_other) const;
	String operator%(const Transform2D &p_other) const;
	String operator%(const Vector4 &p_other) const;
	String operator%(const Vector4i &p_other) const;
	String operator%(const Plane &p_other) const;
	String operator%(const Quaternion &p_other) const;
	String operator%(const AABB &p_other) const;
	String operator%(const Basis &p_other) const;
	String operator%(const Transform3D &p_other) const;
	String operator%(const Projection &p_other) const;
	String operator%(const Color &p_other) const;
	bool operator==(const StringName &p_other) const;
	bool operator!=(const StringName &p_other) const;
	String operator+(const StringName &p_other) const;
	String operator%(const StringName &p_other) const;
	String operator%(const NodePath &p_other) const;
	String operator%(Object *p_other) const;
	String operator%(const Callable &p_other) const;
	String operator%(const Signal &p_other) const;
	String operator%(const Dictionary &p_other) const;
	String operator%(const Array &p_other) const;
	String operator%(const PackedByteArray &p_other) const;
	String operator%(const PackedInt32Array &p_other) const;
	String operator%(const PackedInt64Array &p_other) const;
	String operator%(const PackedFloat32Array &p_other) const;
	String operator%(const PackedFloat64Array &p_other) const;
	String operator%(const PackedStringArray &p_other) const;
	String operator%(const PackedVector2Array &p_other) const;
	String operator%(const PackedVector3Array &p_other) const;
	String operator%(const PackedColorArray &p_other) const;
	String operator%(const PackedVector4Array &p_other) const;
	String &operator=(const String &p_other);
	String &operator=(String &&p_other);
	String &operator=(const char *p_str);
	String &operator=(const wchar_t *p_str);
	String &operator=(const char16_t *p_str);
	String &operator=(const char32_t *p_str);
	bool operator==(const char *p_str) const;
	bool operator==(const wchar_t *p_str) const;
	bool operator==(const char16_t *p_str) const;
	bool operator==(const char32_t *p_str) const;
	bool operator!=(const char *p_str) const;
	bool operator!=(const wchar_t *p_str) const;
	bool operator!=(const char16_t *p_str) const;
	bool operator!=(const char32_t *p_str) const;
	String operator+(const char *p_str);
	String operator+(const wchar_t *p_str);
	String operator+(const char16_t *p_str);
	String operator+(const char32_t *p_str);
	String operator+(char32_t p_char);
	String &operator+=(const String &p_str);
	String &operator+=(char32_t p_char);
	String &operator+=(const char *p_str);
	String &operator+=(const wchar_t *p_str);
	String &operator+=(const char32_t *p_str);
	const char32_t &operator[](int64_t p_index) const;
	char32_t &operator[](int64_t p_index);
	const char32_t *ptr() const;
	char32_t *ptrw();
};

bool operator==(const char *p_chr, const String &p_str);
bool operator==(const wchar_t *p_chr, const String &p_str);
bool operator==(const char16_t *p_chr, const String &p_str);
bool operator==(const char32_t *p_chr, const String &p_str);
bool operator!=(const char *p_chr, const String &p_str);
bool operator!=(const wchar_t *p_chr, const String &p_str);
bool operator!=(const char16_t *p_chr, const String &p_str);
bool operator!=(const char32_t *p_chr, const String &p_str);
String operator+(const char *p_chr, const String &p_str);
String operator+(const wchar_t *p_chr, const String &p_str);
String operator+(const char16_t *p_chr, const String &p_str);
String operator+(const char32_t *p_chr, const String &p_str);
String operator+(char32_t p_char, const String &p_str);
String itos(int64_t p_val);
String uitos(uint64_t p_val);
String rtos(double p_val);
String rtoss(double p_val);

} // namespace godot

#endif // ! GODOT_CPP_STRING_HPP
