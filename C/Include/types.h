//
// types.h
//     Copyright (c) kuailedetongnian all rights reserved.
//

//
// /C/Include/types.h
//

#ifndef _TYPES_H_
#define _TYPES_H_

//
// Define interger types.
//
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
typedef signed char        int8_t;
typedef signed short       int16_t;
typedef signed int         int32_t;
typedef signed long long   int64_t;

typedef unsigned char      uchar;
typedef unsigned short     ushort;
typedef unsigned int       uint;
typedef unsigned long      ulong;
typedef unsigned long long ullong;

typedef uint8_t  byte;
typedef uint16_t word;
typedef uint32_t dword;
typedef uint64_t qword;

#define INT8_MIN   (-127 - 1)
#define INT16_MIN  (-32767 - 1)
#define INT32_MIN  (-2147483647 - 1)
#define INT64_MIN  (-9223372036854775807LL - 1)
#define INT8_MAX   127
#define INT16_MAX  32767
#define INT32_MAX  2147483647
#define INT64_MAX  9223372036854775807LL
#define UINT8_MIN  0x00U
#define UINT16_MIN 0x0000U
#define UINT32_MIN 0x00000000U
#define UINT64_MIN 0x0000000000000000ULL
#define UINT8_MAX  0xFF
#define UINT16_MAX 0xFFFF
#define UINT32_MAX 0xFFFFFFFF
#define UINT64_MAX 0xFFFFFFFFFFFFFFFFLL

#define BYTE_MIN   UINT8_MIN
#define WORD_MIN   UINT16_MIN
#define DWORD_MIN  UINT32_MIN
#define QWORD_MIN  UINT64_MIN
#define BYTE_MAX   UINT8_MAX
#define WORD_MAX   UINT16_MAX
#define DWORD_MAX  UINT32_MAX
#define QWORD_MAX  UINT64_MAX

#define CHAR_MIN   INT8_MIN
#define SHORT_MIN  INT16_MIN
#define INT_MIN    INT32_MIN
#define LONG_MIN   INT32_MIN
#define LLONG_MIN  INT64_MIN
#define CHAR_MAX   INT8_MAX
#define SHORT_MAX  INT16_MAX
#define INT_MAX    INT32_MAX
#define LONG_MAX   INT32_MAX
#define LLONG_MAX  INT64_MAX
#define UCHAR_MIN  UINT8_MIN
#define USHORT_MIN UINT16_MIN
#define UINT_MIN   UINT32_MIN
#define ULONG_MIN  UINT32_MIN
#define ULLONG_MIN UINT64_MIN
#define UCHAR_MAX  UINT8_MAX
#define USHORT_MAX UINT16_MAX
#define UINT_MAX   UINT32_MAX
#define ULONG_MAX  UINT32_MAX
#define ULLONG_MAX UINT64_MAX

#define WCHAR_MIN  UINT16_MIN
#define WCHAR_MAX  UINT16_MAX
#define CHAR16_MIN UINT16_MIN
#define CHAR16_MAX UINT16_MAX
#define CHAR32_MIN UINT32_MIN
#define CHAR32_MAX UINT32_MAX

#ifndef _SIZE_T_SIZE_DEFINED
#define _SIZE_T_SIZE_DEFINED
    #ifdef _WIN64
        #define SIZE_MAX UINT64_MAX
        #define SIZE_MIN UINT64_MIN
    #else /* _WIN64 */
        #define SIZE_MAX UINT32_MAX
        #define SIZE_MIN UINT32_MIN
    #endif /* _WIN64 */
#endif /* _SIZE_T_SIZE_DEFINED */


#ifndef _INTERGER_TYPES_DEFINED
    #define _INTERGER_TYPES_DEFINED
#endif /* _INTERGER_TYPES_DEFINED */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
    #ifdef _WIN64
        typedef uint64_t size_t;
        typedef uint64_t ptrdiff_t;
        typedef uint64_t intptr_t;
    #else /* _WIN64 */
        typedef uint32_t size_t;
        typedef uint32_t ptrdiff_t;
        typedef uint32_t intptr_t;
    #endif /* _WIN64 */
#endif /* _SIZE_T_DEFINED */

#ifndef _SIZE_T_DEFINED
    #define _SIZE_T_DEFINED
#endif /* _SIZE_T_DEFINED */

#ifndef _PTRDIFF_T_DEFINED
    #define _PTRDIFF_T_DEFINED
#endif /* _PTRDIFF_T_DEFINED */

#ifndef _INTPTR_T_DEFINED
    #define _INTPTR_T_DEFINED
#endif /* _INTPTR_T_DEFINED */

#if !defined(__cplusplus) && !defined(_WCHAR_T_DEFINED)
    #define _WCHAR_T_DEFINED
    typedef uint16_t wchar_t;
#endif /* _WCHAR_T_DEFINED */

#ifndef NULL
    #ifdef __cplusplus
        #define NULL 0
    #else /* __cplusplus */
        #define NULL ((void *)0)
    #endif
#endif /* NULL */

#include <float.h>

#if !defined(__cplusplus) && !defined(__bool_true_false_are_defined)
#define __bool_true_false_are_defined 1
    #define bool  _Bool
    #define true  true
    #define false false
#endif /* !defined(__cplusplus) && !defined(__bool_true_false_are_defined) */

#endif /* _TYPES_H_ */
