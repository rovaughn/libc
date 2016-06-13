#include "fmt.h"
#include "strings.h"
#include "os.h"

isize fputs(w, s)
    writer w;
    string s;
{
    return w((const byte*)s, strlen(s));
}

isize fputd(w, n)
    writer w;
    int n;
{
    bool negative = n < 0;

    if (negative) {
        n = -n;
    }

    byte result[11];
    u8 i;

    for (i = sizeof result - 1; i >= 0; i--) {
        switch (n % 10) {
        case 0: result[i] = '0'; break;
        case 1: result[i] = '1'; break;
        case 2: result[i] = '2'; break;
        case 3: result[i] = '3'; break;
        case 4: result[i] = '4'; break;
        case 5: result[i] = '5'; break;
        case 6: result[i] = '6'; break;
        case 7: result[i] = '7'; break;
        case 8: result[i] = '8'; break;
        case 9: result[i] = '9'; break;
        }

        n /= 10;

        if (n == 0) {
            break;
        }
    }

    if (negative) {
        result[--i] = '-';
    }

    return w(&result[i], sizeof result - i);
}

isize puts(s)
    string s;
{
    return fputs(stdout, s);
}

