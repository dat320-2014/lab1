#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "l1.h"

void main(int argc, char *argv[]) {
	//Make a table of size given by an argument on the command line.
	int listSize;
       	sscanf(argv[1], "%d", &listSize);
	double list[listSize];
	printf("listSize: %d\n", listSize);

	//MIN = 0.0 if not specified with another value in command line, i.e optional argument
	int MIN = 0;
	if(argc > 2) sscanf(argv[2], "%d", &MIN);
	printf("MIN: %d\n", MIN);

	//MAX = 100.0 if not specified with another value on command line, i.e optional argument
	int MAX = 100;
	if(argc > 3) sscanf(argv[3], "%d", &MAX);
	printf("MAX: %d\n", MAX);

	//Fill the table with random numbers between MIN and MAX.	
	srand(time(NULL));
	int i = 0;
	for(i = 0; i < listSize; i++) {
		list[i] = (((float)rand() / RAND_MAX) * (MAX-MIN))+MIN;
		printf("list:%d \t  %f\n",i, list[i]);
	}

	//Call tab_sort_sum() in lib1
	double sum = tab_sort_sum(list, listSize);
	printf("Sum: %f\n", sum);

	//Print out table and sum.
}
