// Copyright (C) 2004 Arkadiy Vertleyb
// Copyright (C) 2005 Peder Holt
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_TYPEOF_REGISTER_INTEGRAL_HPP_INCLUDED
#define BOOST_TYPEOF_REGISTER_INTEGRAL_HPP_INCLUDED

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq.hpp>
#include <boost/preprocessor/repetition/enum_trailing.hpp>

// The template parameter description, entered by the user,
// is converted into a polymorphic "object" 
// that is used to generate the code responsible for
// encoding/decoding the parameter, etc.
// See also compliant/template_encoding.hpp and 
// vintage/template_encoding.hpp.

#define BOOST_TYPEOF_MAKE_OBJ(elem) BOOST_PP_SEQ_CAT(\
    (BOOST_TYPEOF_MAKE_OBJ_) BOOST_TYPEOF_TO_SEQ(elem))

#define BOOST_TYPEOF_TO_SEQ(tokens) BOOST_TYPEOF_ ## tokens ## _BOOST_TYPEOF 

#define BOOST_TYPEOF_unsigned (unsigned)
#define BOOST_TYPEOF_signed (signed)

#define char_BOOST_TYPEOF (char)
#define short_BOOST_TYPEOF (short)
#define int_BOOST_TYPEOF (int)
#define long_BOOST_TYPEOF (long)

#define BOOST_TYPEOF_char_BOOST_TYPEOF (char)
#define BOOST_TYPEOF_short_BOOST_TYPEOF (short)
#define BOOST_TYPEOF_int_BOOST_TYPEOF (int)
#define BOOST_TYPEOF_long_BOOST_TYPEOF (long)
#define BOOST_TYPEOF_bool_BOOST_TYPEOF (bool)
#define BOOST_TYPEOF_class_BOOST_TYPEOF (class)
#define BOOST_TYPEOF_typename_BOOST_TYPEOF (typename)
#define BOOST_TYPEOF_unsigned_BOOST_TYPEOF (unsigned)
#define BOOST_TYPEOF_size_t_BOOST_TYPEOF (size_t)

#define BOOST_TYPEOF_MAKE_OBJ_class         BOOST_TYPEOF_TYPE_PARAM
#define BOOST_TYPEOF_MAKE_OBJ_typename      BOOST_TYPEOF_TYPE_PARAM
#define BOOST_TYPEOF_MAKE_OBJ_char          BOOST_TYPEOF_INTEGRAL_PARAM(char,char)
#define BOOST_TYPEOF_MAKE_OBJ_short         BOOST_TYPEOF_INTEGRAL_PARAM(short,short)
#define BOOST_TYPEOF_MAKE_OBJ_int           BOOST_TYPEOF_INTEGRAL_PARAM(int,int)
#define BOOST_TYPEOF_MAKE_OBJ_long          BOOST_TYPEOF_INTEGRAL_PARAM(long,long)
#define BOOST_TYPEOF_MAKE_OBJ_bool          BOOST_TYPEOF_INTEGRAL_PARAM(bool,bool)
#define BOOST_TYPEOF_MAKE_OBJ_unsigned      BOOST_TYPEOF_INTEGRAL_PARAM(unsigned,uint)
#define BOOST_TYPEOF_MAKE_OBJ_size_t        BOOST_TYPEOF_INTEGRAL_PARAM(size_t,size_t)
#define BOOST_TYPEOF_MAKE_OBJ_unsignedchar  BOOST_TYPEOF_INTEGRAL_PARAM(unsigned char,uchar)
#define BOOST_TYPEOF_MAKE_OBJ_unsignedshort BOOST_TYPEOF_INTEGRAL_PARAM(unsigned short,ushort)
#define BOOST_TYPEOF_MAKE_OBJ_unsignedint   BOOST_TYPEOF_INTEGRAL_PARAM(unsigned int,uint)
#define BOOST_TYPEOF_MAKE_OBJ_unsignedlong  BOOST_TYPEOF_INTEGRAL_PARAM(unsigned long,ulong)
#define BOOST_TYPEOF_MAKE_OBJ_signedchar    BOOST_TYPEOF_INTEGRAL_PARAM(signed char,schar)
#define BOOST_TYPEOF_MAKE_OBJ_signedshort   BOOST_TYPEOF_INTEGRAL_PARAM(signed short,short)
#define BOOST_TYPEOF_MAKE_OBJ_signedint     BOOST_TYPEOF_INTEGRAL_PARAM(signed int,int)
#define BOOST_TYPEOF_MAKE_OBJ_signedlong    BOOST_TYPEOF_INTEGRAL_PARAM(signed long,long)
#define BOOST_TYPEOF_MAKE_OBJ_integral(x)   BOOST_TYPEOF_EXPLICIT_INTEGRAL_PARAM(x)

