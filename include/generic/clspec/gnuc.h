//---------------------------------------------------------------------------
#ifndef __MINGW32__
#if defined(__linux__) || defined(__CYGWIN__)
#include <stdint.h>
#include <endian.h>
#ifdef __linux__
#include <byteswap.h>
#define __linux_generic__
#endif
#else
#include <inttypes.h>
#if defined(sun) || defined(__sun)
#define __sun_generic__
#if defined(__SVR4) || defined(__svr4__)
#define __solaris__
#endif
#elif defined(__amigaos__)
#define __amiga_generic__
#elif defined(__unix__)
#include <sys/param.h>
#include <sys/stdint.h>
#include <sys/endian.h>
#define __unix_generic__
#if defined(__APPLE__) && defined(__MACH__)
#define __osx_generic__
#include <TargetConditionals.h>
#elif defined(BSD)
#define __bsd_generic__
#if defined(__FreeBSD__)
#define __freebsd__
#elif defined(__NetBSD__)
#define __netbsd__
#elif defined(__OpenBSD__)
#define __openbsd__
#endif
#endif
#else
#error unknown platform.
#endif
#include <unistd.h>
#include <string.h>
#endif
#include <limits.h>
//---------------------------------------------------------------------------
#if defined(__ia64__)
//TODO: itanium support
#define __intel_processor__
#define __itanium_generic__
#error Itanium processor architecture is not supported yet.
#elif defined(__amd64__) || defined(__x86_64__)
#define __intel_processor__
#define __amd64_generic__
#elif defined(__i386__)
#include "uarch/i386.h"
#if defined(__i386__)
#define __processor_architecture__ __i80386__
#elif defined(__i486__)
#define __processor_architecture__ __i80486__
#elif defined(__i586__)
#define __processor_architecture__ __i80586__
#elif defined(__i686__)
#define __processor_architecture__ __i80686__
#else
#error unknown intel processor architecture
#endif
#elif defined(__arm__) || defined(__aarch64__)
//TODO: ARM support
#include "uarch/arm.h"
#define __arm_processor__
#ifdef __ARM_ARCH_2__
#define __processor_architecture__ __armv2__
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
#define __processor_architecture__ __armv3__
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
#define __processor_architecture__ __armv4__
#elif defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5E__)
#define __processor_architecture__ __armv5__
#elif defined(__ARM_ARCH_6__) || \
      defined(__ARM_ARCH_6J__) || \
      defined(__ARM_ARCH_6K__) || \
      defined(__ARM_ARCH_6Z__) || \
      defined(__ARM_ARCH_6ZK__) || \
      defined(__ARM_ARCH_6T2__)
#define __processor_architecture__ __armv6__
#elif defined(__ARM_ARCH_7__) || \
      defined(__ARM_ARCH_7A__) || \
      defined(__ARM_ARCH_7R__) || \
      defined(__ARM_ARCH_7M__) || \
      defined(__ARM_ARCH_7S__)
