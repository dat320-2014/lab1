#include <stdlib.h>
#include <stdio.h>
#include "l1.h"
double tab_sort_sum(double *, int);


void main( int argc, char *argv[] )
{
	int antall;
	sscanf(argv[1], "%d", &antall);
	double table[antall];
	int i;
	for (i = 0; i < antall; i++) 
	{
		table[i] = rand() % 100 + 1;
		printf("%.2f\n", table[i]);
	}
	double sum = tab_sort_sum(table, antall);
	printf("Sum is %1f\n", sum);
}