#define BOOST_TYPEOF_INTEGRAL(X) integral(X) BOOST_TYPEOF_EAT
#define BOOST_TYPEOF_EAT_BOOST_TYPEOF
#define BOOST_TYPEOF_integral(X) (integral(X))

// "interface"

#define BOOST_TYPEOF_PARAM_ENCODE(Param)\
    BOOST_PP_CAT(BOOST_TYPEOF_ENCODE_, BOOST_PP_SEQ_ELEM(0, Param))

#define BOOST_TYPEOF_PARAM_DECODE(Param)\
    BOOST_PP_CAT(BOOST_TYPEOF_DECODE_, BOOST_PP_SEQ_ELEM(0, Param))

#define BOOST_TYPEOF_PARAM_GETTYPE(Param)\
    BOOST_PP_SEQ_ELEM(1, Param)

#define BOOST_TYPEOF_PARAM_GETNAME(Param)\
    BOOST_PP_SEQ_ELEM(2, Param)

// "constructors"

#define BOOST_TYPEOF_TYPE_PARAM\
    (TYPE_PARAM)\
    (class)\
    (class)

#define BOOST_TYPEOF_INTEGRAL_PARAM(Type,Name)\
    (INTEGRAL_PARAM)\
    (Type)\
    (Name)

#define BOOST_TYPEOF_EXPLICIT_INTEGRAL_PARAM(Type)\
    (EXPLICIT_INTEGRAL_PARAM)\
    (Type)\
    (BOOST_PP_CAT(_,Type))

#define BOOST_TYPEOF_DECODE_EXPLICIT_INTEGRAL_PARAM BOOST_TYPEOF_DECODE_INTEGRAL_PARAM
#define BOOST_TYPEOF_ENCODE_EXPLICIT_INTEGRAL_PARAM BOOST_TYPEOF_ENCODE_INTEGRAL_PARAM

#define BOOST_TYPEOF_EXPAND_TYPE(Param)\
    BOOST_PP_CAT(BOOST_TYPEOF_EXPAND_, BOOST_PP_SEQ_ELEM(0, Param))(Param)

#define BOOST_TYPEOF_EXPAND_TYPE_PARAM(Param) BOOST_TYPEOF_PARAM_GETTYPE(Param)
#define BOOST_TYPEOF_EXPAND_INTEGRAL_PARAM(Param) BOOST_TYPEOF_PARAM_GETTYPE(Param)
#define BOOST_TYPEOF_EXPAND_EXPLICIT_INTEGRAL_PARAM(Param) BOOST_TYPEOF_PARAM_GETTYPE(Param)

#define BOOST_TYPEOF_SEQ_EXPAND_ELEMENT(z,n,seq)\
   BOOST_PP_SEQ_ELEM(0,seq)(z,n,BOOST_PP_SEQ_ELEM(n,BOOST_PP_SEQ_ELEM(1,seq)))

#define BOOST_TYPEOF_SEQ_ENUM(seq,macro)\
BOOST_PP_ENUM(BOOST_PP_SEQ_SIZE(seq),BOOST_TYPEOF_SEQ_EXPAND_ELEMENT,(macro)(seq))

#define BOOST_TYPEOF_SEQ_ENUM_TRAILING(seq,macro)\
BOOST_PP_ENUM_TRAILING(BOOST_PP_SEQ_SIZE(seq),BOOST_TYPEOF_SEQ_EXPAND_ELEMENT,(macro)(seq))

#endif//BOOST_TYPEOF_COMPLIANT_TEMPLATE_ENCODING_HPP_INCLUDED