#include "fmt.h"
#include "strings.h"
#include "os.h"

isize fputs(w, s)
    writer *w;
    string s;
{
    return w->write(w, (const byte*)s, strlen(s));
}

isize fputd(w, n)
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

isize fputu(w, n)
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

isize fputx(w, n)
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

isize puts(s)
    string s;
{
    return fputs((writer*)stdout, s);
}

isize putd(n)
    i64 n;
{
    return fputd((writer*)stdout, n);
}

isize putu(n)
    u64 n;
{
    return fputu((writer*)stdout, n);
}

isize putx(n)
    u64 n;
{
    return fputx((writer*)stdout, n);
}

