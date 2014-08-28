//Make a table of size give by an argument on the command line.
//Fill the table with random numbers between MIN and MAX
//MIN = 0.0 if not specified with another value on command line, i.e. optional argument
//MAX = 100.0 if not specified with another value on command line, i.e. optional argument
//Call tab_sort_sum() in lib1
//Print out table and sum

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

	if(atoi(argv[1])){
		tableSize = atoi(argv[1]);
	}else{
		printf("Error: You need to specify size yo\n");
		return -1;
	}
	
	double table[tableSize];
	
	if(argv[2] != NULL){
		min = atof(argv[2]);
	}
	if(argv[3] != NULL){
		max = atof(argv[3]);
	}
	
	
	sclk();			// Seeds the timer
	int i;
	for(i = 0; i < tableSize;i++){
		//table[i] = min + rand() % max;
		table[i] = randDouble(min,max);
	}

	printf("\nHere is our table:\n");
	for(i = 0; i < sizeof(table)/sizeof(double);i++){
		printf("%f, ",table[i]);
	}

	printf("\n\nSorted table:\n");
   
	double sum = tab_sort_sum(table,tableSize);

	printf("\nSum of table: %f\n\n", sum);
	
return 0;
      
}
      
