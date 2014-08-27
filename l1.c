
#ifndef STDLIB_H
#define STDLIB_H
#include<stdlib.h>
#endif




static int compare(const void *a, const void *b){

	double first = *(double*)a;
	double second = *(double*)b;

	if(first > second){
		return 1;
	}
	
	if(first < second){
		return -1;
	}

	return 0;
}


double tab_sort_sum( double *tab, int tab_size){

	
	qsort(tab, tab_size, sizeof(double), compare);

	double sum = 0;
	int i = 0;
	
	for(i = 0; i < tab_size; i++){
		sum += tab[i];
	}

	return sum;
}
