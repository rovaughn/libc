#ifndef OS_H
#define OS_H

#include "types.h"
#include "io.h"

typedef struct {
    write_fn w;
    int fd;
} fd_writer;

isize write_fd(fd_writer *self, const byte *data, usize len);

extern fd_writer *stdout;
extern fd_writer *stderr;

void __attribute__((noreturn)) exit(u64 error_code);

#endif
