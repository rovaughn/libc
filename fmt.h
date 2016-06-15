#ifndef FMT_H
#define FMT_H

#include "io.h"

void fatal(string s);

write_result fputs(writer *w, string s);
write_result fputd(writer *w, i64 n);
write_result fputu(writer *w, u64 n);
write_result fputx(writer *w, u64 n);

write_result puts(string s);
write_result putd(i64 n);
write_result putu(u64 n);
write_result putx(u64 n);

#endif
