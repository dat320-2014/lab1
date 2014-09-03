#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double generate_random(double min, double max)
{
   double range = (max - min);
   double div = RAND_MAX/range;
   return min + (rand()/div);
}
void print_table_contents(double *tab, int tab_size)
{
  printf("***********************************************\n");
  printf("\n");
  printf("Contents of table is: \n");
  printf("\n");
  for (int i = 0; i < tab_size+1; ++i)
   { 
     printf("%e \n", tab[i]);
   }
  printf("\n");
  printf("***********************************************\n");
}
int main(int argc, char *argv[])
{
    int i;
    if ( argc < 2 ) /* Must have at least two input arguments */
    {
        printf("***********************************\n"); 
        printf( "usage: %s filename (int)table_size \n", argv[0] );
        printf( "optional arguments: (int)min (int)max \n");
	printf("\n");
        printf("Example: main.c 10 0 60 \n"); 
        printf("***********************************\n"); 
        return 0;
    }
    int table_size = atoi(argv[1]);
    double table[table_size];
    double rand_max = 100.0;
    double rand_min = 0.0; 
    if(argc == 3)
    {  
	    if(atof(argv[3]) != 0.00)
	    {
		 rand_max = atof(argv[3]);
	    }
    }
   if(argc == 4)
   {
	    if(atof(argv[2]) != 0.00)
	    {
	    	
		rand_min = atof(argv[2]);
	    }	   
   }
    for(i=0;i<table_size+1;i++)
    {
 	double rand = generate_random(rand_min,rand_max);	
        table[i] = rand;
    }	
    printf("\n");
    printf("Unsorted table: \n");
    print_table_contents(&table, table_size);
    printf("The sum of the sorted table is %e \n",(double)tab_sort_sum(&table,table_size));
    printf("(Obviously some kind of overflow happened here, since the two sums differ...\n");
    printf("\n");
    printf("Sorted table: \n");
    print_table_contents(&table, table_size);
}

