#include "fmt.h"
#include "os.h"

void _start(void);

void _start() {
    fputs(stdout, "Your number is ");
    fputd(stdout, -125553);
    fputs(stdout, "\n");

    exit(0);
}

