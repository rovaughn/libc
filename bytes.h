#ifndef BYTES_H
#define BYTES_H

#include "types.h"

void copy(void *dst, const void *src, usize len);
usize copy_most(void *dst, usize dst_len, const void *src, usize src_len);

#endif
