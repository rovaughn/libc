#include "bufio.h"
#include "bytes.h"

i64 sys_write(u64 fd, const byte *data, u64 len);

write_result bufio_write(bufio_writer *bw, const byte *buf, usize len);

write_result bufio_write(bw, buf, len)
    bufio_writer *bw;
    const byte *buf;
    usize len;
{
    write_result result;

    result.err = NULL;
    result.written = 0;

    while (len > bufio_writer_available(bw) && bw->err == NULL) {
        usize n;

        if (bw->filled == 0) {
            write_result wr;

            wr = bw->dest->write(bw->dest, buf, len);

            bw->err = wr.err;
            n = wr.written;
        } else {
            sys_write(2, (const byte*)"one\n", 4);
            n = copy_most(
                &bw->buffer[bw->filled], bufio_writer_available(bw),
                buf, len
            );
            bw->filled += n;
            bufio_writer_flush(bw);
        }

        result.written += n;
        buf = &buf[n];
        len -= n;
    }

    if (bw->err != NULL) {
        result.err = bw->err;
        return result;
    }

    byte *target = &bw->buffer[bw->filled];

    usize i;
    for (i = 0; i < bufio_writer_available(bw); i++) {
        target[i] = '\0';
    }

    usize n = copy_most(
        &bw->buffer[bw->filled], bufio_writer_available(bw),
        buf, len
    );

    bw->filled += n;
    result.written += n;

    return result;
}

void new_bufio_writer(bw, w)
    bufio_writer *bw;
    writer *w;
{
    bw->w = (write_fn)&bufio_write;
    bw->dest = w;
    bw->filled = 0;
    bw->err = NULL;
}

write_result bufio_writer_flush(bw)
    bufio_writer *bw;
{
    write_result result;

    result.err = NULL;
    result.written = 0;

    if (bw->err != NULL) {
        result.err = bw->err;
        result.written = 0;
    }

    if (bw->filled == 0) {
        return result;
    }

    result = bw->dest->write(bw->dest, bw->buffer, bw->filled);

    if (result.written < bw->filled && result.err == NULL) {
        result.err = err_short_write;
    }

    if (result.err != NULL) {
        if (result.written > 0 && result.written < bw->filled) {
            copy(bw->buffer, &bw->buffer[result.written], result.written - bw->filled);
        }

        bw->filled -= result.written;
        bw->err = result.err;

        return result;
    }

    bw->filled = 0;

    return result;
}

usize bufio_writer_available(bw)
    bufio_writer *bw;
{
    return BUFIO_BUFFER_SIZE - bw->filled;
}

