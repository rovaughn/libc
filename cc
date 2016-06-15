#!/bin/bash
set -eux -o pipefail
#gcc -Wall -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align \
#    -Wmissing-prototypes -Wstack-protector -Werror -pedantic \
#    -fstack-protector-all --param ssp-buffer-size=4 -std=iso9899:1999 -fPIE \
#    -ftrapv -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now -fno-builtin -nostdlib \
#    -nodefaultlibs -nostdinc "$@"
gcc -Wall -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align \
    -Wmissing-prototypes -Wstack-protector -Werror -pedantic -std=iso9899:1999 \
    -fno-builtin -nostdlib -nodefaultlibs -nostdinc \
    -O3 -flto -static -s \
    "$@"
