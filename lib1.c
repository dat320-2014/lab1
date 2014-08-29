#include <stdio.h>
#include "lib1.h"

double tab_sort_sum(double *tab, int tab_size){
	int i = 0, c, d, n, swap;
	double sum;

	n = tab_size;

	/* Bubble sort algorithm */
	for (c = 0 ; c < ( n - 1 ); c++)
  	{
  	  for (d = 0 ; d < n - c - 1; d++)
  	  {
  	    if (tab[d] > tab[d+1]) /* For decreasing order use < */
  	    {
  	      swap      = tab[d];
  	      tab[d]   = tab[d+1];
  	      tab[d+1] = swap;
  	    }
  	  }
  	}
	sum = 0;
	for(i = 0; i < tab_size; i++){
		sum += tab[i];
	}
	return sum; 
}
