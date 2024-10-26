/* THIS FILE IS GENERATED DO NOT EDIT */
#ifndef GDEXTENSION_GDVIRTUAL_GEN_H
#define GDEXTENSION_GDVIRTUAL_GEN_H

/* 0 Arguments */

#define GDVIRTUAL0(m_name)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call() {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, nullptr, 0, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		return method_info;\
	}

#define GDVIRTUAL0R(m_ret, m_name)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, nullptr, 0, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		return method_info;\
	}

#define GDVIRTUAL0C(m_name)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call() const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, nullptr, 0, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		return method_info;\
	}

#define GDVIRTUAL0RC(m_ret, m_name)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, nullptr, 0, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		return method_info;\
	}

/* 1 Arguments */

#define GDVIRTUAL1(m_name, m_type1)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[1] = { ::godot::Variant(arg1) };\
			const ::godot::Variant *vargptrs[1] = { &vargs[0] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 1, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL1R(m_ret, m_name, m_type1)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[1] = { ::godot::Variant(arg1) };\
			const ::godot::Variant *vargptrs[1] = { &vargs[0] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 1, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL1C(m_name, m_type1)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[1] = { ::godot::Variant(arg1) };\
			const ::godot::Variant *vargptrs[1] = { &vargs[0] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 1, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL1RC(m_ret, m_name, m_type1)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[1] = { ::godot::Variant(arg1) };\
			const ::godot::Variant *vargptrs[1] = { &vargs[0] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 1, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		return method_info;\
	}

/* 2 Arguments */

#define GDVIRTUAL2(m_name, m_type1, m_type2)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[2] = { ::godot::Variant(arg1), ::godot::Variant(arg2) };\
			const ::godot::Variant *vargptrs[2] = { &vargs[0], &vargs[1] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 2, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL2R(m_ret, m_name, m_type1, m_type2)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[2] = { ::godot::Variant(arg1), ::godot::Variant(arg2) };\
			const ::godot::Variant *vargptrs[2] = { &vargs[0], &vargs[1] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 2, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL2C(m_name, m_type1, m_type2)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[2] = { ::godot::Variant(arg1), ::godot::Variant(arg2) };\
			const ::godot::Variant *vargptrs[2] = { &vargs[0], &vargs[1] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 2, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL2RC(m_ret, m_name, m_type1, m_type2)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[2] = { ::godot::Variant(arg1), ::godot::Variant(arg2) };\
			const ::godot::Variant *vargptrs[2] = { &vargs[0], &vargs[1] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 2, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		return method_info;\
	}

/* 3 Arguments */

#define GDVIRTUAL3(m_name, m_type1, m_type2, m_type3)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[3] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3) };\
			const ::godot::Variant *vargptrs[3] = { &vargs[0], &vargs[1], &vargs[2] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 3, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL3R(m_ret, m_name, m_type1, m_type2, m_type3)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[3] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3) };\
			const ::godot::Variant *vargptrs[3] = { &vargs[0], &vargs[1], &vargs[2] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 3, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL3C(m_name, m_type1, m_type2, m_type3)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[3] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3) };\
			const ::godot::Variant *vargptrs[3] = { &vargs[0], &vargs[1], &vargs[2] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 3, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL3RC(m_ret, m_name, m_type1, m_type2, m_type3)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[3] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3) };\
			const ::godot::Variant *vargptrs[3] = { &vargs[0], &vargs[1], &vargs[2] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 3, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		return method_info;\
	}

/* 4 Arguments */

#define GDVIRTUAL4(m_name, m_type1, m_type2, m_type3, m_type4)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[4] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4) };\
			const ::godot::Variant *vargptrs[4] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 4, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL4R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[4] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4) };\
			const ::godot::Variant *vargptrs[4] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 4, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL4C(m_name, m_type1, m_type2, m_type3, m_type4)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[4] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4) };\
			const ::godot::Variant *vargptrs[4] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 4, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL4RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[4] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4) };\
			const ::godot::Variant *vargptrs[4] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 4, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		return method_info;\
	}

/* 5 Arguments */

#define GDVIRTUAL5(m_name, m_type1, m_type2, m_type3, m_type4, m_type5)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[5] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5) };\
			const ::godot::Variant *vargptrs[5] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 5, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL5R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[5] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5) };\
			const ::godot::Variant *vargptrs[5] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 5, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL5C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[5] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5) };\
			const ::godot::Variant *vargptrs[5] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 5, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL5RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[5] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5) };\
			const ::godot::Variant *vargptrs[5] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 5, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		return method_info;\
	}

/* 6 Arguments */

#define GDVIRTUAL6(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[6] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6) };\
			const ::godot::Variant *vargptrs[6] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 6, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL6R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[6] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6) };\
			const ::godot::Variant *vargptrs[6] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 6, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL6C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[6] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6) };\
			const ::godot::Variant *vargptrs[6] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 6, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL6RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[6] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6) };\
			const ::godot::Variant *vargptrs[6] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 6, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		return method_info;\
	}

/* 7 Arguments */

#define GDVIRTUAL7(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[7] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7) };\
			const ::godot::Variant *vargptrs[7] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 7, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL7R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[7] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7) };\
			const ::godot::Variant *vargptrs[7] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 7, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL7C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[7] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7) };\
			const ::godot::Variant *vargptrs[7] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 7, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL7RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[7] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7) };\
			const ::godot::Variant *vargptrs[7] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 7, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		return method_info;\
	}

