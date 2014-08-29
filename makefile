all: Program

%.o: %.c lib1.h
	gcc -c $< -o $@

Program: main.o lib1.o
	gcc main.o lib1.o -o Program

TestProgram: main.c lib1.c
	gcc main.c lib1.c -o TestProgram

main.o: main.c
	gcc -c main.c

lib1.o: lib1.c
	gcc -c lib1.c

clean:
	rm -rf *o Program 
