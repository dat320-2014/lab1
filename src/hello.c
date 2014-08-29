#include <stdio.h>

float multiply(float x1, float x2){
   return x1*x2;
}

int main(void){
   int integer;
   char character;
   short shortvar;
   float floating;

   printf("Hello, World!\n");

   printf("%.3f\n", multiply(3.2,4.0));

return 0;

}
