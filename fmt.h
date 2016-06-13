#ifndef FMT_H
#define FMT_H

#include "io.h"

isize fputs(writer w, string s);
isize fputd(writer w, i64 n);
isize fputu(writer w, u64 n);
isize fputx(writer w, u64 n);

isize puts(string s);
isize putd(i64 n);
isize putu(u64 n);
isize putx(u64 n);

#endif
