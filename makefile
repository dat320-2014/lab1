.PHONY: all clean
CC=gcc
CFLAGS := -std=c99 -g -Wall -Wextra
DEPS = sort_sum.h
OBJ = main.o sort_sum.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
