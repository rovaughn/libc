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

        for (i = len - 1;; i--) {
            dstb[i] = srcb[i];
            if (i == 0) {
                break;
            }
        }
    }
}

usize copy_most(dst, dst_len, src, src_len)
    void *dst;
    usize dst_len;
    const void *src;
    usize src_len;
{
    usize len = dst_len < src_len ? dst_len : src_len;

    copy(dst, src, len);

    return len;
}

