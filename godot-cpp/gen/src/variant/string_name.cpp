/**************************************************************************/
/*  string_name.cpp                                                       */
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

#include <godot_cpp/variant/string_name.hpp>

#include <godot_cpp/core/binder_common.hpp>

#include <godot_cpp/godot.hpp>

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/packed_color_array.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>
#include <godot_cpp/variant/packed_float64_array.hpp>
#include <godot_cpp/variant/packed_int32_array.hpp>
#include <godot_cpp/variant/packed_int64_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/packed_vector2_array.hpp>
#include <godot_cpp/variant/packed_vector3_array.hpp>
#include <godot_cpp/variant/packed_vector4_array.hpp>
#include <godot_cpp/variant/plane.hpp>
#include <godot_cpp/variant/projection.hpp>
#include <godot_cpp/variant/quaternion.hpp>
#include <godot_cpp/variant/rect2.hpp>
#include <godot_cpp/variant/rect2i.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/transform2d.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector3i.hpp>
#include <godot_cpp/variant/vector4.hpp>
#include <godot_cpp/variant/vector4i.hpp>

#include <godot_cpp/core/builtin_ptrcall.hpp>

#include <utility>

namespace godot {

StringName::_MethodBindings StringName::_method_bindings;

void StringName::_init_bindings_constructors_destructor() {
	_method_bindings.from_variant_constructor = internal::gdextension_interface_get_variant_to_type_constructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.constructor_0 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME, 0);
	_method_bindings.constructor_1 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME, 1);
	_method_bindings.constructor_2 = internal::gdextension_interface_variant_get_ptr_constructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME, 2);
	_method_bindings.destructor = internal::gdextension_interface_variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME);
}
void StringName::init_bindings() {
	String::_init_bindings_constructors_destructor();
	StringName::_init_bindings_constructors_destructor();
	StringName _gde_name;
	_gde_name = StringName("casecmp_to");
	_method_bindings.method_casecmp_to = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2920860731);
	_gde_name = StringName("nocasecmp_to");
	_method_bindings.method_nocasecmp_to = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2920860731);
	_gde_name = StringName("naturalcasecmp_to");
	_method_bindings.method_naturalcasecmp_to = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2920860731);
	_gde_name = StringName("naturalnocasecmp_to");
	_method_bindings.method_naturalnocasecmp_to = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2920860731);
	_gde_name = StringName("filecasecmp_to");
	_method_bindings.method_filecasecmp_to = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2920860731);
	_gde_name = StringName("filenocasecmp_to");
	_method_bindings.method_filenocasecmp_to = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2920860731);
	_gde_name = StringName("length");
	_method_bindings.method_length = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3173160232);
	_gde_name = StringName("substr");
	_method_bindings.method_substr = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 787537301);
	_gde_name = StringName("get_slice");
	_method_bindings.method_get_slice = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3535100402);
	_gde_name = StringName("get_slicec");
	_method_bindings.method_get_slicec = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 787537301);
	_gde_name = StringName("get_slice_count");
	_method_bindings.method_get_slice_count = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2920860731);
	_gde_name = StringName("find");
	_method_bindings.method_find = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1760645412);
	_gde_name = StringName("findn");
	_method_bindings.method_findn = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1760645412);
	_gde_name = StringName("count");
	_method_bindings.method_count = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2343087891);
	_gde_name = StringName("countn");
	_method_bindings.method_countn = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2343087891);
	_gde_name = StringName("rfind");
	_method_bindings.method_rfind = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1760645412);
	_gde_name = StringName("rfindn");
	_method_bindings.method_rfindn = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1760645412);
	_gde_name = StringName("match");
	_method_bindings.method_match = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("matchn");
	_method_bindings.method_matchn = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("begins_with");
	_method_bindings.method_begins_with = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("ends_with");
	_method_bindings.method_ends_with = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("is_subsequence_of");
	_method_bindings.method_is_subsequence_of = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("is_subsequence_ofn");
	_method_bindings.method_is_subsequence_ofn = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("bigrams");
	_method_bindings.method_bigrams = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 747180633);
	_gde_name = StringName("similarity");
	_method_bindings.method_similarity = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2697460964);
	_gde_name = StringName("format");
	_method_bindings.method_format = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3212199029);
	_gde_name = StringName("replace");
	_method_bindings.method_replace = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1340436205);
	_gde_name = StringName("replacen");
	_method_bindings.method_replacen = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1340436205);
	_gde_name = StringName("repeat");
	_method_bindings.method_repeat = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2162347432);
	_gde_name = StringName("reverse");
	_method_bindings.method_reverse = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("insert");
	_method_bindings.method_insert = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 248737229);
	_gde_name = StringName("erase");
	_method_bindings.method_erase = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 787537301);
	_gde_name = StringName("capitalize");
	_method_bindings.method_capitalize = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("to_camel_case");
	_method_bindings.method_to_camel_case = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("to_pascal_case");
	_method_bindings.method_to_pascal_case = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("to_snake_case");
	_method_bindings.method_to_snake_case = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("split");
	_method_bindings.method_split = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1252735785);
	_gde_name = StringName("rsplit");
	_method_bindings.method_rsplit = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 1252735785);
	_gde_name = StringName("split_floats");
	_method_bindings.method_split_floats = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2092079095);
	_gde_name = StringName("join");
	_method_bindings.method_join = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3595973238);
	_gde_name = StringName("to_upper");
	_method_bindings.method_to_upper = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("to_lower");
	_method_bindings.method_to_lower = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("left");
	_method_bindings.method_left = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2162347432);
	_gde_name = StringName("right");
	_method_bindings.method_right = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2162347432);
	_gde_name = StringName("strip_edges");
	_method_bindings.method_strip_edges = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 907855311);
	_gde_name = StringName("strip_escapes");
	_method_bindings.method_strip_escapes = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("lstrip");
	_method_bindings.method_lstrip = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3134094431);
	_gde_name = StringName("rstrip");
	_method_bindings.method_rstrip = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3134094431);
	_gde_name = StringName("get_extension");
	_method_bindings.method_get_extension = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("get_basename");
	_method_bindings.method_get_basename = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("path_join");
	_method_bindings.method_path_join = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3134094431);
	_gde_name = StringName("unicode_at");
	_method_bindings.method_unicode_at = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 4103005248);
	_gde_name = StringName("indent");
	_method_bindings.method_indent = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3134094431);
	_gde_name = StringName("dedent");
	_method_bindings.method_dedent = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("md5_text");
	_method_bindings.method_md5_text = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("sha1_text");
	_method_bindings.method_sha1_text = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("sha256_text");
	_method_bindings.method_sha256_text = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("md5_buffer");
	_method_bindings.method_md5_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("sha1_buffer");
	_method_bindings.method_sha1_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("sha256_buffer");
	_method_bindings.method_sha256_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("is_empty");
	_method_bindings.method_is_empty = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("contains");
	_method_bindings.method_contains = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("containsn");
	_method_bindings.method_containsn = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2566493496);
	_gde_name = StringName("is_absolute_path");
	_method_bindings.method_is_absolute_path = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_relative_path");
	_method_bindings.method_is_relative_path = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("simplify_path");
	_method_bindings.method_simplify_path = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("get_base_dir");
	_method_bindings.method_get_base_dir = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("get_file");
	_method_bindings.method_get_file = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("xml_escape");
	_method_bindings.method_xml_escape = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3429816538);
	_gde_name = StringName("xml_unescape");
	_method_bindings.method_xml_unescape = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("uri_encode");
	_method_bindings.method_uri_encode = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("uri_decode");
	_method_bindings.method_uri_decode = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("c_escape");
	_method_bindings.method_c_escape = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("c_unescape");
	_method_bindings.method_c_unescape = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("json_escape");
	_method_bindings.method_json_escape = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("validate_node_name");
	_method_bindings.method_validate_node_name = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("validate_filename");
	_method_bindings.method_validate_filename = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3942272618);
	_gde_name = StringName("is_valid_ascii_identifier");
	_method_bindings.method_is_valid_ascii_identifier = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_valid_unicode_identifier");
	_method_bindings.method_is_valid_unicode_identifier = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_valid_identifier");
	_method_bindings.method_is_valid_identifier = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_valid_int");
	_method_bindings.method_is_valid_int = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_valid_float");
	_method_bindings.method_is_valid_float = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_valid_hex_number");
	_method_bindings.method_is_valid_hex_number = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 593672999);
	_gde_name = StringName("is_valid_html_color");
	_method_bindings.method_is_valid_html_color = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_valid_ip_address");
	_method_bindings.method_is_valid_ip_address = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("is_valid_filename");
	_method_bindings.method_is_valid_filename = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3918633141);
	_gde_name = StringName("to_int");
	_method_bindings.method_to_int = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3173160232);
	_gde_name = StringName("to_float");
	_method_bindings.method_to_float = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 466405837);
	_gde_name = StringName("hex_to_int");
	_method_bindings.method_hex_to_int = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3173160232);
	_gde_name = StringName("bin_to_int");
	_method_bindings.method_bin_to_int = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3173160232);
	_gde_name = StringName("lpad");
	_method_bindings.method_lpad = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 248737229);
	_gde_name = StringName("rpad");
	_method_bindings.method_rpad = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 248737229);
	_gde_name = StringName("pad_decimals");
	_method_bindings.method_pad_decimals = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2162347432);
	_gde_name = StringName("pad_zeros");
	_method_bindings.method_pad_zeros = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 2162347432);
	_gde_name = StringName("trim_prefix");
	_method_bindings.method_trim_prefix = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3134094431);
	_gde_name = StringName("trim_suffix");
	_method_bindings.method_trim_suffix = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3134094431);
	_gde_name = StringName("to_ascii_buffer");
	_method_bindings.method_to_ascii_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("to_utf8_buffer");
	_method_bindings.method_to_utf8_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("to_utf16_buffer");
	_method_bindings.method_to_utf16_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("to_utf32_buffer");
	_method_bindings.method_to_utf32_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("hex_decode");
	_method_bindings.method_hex_decode = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("to_wchar_buffer");
	_method_bindings.method_to_wchar_buffer = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 247621236);
	_gde_name = StringName("hash");
	_method_bindings.method_hash = internal::gdextension_interface_variant_get_ptr_builtin_method(GDEXTENSION_VARIANT_TYPE_STRING_NAME, _gde_name._native_ptr(), 3173160232);
	_method_bindings.operator_equal_Variant = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_not_equal_Variant = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_module_Variant = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_not = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_NIL);
	_method_bindings.operator_module_bool = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_BOOL);
	_method_bindings.operator_module_int = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_INT);
	_method_bindings.operator_module_float = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_FLOAT);
	_method_bindings.operator_equal_String = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING);
	_method_bindings.operator_not_equal_String = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING);
	_method_bindings.operator_add_String = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_ADD, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING);
	_method_bindings.operator_module_String = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING);
	_method_bindings.operator_in_String = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING);
	_method_bindings.operator_module_Vector2 = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_VECTOR2);
	_method_bindings.operator_module_Vector2i = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_VECTOR2I);
	_method_bindings.operator_module_Rect2 = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_RECT2);
	_method_bindings.operator_module_Rect2i = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_RECT2I);
	_method_bindings.operator_module_Vector3 = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_VECTOR3);
	_method_bindings.operator_module_Vector3i = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_VECTOR3I);
	_method_bindings.operator_module_Transform2D = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_TRANSFORM2D);
	_method_bindings.operator_module_Vector4 = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_VECTOR4);
	_method_bindings.operator_module_Vector4i = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_VECTOR4I);
	_method_bindings.operator_module_Plane = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PLANE);
	_method_bindings.operator_module_Quaternion = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_QUATERNION);
	_method_bindings.operator_module_AABB = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_AABB);
	_method_bindings.operator_module_Basis = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_BASIS);
	_method_bindings.operator_module_Transform3D = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_TRANSFORM3D);
	_method_bindings.operator_module_Projection = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PROJECTION);
	_method_bindings.operator_module_Color = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_COLOR);
	_method_bindings.operator_equal_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_not_equal_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_NOT_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_less_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_LESS, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_less_equal_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_LESS_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_greater_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_GREATER, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_greater_equal_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_GREATER_EQUAL, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_add_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_ADD, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_module_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_in_StringName = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_STRING_NAME);
	_method_bindings.operator_module_NodePath = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_NODE_PATH);
	_method_bindings.operator_module_Object = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_OBJECT);
	_method_bindings.operator_in_Object = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_OBJECT);
	_method_bindings.operator_module_Callable = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_CALLABLE);
	_method_bindings.operator_module_Signal = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_SIGNAL);
	_method_bindings.operator_module_Dictionary = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_DICTIONARY);
	_method_bindings.operator_in_Dictionary = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_DICTIONARY);
	_method_bindings.operator_module_Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_ARRAY);
	_method_bindings.operator_in_Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_ARRAY);
	_method_bindings.operator_module_PackedByteArray = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_BYTE_ARRAY);
	_method_bindings.operator_module_PackedInt32Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_INT32_ARRAY);
	_method_bindings.operator_module_PackedInt64Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_INT64_ARRAY);
	_method_bindings.operator_module_PackedFloat32Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_FLOAT32_ARRAY);
	_method_bindings.operator_module_PackedFloat64Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_FLOAT64_ARRAY);
	_method_bindings.operator_module_PackedStringArray = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_STRING_ARRAY);
	_method_bindings.operator_in_PackedStringArray = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_IN, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_STRING_ARRAY);
	_method_bindings.operator_module_PackedVector2Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
	_method_bindings.operator_module_PackedVector3Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR3_ARRAY);
	_method_bindings.operator_module_PackedColorArray = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_COLOR_ARRAY);
	_method_bindings.operator_module_PackedVector4Array = internal::gdextension_interface_variant_get_ptr_operator_evaluator(GDEXTENSION_VARIANT_OP_MODULE, GDEXTENSION_VARIANT_TYPE_STRING_NAME, GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR4_ARRAY);
}