#define __processor_architecture__ __armv7__
#else
#error unknown ARM processor architecture.
#endif
#error ARM processor architecture is not supported yet.
#elif defined(__alpha__)
#define __alpha_processor__
#define __alphav4__ 4
#define __alphav5__ 5
#define __alphav6__ 6
#if defined(__alpha_ev4__)
#define __processor_architecture__ __alphav4__
#elif defined(__alpha_ev5__)
#define __processor_architecture__ __alphav5__
#elif defined(__alpha_ev6__)
#define __processor_architecture__ __alphav6__
#else
#error unknown Alpha processor architecture.
#endif
#error Alpha processor architecture is not supported yet.
#elif defined(__convex__)
#include "uarch/convex.h"
#if defined(__convex_c1__)
#define __processor_architecture__ __convex_C01__
#elif defined(__convex_c2__)
#define __processor_architecture__ __convex_C02__
#elif defined(__convex_c32__)
#define __processor_architecture__ __convex_C32__
#elif defined(__convex_c34__)
#define __processor_architecture__ __convex_C34__
#elif defined(__convex_c38__)
#define __processor_architecture__ __convex_C38__
#else
#error unknown Convex processor architecture.
#endif
#error Convex processor architecture is not supported yet.
#elif defined(__m68k__)
#include "uarch/m68k.h"
#if defined(__mc68000__) || defined(__MC68000__)
#define __processor_architecture__ __motorola_68000__
#elif defined(__mc68010__)
#define __processor_architecture__ __motorola_68010__
#elif defined(__mc68020__) || defined(__MC68020__)
#define __processor_architecture__ __motorola_68020__
#elif defined(__mc68030__) || defined(__MC68030__)
#define __processor_architecture__ __motorola_68030__
#elif defined(__mc68040__)
#define __processor_architecture__ __motorola_68040__
#elif defined(__mc68060__)
#define __processor_architecture__ __motorola_68060__
#else
#error unknown Motorola processor architecture.
#endif
#error Motorola m68k processor architecture is not supported yet.
#elif defined(__mips__) || defined(__mips)
#include "uarch/mips.h"
#if defined(_MIPS_ARCH_R2000)
#define __processor_architecture__ __mips_r2000__
#elif defined(_MIPS_ARCH_R3000) || defined(_R3000)
#define __processor_architecture__ __mips_r3000__
#elif defined(_MIPS_ARCH_R3900)
#define __processor_architecture__ __mips_r3900__
#elif defined(_MIPS_ARCH_R4000) || defined(_R4000)
#define __processor_architecture__ __mips_r4000__
#elif defined(_MIPS_ARCH_R4400)
#define __processor_architecture__ __mips_r4400__
#elif defined(_MIPS_ARCH_R4600)
#define __processor_architecture__ __mips_r4600__
#elif defined(_MIPS_ARCH_R4650)
#define __processor_architecture__ __mips_r4650__
#elif defined(_MIPS_ARCH_R6000)
#define __processor_architecture__ __mips_r6000__
#elif defined(_MIPS_ARCH_R7000)
#define __processor_architecture__ __mips_r7000__
#elif defined(_MIPS_ARCH_R8000)
#define __processor_architecture__ __mips_r8000__
#elif defined(_MIPS_ARCH_R9000)
#define __processor_architecture__ __mips_r9000__
#elif defined(_MIPS_ARCH_R10000)
#define __processor_architecture__ __mips_r10000__
#elif defined(_MIPS_ARCH_R12000)
#define __processor_architecture__ __mips_r12000__
#elif defined(_MIPS_ARCH_R14000)
#define __processor_architecture__ __mips_r14000__
#elif defined(_MIPS_ARCH_R16000)
#define __processor_architecture__ __mips_r16000__
#else
#error unknown MIPS processor architecture.
#endif
#error MIPS processor architecture is not supported yet.
#elif defined(__powerpc__) || \
      defined(__powerpc) || \
      defined(__ppc__) || \
      defined(__POWERPC__) || \
      defined(__PPC__) || \
      defined(_ARCH_PPC) || \
      defined(__powerpc64__) || \
      defined(__ppc64__) || \
      defined(__PPC64__) || \
      defined(_ARCH_PPC64)
