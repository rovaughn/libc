#ifndef BUFIO_H
#define BUFIO_H

#include "io.h"

#define BUFIO_BUFFER_SIZE 1024
#define BUFIO_BUFFER_THRESHOLD 1024/2

typedef struct {
    write_fn  w;
    writer   *dest;
    byte      buffer[BUFIO_BUFFER_SIZE];
    usize     filled;
} bufio_writer;

void new_bufio_writer(bufio_writer *bw, writer *w);
isize bufio_flush(bufio_writer *bw);

#endif