/* 8 Arguments */

#define GDVIRTUAL8(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[8] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8) };\
			const ::godot::Variant *vargptrs[8] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 8, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL8R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[8] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8) };\
			const ::godot::Variant *vargptrs[8] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 8, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL8C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[8] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8) };\
			const ::godot::Variant *vargptrs[8] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 8, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL8RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[8] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8) };\
			const ::godot::Variant *vargptrs[8] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 8, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		return method_info;\
	}

/* 9 Arguments */

#define GDVIRTUAL9(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[9] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9) };\
			const ::godot::Variant *vargptrs[9] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 9, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL9R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[9] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9) };\
			const ::godot::Variant *vargptrs[9] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 9, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL9C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[9] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9) };\
			const ::godot::Variant *vargptrs[9] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 9, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL9RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[9] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9) };\
			const ::godot::Variant *vargptrs[9] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 9, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		return method_info;\
	}

/* 10 Arguments */

#define GDVIRTUAL10(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[10] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10) };\
			const ::godot::Variant *vargptrs[10] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 10, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL10R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[10] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10) };\
			const ::godot::Variant *vargptrs[10] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 10, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL10C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[10] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10) };\
			const ::godot::Variant *vargptrs[10] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 10, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL10RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[10] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10) };\
			const ::godot::Variant *vargptrs[10] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 10, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		return method_info;\
	}

/* 11 Arguments */

#define GDVIRTUAL11(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[11] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11) };\
			const ::godot::Variant *vargptrs[11] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 11, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL11R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[11] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11) };\
			const ::godot::Variant *vargptrs[11] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 11, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL11C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[11] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11) };\
			const ::godot::Variant *vargptrs[11] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 11, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL11RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[11] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11) };\
			const ::godot::Variant *vargptrs[11] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 11, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		return method_info;\
	}

/* 12 Arguments */

#define GDVIRTUAL12(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[12] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11), ::godot::Variant(arg12) };\
			const ::godot::Variant *vargptrs[12] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10], &vargs[11] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 12, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type12>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type12>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL12R(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12, m_ret &r_ret) {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[12] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11), ::godot::Variant(arg12) };\
			const ::godot::Variant *vargptrs[12] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10], &vargs[11] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 12, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type12>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type12>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL12C(m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[12] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11), ::godot::Variant(arg12) };\
			const ::godot::Variant *vargptrs[12] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10], &vargs[11] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 12, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type12>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type12>::METADATA);\
		return method_info;\
	}

#define GDVIRTUAL12RC(m_ret, m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12)\
	::godot::StringName _gdvirtual_##m_name##_sn = #m_name;\
	template <bool required>\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_call(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12, m_ret &r_ret) const {\
		if (::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn)) { \
			GDExtensionCallError ce;\
			::godot::Variant vargs[12] = { ::godot::Variant(arg1), ::godot::Variant(arg2), ::godot::Variant(arg3), ::godot::Variant(arg4), ::godot::Variant(arg5), ::godot::Variant(arg6), ::godot::Variant(arg7), ::godot::Variant(arg8), ::godot::Variant(arg9), ::godot::Variant(arg10), ::godot::Variant(arg11), ::godot::Variant(arg12) };\
			const ::godot::Variant *vargptrs[12] = { &vargs[0], &vargs[1], &vargs[2], &vargs[3], &vargs[4], &vargs[5], &vargs[6], &vargs[7], &vargs[8], &vargs[9], &vargs[10], &vargs[11] };\
			::godot::Variant ret;\
			::godot::internal::gdextension_interface_object_call_script_method(_owner, &_gdvirtual_##m_name##_sn, (const GDExtensionConstVariantPtr *)vargptrs, 12, &ret, &ce);\
			if (ce.error == GDEXTENSION_CALL_OK) {\
				r_ret = ::godot::VariantCaster<m_ret>::cast(ret);\
				return true;\
			}\
		}\
		if (required) {\
			ERR_PRINT_ONCE("Required virtual method " + get_class() + "::" + #m_name + " must be overridden before calling.");\
			(void)r_ret;\
		}\
		return false;\
	}\
	_FORCE_INLINE_ bool _gdvirtual_##m_name##_overridden() const {\
		return ::godot::internal::gdextension_interface_object_has_script_method(_owner, &_gdvirtual_##m_name##_sn); \
	}\
	_FORCE_INLINE_ static ::godot::MethodInfo _gdvirtual_##m_name##_get_method_info() {\
		::godot::MethodInfo method_info;\
		method_info.name = #m_name;\
		method_info.flags = ::godot::METHOD_FLAG_VIRTUAL | ::godot::METHOD_FLAG_CONST;\
		method_info.return_val = ::godot::GetTypeInfo<m_ret>::get_class_info();\
		method_info.return_val_metadata = ::godot::GetTypeInfo<m_ret>::METADATA;\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type1>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type1>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type2>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type2>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type3>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type3>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type4>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type4>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type5>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type5>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type6>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type6>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type7>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type7>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type8>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type8>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type9>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type9>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type10>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type10>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type11>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type11>::METADATA);\
		method_info.arguments.push_back(::godot::GetTypeInfo<m_type12>::get_class_info());\
		method_info.arguments_metadata.push_back(::godot::GetTypeInfo<m_type12>::METADATA);\
		return method_info;\
	}

#endif // GDEXTENSION_GDVIRTUAL_GEN_H
