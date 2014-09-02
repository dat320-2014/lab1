#include <stdio.h>
#include <stdlib.h>

int sort(const void * aa, const void * bb) {
	double a = *((double*)aa);
	double b = *((double*)bb);
	if(a <b) return -1;
	if(a == b) return 0;
	if(a > b) return 1;
}

double tab_sort_sum(double *tab, int tab_size) {

	// Sort the table, return the sum and the sorted table.
	qsort(tab, tab_size, sizeof(double), sort);
	printf("Sorted\n");
	double sum;
	int i;
	for(i = 0; i < tab_size; i++) {
		double tableValue = tab[i];
		printf("%f\n", tableValue);
		sum += tableValue;
	}
	return sum;
}
