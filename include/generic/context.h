//---------------------------------------------------------------------------
#pragma once
#ifndef __dcc_generic_context__
#define __dcc_generic_context__
//---------------------------------------------------------------------------
#if (__cplusplus < 201103L)
#error C++11 required at least
#endif
//---------------------------------------------------------------------------
#include <type_traits>
#include <cassert>
//---------------------------------------------------------------------------
#ifdef _MSC_VER
#include "clspec/msvc.h"
#elif defined(__MINGW32__)
#include "clspec/mingw.h"
#elif defined(__GNUC__)
#include "clspec/gnuc.h"
#else
#error unknown compiler
#endif
//---------------------------------------------------------------------------
#ifdef __x64_platform__
#define atomic_xchg atomic_xchg64
#define atomic_add atomic_add64
#define atomic_sub atomic_sub64
#define atomic_inc atomic_inc64
#define atomic_dec atomic_dec64
#define atomic_and atomic_and64
#define atomic_or atomic_or64
#define atomic_xor atomic_xor64
#define atomic_cmpxchg atomic_cmpxchg64
#define atomic_cmpxchg_pointer (void*)atomic_cmpxchg64
#else
#define atomic_xchg atomic_xchg32
#define atomic_add atomic_add32
#define atomic_sub atomic_sub32
#define atomic_inc atomic_inc32
#define atomic_dec atomic_dec32
#define atomic_and atomic_and32
#define atomic_or atomic_or32
#define atomic_xor atomic_xor32
#define atomic_cmpxchg atomic_cmpxchg32
#define atomic_cmpxchg_pointer (void*)atomic_cmpxchg32
#endif
//---------------------------------------------------------------------------
#if (__cplusplus == 201103L)
template< bool B, class T = void >
using enable_if_t = typename enable_if<B, T>::type;
#endif
//---------------------------------------------------------------------------
#include "macro.h"
//---------------------------------------------------------------------------
#endif // __dcc_generic_context__
