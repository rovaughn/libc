
.PHONY: valgrind strace clean compare-sizes

valgrind: test
	valgrind -q --run-libc-freeres=no ./test

strace: test
	strace ./test >/dev/null

test: bufio.c bytes.c fmt.c io.c os.c runtime.c strings.c syscall.c debug.c test.c
	./cc -g $^ -o $@

compare: compare.c
	gcc -O3 -flto -static -s compare.c -o compare

compare-musl: compare.c
	musl-gcc -O3 -flto -static -s compare.c -o compare-musl

compare-sizes: test compare compare-musl
	ls -lah $^

clean:
	rm -rf *.gch *.o test

