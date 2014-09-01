#include <stdio.h>
const int one = 1;
int two = 2;
int zero = 0;
int uninitialized;


float multiply(float x1, float x2) {
	return x1*x2;
}


int main(void) {
	printf("Hello, world! %d %d %d %d\n",zero,uninitialized,one,two);
	printf("%f\n", multiply(3,4));
	return 0;
}
