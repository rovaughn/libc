#include "runtime.h"
#include "os.h"
#include "fmt.h"

#define DEBUG_TRAP 0

#if DEBUG_TRAP
#include "debug.h"
#endif

void __stack_chk_fail() {
    fatal("*** stack smashing detected: terminated ***\n");
}


long __addvdi3(a, b)
    long a;
    long b;
{
#if DEBUG_TRAP
    debug_puts("__addvdi3\n");
#endif

    __asm__("add %2, %0\n\
             jnc ok%=\n\
             movl %3, %%edi\n\
             call fatal\n\
             add $8, %%esp\n\
             ok%=:"
          : "+g" (a)
          : "g0" (a), "g" (b), "g" ("Addition overflow detected: terminated\n")
    );

    return a;
}

int __addvsi3(a, b)
    int a;
    int b;
{
#if DEBUG_TRAP
    debug_puts("__addvsi3\n");
#endif
    __asm__("add %2, %0\n\
             jnc ok%=\n\
             movl %3, %%edi\n\
             call fatal\n\
             add $8, %%esp\n\
             ok%=:"
          : "+g" (a)
          : "g0" (a), "g" (b), "g" ("Addition overflow detected: terminated\n")
    );

    return a;
}

int __subvsi3(a, b)
    int a;
    int b;
{
#if DEBUG_TRAP
    debug_puts("__subvsi3\n");
#endif
    __asm__("sub %2, %0\n\
             jnc ok%=\n\
             movl %3, %%edi\n\
             call fatal\n\
             add $8, %%esp\n\
             ok%=:"
          : "+g" (a)
          : "g0" (a), "g" (b), "g" ("Subtraction overflow detected:: terminated\n")
    );

    return a;
}


long __negvdi2(a)
    long a;
{
#if DEBUG_TRAP
    debug_puts("__negvdi2\n");
#endif
    __asm__("neg %0\n\
             jnc ok%=\n\
             movl %2, %%edi\n\
             call fatal\n\
             add $8, %%esp\n\
             ok%=:"
          : "+g" (a)
          : "g0" (a), "g" ("Negation overflow detected: terminated\n")
    );

    return a;
}

int __negvsi2(a)
    int a;
{
#if DEBUG_TRAP
    debug_puts("__negvsi2\n");
#endif
    __asm__("neg %0\n\
             jnc ok%=\n\
             movl %2, %%edi\n\
             call fatal\n\
             add $8, %%esp\n\
             ok%=:"
          : "+g" (a)
          : "g0" (a), "g" ("Negation overflow detected: terminated\n")
    );

    return a;
}

int __mulvsi3(a, b)
    int a;
    int b;
{
#if DEBUG_TRAP
    debug_puts("__mulvsi3\n");
#endif
    __asm__("mul %2\n\
             jnc ok%=\n\
             movl %2, %%edi\n\
             call fatal\n\
             add $8, %%esp\n\
             ok%=:"
          : "+A" (a)
          : "A0" (a), "r" (b), "g" ("Multiplication overflow detected: terminated\n")
    );

    return a;
}

char stack[1024*1024];

void _start() {
    __asm__ volatile("mov %0, %%rsp\n\
                      mov %0, %%rbp"
                   :
                   : "g" (&stack[sizeof stack])
    );

    exit(main());
}

