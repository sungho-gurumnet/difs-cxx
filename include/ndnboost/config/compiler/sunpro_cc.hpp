//  (C) Copyright John Maddock 2001. 
//  (C) Copyright Jens Maurer 2001 - 2003. 
//  (C) Copyright Peter Dimov 2002. 
//  (C) Copyright Aleksey Gurtovoy 2002 - 2003. 
//  (C) Copyright David Abrahams 2002. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Sun C++ compiler setup:

#    if __SUNPRO_CC <= 0x500
#      define NDNBOOST_NO_MEMBER_TEMPLATES
#      define NDNBOOST_NO_FUNCTION_TEMPLATE_ORDERING
#    endif

#    if (__SUNPRO_CC <= 0x520)
       //
       // Sunpro 5.2 and earler:
       //
       // although sunpro 5.2 supports the syntax for
       // inline initialization it often gets the value
       // wrong, especially where the value is computed
       // from other constants (J Maddock 6th May 2001)
#      define NDNBOOST_NO_INCLASS_MEMBER_INITIALIZATION

       // Although sunpro 5.2 supports the syntax for
       // partial specialization, it often seems to
       // bind to the wrong specialization.  Better
       // to disable it until suppport becomes more stable
       // (J Maddock 6th May 2001).
#      define NDNBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#    endif

#    if (__SUNPRO_CC <= 0x530) 
       // Requesting debug info (-g) with Boost.Python results
       // in an internal compiler error for "static const"
       // initialized in-class.
       //    >> Assertion:   (../links/dbg_cstabs.cc, line 611)
       //         while processing ../test.cpp at line 0.
       // (Jens Maurer according to Gottfried Ganssauge 04 Mar 2002)
#      define NDNBOOST_NO_INCLASS_MEMBER_INITIALIZATION

       // SunPro 5.3 has better support for partial specialization,
       // but breaks when compiling std::less<shared_ptr<T> >
       // (Jens Maurer 4 Nov 2001).

       // std::less specialization fixed as reported by George
       // Heintzelman; partial specialization re-enabled
       // (Peter Dimov 17 Jan 2002)

//#      define NDNBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

       // integral constant expressions with 64 bit numbers fail
#      define NDNBOOST_NO_INTEGRAL_INT64_T
#    endif

#    if (__SUNPRO_CC < 0x570) 
#      define NDNBOOST_NO_TEMPLATE_TEMPLATES
       // see http://lists.boost.org/MailArchives/boost/msg47184.php
       // and http://lists.boost.org/MailArchives/boost/msg47220.php
#      define NDNBOOST_NO_INCLASS_MEMBER_INITIALIZATION
#      define NDNBOOST_NO_SFINAE
#      define NDNBOOST_NO_ARRAY_TYPE_SPECIALIZATIONS
#    endif
#    if (__SUNPRO_CC <= 0x580) 
#      define NDNBOOST_NO_IS_ABSTRACT
#    endif

#    if (__SUNPRO_CC <= 0x5100)
       // Sun 5.10 may not correctly value-initialize objects of
       // some user defined types, as was reported in April 2010
       // (CR 6947016), and confirmed by Steve Clamage.
       // (Niels Dekker, LKEB, May 2010).
#      define NDNBOOST_NO_COMPLETE_VALUE_INITIALIZATION
#    endif

//
// Dynamic shared object (DSO) and dynamic-link library (DLL) support
//
#if __SUNPRO_CC > 0x500
#  define NDNBOOST_SYMBOL_EXPORT __global
#  define NDNBOOST_SYMBOL_IMPORT __global
#  define NDNBOOST_SYMBOL_VISIBLE __global
#endif



//
// Issues that effect all known versions:
//
#define NDNBOOST_NO_TWO_PHASE_NAME_LOOKUP
#define NDNBOOST_NO_ADL_BARRIER

//
// C++0x features
//
#  define NDNBOOST_HAS_LONG_LONG

#define NDNBOOST_NO_CXX11_AUTO_DECLARATIONS
#define NDNBOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define NDNBOOST_NO_CXX11_CHAR16_T
#define NDNBOOST_NO_CXX11_CHAR32_T
#define NDNBOOST_NO_CXX11_CONSTEXPR
#define NDNBOOST_NO_CXX11_DECLTYPE
#define NDNBOOST_NO_CXX11_DECLTYPE_N3276
#define NDNBOOST_NO_CXX11_DEFAULTED_FUNCTIONS
#define NDNBOOST_NO_CXX11_DELETED_FUNCTIONS
#define NDNBOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#define NDNBOOST_NO_CXX11_EXTERN_TEMPLATE
#define NDNBOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define NDNBOOST_NO_CXX11_HDR_INITIALIZER_LIST
#define NDNBOOST_NO_CXX11_LAMBDAS
#define NDNBOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#define NDNBOOST_NO_CXX11_NOEXCEPT
#define NDNBOOST_NO_CXX11_NULLPTR
#define NDNBOOST_NO_CXX11_RANGE_BASED_FOR
#define NDNBOOST_NO_CXX11_RAW_LITERALS
#define NDNBOOST_NO_CXX11_RVALUE_REFERENCES
#define NDNBOOST_NO_CXX11_SCOPED_ENUMS
#define NDNBOOST_NO_SFINAE_EXPR
#define NDNBOOST_NO_CXX11_STATIC_ASSERT
#define NDNBOOST_NO_CXX11_TEMPLATE_ALIASES
#define NDNBOOST_NO_CXX11_UNICODE_LITERALS
#define NDNBOOST_NO_CXX11_VARIADIC_TEMPLATES
#define NDNBOOST_NO_CXX11_VARIADIC_MACROS
#define NDNBOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
#define NDNBOOST_NO_CXX11_USER_DEFINED_LITERALS

//
// Version
//

#define NDNBOOST_COMPILER "Sun compiler version " NDNBOOST_STRINGIZE(__SUNPRO_CC)

//
// versions check:
// we don't support sunpro prior to version 4:
#if __SUNPRO_CC < 0x400
#error "Compiler not supported or configured - please reconfigure"
#endif
//
// last known and checked version is 0x590:
#if (__SUNPRO_CC > 0x590)
#  if defined(NDNBOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  endif
#endif
