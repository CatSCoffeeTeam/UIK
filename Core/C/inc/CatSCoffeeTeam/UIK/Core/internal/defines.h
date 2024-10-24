/**
 * @file UIK/Core/internal/defines.h
 * @author CatSCoffeeTeam (contact@catscoffeeteam.com)
 * @brief This file contains global definitions used throughout the 
 *        core and applications referencing it.
 *        Numeric types are asserted statically to guarantee the expected size.
 * 
 * @version 0.1.0
 * @date 2024-10-24
 * 
 * @copyright User Interface Kit is Copyright (c) CatSCoffeeTeam 2024
 */

#ifndef CatSCoffeeTeam_UIK_Core_defines_h
#define CatSCoffeeTeam_UIK_Core_defines_h



// Unsigned integer types
/** @brief Unsigned 8-bit integer */
typedef unsigned char u8;

/** @brief Unsigned 16-bit integer */
typedef unsigned short u16;

/** @brief Unsigned 32-bit integer */
typedef unsigned int u32;

/** @brief Unsigned 64-bit integer */
typedef unsigned long long u64;

// Signed integer types
/** @brief Signed 8-bit integer */
typedef signed char s8;

/** @brief Signed 16-bit integer */
typedef signed short s16;

/** @brief Signed 32-bit integer */
typedef signed int s32;

/** @brief Signed 64-bit integer */
typedef signed long long s64;

// Floating-point types
/** @brief 32-bit floating point number */
typedef float f32;

/** @brief 64-bit floating point number */
typedef double f64;

// Boolean types
/** @brief 32-bit boolean type, used for APIs which require it */
typedef int b32;

/** @brief 8-bit boolean type */
typedef _Bool b8;

// Static assertion definition
#if defined(__clang__) || defined(__GNUC__)
    /** @brief Static assertion */
    #define UIK_STATIC_ASSERT _Static_assert
#else
    /** @brief Static assertion */
    #define UIK_STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size
/** @brief Assert u8 is 1 byte */
UIK_STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");

/** @brief Assert u16 is 2 bytes */
UIK_STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");

/** @brief Assert u32 is 4 bytes */
UIK_STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");

/** @brief Assert u64 is 8 bytes */
UIK_STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

/** @brief Assert s8 is 1 byte */
UIK_STATIC_ASSERT(sizeof(s8) == 1, "Expected s8 to be 1 byte.");

/** @brief Assert s16 is 2 bytes */
UIK_STATIC_ASSERT(sizeof(s16) == 2, "Expected s16 to be 2 bytes.");

/** @brief Assert s32 is 4 bytes */
UIK_STATIC_ASSERT(sizeof(s32) == 4, "Expected s32 to be 4 bytes.");

/** @brief Assert s64 is 8 bytes */
UIK_STATIC_ASSERT(sizeof(s64) == 8, "Expected s64 to be 8 bytes.");

/** @brief Assert f32 is 4 bytes */
UIK_STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");

/** @brief Assert f64 is 8 bytes */
UIK_STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define UIKPLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-bit is required on Windows!"
    #endif
#elif defined(__linux__) || defined(__gnu_linux__)
    #define UIKPLATFORM_LINUX 1
    #if defined(__ANDROID__)
        #define UIKPLATFORM_ANDROID 1
    #endif
#elif defined(__unix__)
    #define UIKPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
    #define UIKPLATFORM_POSIX 1
#elif defined(__APPLE__)
    #define UIKPLATFORM_APPLE 1
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
        #define UIKPLATFORM_IOS 1
        #define UIKPLATFORM_IOS_SIMULATOR 1
    #elif TARGET_OS_IPHONE
        #define UIKPLATFORM_IOS 1
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
        #error "Unknown Apple platform"
    #endif
#else
    #error "Unknown platform!"
#endif

// Export and import qualifiers
#ifdef UIKEXPORT
    // Export
    #ifdef _MSC_VER
        #define UIKAPI_ATTR __declspec(dllexport)
        #define UIKAPI_CALL __stdcall
        #define UIKAPI_PTR UIKAPI_CALL
    #else
        #define UIKAPI_ATTR __attribute__((visibility("default")))
        #define UIKAPI_CALL
        #define UIKAPI_PTR
    #endif
#else
    // Import
    #ifdef _MSC_VER
        /** @brief Import/export qualifier */
        #define UIKAPI_ATTR __declspec(dllimport)
        #define UIKAPI_CALL __stdcall
        #define UIKAPI_PTR UIKAPI_CALL
    #else
        /** @brief Import/export qualifier */
        #define UIKAPI_ATTR
        #define UIKAPI_CALL
        #define UIKAPI_PTR
    #endif
#endif

// Debug/Release mode
#ifdef _DEBUG
    #define UIK_DEBUG
#else
    #define UIK_RELEASE
#endif

// Deprecation attribute
#if defined(__clang__) || defined(__GNUC__)
    /** @brief Mark something (e.g., a function) as deprecated */
    #define UIKDEPRECATED(message) __attribute__((deprecated(message)))
#elif defined(_MSC_VER)
    /** @brief Mark something (e.g., a function) as deprecated */
    #define UIKDEPRECATED(message) __declspec(deprecated(message))
#else
    #error "Unsupported compiler - don't know how to define deprecations!"
#endif



#endif // CatSCoffeeTeam_UIK_Core_defines_h