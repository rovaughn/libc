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
    int c;

    __asm__("mov %1, %%rax \n\
             add %%rax, %2 \n\
             mov %%eax, %0"
          : "=g" (c)
          : "g" (a), "g" (b)
          : "%rax"
    );

    return c;
}

int __subvsi3(a, b)
    int a;
    int b;
{
    int c;

    __asm__("mov %1, %%rax \n\
             sub %%rax, %2 \n\
             mov %%eax, %0"
          : "=g" (c)
          : "g" (a), "g" (b)
          : "%rax"
    );

    return c;
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
    int c;

    __asm__("mov %1, %%rax  \n\
             mov %2, %%rbx  \n\
             mul %%rbx      \n\
             mov %%eax, %0"
            : "=g" (c)
            : "g" (a), "g" (b)
            : "%eax", "%ebx"
    );

    return c;
}

