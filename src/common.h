#pragma once

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
    ClassDB::add_property(get_class_static(), PropertyInfo(variant_type, #variable, __VA_ARGS__),  \
                          STRING_PREFIX(set_, variable), STRING_PREFIX(get_, variable));

#define SMALL_NUMBER 1.e-8