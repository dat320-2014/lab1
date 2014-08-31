#include <stdio.h>
#define CONSTANT 42 //.rodata

int main(void){
    int i; //.bss
    char str[] = "Hello!"; //.data
    
    printf("Hello world!\n");
    return 0;
}

float double_multiply(float x1, float x2) {
    return x1*x2;	
}


