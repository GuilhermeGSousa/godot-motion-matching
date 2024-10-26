/**************************************************************************/
/*  text_server_extension.hpp                                             */
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

#ifndef GODOT_CPP_TEXT_SERVER_EXTENSION_HPP
#define GODOT_CPP_TEXT_SERVER_EXTENSION_HPP

#include <godot_cpp/classes/caret_info.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/glyph.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/text_server.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_int32_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/packed_vector2_array.hpp>
#include <godot_cpp/variant/rect2.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/transform2d.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/variant/vector3i.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

struct Color;
class Image;
class PackedByteArray;
class PackedFloat32Array;

class TextServerExtension : public TextServer {
	GDEXTENSION_CLASS(TextServerExtension, TextServer)

public:
	virtual bool _has_feature(TextServer::Feature p_feature) const;
	virtual String _get_name() const;
	virtual int64_t _get_features() const;
	virtual void _free_rid(const RID &p_rid);
	virtual bool _has(const RID &p_rid);
	virtual bool _load_support_data(const String &p_filename);
	virtual String _get_support_data_filename() const;
	virtual String _get_support_data_info() const;
	virtual bool _save_support_data(const String &p_filename) const;
	virtual bool _is_locale_right_to_left(const String &p_locale) const;
	virtual int64_t _name_to_tag(const String &p_name) const;
	virtual String _tag_to_name(int64_t p_tag) const;
	virtual RID _create_font();
	virtual RID _create_font_linked_variation(const RID &p_font_rid);
	virtual void _font_set_data(const RID &p_font_rid, const PackedByteArray &p_data);
	virtual void _font_set_data_ptr(const RID &p_font_rid, const uint8_t *p_data_ptr, int64_t p_data_size);
	virtual void _font_set_face_index(const RID &p_font_rid, int64_t p_face_index);
	virtual int64_t _font_get_face_index(const RID &p_font_rid) const;
	virtual int64_t _font_get_face_count(const RID &p_font_rid) const;
	virtual void _font_set_style(const RID &p_font_rid, BitField<TextServer::FontStyle> p_style);
	virtual BitField<TextServer::FontStyle> _font_get_style(const RID &p_font_rid) const;
	virtual void _font_set_name(const RID &p_font_rid, const String &p_name);
	virtual String _font_get_name(const RID &p_font_rid) const;
	virtual Dictionary _font_get_ot_name_strings(const RID &p_font_rid) const;
	virtual void _font_set_style_name(const RID &p_font_rid, const String &p_name_style);
	virtual String _font_get_style_name(const RID &p_font_rid) const;
	virtual void _font_set_weight(const RID &p_font_rid, int64_t p_weight);
	virtual int64_t _font_get_weight(const RID &p_font_rid) const;
	virtual void _font_set_stretch(const RID &p_font_rid, int64_t p_stretch);
	virtual int64_t _font_get_stretch(const RID &p_font_rid) const;
	virtual void _font_set_antialiasing(const RID &p_font_rid, TextServer::FontAntialiasing p_antialiasing);
	virtual TextServer::FontAntialiasing _font_get_antialiasing(const RID &p_font_rid) const;
	virtual void _font_set_disable_embedded_bitmaps(const RID &p_font_rid, bool p_disable_embedded_bitmaps);
	virtual bool _font_get_disable_embedded_bitmaps(const RID &p_font_rid) const;
	virtual void _font_set_generate_mipmaps(const RID &p_font_rid, bool p_generate_mipmaps);
	virtual bool _font_get_generate_mipmaps(const RID &p_font_rid) const;
	virtual void _font_set_multichannel_signed_distance_field(const RID &p_font_rid, bool p_msdf);
	virtual bool _font_is_multichannel_signed_distance_field(const RID &p_font_rid) const;
	virtual void _font_set_msdf_pixel_range(const RID &p_font_rid, int64_t p_msdf_pixel_range);
	virtual int64_t _font_get_msdf_pixel_range(const RID &p_font_rid) const;
	virtual void _font_set_msdf_size(const RID &p_font_rid, int64_t p_msdf_size);
	virtual int64_t _font_get_msdf_size(const RID &p_font_rid) const;
	virtual void _font_set_fixed_size(const RID &p_font_rid, int64_t p_fixed_size);
	virtual int64_t _font_get_fixed_size(const RID &p_font_rid) const;
	virtual void _font_set_fixed_size_scale_mode(const RID &p_font_rid, TextServer::FixedSizeScaleMode p_fixed_size_scale_mode);
	virtual TextServer::FixedSizeScaleMode _font_get_fixed_size_scale_mode(const RID &p_font_rid) const;
	virtual void _font_set_allow_system_fallback(const RID &p_font_rid, bool p_allow_system_fallback);
	virtual bool _font_is_allow_system_fallback(const RID &p_font_rid) const;
	virtual void _font_set_force_autohinter(const RID &p_font_rid, bool p_force_autohinter);
	virtual bool _font_is_force_autohinter(const RID &p_font_rid) const;
	virtual void _font_set_hinting(const RID &p_font_rid, TextServer::Hinting p_hinting);
	virtual TextServer::Hinting _font_get_hinting(const RID &p_font_rid) const;
	virtual void _font_set_subpixel_positioning(const RID &p_font_rid, TextServer::SubpixelPositioning p_subpixel_positioning);
	virtual TextServer::SubpixelPositioning _font_get_subpixel_positioning(const RID &p_font_rid) const;
	virtual void _font_set_embolden(const RID &p_font_rid, double p_strength);
	virtual double _font_get_embolden(const RID &p_font_rid) const;
	virtual void _font_set_spacing(const RID &p_font_rid, TextServer::SpacingType p_spacing, int64_t p_value);
	virtual int64_t _font_get_spacing(const RID &p_font_rid, TextServer::SpacingType p_spacing) const;
	virtual void _font_set_baseline_offset(const RID &p_font_rid, double p_baseline_offset);
	virtual double _font_get_baseline_offset(const RID &p_font_rid) const;
	virtual void _font_set_transform(const RID &p_font_rid, const Transform2D &p_transform);
	virtual Transform2D _font_get_transform(const RID &p_font_rid) const;
	virtual void _font_set_variation_coordinates(const RID &p_font_rid, const Dictionary &p_variation_coordinates);
	virtual Dictionary _font_get_variation_coordinates(const RID &p_font_rid) const;
	virtual void _font_set_oversampling(const RID &p_font_rid, double p_oversampling);
	virtual double _font_get_oversampling(const RID &p_font_rid) const;
	virtual TypedArray<Vector2i> _font_get_size_cache_list(const RID &p_font_rid) const;
	virtual void _font_clear_size_cache(const RID &p_font_rid);
	virtual void _font_remove_size_cache(const RID &p_font_rid, const Vector2i &p_size);
	virtual void _font_set_ascent(const RID &p_font_rid, int64_t p_size, double p_ascent);
	virtual double _font_get_ascent(const RID &p_font_rid, int64_t p_size) const;
	virtual void _font_set_descent(const RID &p_font_rid, int64_t p_size, double p_descent);
	virtual double _font_get_descent(const RID &p_font_rid, int64_t p_size) const;
	virtual void _font_set_underline_position(const RID &p_font_rid, int64_t p_size, double p_underline_position);
	virtual double _font_get_underline_position(const RID &p_font_rid, int64_t p_size) const;
	virtual void _font_set_underline_thickness(const RID &p_font_rid, int64_t p_size, double p_underline_thickness);
	virtual double _font_get_underline_thickness(const RID &p_font_rid, int64_t p_size) const;
	virtual void _font_set_scale(const RID &p_font_rid, int64_t p_size, double p_scale);
	virtual double _font_get_scale(const RID &p_font_rid, int64_t p_size) const;
	virtual int64_t _font_get_texture_count(const RID &p_font_rid, const Vector2i &p_size) const;
	virtual void _font_clear_textures(const RID &p_font_rid, const Vector2i &p_size);
	virtual void _font_remove_texture(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index);
	virtual void _font_set_texture_image(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index, const Ref<Image> &p_image);
	virtual Ref<Image> _font_get_texture_image(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index) const;
	virtual void _font_set_texture_offsets(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index, const PackedInt32Array &p_offset);
	virtual PackedInt32Array _font_get_texture_offsets(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index) const;
	virtual PackedInt32Array _font_get_glyph_list(const RID &p_font_rid, const Vector2i &p_size) const;
	virtual void _font_clear_glyphs(const RID &p_font_rid, const Vector2i &p_size);
	virtual void _font_remove_glyph(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph);
	virtual Vector2 _font_get_glyph_advance(const RID &p_font_rid, int64_t p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_advance(const RID &p_font_rid, int64_t p_size, int64_t p_glyph, const Vector2 &p_advance);
	virtual Vector2 _font_get_glyph_offset(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_offset(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Vector2 &p_offset);
	virtual Vector2 _font_get_glyph_size(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_size(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Vector2 &p_gl_size);
	virtual Rect2 _font_get_glyph_uv_rect(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_uv_rect(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Rect2 &p_uv_rect);
	virtual int64_t _font_get_glyph_texture_idx(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_texture_idx(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, int64_t p_texture_idx);
	virtual RID _font_get_glyph_texture_rid(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual Vector2 _font_get_glyph_texture_size(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual Dictionary _font_get_glyph_contours(const RID &p_font_rid, int64_t p_size, int64_t p_index) const;
	virtual TypedArray<Vector2i> _font_get_kerning_list(const RID &p_font_rid, int64_t p_size) const;
	virtual void _font_clear_kerning_map(const RID &p_font_rid, int64_t p_size);
	virtual void _font_remove_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair);
	virtual void _font_set_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair, const Vector2 &p_kerning);
	virtual Vector2 _font_get_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair) const;
	virtual int64_t _font_get_glyph_index(const RID &p_font_rid, int64_t p_size, int64_t p_char, int64_t p_variation_selector) const;
	virtual int64_t _font_get_char_from_glyph_index(const RID &p_font_rid, int64_t p_size, int64_t p_glyph_index) const;
	virtual bool _font_has_char(const RID &p_font_rid, int64_t p_char) const;
	virtual String _font_get_supported_chars(const RID &p_font_rid) const;
	virtual PackedInt32Array _font_get_supported_glyphs(const RID &p_font_rid) const;
	virtual void _font_render_range(const RID &p_font_rid, const Vector2i &p_size, int64_t p_start, int64_t p_end);
	virtual void _font_render_glyph(const RID &p_font_rid, const Vector2i &p_size, int64_t p_index);
	virtual void _font_draw_glyph(const RID &p_font_rid, const RID &p_canvas, int64_t p_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const;
	virtual void _font_draw_glyph_outline(const RID &p_font_rid, const RID &p_canvas, int64_t p_size, int64_t p_outline_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const;
	virtual bool _font_is_language_supported(const RID &p_font_rid, const String &p_language) const;
	virtual void _font_set_language_support_override(const RID &p_font_rid, const String &p_language, bool p_supported);
	virtual bool _font_get_language_support_override(const RID &p_font_rid, const String &p_language);
	virtual void _font_remove_language_support_override(const RID &p_font_rid, const String &p_language);
	virtual PackedStringArray _font_get_language_support_overrides(const RID &p_font_rid);
	virtual bool _font_is_script_supported(const RID &p_font_rid, const String &p_script) const;
	virtual void _font_set_script_support_override(const RID &p_font_rid, const String &p_script, bool p_supported);
	virtual bool _font_get_script_support_override(const RID &p_font_rid, const String &p_script);
	virtual void _font_remove_script_support_override(const RID &p_font_rid, const String &p_script);
	virtual PackedStringArray _font_get_script_support_overrides(const RID &p_font_rid);
	virtual void _font_set_opentype_feature_overrides(const RID &p_font_rid, const Dictionary &p_overrides);
	virtual Dictionary _font_get_opentype_feature_overrides(const RID &p_font_rid) const;
	virtual Dictionary _font_supported_feature_list(const RID &p_font_rid) const;
	virtual Dictionary _font_supported_variation_list(const RID &p_font_rid) const;
	virtual double _font_get_global_oversampling() const;
	virtual void _font_set_global_oversampling(double p_oversampling);
	virtual Vector2 _get_hex_code_box_size(int64_t p_size, int64_t p_index) const;
	virtual void _draw_hex_code_box(const RID &p_canvas, int64_t p_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const;
	virtual RID _create_shaped_text(TextServer::Direction p_direction, TextServer::Orientation p_orientation);
	virtual void _shaped_text_clear(const RID &p_shaped);
	virtual void _shaped_text_set_direction(const RID &p_shaped, TextServer::Direction p_direction);
	virtual TextServer::Direction _shaped_text_get_direction(const RID &p_shaped) const;
	virtual TextServer::Direction _shaped_text_get_inferred_direction(const RID &p_shaped) const;
	virtual void _shaped_text_set_bidi_override(const RID &p_shaped, const Array &p_override);
	virtual void _shaped_text_set_custom_punctuation(const RID &p_shaped, const String &p_punct);
	virtual String _shaped_text_get_custom_punctuation(const RID &p_shaped) const;
	virtual void _shaped_text_set_custom_ellipsis(const RID &p_shaped, int64_t p_char);
	virtual int64_t _shaped_text_get_custom_ellipsis(const RID &p_shaped) const;
	virtual void _shaped_text_set_orientation(const RID &p_shaped, TextServer::Orientation p_orientation);
	virtual TextServer::Orientation _shaped_text_get_orientation(const RID &p_shaped) const;
	virtual void _shaped_text_set_preserve_invalid(const RID &p_shaped, bool p_enabled);
	virtual bool _shaped_text_get_preserve_invalid(const RID &p_shaped) const;
	virtual void _shaped_text_set_preserve_control(const RID &p_shaped, bool p_enabled);
	virtual bool _shaped_text_get_preserve_control(const RID &p_shaped) const;
	virtual void _shaped_text_set_spacing(const RID &p_shaped, TextServer::SpacingType p_spacing, int64_t p_value);
	virtual int64_t _shaped_text_get_spacing(const RID &p_shaped, TextServer::SpacingType p_spacing) const;
	virtual bool _shaped_text_add_string(const RID &p_shaped, const String &p_text, const TypedArray<RID> &p_fonts, int64_t p_size, const Dictionary &p_opentype_features, const String &p_language, const Variant &p_meta);
	virtual bool _shaped_text_add_object(const RID &p_shaped, const Variant &p_key, const Vector2 &p_size, InlineAlignment p_inline_align, int64_t p_length, double p_baseline);
	virtual bool _shaped_text_resize_object(const RID &p_shaped, const Variant &p_key, const Vector2 &p_size, InlineAlignment p_inline_align, double p_baseline);
	virtual int64_t _shaped_get_span_count(const RID &p_shaped) const;
	virtual Variant _shaped_get_span_meta(const RID &p_shaped, int64_t p_index) const;
	virtual void _shaped_set_span_update_font(const RID &p_shaped, int64_t p_index, const TypedArray<RID> &p_fonts, int64_t p_size, const Dictionary &p_opentype_features);
	virtual RID _shaped_text_substr(const RID &p_shaped, int64_t p_start, int64_t p_length) const;
	virtual RID _shaped_text_get_parent(const RID &p_shaped) const;
	virtual double _shaped_text_fit_to_width(const RID &p_shaped, double p_width, BitField<TextServer::JustificationFlag> p_justification_flags);
	virtual double _shaped_text_tab_align(const RID &p_shaped, const PackedFloat32Array &p_tab_stops);
	virtual bool _shaped_text_shape(const RID &p_shaped);
	virtual bool _shaped_text_update_breaks(const RID &p_shaped);
	virtual bool _shaped_text_update_justification_ops(const RID &p_shaped);
	virtual bool _shaped_text_is_ready(const RID &p_shaped) const;
	virtual const Glyph *_shaped_text_get_glyphs(const RID &p_shaped) const;
	virtual const Glyph *_shaped_text_sort_logical(const RID &p_shaped);
	virtual int64_t _shaped_text_get_glyph_count(const RID &p_shaped) const;
	virtual Vector2i _shaped_text_get_range(const RID &p_shaped) const;
	virtual PackedInt32Array _shaped_text_get_line_breaks_adv(const RID &p_shaped, const PackedFloat32Array &p_width, int64_t p_start, bool p_once, BitField<TextServer::LineBreakFlag> p_break_flags) const;
	virtual PackedInt32Array _shaped_text_get_line_breaks(const RID &p_shaped, double p_width, int64_t p_start, BitField<TextServer::LineBreakFlag> p_break_flags) const;
	virtual PackedInt32Array _shaped_text_get_word_breaks(const RID &p_shaped, BitField<TextServer::GraphemeFlag> p_grapheme_flags, BitField<TextServer::GraphemeFlag> p_skip_grapheme_flags) const;
	virtual int64_t _shaped_text_get_trim_pos(const RID &p_shaped) const;
	virtual int64_t _shaped_text_get_ellipsis_pos(const RID &p_shaped) const;
	virtual int64_t _shaped_text_get_ellipsis_glyph_count(const RID &p_shaped) const;
	virtual const Glyph *_shaped_text_get_ellipsis_glyphs(const RID &p_shaped) const;
	virtual void _shaped_text_overrun_trim_to_width(const RID &p_shaped, double p_width, BitField<TextServer::TextOverrunFlag> p_trim_flags);
	virtual Array _shaped_text_get_objects(const RID &p_shaped) const;
	virtual Rect2 _shaped_text_get_object_rect(const RID &p_shaped, const Variant &p_key) const;
	virtual Vector2i _shaped_text_get_object_range(const RID &p_shaped, const Variant &p_key) const;
	virtual int64_t _shaped_text_get_object_glyph(const RID &p_shaped, const Variant &p_key) const;
	virtual Vector2 _shaped_text_get_size(const RID &p_shaped) const;
	virtual double _shaped_text_get_ascent(const RID &p_shaped) const;
	virtual double _shaped_text_get_descent(const RID &p_shaped) const;
	virtual double _shaped_text_get_width(const RID &p_shaped) const;
	virtual double _shaped_text_get_underline_position(const RID &p_shaped) const;
	virtual double _shaped_text_get_underline_thickness(const RID &p_shaped) const;
	virtual int64_t _shaped_text_get_dominant_direction_in_range(const RID &p_shaped, int64_t p_start, int64_t p_end) const;
	virtual void _shaped_text_get_carets(const RID &p_shaped, int64_t p_position, CaretInfo *p_caret) const;
	virtual PackedVector2Array _shaped_text_get_selection(const RID &p_shaped, int64_t p_start, int64_t p_end) const;
	virtual int64_t _shaped_text_hit_test_grapheme(const RID &p_shaped, double p_coord) const;
	virtual int64_t _shaped_text_hit_test_position(const RID &p_shaped, double p_coord) const;
	virtual void _shaped_text_draw(const RID &p_shaped, const RID &p_canvas, const Vector2 &p_pos, double p_clip_l, double p_clip_r, const Color &p_color) const;
	virtual void _shaped_text_draw_outline(const RID &p_shaped, const RID &p_canvas, const Vector2 &p_pos, double p_clip_l, double p_clip_r, int64_t p_outline_size, const Color &p_color) const;
	virtual Vector2 _shaped_text_get_grapheme_bounds(const RID &p_shaped, int64_t p_pos) const;
	virtual int64_t _shaped_text_next_grapheme_pos(const RID &p_shaped, int64_t p_pos) const;
	virtual int64_t _shaped_text_prev_grapheme_pos(const RID &p_shaped, int64_t p_pos) const;
	virtual PackedInt32Array _shaped_text_get_character_breaks(const RID &p_shaped) const;
	virtual int64_t _shaped_text_next_character_pos(const RID &p_shaped, int64_t p_pos) const;
	virtual int64_t _shaped_text_prev_character_pos(const RID &p_shaped, int64_t p_pos) const;
	virtual int64_t _shaped_text_closest_character_pos(const RID &p_shaped, int64_t p_pos) const;
	virtual String _format_number(const String &p_number, const String &p_language) const;
	virtual String _parse_number(const String &p_number, const String &p_language) const;
	virtual String _percent_sign(const String &p_language) const;
	virtual String _strip_diacritics(const String &p_string) const;
	virtual bool _is_valid_identifier(const String &p_string) const;
	virtual bool _is_valid_letter(uint64_t p_unicode) const;
	virtual PackedInt32Array _string_get_word_breaks(const String &p_string, const String &p_language, int64_t p_chars_per_line) const;
	virtual PackedInt32Array _string_get_character_breaks(const String &p_string, const String &p_language) const;
	virtual int64_t _is_confusable(const String &p_string, const PackedStringArray &p_dict) const;
	virtual bool _spoof_check(const String &p_string) const;
	virtual String _string_to_upper(const String &p_string, const String &p_language) const;
	virtual String _string_to_lower(const String &p_string, const String &p_language) const;
	virtual String _string_to_title(const String &p_string, const String &p_language) const;
	virtual TypedArray<Vector3i> _parse_structured_text(TextServer::StructuredTextParser p_parser_type, const Array &p_args, const String &p_text) const;
	virtual void _cleanup();

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		TextServer::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_has_feature), decltype(&T::_has_feature)>) {
			BIND_VIRTUAL_METHOD(T, _has_feature);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_name), decltype(&T::_get_name)>) {
			BIND_VIRTUAL_METHOD(T, _get_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_features), decltype(&T::_get_features)>) {
			BIND_VIRTUAL_METHOD(T, _get_features);
		}
		if constexpr (!std::is_same_v<decltype(&B::_free_rid), decltype(&T::_free_rid)>) {
			BIND_VIRTUAL_METHOD(T, _free_rid);
		}
		if constexpr (!std::is_same_v<decltype(&B::_has), decltype(&T::_has)>) {
			BIND_VIRTUAL_METHOD(T, _has);
		}
		if constexpr (!std::is_same_v<decltype(&B::_load_support_data), decltype(&T::_load_support_data)>) {
			BIND_VIRTUAL_METHOD(T, _load_support_data);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_support_data_filename), decltype(&T::_get_support_data_filename)>) {
			BIND_VIRTUAL_METHOD(T, _get_support_data_filename);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_support_data_info), decltype(&T::_get_support_data_info)>) {
			BIND_VIRTUAL_METHOD(T, _get_support_data_info);
		}
		if constexpr (!std::is_same_v<decltype(&B::_save_support_data), decltype(&T::_save_support_data)>) {
			BIND_VIRTUAL_METHOD(T, _save_support_data);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_locale_right_to_left), decltype(&T::_is_locale_right_to_left)>) {
			BIND_VIRTUAL_METHOD(T, _is_locale_right_to_left);
		}
		if constexpr (!std::is_same_v<decltype(&B::_name_to_tag), decltype(&T::_name_to_tag)>) {
			BIND_VIRTUAL_METHOD(T, _name_to_tag);
		}
		if constexpr (!std::is_same_v<decltype(&B::_tag_to_name), decltype(&T::_tag_to_name)>) {
			BIND_VIRTUAL_METHOD(T, _tag_to_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_create_font), decltype(&T::_create_font)>) {
			BIND_VIRTUAL_METHOD(T, _create_font);
		}
		if constexpr (!std::is_same_v<decltype(&B::_create_font_linked_variation), decltype(&T::_create_font_linked_variation)>) {
			BIND_VIRTUAL_METHOD(T, _create_font_linked_variation);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_data), decltype(&T::_font_set_data)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_data);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_data_ptr), decltype(&T::_font_set_data_ptr)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_data_ptr);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_face_index), decltype(&T::_font_set_face_index)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_face_index);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_face_index), decltype(&T::_font_get_face_index)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_face_index);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_face_count), decltype(&T::_font_get_face_count)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_face_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_style), decltype(&T::_font_set_style)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_style);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_style), decltype(&T::_font_get_style)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_style);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_name), decltype(&T::_font_set_name)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_name), decltype(&T::_font_get_name)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_ot_name_strings), decltype(&T::_font_get_ot_name_strings)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_ot_name_strings);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_style_name), decltype(&T::_font_set_style_name)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_style_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_style_name), decltype(&T::_font_get_style_name)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_style_name);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_weight), decltype(&T::_font_set_weight)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_weight);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_weight), decltype(&T::_font_get_weight)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_weight);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_stretch), decltype(&T::_font_set_stretch)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_stretch);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_stretch), decltype(&T::_font_get_stretch)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_stretch);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_antialiasing), decltype(&T::_font_set_antialiasing)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_antialiasing);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_antialiasing), decltype(&T::_font_get_antialiasing)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_antialiasing);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_disable_embedded_bitmaps), decltype(&T::_font_set_disable_embedded_bitmaps)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_disable_embedded_bitmaps);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_disable_embedded_bitmaps), decltype(&T::_font_get_disable_embedded_bitmaps)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_disable_embedded_bitmaps);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_generate_mipmaps), decltype(&T::_font_set_generate_mipmaps)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_generate_mipmaps);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_generate_mipmaps), decltype(&T::_font_get_generate_mipmaps)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_generate_mipmaps);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_multichannel_signed_distance_field), decltype(&T::_font_set_multichannel_signed_distance_field)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_multichannel_signed_distance_field);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_is_multichannel_signed_distance_field), decltype(&T::_font_is_multichannel_signed_distance_field)>) {
			BIND_VIRTUAL_METHOD(T, _font_is_multichannel_signed_distance_field);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_msdf_pixel_range), decltype(&T::_font_set_msdf_pixel_range)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_msdf_pixel_range);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_msdf_pixel_range), decltype(&T::_font_get_msdf_pixel_range)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_msdf_pixel_range);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_msdf_size), decltype(&T::_font_set_msdf_size)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_msdf_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_msdf_size), decltype(&T::_font_get_msdf_size)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_msdf_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_fixed_size), decltype(&T::_font_set_fixed_size)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_fixed_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_fixed_size), decltype(&T::_font_get_fixed_size)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_fixed_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_fixed_size_scale_mode), decltype(&T::_font_set_fixed_size_scale_mode)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_fixed_size_scale_mode);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_fixed_size_scale_mode), decltype(&T::_font_get_fixed_size_scale_mode)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_fixed_size_scale_mode);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_allow_system_fallback), decltype(&T::_font_set_allow_system_fallback)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_allow_system_fallback);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_is_allow_system_fallback), decltype(&T::_font_is_allow_system_fallback)>) {
			BIND_VIRTUAL_METHOD(T, _font_is_allow_system_fallback);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_force_autohinter), decltype(&T::_font_set_force_autohinter)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_force_autohinter);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_is_force_autohinter), decltype(&T::_font_is_force_autohinter)>) {
			BIND_VIRTUAL_METHOD(T, _font_is_force_autohinter);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_hinting), decltype(&T::_font_set_hinting)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_hinting);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_hinting), decltype(&T::_font_get_hinting)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_hinting);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_subpixel_positioning), decltype(&T::_font_set_subpixel_positioning)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_subpixel_positioning);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_subpixel_positioning), decltype(&T::_font_get_subpixel_positioning)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_subpixel_positioning);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_embolden), decltype(&T::_font_set_embolden)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_embolden);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_embolden), decltype(&T::_font_get_embolden)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_embolden);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_spacing), decltype(&T::_font_set_spacing)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_spacing);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_spacing), decltype(&T::_font_get_spacing)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_spacing);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_baseline_offset), decltype(&T::_font_set_baseline_offset)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_baseline_offset);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_baseline_offset), decltype(&T::_font_get_baseline_offset)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_baseline_offset);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_transform), decltype(&T::_font_set_transform)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_transform);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_transform), decltype(&T::_font_get_transform)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_transform);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_variation_coordinates), decltype(&T::_font_set_variation_coordinates)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_variation_coordinates);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_variation_coordinates), decltype(&T::_font_get_variation_coordinates)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_variation_coordinates);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_oversampling), decltype(&T::_font_set_oversampling)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_oversampling);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_oversampling), decltype(&T::_font_get_oversampling)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_oversampling);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_size_cache_list), decltype(&T::_font_get_size_cache_list)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_size_cache_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_clear_size_cache), decltype(&T::_font_clear_size_cache)>) {
			BIND_VIRTUAL_METHOD(T, _font_clear_size_cache);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_remove_size_cache), decltype(&T::_font_remove_size_cache)>) {
			BIND_VIRTUAL_METHOD(T, _font_remove_size_cache);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_ascent), decltype(&T::_font_set_ascent)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_ascent);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_ascent), decltype(&T::_font_get_ascent)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_ascent);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_descent), decltype(&T::_font_set_descent)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_descent);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_descent), decltype(&T::_font_get_descent)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_descent);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_underline_position), decltype(&T::_font_set_underline_position)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_underline_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_underline_position), decltype(&T::_font_get_underline_position)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_underline_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_underline_thickness), decltype(&T::_font_set_underline_thickness)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_underline_thickness);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_underline_thickness), decltype(&T::_font_get_underline_thickness)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_underline_thickness);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_scale), decltype(&T::_font_set_scale)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_scale);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_scale), decltype(&T::_font_get_scale)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_scale);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_texture_count), decltype(&T::_font_get_texture_count)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_texture_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_clear_textures), decltype(&T::_font_clear_textures)>) {
			BIND_VIRTUAL_METHOD(T, _font_clear_textures);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_remove_texture), decltype(&T::_font_remove_texture)>) {
			BIND_VIRTUAL_METHOD(T, _font_remove_texture);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_texture_image), decltype(&T::_font_set_texture_image)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_texture_image);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_texture_image), decltype(&T::_font_get_texture_image)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_texture_image);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_texture_offsets), decltype(&T::_font_set_texture_offsets)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_texture_offsets);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_texture_offsets), decltype(&T::_font_get_texture_offsets)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_texture_offsets);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_list), decltype(&T::_font_get_glyph_list)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_clear_glyphs), decltype(&T::_font_clear_glyphs)>) {
			BIND_VIRTUAL_METHOD(T, _font_clear_glyphs);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_remove_glyph), decltype(&T::_font_remove_glyph)>) {
			BIND_VIRTUAL_METHOD(T, _font_remove_glyph);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_advance), decltype(&T::_font_get_glyph_advance)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_advance);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_glyph_advance), decltype(&T::_font_set_glyph_advance)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_glyph_advance);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_offset), decltype(&T::_font_get_glyph_offset)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_offset);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_glyph_offset), decltype(&T::_font_set_glyph_offset)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_glyph_offset);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_size), decltype(&T::_font_get_glyph_size)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_glyph_size), decltype(&T::_font_set_glyph_size)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_glyph_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_uv_rect), decltype(&T::_font_get_glyph_uv_rect)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_uv_rect);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_glyph_uv_rect), decltype(&T::_font_set_glyph_uv_rect)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_glyph_uv_rect);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_texture_idx), decltype(&T::_font_get_glyph_texture_idx)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_texture_idx);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_glyph_texture_idx), decltype(&T::_font_set_glyph_texture_idx)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_glyph_texture_idx);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_texture_rid), decltype(&T::_font_get_glyph_texture_rid)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_texture_rid);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_texture_size), decltype(&T::_font_get_glyph_texture_size)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_texture_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_contours), decltype(&T::_font_get_glyph_contours)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_contours);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_kerning_list), decltype(&T::_font_get_kerning_list)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_kerning_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_clear_kerning_map), decltype(&T::_font_clear_kerning_map)>) {
			BIND_VIRTUAL_METHOD(T, _font_clear_kerning_map);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_remove_kerning), decltype(&T::_font_remove_kerning)>) {
			BIND_VIRTUAL_METHOD(T, _font_remove_kerning);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_kerning), decltype(&T::_font_set_kerning)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_kerning);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_kerning), decltype(&T::_font_get_kerning)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_kerning);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_glyph_index), decltype(&T::_font_get_glyph_index)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_glyph_index);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_char_from_glyph_index), decltype(&T::_font_get_char_from_glyph_index)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_char_from_glyph_index);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_has_char), decltype(&T::_font_has_char)>) {
			BIND_VIRTUAL_METHOD(T, _font_has_char);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_supported_chars), decltype(&T::_font_get_supported_chars)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_supported_chars);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_supported_glyphs), decltype(&T::_font_get_supported_glyphs)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_supported_glyphs);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_render_range), decltype(&T::_font_render_range)>) {
			BIND_VIRTUAL_METHOD(T, _font_render_range);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_render_glyph), decltype(&T::_font_render_glyph)>) {
			BIND_VIRTUAL_METHOD(T, _font_render_glyph);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_draw_glyph), decltype(&T::_font_draw_glyph)>) {
			BIND_VIRTUAL_METHOD(T, _font_draw_glyph);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_draw_glyph_outline), decltype(&T::_font_draw_glyph_outline)>) {
			BIND_VIRTUAL_METHOD(T, _font_draw_glyph_outline);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_is_language_supported), decltype(&T::_font_is_language_supported)>) {
			BIND_VIRTUAL_METHOD(T, _font_is_language_supported);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_language_support_override), decltype(&T::_font_set_language_support_override)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_language_support_override);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_language_support_override), decltype(&T::_font_get_language_support_override)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_language_support_override);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_remove_language_support_override), decltype(&T::_font_remove_language_support_override)>) {
			BIND_VIRTUAL_METHOD(T, _font_remove_language_support_override);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_language_support_overrides), decltype(&T::_font_get_language_support_overrides)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_language_support_overrides);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_is_script_supported), decltype(&T::_font_is_script_supported)>) {
			BIND_VIRTUAL_METHOD(T, _font_is_script_supported);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_script_support_override), decltype(&T::_font_set_script_support_override)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_script_support_override);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_script_support_override), decltype(&T::_font_get_script_support_override)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_script_support_override);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_remove_script_support_override), decltype(&T::_font_remove_script_support_override)>) {
			BIND_VIRTUAL_METHOD(T, _font_remove_script_support_override);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_script_support_overrides), decltype(&T::_font_get_script_support_overrides)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_script_support_overrides);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_opentype_feature_overrides), decltype(&T::_font_set_opentype_feature_overrides)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_opentype_feature_overrides);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_opentype_feature_overrides), decltype(&T::_font_get_opentype_feature_overrides)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_opentype_feature_overrides);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_supported_feature_list), decltype(&T::_font_supported_feature_list)>) {
			BIND_VIRTUAL_METHOD(T, _font_supported_feature_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_supported_variation_list), decltype(&T::_font_supported_variation_list)>) {
			BIND_VIRTUAL_METHOD(T, _font_supported_variation_list);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_get_global_oversampling), decltype(&T::_font_get_global_oversampling)>) {
			BIND_VIRTUAL_METHOD(T, _font_get_global_oversampling);
		}
		if constexpr (!std::is_same_v<decltype(&B::_font_set_global_oversampling), decltype(&T::_font_set_global_oversampling)>) {
			BIND_VIRTUAL_METHOD(T, _font_set_global_oversampling);
		}
		if constexpr (!std::is_same_v<decltype(&B::_get_hex_code_box_size), decltype(&T::_get_hex_code_box_size)>) {
			BIND_VIRTUAL_METHOD(T, _get_hex_code_box_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_draw_hex_code_box), decltype(&T::_draw_hex_code_box)>) {
			BIND_VIRTUAL_METHOD(T, _draw_hex_code_box);
		}
		if constexpr (!std::is_same_v<decltype(&B::_create_shaped_text), decltype(&T::_create_shaped_text)>) {
			BIND_VIRTUAL_METHOD(T, _create_shaped_text);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_clear), decltype(&T::_shaped_text_clear)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_clear);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_direction), decltype(&T::_shaped_text_set_direction)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_direction);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_direction), decltype(&T::_shaped_text_get_direction)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_direction);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_inferred_direction), decltype(&T::_shaped_text_get_inferred_direction)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_inferred_direction);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_bidi_override), decltype(&T::_shaped_text_set_bidi_override)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_bidi_override);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_custom_punctuation), decltype(&T::_shaped_text_set_custom_punctuation)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_custom_punctuation);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_custom_punctuation), decltype(&T::_shaped_text_get_custom_punctuation)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_custom_punctuation);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_custom_ellipsis), decltype(&T::_shaped_text_set_custom_ellipsis)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_custom_ellipsis);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_custom_ellipsis), decltype(&T::_shaped_text_get_custom_ellipsis)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_custom_ellipsis);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_orientation), decltype(&T::_shaped_text_set_orientation)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_orientation);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_orientation), decltype(&T::_shaped_text_get_orientation)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_orientation);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_preserve_invalid), decltype(&T::_shaped_text_set_preserve_invalid)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_preserve_invalid);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_preserve_invalid), decltype(&T::_shaped_text_get_preserve_invalid)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_preserve_invalid);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_preserve_control), decltype(&T::_shaped_text_set_preserve_control)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_preserve_control);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_preserve_control), decltype(&T::_shaped_text_get_preserve_control)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_preserve_control);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_set_spacing), decltype(&T::_shaped_text_set_spacing)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_set_spacing);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_spacing), decltype(&T::_shaped_text_get_spacing)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_spacing);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_add_string), decltype(&T::_shaped_text_add_string)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_add_string);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_add_object), decltype(&T::_shaped_text_add_object)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_add_object);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_resize_object), decltype(&T::_shaped_text_resize_object)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_resize_object);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_get_span_count), decltype(&T::_shaped_get_span_count)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_get_span_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_get_span_meta), decltype(&T::_shaped_get_span_meta)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_get_span_meta);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_set_span_update_font), decltype(&T::_shaped_set_span_update_font)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_set_span_update_font);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_substr), decltype(&T::_shaped_text_substr)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_substr);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_parent), decltype(&T::_shaped_text_get_parent)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_parent);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_fit_to_width), decltype(&T::_shaped_text_fit_to_width)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_fit_to_width);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_tab_align), decltype(&T::_shaped_text_tab_align)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_tab_align);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_shape), decltype(&T::_shaped_text_shape)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_shape);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_update_breaks), decltype(&T::_shaped_text_update_breaks)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_update_breaks);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_update_justification_ops), decltype(&T::_shaped_text_update_justification_ops)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_update_justification_ops);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_is_ready), decltype(&T::_shaped_text_is_ready)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_is_ready);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_glyphs), decltype(&T::_shaped_text_get_glyphs)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_glyphs);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_sort_logical), decltype(&T::_shaped_text_sort_logical)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_sort_logical);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_glyph_count), decltype(&T::_shaped_text_get_glyph_count)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_glyph_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_range), decltype(&T::_shaped_text_get_range)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_range);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_line_breaks_adv), decltype(&T::_shaped_text_get_line_breaks_adv)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_line_breaks_adv);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_line_breaks), decltype(&T::_shaped_text_get_line_breaks)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_line_breaks);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_word_breaks), decltype(&T::_shaped_text_get_word_breaks)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_word_breaks);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_trim_pos), decltype(&T::_shaped_text_get_trim_pos)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_trim_pos);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_ellipsis_pos), decltype(&T::_shaped_text_get_ellipsis_pos)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_ellipsis_pos);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_ellipsis_glyph_count), decltype(&T::_shaped_text_get_ellipsis_glyph_count)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_ellipsis_glyph_count);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_ellipsis_glyphs), decltype(&T::_shaped_text_get_ellipsis_glyphs)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_ellipsis_glyphs);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_overrun_trim_to_width), decltype(&T::_shaped_text_overrun_trim_to_width)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_overrun_trim_to_width);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_objects), decltype(&T::_shaped_text_get_objects)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_objects);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_object_rect), decltype(&T::_shaped_text_get_object_rect)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_object_rect);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_object_range), decltype(&T::_shaped_text_get_object_range)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_object_range);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_object_glyph), decltype(&T::_shaped_text_get_object_glyph)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_object_glyph);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_size), decltype(&T::_shaped_text_get_size)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_size);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_ascent), decltype(&T::_shaped_text_get_ascent)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_ascent);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_descent), decltype(&T::_shaped_text_get_descent)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_descent);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_width), decltype(&T::_shaped_text_get_width)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_width);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_underline_position), decltype(&T::_shaped_text_get_underline_position)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_underline_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_underline_thickness), decltype(&T::_shaped_text_get_underline_thickness)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_underline_thickness);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_dominant_direction_in_range), decltype(&T::_shaped_text_get_dominant_direction_in_range)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_dominant_direction_in_range);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_carets), decltype(&T::_shaped_text_get_carets)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_carets);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_selection), decltype(&T::_shaped_text_get_selection)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_selection);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_hit_test_grapheme), decltype(&T::_shaped_text_hit_test_grapheme)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_hit_test_grapheme);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_hit_test_position), decltype(&T::_shaped_text_hit_test_position)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_hit_test_position);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_draw), decltype(&T::_shaped_text_draw)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_draw);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_draw_outline), decltype(&T::_shaped_text_draw_outline)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_draw_outline);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_grapheme_bounds), decltype(&T::_shaped_text_get_grapheme_bounds)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_grapheme_bounds);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_next_grapheme_pos), decltype(&T::_shaped_text_next_grapheme_pos)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_next_grapheme_pos);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_prev_grapheme_pos), decltype(&T::_shaped_text_prev_grapheme_pos)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_prev_grapheme_pos);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_get_character_breaks), decltype(&T::_shaped_text_get_character_breaks)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_get_character_breaks);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_next_character_pos), decltype(&T::_shaped_text_next_character_pos)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_next_character_pos);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_prev_character_pos), decltype(&T::_shaped_text_prev_character_pos)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_prev_character_pos);
		}
		if constexpr (!std::is_same_v<decltype(&B::_shaped_text_closest_character_pos), decltype(&T::_shaped_text_closest_character_pos)>) {
			BIND_VIRTUAL_METHOD(T, _shaped_text_closest_character_pos);
		}
		if constexpr (!std::is_same_v<decltype(&B::_format_number), decltype(&T::_format_number)>) {
			BIND_VIRTUAL_METHOD(T, _format_number);
		}
		if constexpr (!std::is_same_v<decltype(&B::_parse_number), decltype(&T::_parse_number)>) {
			BIND_VIRTUAL_METHOD(T, _parse_number);
		}
		if constexpr (!std::is_same_v<decltype(&B::_percent_sign), decltype(&T::_percent_sign)>) {
			BIND_VIRTUAL_METHOD(T, _percent_sign);
		}
		if constexpr (!std::is_same_v<decltype(&B::_strip_diacritics), decltype(&T::_strip_diacritics)>) {
			BIND_VIRTUAL_METHOD(T, _strip_diacritics);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_valid_identifier), decltype(&T::_is_valid_identifier)>) {
			BIND_VIRTUAL_METHOD(T, _is_valid_identifier);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_valid_letter), decltype(&T::_is_valid_letter)>) {
			BIND_VIRTUAL_METHOD(T, _is_valid_letter);
		}
		if constexpr (!std::is_same_v<decltype(&B::_string_get_word_breaks), decltype(&T::_string_get_word_breaks)>) {
			BIND_VIRTUAL_METHOD(T, _string_get_word_breaks);
		}
		if constexpr (!std::is_same_v<decltype(&B::_string_get_character_breaks), decltype(&T::_string_get_character_breaks)>) {
			BIND_VIRTUAL_METHOD(T, _string_get_character_breaks);
		}
		if constexpr (!std::is_same_v<decltype(&B::_is_confusable), decltype(&T::_is_confusable)>) {
			BIND_VIRTUAL_METHOD(T, _is_confusable);
		}
		if constexpr (!std::is_same_v<decltype(&B::_spoof_check), decltype(&T::_spoof_check)>) {
			BIND_VIRTUAL_METHOD(T, _spoof_check);
		}
		if constexpr (!std::is_same_v<decltype(&B::_string_to_upper), decltype(&T::_string_to_upper)>) {
			BIND_VIRTUAL_METHOD(T, _string_to_upper);
		}
		if constexpr (!std::is_same_v<decltype(&B::_string_to_lower), decltype(&T::_string_to_lower)>) {
			BIND_VIRTUAL_METHOD(T, _string_to_lower);
		}
		if constexpr (!std::is_same_v<decltype(&B::_string_to_title), decltype(&T::_string_to_title)>) {
			BIND_VIRTUAL_METHOD(T, _string_to_title);
		}
		if constexpr (!std::is_same_v<decltype(&B::_parse_structured_text), decltype(&T::_parse_structured_text)>) {
			BIND_VIRTUAL_METHOD(T, _parse_structured_text);
		}
		if constexpr (!std::is_same_v<decltype(&B::_cleanup), decltype(&T::_cleanup)>) {
			BIND_VIRTUAL_METHOD(T, _cleanup);
		}
	}

public:
};

} // namespace godot

#endif // ! GODOT_CPP_TEXT_SERVER_EXTENSION_HPP
