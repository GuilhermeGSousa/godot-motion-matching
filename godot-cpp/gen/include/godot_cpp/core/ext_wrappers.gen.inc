
#ifndef GDEXTENSION_WRAPPERS_GEN_H
#define GDEXTENSION_WRAPPERS_GEN_H


/* Module Wrapper 0 Arguments */

#define MODBIND0( m_name) \
virtual void _##m_name()  override; \

#define MODBIND0R(m_ret,  m_name) \
virtual m_ret _##m_name()  override; \

#define MODBIND0C( m_name) \
virtual void _##m_name() const override; \

#define MODBIND0RC(m_ret,  m_name) \
virtual m_ret _##m_name() const override; \

/* Module Wrapper 1 Arguments */

#define MODBIND1( m_name, m_type1) \
virtual void _##m_name(m_type1 arg1)  override; \

#define MODBIND1R(m_ret,  m_name, m_type1) \
virtual m_ret _##m_name(m_type1 arg1)  override; \

#define MODBIND1C( m_name, m_type1) \
virtual void _##m_name(m_type1 arg1) const override; \

#define MODBIND1RC(m_ret,  m_name, m_type1) \
virtual m_ret _##m_name(m_type1 arg1) const override; \

/* Module Wrapper 2 Arguments */

#define MODBIND2( m_name, m_type1, m_type2) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2)  override; \

#define MODBIND2R(m_ret,  m_name, m_type1, m_type2) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2)  override; \

#define MODBIND2C( m_name, m_type1, m_type2) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2) const override; \

#define MODBIND2RC(m_ret,  m_name, m_type1, m_type2) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2) const override; \

/* Module Wrapper 3 Arguments */

#define MODBIND3( m_name, m_type1, m_type2, m_type3) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3)  override; \

#define MODBIND3R(m_ret,  m_name, m_type1, m_type2, m_type3) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3)  override; \

#define MODBIND3C( m_name, m_type1, m_type2, m_type3) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3) const override; \

#define MODBIND3RC(m_ret,  m_name, m_type1, m_type2, m_type3) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3) const override; \

/* Module Wrapper 4 Arguments */

#define MODBIND4( m_name, m_type1, m_type2, m_type3, m_type4) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4)  override; \

#define MODBIND4R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4)  override; \

#define MODBIND4C( m_name, m_type1, m_type2, m_type3, m_type4) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4) const override; \

#define MODBIND4RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4) const override; \

/* Module Wrapper 5 Arguments */

#define MODBIND5( m_name, m_type1, m_type2, m_type3, m_type4, m_type5) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5)  override; \

#define MODBIND5R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5)  override; \

#define MODBIND5C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5) const override; \

#define MODBIND5RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5) const override; \

/* Module Wrapper 6 Arguments */

#define MODBIND6( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6)  override; \

#define MODBIND6R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6)  override; \

#define MODBIND6C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6) const override; \

#define MODBIND6RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6) const override; \

/* Module Wrapper 7 Arguments */

#define MODBIND7( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7)  override; \

#define MODBIND7R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7)  override; \

#define MODBIND7C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7) const override; \

#define MODBIND7RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7) const override; \

/* Module Wrapper 8 Arguments */

#define MODBIND8( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8)  override; \

#define MODBIND8R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8)  override; \

#define MODBIND8C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8) const override; \

#define MODBIND8RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8) const override; \

/* Module Wrapper 9 Arguments */

#define MODBIND9( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9)  override; \

#define MODBIND9R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9)  override; \

#define MODBIND9C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9) const override; \

#define MODBIND9RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9) const override; \

/* Module Wrapper 10 Arguments */

#define MODBIND10( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10)  override; \

#define MODBIND10R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10)  override; \

#define MODBIND10C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10) const override; \

#define MODBIND10RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10) const override; \

/* Module Wrapper 11 Arguments */

#define MODBIND11( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11)  override; \

#define MODBIND11R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11)  override; \

#define MODBIND11C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11) const override; \

#define MODBIND11RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11) const override; \

/* Module Wrapper 12 Arguments */

#define MODBIND12( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12)  override; \

#define MODBIND12R(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12)  override; \

#define MODBIND12C( m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12) \
virtual void _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12) const override; \

#define MODBIND12RC(m_ret,  m_name, m_type1, m_type2, m_type3, m_type4, m_type5, m_type6, m_type7, m_type8, m_type9, m_type10, m_type11, m_type12) \
virtual m_ret _##m_name(m_type1 arg1, m_type2 arg2, m_type3 arg3, m_type4 arg4, m_type5 arg5, m_type6 arg6, m_type7 arg7, m_type8 arg8, m_type9 arg9, m_type10 arg10, m_type11 arg11, m_type12 arg12) const override; \

#endif
