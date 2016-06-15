#include "fmt.h"
#include "strings.h"
#include "os.h"
#include "syscall.h"

void fatal(s)
    string s;
{
    sys_write(2, (const byte*)s, strlen(s));
    exit(1);
}

write_result fputs(w, s)
    writer *w;
    string s;
{
    return w->write(w, (const byte*)s, strlen(s));
}

write_result fputd(w, n)
    writer *w;
    i64 n;
{
    bool negative = n < 0;

    u64 un = negative ? (u64)(-n) : (u64)n;
    byte result[21];
    u8 i;

    for (i = sizeof result - 1; i >= 0; i--) {
        result[i] = '0' + (un % 10);
        un /= 10;

        if (un == 0) {
            break;
        }
    }

    if (negative) {
        result[--i] = '-';
    }

    return w->write(w, &result[i], sizeof result - i);
}

write_result fputu(w, n)
    writer *w;
    u64 n;
{
    byte result[20];
    u8 i;

    for (i = sizeof result - 1; i >= 0; i--) {
        result[i] = '0' + (n % 10);
        n /= 10;

        if (n == 0) {
            break;
        }
    }

    return w->write(w, &result[i], sizeof result - i);
}

write_result fputx(w, n)
    writer *w;
    u64 n;
{
    byte result[16];
    u8 i;

    for (i = sizeof result - 1; i >= 0; i--) {
        u8 remainder = n & 0xf;

        if (remainder < 10) {
            result[i] = '0' + remainder;
        } else {
            result[i] = 'a' + (remainder - 10);
        }

        n >>= 4;

        if (n == 0) {
            break;
        }
    }

    return w->write(w, &result[i], sizeof result - i);
}

write_result puts(s)
    string s;
{
    return fputs((writer*)stdout, s);
}

write_result putd(n)
    i64 n;
{
    return fputd((writer*)stdout, n);
}

write_result putu(n)
    u64 n;
{
    return fputu((writer*)stdout, n);
}

write_result putx(n)
    u64 n;
{
    return fputx((writer*)stdout, n);
}

