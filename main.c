#include <stdio.h>
#include <stdlib.h>
#include "l1.h"

void main( int argc, char *argv[] ) {
    int max = 100;
    int min = 0;
    
    if (argc > 1) {
	    min = atoi(argv[2]);
    }
    if (argc > 2) {    
    	max = atoi(argv[3]);
    }
    
    double *my_table;
    int number_of_elements = atoi(argv[1]);
    my_table = malloc(number_of_elements * sizeof(double)); //create space in memory for table

    int i;
    for (i = 0; i < number_of_elements; i++) {
    	double r = rand() % (max - min + 1) + min;
	my_table[i] = r;	
    }	    

    double suma = 1;
    suma = tab_sort_sum(my_table, number_of_elements); 
    printf("Sum: %f\nSorted table: ", suma);                 
    
    for (i = 0; i < number_of_elements; i++) {
        printf("%f ",my_table[i]);
    }
    printf("\n");
    free(my_table); //free the memory
    
}



