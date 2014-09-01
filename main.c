#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void main( int argc, char *argv[] )
{
	int antall;
	sscanf(argv[1], "%d", &antall);
	double table[antall];
	int i;
	srand(time(NULL));
	for (i = 0; i < antall; i++) 
	{
		table[i] = rand() % 100 + 1;
		printf("%.2f\n", table[i]);
	}
	double sum = tab_sort_sum(table, antall);
	printf("Sum is %.2f\n", sum);
}

