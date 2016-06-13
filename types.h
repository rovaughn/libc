#ifndef TYPES_H
#define TYPES_H

typedef signed char i8;
typedef short       i16;
typedef int         i32;
typedef long        i64;

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long  u64;

typedef u64 usize;
typedef i64 isize;

typedef u8 byte;
typedef const char string[];

typedef _Bool bool;

#define true 1
#define false 0
#define NULL 0

#include "static_assert.h"

STATIC_ASSERT(i8, sizeof(i8) == 1)
STATIC_ASSERT(i16, sizeof(i16) == 2)
STATIC_ASSERT(i32, sizeof(i32) == 4)
STATIC_ASSERT(i64, sizeof(i64) == 8)

STATIC_ASSERT(u8, sizeof(u8) == 1)
STATIC_ASSERT(u16, sizeof(u16) == 2)
STATIC_ASSERT(u32, sizeof(u32) == 4)
STATIC_ASSERT(u64, sizeof(u64) == 8)

#endif
