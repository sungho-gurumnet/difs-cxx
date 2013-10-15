
#ifndef NDNBOOST_MPL_AUX_LARGEST_INT_HPP_INCLUDED
#define NDNBOOST_MPL_AUX_LARGEST_INT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: largest_int.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <ndnboost/mpl/if.hpp>
#include <ndnboost/mpl/int.hpp>
#include <ndnboost/mpl/aux_/config/integral.hpp>
#include <ndnboost/config.hpp>

namespace ndnboost { namespace mpl { namespace aux {

template< typename T > struct integral_rank;

template<> struct integral_rank<bool>           : int_<1> {};
template<> struct integral_rank<signed char>    : int_<2> {};
template<> struct integral_rank<char>           : int_<3> {};
template<> struct integral_rank<unsigned char>  : int_<4> {};
#if !defined(NDNBOOST_NO_INTRINSIC_WCHAR_T)
template<> struct integral_rank<wchar_t>        : int_<5> {};
#endif
template<> struct integral_rank<short>          : int_<6> {};
template<> struct integral_rank<unsigned short> : int_<7> {};
template<> struct integral_rank<int>            : int_<8> {};
template<> struct integral_rank<unsigned int>   : int_<9> {};
template<> struct integral_rank<long>           : int_<10> {};
template<> struct integral_rank<unsigned long>  : int_<11> {};

#if defined(NDNBOOST_HAS_LONG_LONG)
template<> struct integral_rank<long_long_type> : int_<12> {};
template<> struct integral_rank<ulong_long_type>: int_<13> {};
#endif

template< typename T1, typename T2 > struct largest_int
#if !defined(NDNBOOST_MPL_CFG_NO_NESTED_VALUE_ARITHMETIC)
    : if_c< 
          ( integral_rank<T1>::value >= integral_rank<T2>::value )
        , T1
        , T2
        >
{
#else
{
    enum { rank1 = integral_rank<T1>::value };
    enum { rank2 = integral_rank<T2>::value };
    typedef typename if_c< (rank1 >= rank2),T1,T2 >::type type;
#endif
};

}}}

#endif // NDNBOOST_MPL_AUX_LARGEST_INT_HPP_INCLUDED
