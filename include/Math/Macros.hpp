/*
 * ---------------------------------------------------
 * Macros.hpp
 *
 * Author: Thomas Choquet <semoir.dense-0h@icloud.com>
 * Date: 2024/08/29 14:21:43
 * ---------------------------------------------------
 */

#ifndef MATH_MACROS_HPP
#define MATH_MACROS_HPP

#if (defined(__GNUC__) || defined(__clang__)) && defined(MATH_API_IMPLEMENTATION)
    #define MATH_API __attribute__((visibility("default")))
#elif defined(_MSC_VER) && defined(MATH_API_IMPLEMENTATION)
    #define MATH_API __declspec(dllexport)
#elif defined(_MSC_VER) && defined(MATH_DLL_LINK)
    #define MATH_API __declspec(dllimport)
#else
    #define MATH_API
#endif

#if defined(__GNUC__) && __GNUC__ < 14
    #define ALIGNAS(x) __attribute__((aligned(x)))
#else
    #define ALIGNAS(x) alignas(x)
#endif


#endif // MATH_MACROS_HPP