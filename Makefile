main: main.c l1.h libl1.a
	gcc main.c -o main -L . -l l1

libl1.a: l1.c l1.h
	gcc -c l1.c -o l1.o
	ar rcs libl1.a l1.o

Test:
	./main 4
