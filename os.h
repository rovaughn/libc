#ifndef OS_H
#define OS_H

#include "types.h"

isize stdout(const byte *buf, usize len);
isize stderr(const byte *buf, usize len);
void __attribute__((noreturn)) exit(u64 error_code);

#endif