StringName::StringName(const Variant *p_variant) {
	_method_bindings.from_variant_constructor(&opaque, p_variant->_native_ptr());
}

StringName::StringName() {
	internal::_call_builtin_constructor(_method_bindings.constructor_0, &opaque);
}

StringName::StringName(const StringName &p_from) {
	internal::_call_builtin_constructor(_method_bindings.constructor_1, &opaque, &p_from);
}

StringName::StringName(const String &p_from) {
	internal::_call_builtin_constructor(_method_bindings.constructor_2, &opaque, &p_from);
}

StringName::StringName(StringName &&p_other) {
	std::swap(opaque, p_other.opaque);
}

StringName::~StringName() {
	_method_bindings.destructor(&opaque);
}

int64_t StringName::casecmp_to(const String &p_to) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_casecmp_to, (GDExtensionTypePtr)&opaque, &p_to);
}

int64_t StringName::nocasecmp_to(const String &p_to) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_nocasecmp_to, (GDExtensionTypePtr)&opaque, &p_to);
}

int64_t StringName::naturalcasecmp_to(const String &p_to) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_naturalcasecmp_to, (GDExtensionTypePtr)&opaque, &p_to);
}

int64_t StringName::naturalnocasecmp_to(const String &p_to) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_naturalnocasecmp_to, (GDExtensionTypePtr)&opaque, &p_to);
}

