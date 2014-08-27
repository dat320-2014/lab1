
# Makefile for the table sorting program
PNAME=tabsorter
SRC=main.c l1.c
TEST_ARGS=3 0 10

all: build
	
test: build
	./${PNAME} ${TEST_ARGS}

build: 
	gcc ${SRC} -o ${PNAME}
