#ifndef _STDDEF_H
#include "stddef.h"
#endif
#ifndef _STDINT_H
#include "stdint.h"
#endif
#define string char *

#define big long long
#define ubig unsigned long long

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
#ifdef __SIZEOF_INT128__
    typedef uint128_t uint128;
#else
    typedef uint64_t uint128;
#endif

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
#ifdef __SIZEOF_INT128__
    typedef int128_t int128;
#else
    typedef int64_t int128;
#endif


#define GetType(type) _Generic((type), \
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    short: "short", \
    unsigned short: "unsigned short", \
    int: "int", \
    unsigned int: "unsigned int", \
    long: "long", \
    unsigned long: "unsigned long", \
    long long: "long long", \
    unsigned long long: "unsigned long long", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    void: "void", \
    char *: "char *", \
    signed char *: "signed char *", \
    unsigned char *: "unsigned char *", \
    short *: "short *", \
    unsigned short *: "unsigned short *", \
    int *: "int *", \
    unsigned int *: "unsigned int *", \
    long *: "long *", \
    unsigned long *: "unsigned long *", \
    long long *: "long long *", \
    unsigned long long *: "unsigned long long *", \
    float *: "float *", \
    double *: "double *", \
    long double *: "long double *", \
    void *: "void *", \
    default: "unknown" \
)