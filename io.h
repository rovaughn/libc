#ifndef IO_H
#define IO_H

#include "types.h"

typedef isize (*writer)(const byte *data, usize len);
typedef isize (*reader)(byte *data, usize len);

isize copy(writer w, reader r);
isize copy_buffer(writer w, reader r, byte *buffer, usize len);

#endif
