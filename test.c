#include "fmt.h"
#include "os.h"
#include "runtime.h"
#include "bufio.h"

void _start() {
    bufio_writer bw;

    new_bufio_writer(&bw, (writer*)stdout);

    fputs((writer*)&bw, "Your number is "); fputx((writer*)&bw, 0xfe3); fputs((writer*)&bw, ".\n");
    bufio_flush(&bw);

    exit(0);
}

