SRC=test.c
LIB_PRE=test

all:libtest.so test_lib

libtest:
	cc -fPIC -c ${SRC}
	cc -shared ${LIB_PRE}.o -o libtest.so

test_lib:
	gcc -g test_lib.c -o test_lib -ldl

clean:
	rm -f *.o
	rm -f *.so
	rm -f test_lib
