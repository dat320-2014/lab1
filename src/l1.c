#include <stdio.h>
#include "l1.h"
#include <stdlib.h>

double tab_sort_sum(double *tab, int tab_size){
   // A version of bubble sort

   int swapped = 1;
   int idx;
   int big, small;
   double *table = tab;
   double sum;
   while(swapped == 0){
   for(idx = 1;idx < tab_size;idx ++){
   	if(table[idx -1] > table[idx]){
	  big = table[idx - 1];
	  small = table[idx];
	  table[idx] = big;
	  table[idx-1] = small;
	  swapped = 1;
	 }else{
	 swapped = 0;
    	}
    }
}

    for(idx = 0; idx < tab_size; idx ++){
    	sum += table[idx];
    }
    for(idx = 0; idx < tab_size; idx ++){
    	printf("%f ", table[idx]);
    }

    return sum;
}

    





	