int64_t StringName::filecasecmp_to(const String &p_to) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_filecasecmp_to, (GDExtensionTypePtr)&opaque, &p_to);
}

int64_t StringName::filenocasecmp_to(const String &p_to) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_filenocasecmp_to, (GDExtensionTypePtr)&opaque, &p_to);
}

int64_t StringName::length() const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_length, (GDExtensionTypePtr)&opaque);
}

String StringName::substr(int64_t p_from, int64_t p_len) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	int64_t p_len_encoded;
	PtrToArg<int64_t>::encode(p_len, &p_len_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_substr, (GDExtensionTypePtr)&opaque, &p_from_encoded, &p_len_encoded);
}

String StringName::get_slice(const String &p_delimiter, int64_t p_slice) const {
	int64_t p_slice_encoded;
	PtrToArg<int64_t>::encode(p_slice, &p_slice_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_get_slice, (GDExtensionTypePtr)&opaque, &p_delimiter, &p_slice_encoded);
}

String StringName::get_slicec(int64_t p_delimiter, int64_t p_slice) const {
	int64_t p_delimiter_encoded;
	PtrToArg<int64_t>::encode(p_delimiter, &p_delimiter_encoded);
	int64_t p_slice_encoded;
	PtrToArg<int64_t>::encode(p_slice, &p_slice_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_get_slicec, (GDExtensionTypePtr)&opaque, &p_delimiter_encoded, &p_slice_encoded);
}

