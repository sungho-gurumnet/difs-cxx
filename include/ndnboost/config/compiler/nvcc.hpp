//  (C) Copyright Eric Jourdanneau, Joel Falcou 2010
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  NVIDIA CUDA C++ compiler setup

#ifndef NDNBOOST_COMPILER
#  define NDNBOOST_COMPILER "NVIDIA CUDA C++ Compiler"
#endif

// NVIDIA Specific support
// NDNBOOST_GPU_ENABLED : Flag a function or a method as being enabled on the host and device
#define NDNBOOST_GPU_ENABLED __host__ __device__

// Boost support macro for NVCC 
// NVCC Basically behaves like some flavor of MSVC6 + some specific quirks
#ifdef __GNUC__

#include <ndnboost/config/compiler/gcc.hpp>

#elif defined(_MSC_VER)

#include <ndnboost/config/compiler/visualc.hpp>

#endif
