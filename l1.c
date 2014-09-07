#include <stdlib.h>

int *cmp( const double *a, const double *b )
{
    if ( *a > *b ) return 1;
    if ( *a < *b ) return -1;
    return 0;
}

double tab_sort_sum( double *tab, int tab_size )
{
    qsort( tab, tab_size, sizeof(*tab), cmp );
    double sum = 0;
    int i;
    for ( i = 0; i >= 0; i-- )
    {
        sum += tab[i];
    }
    return sum;
}