int64_t StringName::get_slice_count(const String &p_delimiter) const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_get_slice_count, (GDExtensionTypePtr)&opaque, &p_delimiter);
}

int64_t StringName::find(const String &p_what, int64_t p_from) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_find, (GDExtensionTypePtr)&opaque, &p_what, &p_from_encoded);
}

int64_t StringName::findn(const String &p_what, int64_t p_from) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_findn, (GDExtensionTypePtr)&opaque, &p_what, &p_from_encoded);
}

int64_t StringName::count(const String &p_what, int64_t p_from, int64_t p_to) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	int64_t p_to_encoded;
	PtrToArg<int64_t>::encode(p_to, &p_to_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_count, (GDExtensionTypePtr)&opaque, &p_what, &p_from_encoded, &p_to_encoded);
}

int64_t StringName::countn(const String &p_what, int64_t p_from, int64_t p_to) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	int64_t p_to_encoded;
	PtrToArg<int64_t>::encode(p_to, &p_to_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_countn, (GDExtensionTypePtr)&opaque, &p_what, &p_from_encoded, &p_to_encoded);
}

int64_t StringName::rfind(const String &p_what, int64_t p_from) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_rfind, (GDExtensionTypePtr)&opaque, &p_what, &p_from_encoded);
}

int64_t StringName::rfindn(const String &p_what, int64_t p_from) const {
	int64_t p_from_encoded;
	PtrToArg<int64_t>::encode(p_from, &p_from_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_rfindn, (GDExtensionTypePtr)&opaque, &p_what, &p_from_encoded);
}

