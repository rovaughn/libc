#ifndef STDIO_H
#define STDIO_H

#include "types.h"

i64 sys_write(u64 fd, const byte *data, u64 len);
void __attribute__((noreturn)) sys_exit(u64 error_code);

#endif
