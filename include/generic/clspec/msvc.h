//---------------------------------------------------------------------------
// platform detection
#if defined(_WIN32_WCE)
// windows ce (mobile)?
#define __wince_generic__
#error windows ce platform is not supported yet.
#elif defined(_MANAGED)
#error clr is not supported.
#elif defined(_WIN32)
#define __win_generic__
#ifdef _WIN64
#define __x64_platform__
typedef int64_t signed_ptr;
typedef uint64_t unsigned_ptr;
#else
#define __x32_platform__
typedef int32_t signed_ptr;
typedef uint32_t unsigned_ptr;
#endif
#else
#error unknown windows platform.
#endif
//---------------------------------------------------------------------------
// processor detection
#ifdef _M_IX86
#include "uarch/i386.h"
#define __intel_processor__
#if _M_IX86 == 300
#define __processor_architecture__ __i80386__
#elif _M_IX86 == 400
#define __processor_architecture__ __i80486__
#elif _M_IX86 == 500
#define __processor_architecture__ __i80586__
#elif _M_IX86 == 600
#define __processor_architecture__ __i80686__
#else
#error unknown intel processor architecture
#endif
#elif defined(_M_IA64)
//TODO: itanium support
#define __intel_processor__
#define __itanium_generic__
#error Itanium processor architecture is not supported yet.
#elif defined(_M_X64)||defined(_M_AMD64)
#define __amd64_generic__
#define __intel_processor__
#elif defined(_M_ARM)
//TODO: ARM support
#include "uarch/arm.h"
#define __arm_processor__
#define __processor_architecture__ _M_ARM
#error ARM processor architecture is not supported yet.
#elif defined(_M_MRX000)
#include "uarch/mips.h"
#define __processor_architecture__ _M_MRX000
#error MIPS processor architecture is not supported yet.
#elif defined(_M_PPC)
#include "arch/ppc.h"
#define __processor_architecture__ _M_PPC
#error PowerPC processor architecture is not supported yet.
#elif defined(_M_MPPC)
#include "uarch/ppc.h"
#define __processor_architecture__ _M_PPC
#error Power Macintosh processor architecture is not supported yet.
#elif defined(_M_ALPHA)
#define __alpha_processor__
#error Alpha processor architecture is not supported yet.
#else
#error unknown processor architecture.
#endif
//---------------------------------------------------------------------------
#ifndef __MINGW32__
#include <intrin.h>
#include <string.h>
#include <windows.h>
//---------------------------------------------------------------------------
#define __msvc_generic__
//---------------------------------------------------------------------------
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchange8)
#pragma intrinsic(_InterlockedExchange16)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedExchangeAdd8)
#pragma intrinsic(_InterlockedExchangeAdd16)
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedIncrement16)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedDecrement16)
#pragma intrinsic(_InterlockedAnd)
#pragma intrinsic(_InterlockedAnd8)
#pragma intrinsic(_InterlockedAnd16)
#pragma intrinsic(_InterlockedOr)
#pragma intrinsic(_InterlockedOr8)
#pragma intrinsic(_InterlockedOr16)
#pragma intrinsic(_InterlockedXor)
#pragma intrinsic(_InterlockedXor8)
#pragma intrinsic(_InterlockedXor16)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedCompareExchange8)
#pragma intrinsic(_InterlockedCompareExchange16)
#pragma intrinsic(_InterlockedCompareExchange64)
//---------------------------------------------------------------------------
#define atomic_xchg8(target, value) _InterlockedExchange8((CHAR volatile *)(target),(CHAR)(value))
#define atomic_xchg16(target, value) _InterlockedExchange16((SHORT volatile *)(target),(SHORT)(value))
#define atomic_xchg32(target, value) _InterlockedExchange((LONG volatile*)(target),(LONG)(value))
#define atomic_add8(target, value) _InterlockedExchangeAdd8((CHAR volatile *)(target),(CHAR)(value))
#define atomic_add16(target, value) _InterlockedExchangeAdd16((SHORT volatile *)(target),(SHORT)(value))
#define atomic_add32(target, value) _InterlockedExchangeAdd((LONG volatile*)(target),(LONG)(value))
#define atomic_sub8(target, value) atomic_add8(target, -value)
#define atomic_sub16(target, value) atomic_add16(target, -value)
#define atomic_sub32(target, value) atomic_add32(target, -value)
#define atomic_inc8(addend) atomic_add8(addend, 1)
#define atomic_inc16(addend) _InterlockedIncrement16((SHORT volatile *)(addend))
#define atomic_inc32(addend) _InterlockedIncrement((LONG volatile*)(addend))
#define atomic_dec8(addend) atomic_add8(addend, -1)
#define atomic_dec16(addend) _InterlockedDecrement16((SHORT volatile *)(addend))
#define atomic_dec32(addend) _InterlockedDecrement((LONG volatile*)(addend))
#define atomic_and8(destination, value) _InterlockedAnd8((CHAR volatile*)(destination),(CHAR)(value))
#define atomic_and16(destination, value) _InterlockedAnd16((SHORT volatile*)(destination),(SHORT)(value))
#define atomic_and32(destination, value) _InterlockedAnd((LONG volatile*)(destination),(LONG)(value))
#define atomic_or8(destination, value) _InterlockedOr8((CHAR volatile*)(destination),(CHAR)(value))
#define atomic_or16(destination, value) _InterlockedOr16((SHORT volatile*)(destination),(SHORT)(value))
#define atomic_or32(destination, value) _InterlockedOr((LONG volatile*)(destination),(LONG)(value))
#define atomic_xor8(destination, value) _InterlockedXor8((CHAR volatile*)(destination),(CHAR)(value))
#define atomic_xor16(destination, value) _InterlockedXor16((SHORT volatile*)(destination),(SHORT)(value))
#define atomic_xor32(destination, value) _InterlockedXor((LONG volatile*)(destination),(LONG)(value))
#define atomic_cmpxchg8(target, exchange, comperand) _InterlockedCompareExchange8((CHAR volatile *)(target),(CHAR)(exchange),(CHAR)(comperand))
#define atomic_cmpxchg16(target, exchange, comperand) _InterlockedCompareExchange16((SHORT volatile *)(target),(SHORT)(exchange),(SHORT)(comperand))
#define atomic_cmpxchg32(target, exchange, comperand) _InterlockedCompareExchange((LONG volatile *)(target),(LONG)(exchange),(LONG)(comperand))
#define atomic_cmpxchg64(target, exchange, comperand) _InterlockedCompareExchange64((LONG64 volatile*)(target),(LONG64)(exchange),(LONG64)(comperand))
//---------------------------------------------------------------------------
#ifdef __x64_platform__
#pragma intrinsic(_InterlockedExchange64)
#pragma intrinsic(_InterlockedExchangeAdd64)
#pragma intrinsic(_InterlockedAnd64)
#pragma intrinsic(_InterlockedOr64)
#pragma intrinsic(_InterlockedXor64)
#pragma intrinsic(_InterlockedIncrement64)
#pragma intrinsic(_InterlockedDecrement64)
#define atomic_xchg64(target, value) _InterlockedExchange64((LONG64 volatile*)(target),(LONG64)(value))
#define atomic_add64(target, value) _InterlockedExchangeAdd64((LONG64 volatile*)(target),(LONG64)(value))
#define atomic_inc64(addend) _InterlockedIncrement64((LONG64 volatile*)(addend))
#define atomic_dec64(addend) _InterlockedDecrement64((LONG64 volatile*)(addend))
#define atomic_and64(destination, value) _InterlockedAnd64((LONG64 volatile*)(destination),(LONG64)(value))
#define atomic_or64(destination, value) _InterlockedOr64((LONG64 volatile*)(destination),(LONG64)(value))
#define atomic_xor64(destination, value) _InterlockedXor64((LONG64 volatile*)(destination),(LONG64)(value))
#else
#define atomic_xchg64(target, value) InterlockedExchange64((LONG64 volatile*)(target),(LONG64)(value))
#define atomic_add64(target, value) InterlockedExchangeAdd64((LONG64 volatile*)(target),(LONG64)(value))
#define atomic_inc64(addend) InterlockedIncrement64((LONG64 volatile*)(addend))
#define atomic_dec64(addend) InterlockedDecrement64((LONG64 volatile*)(addend))
#define atomic_and64(destination, value) InterlockedAnd64((LONG64 volatile*)(destination),(LONG64)(value))
#define atomic_or64(destination, value) InterlockedOr64((LONG64 volatile*)(destination),(LONG64)(value))
#define atomic_xor64(destination, value) InterlockedXor64((LONG64 volatile*)(destination),(LONG64)(value))
#endif
#define atomic_sub64(target, value) atomic_add64(target, -value)
#define atomic_xchg_pointer(target, value)  InterlockedExchangePointer((volatile PVOID*)(target),(PVOID)(value))
#pragma intrinsic(memcmp,memcpy,memset,strlen)
//---------------------------------------------------------------------------
#pragma warning( disable : 4250 )
#define DENOTATION __FUNCTION__
#define DEMANGLED __FUNCSIG__
//#define SYMBOL __FUNCDNAME__ 
//---------------------------------------------------------------------------
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#define LOCAL
//---------------------------------------------------------------------------
#define __fast __fastcall
#define __thread __declspec(thread)
#define __noinline __declspec(noinline)
#define __noreturn __declspec(noreturn)
#endif
//---------------------------------------------------------------------------