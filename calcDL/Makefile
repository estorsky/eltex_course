CC = gcc
CFLAGS =-c -fPIC -Wall -Wextra -O2 -pedantic -g #-ansi

all: calc

calc: main.c libfunc.so
	$(CC) main.c -o calc -L. -lfunc

func.o: func.c
	$(CC) $(CFLAGS) func.c

libfunc.so: func.o
	$(CC) -shared func.o -o libfunc.so

clean:
	rm -rf *.o *.so calc

