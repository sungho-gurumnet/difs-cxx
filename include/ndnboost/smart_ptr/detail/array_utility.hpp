/*
 * Copyright (c) 2012 Glen Joseph Fernandes 
 * glenfe at live dot com
 *
 * Distributed under the Boost Software License, 
 * Version 1.0. (See accompanying file LICENSE_1_0.txt 
 * or copy at http://boost.org/LICENSE_1_0.txt)
 */
#ifndef NDNBOOST_SMART_PTR_DETAIL_ARRAY_UTILITY_HPP
#define NDNBOOST_SMART_PTR_DETAIL_ARRAY_UTILITY_HPP

#include <ndnboost/config.hpp>
#include <ndnboost/type_traits/has_trivial_constructor.hpp>
#include <ndnboost/type_traits/has_trivial_destructor.hpp>

namespace ndnboost {
    namespace detail {
        template<typename T>
        inline void array_destroy(T*, std::size_t, ndnboost::true_type) {
        }
        template<typename T>
        inline void array_destroy(T* memory, std::size_t size, ndnboost::false_type) {
            for (std::size_t i = size; i > 0; ) {
                memory[--i].~T();
            }
        }
        template<typename T>
        inline void array_destroy(T* memory, std::size_t size) {
            ndnboost::has_trivial_destructor<T> type;
            array_destroy(memory, size, type);
        }
        template<typename T>
        inline void array_init(T* memory, std::size_t size, ndnboost::true_type) {
            for (std::size_t i = 0; i < size; i++) {
                memory[i] = T();
            }
        }
        template<typename T>
        inline void array_init(T* memory, std::size_t size, ndnboost::false_type) {
#if !defined(NDNBOOST_NO_EXCEPTIONS)
            std::size_t i = 0;
            try {
                for (; i < size; i++) {
                    void* p1 = memory + i;
                    ::new(p1) T();
                }
            } catch (...) {
                array_destroy(memory, i);
                throw;
            }
#else
            for (std::size_t i = 0; i < size; i++) {
                void* p1 = memory + i;
                ::new(p1) T();
            }
#endif
        }
        template<typename T>
        inline void array_init(T* memory, std::size_t size) {
            ndnboost::has_trivial_default_constructor<T> type;            
            array_init(memory, size, type);
        }
#if !defined(NDNBOOST_NO_CXX11_RVALUE_REFERENCES)
        template<typename T>
        inline void array_init_value(T* memory, std::size_t size, T&& value) {
#if !defined(NDNBOOST_NO_EXCEPTIONS)
            std::size_t i = 0;
            try {
                for (; i < size; i++) {
                    void* p1 = memory + i;
                    ::new(p1) T(value);
                }
            } catch (...) {
                array_destroy(memory, i);
                throw;
            }
#else
            for (std::size_t i = 0; i < size; i++) {
                void* p1 = memory + i;
                ::new(p1) T(value);
            }
#endif
        }
#if !defined(NDNBOOST_NO_CXX11_VARIADIC_TEMPLATES)
        template<typename T, typename... Args>
        inline void array_init_args(T* memory, std::size_t size, Args&&... args) {
#if !defined(NDNBOOST_NO_EXCEPTIONS)
            std::size_t i = 0;
            try {
                for (; i < size; i++) {
                    void* p1 = memory + i;
                    ::new(p1) T(args...);
                }
            } catch (...) {
                array_destroy(memory, i);
                throw;
            }
#else
            for (std::size_t i = 0; i < size; i++) {
                void* p1 = memory + i;
                ::new(p1) T(args...);
            }
#endif
        }
#endif
#endif
        template<typename T>
        inline void array_init_list(T* memory, std::size_t size, const T* list) {
#if !defined(NDNBOOST_NO_EXCEPTIONS)
            std::size_t i = 0;
            try {
                for (; i < size; i++) {
                    void* p1 = memory + i;
                    ::new(p1) T(list[i]);
                }
            } catch (...) {
                array_destroy(memory, i);
                throw;
            }
#else
            for (std::size_t i = 0; i < size; i++) {
                void* p1 = memory + i;
                ::new(p1) T(list[i]);
            }
#endif
        }
        template<typename T, std::size_t N>
        inline void array_init_list(T* memory, std::size_t size, const T* list) {
#if !defined(NDNBOOST_NO_EXCEPTIONS)
            std::size_t i = 0;
            try {
                for (; i < size; i++) {
                    void* p1 = memory + i;
                    ::new(p1) T(list[i % N]);
                }
            } catch (...) {
                array_destroy(memory, i);
                throw;
            }
#else
            for (std::size_t i = 0; i < size; i++) {
                void* p1 = memory + i;
                ::new(p1) T(list[i % N]);
            }
#endif
        }
        template<typename T>
        inline void array_noinit(T*, std::size_t, ndnboost::true_type) {
        }
        template<typename T>
        inline void array_noinit(T* memory, std::size_t size, ndnboost::false_type) {
#if !defined(NDNBOOST_NO_EXCEPTIONS)
            std::size_t i = 0;
            try {
                for (; i < size; i++) {
                    void* p1 = memory + i;
                    ::new(p1) T;
                }
            } catch (...) {
                array_destroy(memory, i);
                throw;
            }
#else
            for (std::size_t i = 0; i < size; i++) {
                void* p1 = memory + i;
                ::new(p1) T;
            }
#endif
        }
        template<typename T>
        inline void array_noinit(T* memory, std::size_t size) {
            ndnboost::has_trivial_default_constructor<T> type;
            array_noinit(memory, size, type);
        }
    }
}

#endif
