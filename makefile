
valgrind: test
	valgrind -q --run-libc-freeres=no ./test

strace: test
	strace ./test >/dev/null

test: *.c *.h
	gcc -Wall -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align \
        -Wmissing-prototypes -Wstack-protector -Werror -pedantic \
        -fstack-protector-all --param ssp-buffer-size=4 -pedantic \
		-std=iso9899:1999 \
		-pie -fPIE -ftrapv -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now \
		-fno-builtin -nostdlib -nodefaultlibs -nostdinc -g \
		-o test *.c

clean:
	rm -rf *.gch test

