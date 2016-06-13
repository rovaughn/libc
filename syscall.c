#include "syscall.h"
#include "strings.h"

i64 sys_write(fd, data, len)
    u64 fd;
    const byte *data;
    u64 len;
{
    i64 result;

    __asm__("movq $1, %%rax\n\
             movq %1, %%rdi\n\
             movq %2, %%rsi\n\
             movq %3, %%rdx\n\
             syscall\n\
             movq %%rax, %0"
        : "=r" (result)
        : "ri" (fd), "m" (data), "ri" (len)
        : "%rdi", "%rsi", "%rdx", "%rax"
    );

    return result;
}

void __attribute__((noreturn)) sys_exit(error_code)
    u64 error_code;
{
    __asm__("movq $60, %%rax\n\
             movq %0, %%rdi\n\
             syscall"
        :
        : "ri" (error_code)
        : "%rax", "%rdi"
    );
    for (;;) {} // so GCC doesn't think this function returns.
}