bool StringName::match(const String &p_expr) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_match, (GDExtensionTypePtr)&opaque, &p_expr);
}

bool StringName::matchn(const String &p_expr) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_matchn, (GDExtensionTypePtr)&opaque, &p_expr);
}

bool StringName::begins_with(const String &p_text) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_begins_with, (GDExtensionTypePtr)&opaque, &p_text);
}

bool StringName::ends_with(const String &p_text) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_ends_with, (GDExtensionTypePtr)&opaque, &p_text);
}

bool StringName::is_subsequence_of(const String &p_text) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_subsequence_of, (GDExtensionTypePtr)&opaque, &p_text);
}

bool StringName::is_subsequence_ofn(const String &p_text) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_subsequence_ofn, (GDExtensionTypePtr)&opaque, &p_text);
}

PackedStringArray StringName::bigrams() const {
	return internal::_call_builtin_method_ptr_ret<PackedStringArray>(_method_bindings.method_bigrams, (GDExtensionTypePtr)&opaque);
}

double StringName::similarity(const String &p_text) const {
	return internal::_call_builtin_method_ptr_ret<double>(_method_bindings.method_similarity, (GDExtensionTypePtr)&opaque, &p_text);
}

String StringName::format(const Variant &p_values, const String &p_placeholder) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_format, (GDExtensionTypePtr)&opaque, &p_values, &p_placeholder);
}

String StringName::replace(const String &p_what, const String &p_forwhat) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_replace, (GDExtensionTypePtr)&opaque, &p_what, &p_forwhat);
}

String StringName::replacen(const String &p_what, const String &p_forwhat) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_replacen, (GDExtensionTypePtr)&opaque, &p_what, &p_forwhat);
}

String StringName::repeat(int64_t p_count) const {
	int64_t p_count_encoded;
	PtrToArg<int64_t>::encode(p_count, &p_count_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_repeat, (GDExtensionTypePtr)&opaque, &p_count_encoded);
}

String StringName::reverse() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_reverse, (GDExtensionTypePtr)&opaque);
}

String StringName::insert(int64_t p_position, const String &p_what) const {
	int64_t p_position_encoded;
	PtrToArg<int64_t>::encode(p_position, &p_position_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_insert, (GDExtensionTypePtr)&opaque, &p_position_encoded, &p_what);
}

String StringName::erase(int64_t p_position, int64_t p_chars) const {
	int64_t p_position_encoded;
	PtrToArg<int64_t>::encode(p_position, &p_position_encoded);
	int64_t p_chars_encoded;
	PtrToArg<int64_t>::encode(p_chars, &p_chars_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_erase, (GDExtensionTypePtr)&opaque, &p_position_encoded, &p_chars_encoded);
}

String StringName::capitalize() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_capitalize, (GDExtensionTypePtr)&opaque);
}

String StringName::to_camel_case() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_to_camel_case, (GDExtensionTypePtr)&opaque);
}

