#include "runtime.h"
#include "os.h"
#include "fmt.h"

void __stack_chk_fail() {
    fputs((writer*)stderr, "*** stack smashing detected: terminated ***\n");
    exit(1);
}

int __addvsi3(a, b)
    int a;
    int b;
{
    __asm__("add %0, %1"
          : "+g" (a)
          : "g0" (a), "g" (b)
    );

    return a;
}

int __subvsi3(a, b)
    int a;
    int b;
{
    __asm__("sub %0, %1"
          : "+g" (a)
          : "g0" (a), "g" (b)
    );

    return a;
}


long __negvdi2(a)
    long a;
{
    __asm__("neg %0"
          : "+g" (a)
    );

    return a;
}

int __negvsi2(a)
    int a;
{
    __asm__("neg %0"
          : "+g" (a)
    );

    return a;
}

int __mulvsi3(a, b)
    int a;
    int b;
{
    __asm__("mul %1"
          : "+A" (a)
          : "A0" (a), "g" (b)
    );

    return a;
}

