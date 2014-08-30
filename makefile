main: l1.o main.o
	gcc l1.o main.o -o main

l1.o: l1.c
	gcc l1.c -c

main.o: main.c l1.h
	gcc main.c -c