String StringName::to_pascal_case() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_to_pascal_case, (GDExtensionTypePtr)&opaque);
}

String StringName::to_snake_case() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_to_snake_case, (GDExtensionTypePtr)&opaque);
}

PackedStringArray StringName::split(const String &p_delimiter, bool p_allow_empty, int64_t p_maxsplit) const {
	int8_t p_allow_empty_encoded;
	PtrToArg<bool>::encode(p_allow_empty, &p_allow_empty_encoded);
	int64_t p_maxsplit_encoded;
	PtrToArg<int64_t>::encode(p_maxsplit, &p_maxsplit_encoded);
	return internal::_call_builtin_method_ptr_ret<PackedStringArray>(_method_bindings.method_split, (GDExtensionTypePtr)&opaque, &p_delimiter, &p_allow_empty_encoded, &p_maxsplit_encoded);
}

PackedStringArray StringName::rsplit(const String &p_delimiter, bool p_allow_empty, int64_t p_maxsplit) const {
	int8_t p_allow_empty_encoded;
	PtrToArg<bool>::encode(p_allow_empty, &p_allow_empty_encoded);
	int64_t p_maxsplit_encoded;
	PtrToArg<int64_t>::encode(p_maxsplit, &p_maxsplit_encoded);
	return internal::_call_builtin_method_ptr_ret<PackedStringArray>(_method_bindings.method_rsplit, (GDExtensionTypePtr)&opaque, &p_delimiter, &p_allow_empty_encoded, &p_maxsplit_encoded);
}

PackedFloat64Array StringName::split_floats(const String &p_delimiter, bool p_allow_empty) const {
	int8_t p_allow_empty_encoded;
	PtrToArg<bool>::encode(p_allow_empty, &p_allow_empty_encoded);
	return internal::_call_builtin_method_ptr_ret<PackedFloat64Array>(_method_bindings.method_split_floats, (GDExtensionTypePtr)&opaque, &p_delimiter, &p_allow_empty_encoded);
}

String StringName::join(const PackedStringArray &p_parts) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_join, (GDExtensionTypePtr)&opaque, &p_parts);
}

String StringName::to_upper() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_to_upper, (GDExtensionTypePtr)&opaque);
}

String StringName::to_lower() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_to_lower, (GDExtensionTypePtr)&opaque);
}

String StringName::left(int64_t p_length) const {
	int64_t p_length_encoded;
	PtrToArg<int64_t>::encode(p_length, &p_length_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_left, (GDExtensionTypePtr)&opaque, &p_length_encoded);
}

String StringName::right(int64_t p_length) const {
	int64_t p_length_encoded;
	PtrToArg<int64_t>::encode(p_length, &p_length_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_right, (GDExtensionTypePtr)&opaque, &p_length_encoded);
}

String StringName::strip_edges(bool p_left, bool p_right) const {
	int8_t p_left_encoded;
	PtrToArg<bool>::encode(p_left, &p_left_encoded);
	int8_t p_right_encoded;
	PtrToArg<bool>::encode(p_right, &p_right_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_strip_edges, (GDExtensionTypePtr)&opaque, &p_left_encoded, &p_right_encoded);
}

String StringName::strip_escapes() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_strip_escapes, (GDExtensionTypePtr)&opaque);
}

String StringName::lstrip(const String &p_chars) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_lstrip, (GDExtensionTypePtr)&opaque, &p_chars);
}

String StringName::rstrip(const String &p_chars) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_rstrip, (GDExtensionTypePtr)&opaque, &p_chars);
}

String StringName::get_extension() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_get_extension, (GDExtensionTypePtr)&opaque);
}

String StringName::get_basename() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_get_basename, (GDExtensionTypePtr)&opaque);
}

String StringName::path_join(const String &p_file) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_path_join, (GDExtensionTypePtr)&opaque, &p_file);
}

int64_t StringName::unicode_at(int64_t p_at) const {
	int64_t p_at_encoded;
	PtrToArg<int64_t>::encode(p_at, &p_at_encoded);
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_unicode_at, (GDExtensionTypePtr)&opaque, &p_at_encoded);
}

String StringName::indent(const String &p_prefix) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_indent, (GDExtensionTypePtr)&opaque, &p_prefix);
}

String StringName::dedent() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_dedent, (GDExtensionTypePtr)&opaque);
}

