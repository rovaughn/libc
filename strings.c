#include "strings.h"

usize strlen(s)
    string s;
{
    usize i;

    for (i = 0; s[i] != '\0'; i++);

    return i;
}

