#include <stdlib.h>
#include <stdio.h>

int cmpfunc(const void *a, const void *b) {
	if (*(double*)a > *(double*)b) return 1;
	else if (*(double*)a < *(double*)b) return -1;	
	return 0; 
}

double tab_sort_sum(double *table, int size) {
	double sum = 0.0;
	int i;
	for (i=0; i<size; i++) {
		sum+=table[i];
	}
	qsort(table, size, sizeof(double), cmpfunc);
	return sum;
}
