#include <stdio.h>

float multiply(float x1, float x2);


char s[] = "Hello World!";	// in .data

static int i;			// in .bss

const unsigned int lol = 14;	// in .rodata

int main(void) {
	#ifdef DEBUG
		printf("Debugging\n");
	#endif
	printf("Hello, world!\n");
	return 0;
}

float multiply(float x1, float x2) {
	return x1 * x2;
}
