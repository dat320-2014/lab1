#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "l1.h"

void sclk(){
	srand(time(NULL));
}

double randDouble(double min, double max){
	double range = (max - min);
	double div = (RAND_MAX / range);
	return min + (rand() / div);
}

int main(int argc, char *argv[])
{
	int tableSize;
	//Default Values	
	double min = 0;
	double max = 100;

	if(argc == 1){
		printf("Error: You need to specify Array Size\n");
		printf("Usage: main [size] [min] [max]\n");
		return -1;
	}else{
		tableSize = atoi(argv[1]);
	}
	
	double table[tableSize];
	if(argc >= 3){
		min = atof(argv[2]);
		printf("HELLOOOAOODOWDOAOWDE921823912316212616926912639");
	}else{
		min = 0.0;
	}
	if(argc >= 4){
		max = atof(argv[3]);
	}else{
		max = 100.0;
	}
	
	
	sclk();			// Seeds the timer
	int i;
	for(i = 0; i < tableSize;i++){
		//table[i] = min + rand() % max;
		table[i] = randDouble(min,max);
	}

	printf("\nHere is our table:\n");
	for(i = 0; i < sizeof(table)/sizeof(double);i++){
		printf("%.2f, ",table[i]);
	}

	printf("\n\nSorted table:\n");
   
	double sum = tab_sort_sum(table,tableSize);

	printf("\n\n**Sum of table: %.2f**\n\n", sum);
	
return 0;
      
}
      
