#pragma once

#if HK_PLATFORM == HK_PLATFORM_WIN32
# if HK_COMPILER == HK_COMPILER_MSVC
#   if defined(HK_STATIC_LIB)
#     define HK_GRAPHICS_OPENGL_EXPORT
#   else
#     if defined(HK_GRAPHICS_OPENGL_EXPORTS)
#       define HK_GRAPHICS_OPENGL_EXPORT  __declspec(dllexport)
#     else
#       define HK_GRAPHICS_OPENGL_EXPORT  __declspec(dllimport)
#     endif
#   endif
# else //Any other compiler
#   if defined( HK_STATIC_LIB )
#     define HK_GRAPHICS_OPENGL_EXPORT
#   else
#     if defined( HK_GRAPHICS_OPENGL_EXPORTS)
#       defined HK_GRAPHICS_OPENGL_EXPORT __attribute__((dllexport))
#     else
#       define HK_GRAPHICS_OPENGL_EXPORT  __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define HK_GRAPHICS_OPENGL_HIDDEN
#else // Linux / Mac settings
# define HK_GRAPHICS_OPENGL_EXPORT __attribute__ ((visibility("default")))
# define HK_GRAPHICS_OPENGL_EXPORT __attribute__ ((visibility("hidden")))
#endif

//DLL export for plug-ins
#if HK_PLATFORM == HK_PLATFORM_WIN32
# if HK_COMPILER == HK_COMPILER_MSVC
#  define HK_PLUGIN_EXPORT __declspec(dllexport)
# else
#   define HK_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
# define HK_GRAPHICS_OPENGL_HIDDEN
#else // Linux / Mac settings
# define HK_PLUGIN_EXPORT __attribute__ ((visibility("default")))
#endif