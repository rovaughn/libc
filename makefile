
.PHONY: valgrind strace clean

valgrind: test
	valgrind -q --run-libc-freeres=no ./test

strace: test
	strace ./test >/dev/null

%.o: %.c
	./cc -c -O3 $< -o $@

test: bufio.o bytes.o fmt.o io.o os.o runtime.o strings.o syscall.o test.o
	./cc -O3 -flto -s $^ -o $@

clean:
	rm -rf *.gch *.o test

