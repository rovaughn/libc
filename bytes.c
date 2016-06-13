#include "bytes.h"

void copy(dst, src, len)
    void *dst;
    const void *src;
    usize len;
{
    byte *dstb = dst;
    const byte *srcb = src;
    usize i;

    for (i = 0; i < len; i++) {
        dstb[i] = srcb[i];
    }
}

