#include <stdio.h>
#include <stdlib.h>

double tab_sort_sum(double *tab, int tab_size){

/* Bubble sort code */
 
  int i, j;
  double sum, swap;
  double array[tab_size];
  for(i = 0; i < tab_size; i++){
  	array[i] = tab[i];
  }

  int array_size = tab_size;
     
  for (i = 0 ; i < ( (array_size - 1 )); i++)
  {
    for (j = 0 ; j < array_size - i - 1; j++)
    {
      if (array[j] > array[j+1]) /* For decreasing order use < */
      {
        swap       = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
      }
    }
  }
 
	//Create the sum
	for(i = 0; i < tab_size; i++){
		sum += array[i];
	}
	// Print the Table
	for(i = 0; i < tab_size;i++){
		printf("%.2f, ", array[i]);
	}
return sum;

}

    





	