#include "uarch/ppc.h"
#if defined(__ppc601__)
#define __processor_architecture__ __ppc_601__
#elif defined(__ppc603__)
#define __processor_architecture__ __ppc_603__
#elif defined(__ppc604__)
#define __processor_architecture__ __ppc_604__
#elif defined(__ppc620__)
#define __processor_architecture__ __ppc_620__
#else
#error unknown PowerPC processor architecture.
#endif
#error PowerPC processor architecture is not supported yet.
#elif defined(__sparc) || defined(__sparc64__)
#define __sparc_processor__
#define __sparcv8__ 8
#define __sparcv9__ 9
#if defined(__sparc_v8__)
#define __processor_architecture__ __sparcv8__
#elif defined(__sparc_v9__)
#define __processor_architecture__ __sparcv9__
#else
#error unknown SPARC processor architecture.
#endif
#error SPARC processor architecture is not supported yet.
#else
#error unknown processor architecture.
#endif
#endif //__MINGW32__
//---------------------------------------------------------------------------
#if UINTPTR_MAX == 0xFFFFFFFF
#define __x32_platform__
typedef int32_t signed_ptr;
typedef unsigned int32_t unsigned_ptr;
#elif UINTPTR_MAX == 0xFFFFFFFFFFFFFFFF
#define __x64_platform__
typedef int64_t signed_ptr;
typedef unsigned int64_t unsigned_ptr;
#else
#error unknown architecture.
#endif
//---------------------------------------------------------------------------
#define DENOTATION __FUNCTION__
#define DEMANGLED __PRETTY_FUNCTION__
//#define SYMBOL __FUNCDNAME__ 
//---------------------------------------------------------------------------
#define IMPORT
#define EXPORT __attribute__((visibility("default")))
#define LOCAL __attribute__((visibility("hidden")))
//---------------------------------------------------------------------------
#define __fast __attribute__((fastcall))
#define __noinline __attribute__((noinline))
#define __noreturn __attribute__((noreturn))
//---------------------------------------------------------------------------
#define __gnuc_generic__
#define atomic_xchg8(target, value) __atomic_exchange_n_1((uint8_t*)(target), (uint8_t)(value), __ATOMIC_SEQ_CST)
#define atomic_xchg16(target, value) __atomic_exchange_n_2((uint16_t*)(target), (uint16_t)(value), __ATOMIC_SEQ_CST)
#define atomic_xchg32(target, value) __atomic_exchange_n_4((uint32_t*)(target), (uint32_t)(value), __ATOMIC_SEQ_CST)
#define atomic_xchg64(target, value) __atomic_exchange_n_8((uint64_t*)(target), (uint64_t)(value), __ATOMIC_SEQ_CST)
#define atomic_add8(target, value) __atomic_fetch_add_1((uint8_t*)(target), (uint8_t)(value), __ATOMIC_SEQ_CST)
#define atomic_add16(target, value) __atomic_fetch_add_2((uint16_t*)(target), (uint16_t)(value), __ATOMIC_SEQ_CST)
#define atomic_add32(target, value) __atomic_fetch_add_4((uint32_t*)(target), (uint32_t)(value), __ATOMIC_SEQ_CST)
#define atomic_add64(target, value) __atomic_fetch_add_8((uint64_t*)(target), (uint64_t)(value), __ATOMIC_SEQ_CST)
#define atomic_sub8(target, value) __atomic_fetch_sub_1((uint8_t*)(target), (uint8_t)(value), __ATOMIC_SEQ_CST)
#define atomic_sub16(target, value) __atomic_fetch_sub_2((uint16_t*)(target), (uint16_t)(value), __ATOMIC_SEQ_CST)
#define atomic_sub32(target, value) __atomic_fetch_sub_4((uint32_t*)(target), (uint32_t)(value), __ATOMIC_SEQ_CST)
#define atomic_sub64(target, value) __atomic_fetch_sub_8((uint64_t*)(target), (uint64_t)(value), __ATOMIC_SEQ_CST)
#define atomic_inc8(addend) atomic_add8(addend, 1)
#define atomic_inc16(addend) atomic_add16(addend, 1)
#define atomic_inc32(addend) atomic_add32(addend, 1)
#define atomic_inc64(addend) atomic_add64(addend, 1)
#define atomic_dec8(addend) atomic_sub8(addend, 1)
#define atomic_dec16(addend) atomic_sub16(addend, 1)
#define atomic_dec32(addend) atomic_sub32(addend, 1)
#define atomic_dec64(addend) atomic_sub64(addend, 1)
#define atomic_and8(destination, value) __atomic_fetch_and_1((uint8_t*)(target), (uint8_t)(value), __ATOMIC_SEQ_CST)
#define atomic_and16(destination, value) __atomic_fetch_and_2((uint16_t*)(target), (uint16_t)(value), __ATOMIC_SEQ_CST)
#define atomic_and32(destination, value) __atomic_fetch_and_4((uint32_t*)(target), (uint32_t)(value), __ATOMIC_SEQ_CST)
#define atomic_and64(destination, value) __atomic_fetch_and_8((uint64_t*)(target), (uint64_t)(value), __ATOMIC_SEQ_CST)
#define atomic_or8(destination, value) __atomic_fetch_or_1((uint8_t*)(target), (uint8_t)(value), __ATOMIC_SEQ_CST)
#define atomic_or16(destination, value) __atomic_fetch_or_2((uint16_t*)(target), (uint16_t)(value), __ATOMIC_SEQ_CST)
#define atomic_or32(destination, value) __atomic_fetch_or_4((uint32_t*)(target), (uint32_t)(value), __ATOMIC_SEQ_CST)
#define atomic_or64(destination, value) __atomic_fetch_or_8((uint64_t*)(target), (uint64_t)(value), __ATOMIC_SEQ_CST)
#define atomic_xor8(destination, value) __atomic_fetch_xor_1((uint8_t*)(target), (uint8_t)(value), __ATOMIC_SEQ_CST)
#define atomic_xor16(destination, value) __atomic_fetch_xor_2((uint16_t*)(target), (uint16_t)(value), __ATOMIC_SEQ_CST)
#define atomic_xor32(destination, value) __atomic_fetch_xor_4((uint32_t*)(target), (uint32_t)(value), __ATOMIC_SEQ_CST)
#define atomic_xor64(destination, value) __atomic_fetch_xor_8((uint64_t*)(target), (uint64_t)(value), __ATOMIC_SEQ_CST)
//---------------------------------------------------------------------------
static inline uint8_t __atomic_compare_exchange8(uint8_t* target, uint8_t exchange, uint8_t comperand) {
    __atomic_compare_exchange_1(target, &comperand, exchange, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
    return comperand;
}
static inline uint16_t __atomic_compare_exchange16(uint16_t* target, uint16_t exchange, uint16_t comperand) {
    __atomic_compare_exchange_2(target, &comperand, exchange, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
    return comperand;
}
static inline uint32_t __atomic_compare_exchange32(uint32_t* target, uint32_t exchange, uint32_t comperand) {
    __atomic_compare_exchange_4(target, &comperand, exchange, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
    return comperand;
}
static inline uint64_t __atomic_compare_exchange64(uint64_t* target, uint64_t exchange, uint64_t comperand) {
    __atomic_compare_exchange_8(target, &comperand, exchange, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
    return comperand;
}
//---------------------------------------------------------------------------
#define atomic_cmpxchg8(target, exchange, comperand) __atomic_compare_exchange8((uint8_t*)(target),(uint8_t)(exchange),(uint8_t)(comperand))
#define atomic_cmpxchg16(target, exchange, comperand) __atomic_compare_exchange16((uint16_t*)(target),(uint16_t)(exchange),(uint16_t)(comperand))
#define atomic_cmpxchg32(target, exchange, comperand) __atomic_compare_exchange32((uint32_t*)(target),(uint32_t)(exchange),(uint32_t)(comperand))
#define atomic_cmpxchg64(target, exchange, comperand) __atomic_compare_exchange64((uint64_t*)(target),(uint64_t)(exchange),(uint64_t)(comperand))
//---------------------------------------------------------------------------
#ifdef __x64_platform__
#define atomic_xchg_pointer(target, value) (void*)atomic_xchg64(target, value)
#else
#define atomic_xchg_pointer(target, value) (void*)atomic_xchg32(target, value)
#endif
//---------------------------------------------------------------------------
