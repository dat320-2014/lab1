#include <stdlib.h>
#include <stdio.h>

int comp(const void * a, const void * b) 
{
	return ( *(double*)a - *(double*)b );
}

double tab_sort_sum( double *tab, int tab_size )
{
	qsort(tab, tab_size, sizeof(double), comp);
	double sum;
	int i;
	printf("sorted:\n");
	for (i = 0; i < tab_size; i++)
       	{
		printf("%.2f\n", tab[i]);
		sum += tab[i];
	}
	return sum;
}
