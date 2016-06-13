#ifndef IO_H
#define IO_H

#include "types.h"

struct writer;
struct reader;

typedef isize (*write_fn)(struct writer *self, const byte *data, usize len);
typedef isize (*read_fn)(struct reader *self, byte *data, usize len);

typedef struct writer {
    write_fn write;
} writer;

typedef struct reader {
    read_fn read;
} reader;

isize io_copy(writer *w, reader *r);
isize io_copy_buffer(writer *w, reader *r, byte *buffer, usize len);

#endif
