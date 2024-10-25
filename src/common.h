/**************************************************************************/
/*  common.h                                                              */
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

#ifndef COMMON_H
#define COMMON_H

#define GETSET(type, variable, ...)   \
    type variable{__VA_ARGS__};       \
    type get_##variable() const {     \
        return variable;              \
    }                                 \
    void set_##variable(type value) { \
        variable = value;             \
    }

#define STR(x) #x

#define STRING_PREFIX(prefix, s) STR(prefix##s)

#define BINDER_PROPERTY_PARAMS(type, variant_type, variable, ...)                                  \
    ClassDB::bind_method(D_METHOD(STRING_PREFIX(set_, variable), "value"), &type::set_##variable); \
    ClassDB::bind_method(D_METHOD(STRING_PREFIX(get_, variable)), &type::get_##variable);          \
    ClassDB::add_property(get_class_static(), PropertyInfo(variant_type, #variable, ##__VA_ARGS__), STRING_PREFIX(set_, variable), STRING_PREFIX(get_, variable));

#define SMALL_NUMBER 1.e-8

#endif // COMMON_H
