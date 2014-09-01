#include <stdio.h>
int debug = 0;
int main(void) {
	if(debug) {	
		printf("Debug\n");
	}	
	printf("Hello, world!\n");
	return 0;
}
