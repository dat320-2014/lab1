#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "l1.h"

#define TABLE_SIZE 30

int main(int args, char *argv[]) {
	double table[TABLE_SIZE];
	srand(time(NULL));
	int i;
	double min = 0.0;
	double max = 100.0;
	double sum;
	if (args == 3) {
		min = atof(argv[1]);
		max = atof(argv[2]);
	}
	for (i=0; i<TABLE_SIZE; i++) {
		table[i] = (double)rand() / (double) RAND_MAX * (max-min) + min;
	}
	sum = tab_sort_sum(table, TABLE_SIZE);
	for (i=0; i<TABLE_SIZE; i++) {
		printf("%f\n", table[i]);
	}
	printf("%f\n",sum);
	return 0;
} 
