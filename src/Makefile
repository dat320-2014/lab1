#Makefile
#v 1.0

all: main hello

hello: hello.o
	gcc hello.o -o hello
hello.o: hello.c
	gcc -c hello.c
main: main.o l1.o
	gcc main.o l1.o -o main
main.o: main.c
	gcc -c main.c
l1.o: l1.c
	gcc -c l1.c
clean:
	rm -rf *o main hello
test: main hello main.o l1.o hello.c
	./main 10 1 10
	./hello
