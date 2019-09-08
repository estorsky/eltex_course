CC = gcc
FLAGS = -pedantic -Wall -Wextra -O2 # -Werror
CFLAGS = -g -fPIC
LDFLAGS = -shared
TARGET = libAdd.so libSub.so libMul.so libDiv.so
DR = ../plugins/

.PHONY: all clean

all: $(DR)libAdd.so $(DR)libSub.so $(DR)libMul.so $(DR)libDiv.so

$(DR)libAdd.so: add.o
	$(CC) $(LDFLAGS) add.o -o $(DR)libAdd.so

$(DR)libSub.so: sub.o
	$(CC) $(LDFLAGS) sub.o -o $(DR)libSub.so

$(DR)libMul.so: mul.o
	$(CC) $(LDFLAGS) mul.o -o $(DR)libMul.so

$(DR)libDiv.so: div.o
	$(CC) $(LDFLAGS) div.o -o $(DR)libDiv.so

.c.o:
	$(CC) $(CFLAGS) $(FLAGS) -c $<

clean:
	rm -rf *.o
	rm -rf ../plugins/*.so

