//  (C) Copyright Noel Belcourt 2007.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  PGI C++ compiler setup:

#define NDNBOOST_COMPILER_VERSION __PGIC__##__PGIC_MINOR__
#define NDNBOOST_COMPILER "PGI compiler version " NDNBOOST_STRINGIZE(NDNBOOST_COMPILER_VERSION)

//
// Threading support:
// Turn this on unconditionally here, it will get turned off again later
// if no threading API is detected.
//

#if __PGIC__ >= 11

// options requested by configure --enable-test
#define NDNBOOST_HAS_PTHREADS
#define NDNBOOST_HAS_THREADS
#define NDNBOOST_HAS_PTHREAD_YIELD
#define NDNBOOST_HAS_NRVO
#define NDNBOOST_HAS_LONG_LONG

// options --enable-test wants undefined
#undef NDNBOOST_NO_STDC_NAMESPACE
#undef NDNBOOST_NO_EXCEPTION_STD_NAMESPACE
#undef NDNBOOST_DEDUCED_TYPENAME

#define NDNBOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#define NDNBOOST_NO_TWO_PHASE_NAME_LOOKUP
#define NDNBOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define NDNBOOST_NO_CXX11_AUTO_DECLARATIONS

#elif __PGIC__ >= 10

// options requested by configure --enable-test
#define NDNBOOST_HAS_THREADS
#define NDNBOOST_HAS_NRVO
#define NDNBOOST_HAS_LONG_LONG

// options --enable-test wants undefined
#undef NDNBOOST_NO_STDC_NAMESPACE
#undef NDNBOOST_NO_EXCEPTION_STD_NAMESPACE
#undef NDNBOOST_DEDUCED_TYPENAME

#elif __PGIC__ >= 7

#define NDNBOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#define NDNBOOST_NO_TWO_PHASE_NAME_LOOKUP
#define NDNBOOST_NO_SWPRINTF
#define NDNBOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define NDNBOOST_NO_CXX11_AUTO_DECLARATIONS

#else

#  error "Pgi compiler not configured - please reconfigure"

#endif
//
// C++0x features
//
//   See boost\config\suffix.hpp for NDNBOOST_NO_LONG_LONG
//
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
#define NDNBOOST_NO_CXX11_LAMBDAS
#define NDNBOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#define NDNBOOST_NO_CXX11_NOEXCEPT
#define NDNBOOST_NO_CXX11_NULLPTR
#define NDNBOOST_NO_CXX11_NUMERIC_LIMITS
#define NDNBOOST_NO_CXX11_RANGE_BASED_FOR
#define NDNBOOST_NO_CXX11_RAW_LITERALS
#define NDNBOOST_NO_CXX11_RVALUE_REFERENCES
#define NDNBOOST_NO_CXX11_SCOPED_ENUMS
#define NDNBOOST_NO_SFINAE_EXPR
#define NDNBOOST_NO_CXX11_STATIC_ASSERT
#define NDNBOOST_NO_SWPRINTF
#define NDNBOOST_NO_CXX11_TEMPLATE_ALIASES
#define NDNBOOST_NO_CXX11_UNICODE_LITERALS
#define NDNBOOST_NO_CXX11_VARIADIC_TEMPLATES
#define NDNBOOST_NO_CXX11_VARIADIC_MACROS
#define NDNBOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX

#define NDNBOOST_NO_CXX11_HDR_UNORDERED_SET
#define NDNBOOST_NO_CXX11_HDR_UNORDERED_MAP
#define NDNBOOST_NO_CXX11_HDR_TYPEINDEX
#define NDNBOOST_NO_CXX11_HDR_TYPE_TRAITS
#define NDNBOOST_NO_CXX11_HDR_TUPLE
#define NDNBOOST_NO_CXX11_HDR_THREAD
#define NDNBOOST_NO_CXX11_HDR_SYSTEM_ERROR
#define NDNBOOST_NO_CXX11_HDR_REGEX
#define NDNBOOST_NO_CXX11_HDR_RATIO
#define NDNBOOST_NO_CXX11_HDR_RANDOM
#define NDNBOOST_NO_CXX11_HDR_MUTEX
#define NDNBOOST_NO_CXX11_HDR_INITIALIZER_LIST
#define NDNBOOST_NO_CXX11_HDR_FUTURE
#define NDNBOOST_NO_CXX11_HDR_FORWARD_LIST
#define NDNBOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#define NDNBOOST_NO_CXX11_HDR_CODECVT
#define NDNBOOST_NO_CXX11_HDR_CHRONO
#define NDNBOOST_NO_CXX11_HDR_ARRAY
#define NDNBOOST_NO_CXX11_USER_DEFINED_LITERALS

//
// version check:
// probably nothing to do here?

