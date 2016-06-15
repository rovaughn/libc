#include "fmt.h"
#include "os.h"
#include "runtime.h"
#include "bufio.h"

int main() {
    bufio_writer bw;

    new_bufio_writer(&bw, (writer*)stdout);

    fputs((writer*)&bw, "Your number is "); fputx((writer*)&bw, 0xfe3); fputs((writer*)&bw, ".\n");
    bufio_writer_flush(&bw);

    return 0;
}

