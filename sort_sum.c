#include <stdlib.h>
#include <stdio.h>
#include "sort_sum.h"

double tab_sort_sum(double *tab, int tab_size)
{
   double sum = 0.0;
   int i;
   qsort(tab, tab_size, sizeof (double), compare_doubles);
   for (i = 0; i <= tab_size+1; ++i)
   { 
      sum += tab[i];
   }
   printf("Sum before return of tab_sort_sum(***): %e (Correct sum!)\n", sum);
   return sum;
}
int compare_doubles(const void *x, const void *y)
{
  double xx = *(double*)x, yy = *(double*)y;
  if (xx < yy) return -1;
  if (xx > yy) return  1;
  return 0;
}
