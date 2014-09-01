#include <stdio.h> //printf NULL
#include <stdlib.h> //malloc
#include <time.h>
#include "l1.h"

int main(int argc, char *argv[] )
{
//Make a table of size give by an argument on the command line.
////Fill the table with random numbers between MIN and MAX
////MIN = 0.0 if not specified with another value on command line, i.e. optional argument
////MAX = 100.0 if not specified with another value on command line, i.e. optional argument
////Call tab_sort_sum() in lib1
////Print out table and sum

//argc = number of command line arguments

int tblsize;
int MIN = 0;
int MAX = 100;
double *tbl;

int i; //for loop

    //assume that argv0 = program name
    if(argc < 2){
        printf("Usage: %s tablesize min(optional) max(optional)\n", argv[0]);
        return 2;
    }

    tblsize = atoi(argv[1]);
    
    if(argc > 2){
        MIN = atoi(argv[2]);
    }

    if(argc > 3){
        MAX = atoi(argv[3]);
    }


    printf("tblsize: %d, min: %d, max: %d\n", tblsize, MIN, MAX);

    tbl = (double*) malloc (tblsize +1);    

    //generate random int and fill table
    srand(time(NULL));
    for(i = 0; i < tblsize; i++){
        double rnd = rand() % MAX + MIN;
        tbl[i] = rnd;
    }

    //sort table and get sum
    double sum = tab_sort_sum(tbl, tblsize);

    //print table
    for(i = 0; i < tblsize; i++){
        printf("%f\n", tbl[i]);
    }

    //print sum
    printf("Sum: %f\n", sum);


    return 0;
}


