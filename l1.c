#include <stdlib.h>

//http://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
int cmp(const void * a, const void * b)
{
    return ( *(double*)a - *(double*)b );
}

double tab_sort_sum (double *tab, int tab_size){
    //sort the table, return the sum and the sorted table
    qsort(tab, tab_size, sizeof(double), cmp);

    double sum = 0;
    int i;


    for (i = 0; i < tab_size; i++){
        sum = sum + tab[i];
    }

    return sum;
}

