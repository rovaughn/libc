#include "os.h"
#include "syscall.h"

// TODO: These have to translate errors correctly.

fd_writer _stdout = {(write_fn)write_fd, 1};
fd_writer _stderr = {(write_fn)write_fd, 2};

fd_writer *stdout = &_stdout;
fd_writer *stderr = &_stderr;

isize write_fd(self, buf, len)
    fd_writer *self;
    const byte *buf;
    usize len;
{
    return sys_write(self->fd, buf, len);
}

void __attribute__((noreturn)) exit(error_code)
    u64 error_code;
{
    sys_exit(error_code);
}

