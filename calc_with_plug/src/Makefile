CC = gcc
FLAGS = -pedantic -Wall -Wextra -O2 # -Werror
CFLAGS = -g -fPIC
TARGET = calc
BINDIR = ../
SRC = main.c func.c

.PHONY: all clean

all: $(BINDIR)$(TARGET)

$(BINDIR)$(TARGET): main.c func.c
	$(CC) $(FLAGS) $(SRC) -o $(BINDIR)$(TARGET) -ldl

clean:
	rm -rf $(BINDIR)$(TARGET)

