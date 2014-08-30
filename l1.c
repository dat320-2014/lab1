#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b);

double tab_sort_sum (double *tab, int tab_size) {
    int i;
    double sum = 0;
    for (i = 0; i < tab_size; i++) {
	    sum += tab[i];
    }	    
    qsort(tab, tab_size, sizeof(double), cmpfunc);
    return sum;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(double*)a - *(double*)b );
}
