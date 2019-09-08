CC = gcc
CFLAGS =-c -Wall -Wextra -O2 -pedantic -g #-ansi

all: calc

calc: main.o libfunc.a
	$(CC) main.o -o calc -L. -lfunc

main.o: main.c
	$(CC) $(CFLAGS) main.c

func.o: func.c
	$(CC) $(CFLAGS) func.c

libfunc.a: func.o
	ar rc libfunc.a func.o

clean:
	rm -rf *.o *.a calc

