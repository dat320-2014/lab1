#include <stdio.h>

int datavar = 42;
int bssvar;
static const float rodatavar = 3.14159f;

int main(void){
	
	#ifdef DEBUG
		printf("Debug mode!\n");
	#endif

	printf("Hello World!\n");

	return 0;
}
