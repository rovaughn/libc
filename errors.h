#ifndef ERRORS_H
#define ERRORS_H

typedef enum {
    ERR_SUCCESS     = 0,
    ERR_EOF         = 1,
    ERR_ARG         = 2,
    ERR_SHORT_WRITE = 3
} error;

#endif