String StringName::md5_text() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_md5_text, (GDExtensionTypePtr)&opaque);
}

String StringName::sha1_text() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_sha1_text, (GDExtensionTypePtr)&opaque);
}

String StringName::sha256_text() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_sha256_text, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::md5_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_md5_buffer, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::sha1_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_sha1_buffer, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::sha256_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_sha256_buffer, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_empty() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_empty, (GDExtensionTypePtr)&opaque);
}

bool StringName::contains(const String &p_what) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_contains, (GDExtensionTypePtr)&opaque, &p_what);
}

bool StringName::containsn(const String &p_what) const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_containsn, (GDExtensionTypePtr)&opaque, &p_what);
}

bool StringName::is_absolute_path() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_absolute_path, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_relative_path() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_relative_path, (GDExtensionTypePtr)&opaque);
}

String StringName::simplify_path() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_simplify_path, (GDExtensionTypePtr)&opaque);
}

String StringName::get_base_dir() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_get_base_dir, (GDExtensionTypePtr)&opaque);
}

String StringName::get_file() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_get_file, (GDExtensionTypePtr)&opaque);
}

String StringName::xml_escape(bool p_escape_quotes) const {
	int8_t p_escape_quotes_encoded;
	PtrToArg<bool>::encode(p_escape_quotes, &p_escape_quotes_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_xml_escape, (GDExtensionTypePtr)&opaque, &p_escape_quotes_encoded);
}

String StringName::xml_unescape() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_xml_unescape, (GDExtensionTypePtr)&opaque);
}

String StringName::uri_encode() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_uri_encode, (GDExtensionTypePtr)&opaque);
}

String StringName::uri_decode() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_uri_decode, (GDExtensionTypePtr)&opaque);
}

String StringName::c_escape() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_c_escape, (GDExtensionTypePtr)&opaque);
}

String StringName::c_unescape() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_c_unescape, (GDExtensionTypePtr)&opaque);
}

String StringName::json_escape() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_json_escape, (GDExtensionTypePtr)&opaque);
}

String StringName::validate_node_name() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_validate_node_name, (GDExtensionTypePtr)&opaque);
}

String StringName::validate_filename() const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_validate_filename, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_ascii_identifier() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_ascii_identifier, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_unicode_identifier() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_unicode_identifier, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_identifier() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_identifier, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_int() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_int, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_float() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_float, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_hex_number(bool p_with_prefix) const {
	int8_t p_with_prefix_encoded;
	PtrToArg<bool>::encode(p_with_prefix, &p_with_prefix_encoded);
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_hex_number, (GDExtensionTypePtr)&opaque, &p_with_prefix_encoded);
}

bool StringName::is_valid_html_color() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_html_color, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_ip_address() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_ip_address, (GDExtensionTypePtr)&opaque);
}

bool StringName::is_valid_filename() const {
	return internal::_call_builtin_method_ptr_ret<int8_t>(_method_bindings.method_is_valid_filename, (GDExtensionTypePtr)&opaque);
}

int64_t StringName::to_int() const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_to_int, (GDExtensionTypePtr)&opaque);
}

double StringName::to_float() const {
	return internal::_call_builtin_method_ptr_ret<double>(_method_bindings.method_to_float, (GDExtensionTypePtr)&opaque);
}

int64_t StringName::hex_to_int() const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_hex_to_int, (GDExtensionTypePtr)&opaque);
}

int64_t StringName::bin_to_int() const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_bin_to_int, (GDExtensionTypePtr)&opaque);
}

String StringName::lpad(int64_t p_min_length, const String &p_character) const {
	int64_t p_min_length_encoded;
	PtrToArg<int64_t>::encode(p_min_length, &p_min_length_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_lpad, (GDExtensionTypePtr)&opaque, &p_min_length_encoded, &p_character);
}

String StringName::rpad(int64_t p_min_length, const String &p_character) const {
	int64_t p_min_length_encoded;
	PtrToArg<int64_t>::encode(p_min_length, &p_min_length_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_rpad, (GDExtensionTypePtr)&opaque, &p_min_length_encoded, &p_character);
}

String StringName::pad_decimals(int64_t p_digits) const {
	int64_t p_digits_encoded;
	PtrToArg<int64_t>::encode(p_digits, &p_digits_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_pad_decimals, (GDExtensionTypePtr)&opaque, &p_digits_encoded);
}

