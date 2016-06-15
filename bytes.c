#include "bytes.h"

void copy(dst, src, len)
    void *dst;
    const void *src;
    usize len;
{
    byte *dstb = dst;
    const byte *srcb = src;

    if (dstb < srcb) {
        usize i;

        for (i = 0; i < len; i++) {
            dstb[i] = srcb[i];
        }
    } else if (dstb > srcb) {
        usize i;

        for (i = len - 1; i >= 0; i--) {
            dstb[i] = srcb[i];
        }
    }
}

