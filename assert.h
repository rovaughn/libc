#ifndef ASSERT_H
#define ASSERT_H

#include "fmt.h"

void assert(string message, bool condition) {
    if (!condition) {
        fputs(stderr, "Assertion failed: ");
        fputs(stderr, message);
    }
}

#endif
