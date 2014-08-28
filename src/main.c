//Make a table of size give by an argument on the command line.
//Fill the table with random numbers between MIN and MAX
//MIN = 0.0 if not specified with another value on command line, i.e. optional argument
//MAX = 100.0 if not specified with another value on command line, i.e. optional argument
//Call tab_sort_sum() in lib1
//Print out table and sum

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "l1.h"

double randFloat(double min, double max);

double randFloat(double min, double max){
	//srand(time(NULL));
	double range = (max - min);
	double div = (RAND_MAX / range);
	return min + (rand() / div);
}
int main(int argc, char *argv[])
{
   int tableSize;

   double min = 0.0; //Default Min value
   double max = 100.0; //Default Max value

   if(atoi(argv[1])){
      tableSize = atoi(argv[1]);
   }else{
      printf("Error: You need to specify size yo\n");
      return -1;
   }
   double table[tableSize];
   if(atof(argv[2])){
      min = atof(argv[2]);
   }
   if(atof(argv[3])){
      max = atof(argv[3]);
   }
   srand(time(NULL));
   int i;
   for(i = 0; i < tableSize;i++){
      //table[i] = min + rand() % max;
      table[i] = randFloat(min,max);
   }
   printf("Here is our table:\n");
   for(i = 0; i < sizeof(table)/sizeof(double);i++){
      printf("%f, ",table[i]);
   }

   printf("Sorted table: \n \n");
   
   printf("Sum of table: %f\n",tab_sort_sum(table, sizeof(table)/sizeof(double)));


   return 0;
      
}
      