String StringName::pad_zeros(int64_t p_digits) const {
	int64_t p_digits_encoded;
	PtrToArg<int64_t>::encode(p_digits, &p_digits_encoded);
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_pad_zeros, (GDExtensionTypePtr)&opaque, &p_digits_encoded);
}

String StringName::trim_prefix(const String &p_prefix) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_trim_prefix, (GDExtensionTypePtr)&opaque, &p_prefix);
}

String StringName::trim_suffix(const String &p_suffix) const {
	return internal::_call_builtin_method_ptr_ret<String>(_method_bindings.method_trim_suffix, (GDExtensionTypePtr)&opaque, &p_suffix);
}

PackedByteArray StringName::to_ascii_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_to_ascii_buffer, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::to_utf8_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_to_utf8_buffer, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::to_utf16_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_to_utf16_buffer, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::to_utf32_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_to_utf32_buffer, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::hex_decode() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_hex_decode, (GDExtensionTypePtr)&opaque);
}

PackedByteArray StringName::to_wchar_buffer() const {
	return internal::_call_builtin_method_ptr_ret<PackedByteArray>(_method_bindings.method_to_wchar_buffer, (GDExtensionTypePtr)&opaque);
}

int64_t StringName::hash() const {
	return internal::_call_builtin_method_ptr_ret<int64_t>(_method_bindings.method_hash, (GDExtensionTypePtr)&opaque);
}

bool StringName::operator==(const Variant &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_Variant, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator!=(const Variant &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not_equal_Variant, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Variant &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Variant, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator!() const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr) nullptr);
}

String StringName::operator%(bool p_other) const {
	int8_t p_other_encoded;
	PtrToArg<bool>::encode(p_other, &p_other_encoded);
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_bool, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other_encoded);
}

String StringName::operator%(int64_t p_other) const {
	int64_t p_other_encoded;
	PtrToArg<int64_t>::encode(p_other, &p_other_encoded);
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_int, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other_encoded);
}

String StringName::operator%(double p_other) const {
	double p_other_encoded;
	PtrToArg<double>::encode(p_other, &p_other_encoded);
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_float, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other_encoded);
}

bool StringName::operator==(const String &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_String, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator!=(const String &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not_equal_String, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator+(const String &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_add_String, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const String &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_String, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Vector2 &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Vector2, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Vector2i &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Vector2i, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Rect2 &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Rect2, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Rect2i &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Rect2i, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Vector3 &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Vector3, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Vector3i &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Vector3i, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Transform2D &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Transform2D, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Vector4 &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Vector4, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Vector4i &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Vector4i, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Plane &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Plane, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Quaternion &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Quaternion, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const AABB &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_AABB, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Basis &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Basis, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Transform3D &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Transform3D, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Projection &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Projection, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Color &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Color, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator==(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_equal_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator!=(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_not_equal_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator<(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_less_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator<=(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_less_equal_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator>(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_greater_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

bool StringName::operator>=(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<int8_t>(_method_bindings.operator_greater_equal_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator+(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_add_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const StringName &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_StringName, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const NodePath &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_NodePath, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(Object *p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Object, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)(p_other != nullptr ? &p_other->_owner : nullptr));
}

String StringName::operator%(const Callable &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Callable, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Signal &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Signal, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Dictionary &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Dictionary, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedByteArray &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedByteArray, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedInt32Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedInt32Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedInt64Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedInt64Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedFloat32Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedFloat32Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedFloat64Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedFloat64Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedStringArray &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedStringArray, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedVector2Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedVector2Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedVector3Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedVector3Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedColorArray &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedColorArray, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

String StringName::operator%(const PackedVector4Array &p_other) const {
	return internal::_call_builtin_operator_ptr<String>(_method_bindings.operator_module_PackedVector4Array, (GDExtensionConstTypePtr)&opaque, (GDExtensionConstTypePtr)&p_other);
}

StringName &StringName::operator=(const StringName &p_other) {
	_method_bindings.destructor(&opaque);
	internal::_call_builtin_constructor(_method_bindings.constructor_1, &opaque, &p_other);
	return *this;
}

StringName &StringName::operator=(StringName &&p_other) {
	std::swap(opaque, p_other.opaque);
	return *this;
}

} //namespace godot
