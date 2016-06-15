#ifndef IO_H
#define IO_H

#include "types.h"

typedef struct { error err; usize written; } write_result;
typedef struct { error err; usize read; } read_result;

struct writer;
struct reader;

typedef write_result (*write_fn)(struct writer *self, const byte *data, usize len);
typedef read_result (*read_fn)(struct reader *self, byte *data, usize len);

typedef struct writer {
    write_fn write;
} writer;

typedef struct reader {
    read_fn read;
} reader;

extern error err_eof;
extern error err_short_write;

write_result io_copy(writer *w, reader *r);
write_result io_copy_buffer(writer *w, reader *r, byte *buffer, usize len);

#endif
