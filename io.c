#include "io.h"

error err_eof = (error)"EOF";
error err_short_write = (error)"Short write.";

static write_result io_copy_buffer_unchecked(w, r, buf, len)
    writer *w;
    reader *r;
    byte *buf;
    usize len;
{
    write_result result;

    result.err = NULL;
    result.written = 0;

    for (;;) {
        read_result rr;

        rr = r->read(r, buf, len);

        if (rr.err == err_eof) {
            result.err = NULL;
            return result;
        } else if (rr.err != NULL) {
            result.err = rr.err;
            return result;
        } else if (rr.read > 0) {
            write_result wr;

            wr = w->write(w, buf, rr.read);

            if (wr.err != NULL) {
                result.err = wr.err;
                return result;
            } else if (rr.read != wr.written) {
                result.err = err_short_write;
                return result;
            } else {
                result.written += wr.written;
            }
        }
    }
}

write_result io_copy(w, r)
    writer *w;
    reader *r;
{
    byte buf[32*1024];

    return io_copy_buffer_unchecked(w, r, buf, sizeof buf);
}

write_result io_copy_buffer(w, r, buf, len)
    writer *w;
    reader *r;
    byte *buf;
    usize len;
{
    if (buf == NULL) {
        write_result result;
        result.err = (error)"io_copy_buffer: buf cannot be NULL.";
        result.written = 0;
        return result;
    } else if (len == 0) {
        write_result result;
        result.err = (error)"io_copy_buffer: len cannot be 0.";
        result.written = 0;
        return result;
    }

    return io_copy_buffer_unchecked(w, r, buf, len);
}

