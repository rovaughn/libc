#include "fmt.h"
#include "os.h"

void _start(void);

void _start() {
    fputs(stdout, "Your number is ");
    fputx(stdout, 0xfe3);
    fputs(stdout, ".\n");

    exit(0);
}

