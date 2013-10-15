//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 54633 $
//
//  Description : environment subsystem forward declarations
// ***************************************************************************

#ifndef NDNBOOST_RT_ENV_FWD_HPP_062604GER
#define NDNBOOST_RT_ENV_FWD_HPP_062604GER

#ifdef UNDER_CE
#error Windows CE does not support environment variables.
#endif

// Boost.Runtime.Parameter
#include <ndnboost/test/utils/runtime/config.hpp>

namespace ndnboost {

namespace NDNBOOST_RT_PARAM_NAMESPACE {

namespace environment {

class variable_base;
variable_base var( cstring var_name );

namespace rt_env_detail {

struct variable_data;

variable_data&  new_var_record( cstring var_name );
variable_data*  find_var_record( cstring var_name );

cstring         sys_read_var( cstring var_name );
void            sys_write_var( cstring var_name, format_stream& var_value );

}

template <typename T> class variable;

} // namespace environment

} // namespace NDNBOOST_RT_PARAM_NAMESPACE

} // namespace ndnboost

#endif // NDNBOOST_RT_ENV_FWD_HPP_062604GER
