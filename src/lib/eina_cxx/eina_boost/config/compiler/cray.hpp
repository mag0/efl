//  (C) Copyright John Maddock 2011.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Greenhills C compiler setup:

#define EFL_EINA_BOOST_COMPILER "Cray C version " EFL_EINA_BOOST_STRINGIZE(_RELEASE)

#if _RELEASE < 7
#  error "Boost is not configured for Cray compilers prior to version 7, please try the configure script."
#endif

//
// Check this is a recent EDG based compiler, otherwise we don't support it here:
//
#ifndef __EDG_VERSION__
#  error "Unsupported Cray compiler, please try running the configure script."
#endif

#include "eina_boost/config/compiler/common_edg.hpp"

//
// Cray peculiarities, probably version 7 specific:
//
#undef EFL_EINA_BOOST_NO_CXX11_AUTO_DECLARATIONS
#undef EFL_EINA_BOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define EFL_EINA_BOOST_HAS_NRVO
#define EFL_EINA_BOOST_NO_CXX11_VARIADIC_TEMPLATES
#define EFL_EINA_BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
#define EFL_EINA_BOOST_NO_CXX11_UNICODE_LITERALS
#define EFL_EINA_BOOST_NO_TWO_PHASE_NAME_LOOKUP
#define EFL_EINA_BOOST_HAS_NRVO
#define EFL_EINA_BOOST_NO_CXX11_TEMPLATE_ALIASES
#define EFL_EINA_BOOST_NO_CXX11_STATIC_ASSERT
#define EFL_EINA_BOOST_NO_SFINAE_EXPR
#define EFL_EINA_BOOST_NO_CXX11_SCOPED_ENUMS
#define EFL_EINA_BOOST_NO_CXX11_RVALUE_REFERENCES
#define EFL_EINA_BOOST_NO_CXX11_RANGE_BASED_FOR
#define EFL_EINA_BOOST_NO_CXX11_RAW_LITERALS
#define EFL_EINA_BOOST_NO_CXX11_NULLPTR
#define EFL_EINA_BOOST_NO_CXX11_NOEXCEPT
#define EFL_EINA_BOOST_NO_CXX11_LAMBDAS
#define EFL_EINA_BOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#define EFL_EINA_BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define EFL_EINA_BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#define EFL_EINA_BOOST_NO_CXX11_DELETED_FUNCTIONS
#define EFL_EINA_BOOST_NO_CXX11_DEFAULTED_FUNCTIONS
#define EFL_EINA_BOOST_NO_CXX11_DECLTYPE_N3276
#define EFL_EINA_BOOST_NO_CXX11_DECLTYPE
#define EFL_EINA_BOOST_NO_CXX11_CONSTEXPR
#define EFL_EINA_BOOST_NO_CXX11_USER_DEFINED_LITERALS
#define EFL_EINA_BOOST_NO_COMPLETE_VALUE_INITIALIZATION
#define EFL_EINA_BOOST_NO_CXX11_CHAR32_T
#define EFL_EINA_BOOST_NO_CXX11_CHAR16_T
#define EFL_EINA_BOOST_NO_CXX11_ALIGNAS
//#define EFL_EINA_BOOST_BCB_PARTIAL_SPECIALIZATION_BUG
#define EFL_EINA_BOOST_MATH_DISABLE_STD_FPCLASSIFY
//#define EFL_EINA_BOOST_HAS_FPCLASSIFY

#define EFL_EINA_BOOST_SP_USE_PTHREADS
#define EFL_EINA_BOOST_AC_USE_PTHREADS

