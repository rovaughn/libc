#ifndef TYPES_H
#define TYPES_H

typedef signed char i8;
typedef short       i16;
typedef long        i32;
typedef long long   i64;

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned long      u32;
typedef unsigned long long u64;

typedef u64 usize;
typedef i64 isize;

typedef u8 byte;
typedef const char string[];

typedef _Bool bool;

#define true 1
#define false 0
#define NULL 0

#endif
