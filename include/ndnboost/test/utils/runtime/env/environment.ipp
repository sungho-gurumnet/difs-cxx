//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 57992 $
//
//  Description : implements model of program environment 
// ***************************************************************************

#ifndef NDNBOOST_RT_ENV_ENVIRONMENT_IPP_062904GER
#define NDNBOOST_RT_ENV_ENVIRONMENT_IPP_062904GER

// Boost.Runtime.Parameter
#include <ndnboost/test/utils/runtime/config.hpp>
#include <ndnboost/test/utils/runtime/validation.hpp>

#include <ndnboost/test/utils/runtime/env/variable.hpp>

// Boost.Test
#include <ndnboost/test/utils/basic_cstring/compare.hpp>
#include <ndnboost/test/utils/basic_cstring/io.hpp>

// STL
#include <map>
#include <list>

namespace ndnboost {

namespace NDNBOOST_RT_PARAM_NAMESPACE {

namespace environment {

// ************************************************************************** //
// **************             runtime::environment             ************** //
// ************************************************************************** //

namespace rt_env_detail {

typedef std::map<cstring,rt_env_detail::variable_data> registry;
typedef std::list<dstring> keys;

NDNBOOST_RT_PARAM_INLINE registry& s_registry()    { static registry instance; return instance; }
NDNBOOST_RT_PARAM_INLINE keys&     s_keys()        { static keys instance; return instance; }

NDNBOOST_RT_PARAM_INLINE variable_data&
new_var_record( cstring var_name )
{
    // save the name in list of keys
    s_keys().push_back( dstring() );
    dstring& key = s_keys().back();
    assign_op( key, var_name, 0 );

    // create and return new record
    variable_data& new_var_data = s_registry()[key];
    
    new_var_data.m_var_name = key;
    
    return new_var_data;
}

//____________________________________________________________________________//

NDNBOOST_RT_PARAM_INLINE variable_data*
find_var_record( cstring var_name )
{
    registry::iterator it = s_registry().find( var_name );

    return it == s_registry().end() ? 0 : &(it->second);
}

//____________________________________________________________________________//

#ifdef NDNBOOST_MSVC 
#pragma warning(push) 
#pragma warning(disable:4996) // getenv
#endif

NDNBOOST_RT_PARAM_INLINE cstring
sys_read_var( cstring var_name )
{
    using namespace std;
    return NDNBOOST_RT_PARAM_GETENV( var_name.begin() );
}

#ifdef NDNBOOST_MSVC 
#pragma warning(pop) 
#endif
//____________________________________________________________________________//

NDNBOOST_RT_PARAM_INLINE void
sys_write_var( cstring var_name, format_stream& var_value )
{
    NDNBOOST_RT_PARAM_PUTENV( var_name, cstring( var_value.str() ) );
}

//____________________________________________________________________________//

} // namespace rt_env_detail

NDNBOOST_RT_PARAM_INLINE variable_base
var( cstring var_name )
{
    rt_env_detail::variable_data* vd = rt_env_detail::find_var_record( var_name );

    NDNBOOST_RT_PARAM_VALIDATE_LOGIC( !!vd,
                                   NDNBOOST_RT_PARAM_LITERAL( "First access to the environment variable " ) 
                                        << var_name << NDNBOOST_RT_PARAM_LITERAL( " should be typed" ) );

    return variable_base( *vd );
}

//____________________________________________________________________________//

} // namespace environment

} // namespace NDNBOOST_RT_PARAM_NAMESPACE

} // namespace ndnboost

#endif // NDNBOOST_RT_ENV_ENVIRONMENT_IPP_062904GER
