#ifndef NDNBOOST_DETAIL_SP_TYPEINFO_HPP_INCLUDED
#define NDNBOOST_DETAIL_SP_TYPEINFO_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//  detail/sp_typeinfo.hpp
//
//  Copyright 2007 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <ndnboost/config.hpp>

#if defined( NDNBOOST_NO_TYPEID )

#include <ndnboost/current_function.hpp>
#include <functional>

namespace ndnboost
{

namespace detail
{

class sp_typeinfo
{
private:

    sp_typeinfo( sp_typeinfo const& );
    sp_typeinfo& operator=( sp_typeinfo const& );

    char const * name_;

public:

    explicit sp_typeinfo( char const * name ): name_( name )
    {
    }

    bool operator==( sp_typeinfo const& rhs ) const
    {
        return this == &rhs;
    }

    bool operator!=( sp_typeinfo const& rhs ) const
    {
        return this != &rhs;
    }

    bool before( sp_typeinfo const& rhs ) const
    {
        return std::less< sp_typeinfo const* >()( this, &rhs );
    }

    char const* name() const
    {
        return name_;
    }
};

template<class T> struct sp_typeid_
{
    static sp_typeinfo ti_;

    static char const * name()
    {
        return NDNBOOST_CURRENT_FUNCTION;
    }
};

#if defined(__SUNPRO_CC)
// see #4199, the Sun Studio compiler gets confused about static initialization 
// constructor arguments. But an assignment works just fine. 
template<class T> sp_typeinfo sp_typeid_< T >::ti_ = sp_typeid_< T >::name();
#else
template<class T> sp_typeinfo sp_typeid_< T >::ti_(sp_typeid_< T >::name());
#endif

template<class T> struct sp_typeid_< T & >: sp_typeid_< T >
{
};

template<class T> struct sp_typeid_< T const >: sp_typeid_< T >
{
};

template<class T> struct sp_typeid_< T volatile >: sp_typeid_< T >
{
};

template<class T> struct sp_typeid_< T const volatile >: sp_typeid_< T >
{
};

} // namespace detail

} // namespace ndnboost

#define NDNBOOST_SP_TYPEID(T) (ndnboost::detail::sp_typeid_<T>::ti_)

#else

#include <typeinfo>

namespace ndnboost
{

namespace detail
{

#if defined( NDNBOOST_NO_STD_TYPEINFO )

typedef ::type_info sp_typeinfo;

#else

typedef std::type_info sp_typeinfo;

#endif

} // namespace detail

} // namespace ndnboost

#define NDNBOOST_SP_TYPEID(T) typeid(T)

#endif

#endif  // #ifndef NDNBOOST_DETAIL_SP_TYPEINFO_HPP_INCLUDED
