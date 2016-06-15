#ifndef DEBUG_H
#define DEBUG_H

#include "syscall.h"

void debug_puts(const char *s);
void debug_hex(u64 n);
void debug_buffer(const byte *b, usize len);

#endif
