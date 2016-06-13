#include "os.h"
#include "syscall.h"

// TODO: These have to translate errors correctly.

isize stdout(buf, len)
    const byte *buf;
    usize len;
{
    return sys_write(1, buf, len);
}

isize stderr(buf, len)
    const byte *buf;
    usize len;
{
    return sys_write(2, buf, len);
}

void __attribute__((noreturn)) exit(error_code)
    u64 error_code;
{
    sys_exit(error_code);
}

