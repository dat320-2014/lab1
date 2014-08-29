#include <stdio.h>
#include "lib1.h"

int main(void){
	int tab_size = 5, min = 0, max = 100, i = 0;
	double sum;
	char rangeReply[10];

	printf("Please write your desired table size: ");
	scanf("%d", &tab_size);

	while(strcmp(rangeReply, "y") != 0 && strcmp(rangeReply, "n") != 0){
		printf("Would you like to specify min and max value (default: 0-100)? (y/n): ");
		scanf("%s", &rangeReply);
	}

	if(strcmp(rangeReply, "y") == 0){
		printf("Please write desired minimum value: ");
        	scanf("%d", &min);

		printf("Please write desired maximum value: ");
        	scanf("%d", &max);
	}

	double tab[tab_size];

	srand((unsigned)time(NULL));

	for(i = 0; i < tab_size; i++){
		tab[i] = (rand() % (max-min)) + min;
	}
	
	sum  = tab_sort_sum(tab, tab_size);
	
	for(i = 0; i < tab_size; i++){
        	printf("%f \n", tab[i]);
        }

	printf("Sum is: %f \n", sum);	
}
