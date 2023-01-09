#ifndef LIBC_TYPES_H
#define LIBC_TYPES_H

#define NULL ((void*)0)

#ifdef __x86_64__
typedef struct
{
    long quot;
    long rem;
} div_t;

typedef struct
{
    long quot;
    long rem;
} ldiv_t;
typedef struct
{
    long long quot;
    long long rem;
} lldiv_t;

typedef int wchar_t;
typedef unsigned long long size_t;
#else
typedef struct
{
    int quot;
    int rem;
} div_t;

typedef struct
{
    long quot;
    long rem;
} ldiv_t;
typedef struct
{
    long quot;
    long rem;
} lldiv_t;

typedef char wchar_t;
typedef unsigned int size_t;
#endif

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef s8* ps8;
typedef s16* ps16;
typedef s32* ps32;
typedef s64* ps64;

typedef u8* pu8;
typedef u16* pu16;
typedef u32* pu32;
typedef u64* pu64;

typedef void* pvoid;

#endif // LIBC_TYPES_H
