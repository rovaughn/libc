#include "debug.h"

void debug_puts(s)
    const char *s;
{
    usize i;

    for (i = 0; s[i] != '\0'; i++);

    sys_write(2, (const byte*)s, i);
}

void debug_hex(n)
    u64 n;
{
    char msg[16];

    int i;
    for (i = 0; i < 16; i++) {
        int r = (n >> (4*i))&0xf;

        if (r < 10) {
            msg[15 - i] = '0' + r;
        } else {
            msg[15 - i] = 'a' + (r - 10);
        }
    }

    sys_write(2, (const byte*)&msg, sizeof msg);
}

void debug_buffer(buf, len)
    const byte *buf;
    usize len;
{
    byte result[1024];
    usize j = 0;

    u64 i;
    for (i = 0; i < len; i++) {
        int a = (buf[i] >> 4)&0xf;
        int b = (buf[i] >> 0)&0xf;

        if (a < 10) {
            result[j++] = '0' + a;
        } else {
            result[j++] = 'a' + (a - 10);
        }

        if (b < 10) {
            result[j++] = '0' + b;
        } else {
            result[j++] = 'a' + (b - 10);
        }

        if (j == sizeof result) {
            sys_write(2, result, j);
            j = 0;
        }
    }

    sys_write(2, result, j);
}

