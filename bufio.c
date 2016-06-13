#include "bufio.h"
#include "bytes.h"

isize bufio_write(bufio_writer *self, const byte *buf, usize len);

isize bufio_write(self, buf, len)
    bufio_writer *self;
    const byte *buf;
    usize len;
{
    copy(&self->buffer[self->filled], buf, len);
    self->filled += len;

    if (self->filled >= BUFIO_BUFFER_THRESHOLD) {
        return bufio_flush(self);
    }

    return len;
}

void new_bufio_writer(bw, w)
    bufio_writer *bw;
    writer *w;
{
    bw->w = (write_fn)&bufio_write;
    bw->dest = w;
    bw->filled = 0;
}

isize bufio_flush(bw)
    bufio_writer *bw;
{
    isize ret = bw->dest->write(bw->dest, bw->buffer, bw->filled);
    bw->filled = 0;
    return ret;
}

