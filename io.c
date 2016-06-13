#include "io.h"
#include "errors.h"

static isize copy_buffer_unchecked(w, r, buf, len)
    writer w;
    reader r;
    byte *buf;
    usize len;
{
    usize written = 0;

    for (;;) {
        isize nr = r(buf, len);

        if (nr == ERR_EOF) {
            return (isize)written;
        } else if (nr < 0) {
            return nr;
        } else if (nr > 0) {
            isize nw = w(buf, (usize)nr);

            if (nw < 0) {
                return nw;
            } else if (nr != nw) {
                return ERR_SHORT_WRITE;
            } else {
                written += (usize)nw;
            }
        }
    }
}

isize copy(w, r)
    writer w;
    reader r;
{
    byte buf[32*1024];

    return copy_buffer_unchecked(w, r, buf, sizeof buf);
}

isize copy_buffer(w, r, buf, len)
    writer w;
    reader r;
    byte *buf;
    usize len;
{
    if (buf == NULL || len == 0) {
        return ERR_ARG;
    }

    return copy_buffer_unchecked(w, r, buf, len);
}

