#include <stdio.h>
int main(void) {
	#ifdef DEBUG
		printf("Debug\n");
	#endif
	printf("Hello, world!\n");
	return 0;
}
