#pragma once

#define HK_PLATFORM_WIN32 1
#define HK_PLATFORM_OSX 2
#define HK_PLATFORM_LINUX 3
#define HK_PLATFORM_PS4 4

#define HK_COMPILER_MSVC 1
#define HK_COMPILER_GCC 2
#define HK_COMPILER_INTEL 3
#define HK_COMPILER_GNUC 4

#define HK_ARCHITECTURE_x86_64 1
#define HK_ARCHITECTURE_x86_32 2

#define HK_ENDIAN_LITTLE 1
#define HK_ENDIAN_BIG 2

//
#define HK_ENDIAN_ HK_ENDIAN_LITTLE;

#if defined(__clang__)

# define HK_COMPILER HK_COMPILER_MSVC // CLANG
# define HK_COMP_VER __clang_version__
# define HK_THREADLOCAL _thread
# define HK_STDCALL __attribute__((stdcall))
# define HK_CDECL __attribute__ ((cdecl))

#elif defined(__GNUC__)

# define HK_COMPILER HK_COMPILER_GNUC //GNUC
# define HK_COMP_VER (((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
# define HK_THREADLOCAL __thread
# define HK_STDCALL _attribute__((stdcall))
# define HK_CDECL __attribute__ ((cdecl))

#elif defined (__INTEL_COMPILER)

# define HK_COMPILER HK_COMPILER_INTEL // INTEL
# define HK_COMP_VER __INTEL_COMPILER
# define HK_STDCALL __stdcall
# define HK_CDECL __cdecl

// check if we could be building with either with vs
#elif defined(_MSC_VER)

# define HK_COMPILER HK_COMPILER_MSVC
# define HK_COMP_VER _MSC_VER
# define HK_THREADLOCAL _declspec(thread)
# define HK_STDCALL __stdcall
# define HK_CDECL __cdecl
# undef __PRETTY_FUNCTION__
# define __PRETTY_FUNCTION__ __FUNCSIG__ 

#else

# pragma error "No known compiler."

#endif

#if HK_COMPILER == HK_COMPILER_MSVC       // if we are on VS6 or Higher.
# if HK_COMP_VER >= 1200
#   define FORCEINLINE __forceinline
#   ifndef RESTRICT
#     define RESTRICT __restrict
#   endif
# endif
#elif defined(__MINGW32__)                // if we are on a Unix System.
# if !defined (FORCEINLINE)
#   define FORCEINLINE __inline
#   ifndef RESTRICT
#     define RESTRICT
#   endif
# endif
#else
# define  FORCEINLINE __inline
#   ifndef RESTRICT
#     define RESTRICT __restrict
#   endif
#endif

/************************************************************************/
/* FInds the current platform                                                                     */
/************************************************************************/

#if defined(__WIN32__) || defined(_WIN32)
#define HK_PLATFORM HK_PLATFORM_WIN32
#elif defined( __APPLE_CC__)
#define HK_PLATFORM HK_PLATFORM_OSX
#elif defined(__ORBIS__)
#define HK_PLATFORM HK_PLATFORM_PS4
#else
#define HK_PLATFORM HK_PLATFORM_LINUX
#endif

/************************************************************************/
/* Find the architecture type                                           */
/************************************************************************/

#if defined(__x86_64__) || defined(_M_X64)
# define HK_ARCH_TYPE HK_ARCHITECTURE_x86_64
#else
# define HK_ARCH_TYPE HK_ARCHITECTURE_x86_32
#endif

/************************************************************************/
/* Memory Alignment macros                                              */
/************************************************************************/

#if HK_COMPILER == HK_COMPILER_MSVC
# define MS_ALIGN(n)  __declspec(align(n))
# ifdef GCC_PACK
#   define GCC_PACK(n)
# endif
# ifndef GCC_ALIGN
#   define GCC_ALIGN(n)
# endif
#elif ( HK_COMPILER == HK_COMPILER_GNUC && HK_PLATFORM == HK_PLATFORM_PS4 )
# define MS_ALIGN(n)
# define GCC_PACK(n)
# define GCC_ALIGN(n) __attribute__((__aligned__(n)))
#else
# define MS_ALIGN(n)  
# define GCC_PACK(n)   __attribute__((packed, aligned(n)))
# define GCC_ALIIGN(n) __attribute__((aligned(n)))
#endif

/************************************************************************/
/* for throw override                                                   */
/************************************************************************/

#if HK_COMPILER == HK_COMPILER_MSVC
# define _NOEXCEPT noexcept
#elif HK_COMPILER == HK_COMPILER_INTEL
# define _NOEXCEPT noexcept
#elif HK_COMPILER == HK_COMPILER_GNUC
# define _NOEXCEPT noexcept
#else
# define _NOEXCEPT
#endif

/************************************************************************/
/* Windows specific settings                                            */
/************************************************************************/

//win32 compilers use _DEBUG for specifying debug builds. For MinGW, we set DEBUG
#if HK_PLATFORM == HK_PLATFORM_WIN32
# if defined(_DEBUG) || defined(DEBUG)
#   define HK_DEBUG_MODE 1
# else
#   define HK_DEBUG_MODE 0
# endif
# if HK_COMPILER == HK_COMPILER_INTEL
#   define HK_THREADLOCAL __declspec(thread)
# endif
#endif

/************************************************************************/
/* Linux / Apple specific Settings                                      */
/************************************************************************/
#if HK_PLATFORM == HK_PLATFORM_LINUX || HK_PLATFORM == HK_PLATFORM_OSX
# define stripcmp strcasecmp

//If we are one DEBUG build
#if defined(_DEBUG) || defined(DEBUG)
#   define HK_DEBUG_MODE 1
# else
#   define HK_DEBUG_MODE 0
# endif
# if HK_COMPILER == HK_COMPILER_INTEL 
#   define HK_THREADLOCAL __thread
# endif
#endif

#if HK_PLATFORM == HK_PLATFORM_PS4
# if defined(_DEBUG) || defined(DEBUG)
#   define HK_DEBUG_MODE 1
# else
#   define HK_DEBUG_MODE 0
# endif
#endif

/************************************************************************/
/* Definition of Debug macros                                           */
/************************************************************************/

#if HK_DEBUG_MODE
# define HK_DEBUG_ONLY(x) x
# define HK_ASSERT(x) assert(x)
#else
# define HK_DEBUG_ONLY(x)
# define HK_ASSERT(x)
#endif

#if HK_COMPILER == HK_COMPILER_MSVC
# define _CRT_SECURE_NO_WARNINGS
# pragma warning(disable : 4251)
#endif