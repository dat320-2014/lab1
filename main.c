#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "l1.h"



int main(int argc, char *argv[]){

	int N = 0;
	int i = 0;
	
	if(argc > 1){
		int err_chk = sscanf(argv[1], "%i", &N);
		if(err_chk!=1){
			printf("Invalid Argument![SIZE]\n");
			return -1;
		}
	}else{
		printf("Needs atleast 1 Argument!\n");
		return -1;
	}

	int MIN = 0;
	int MAX = 100;

	if(argc > 2){
		int err_chk = sscanf(argv[2], "%i", &MIN);
		if(err_chk!=1){
			printf("Invalid Argument![MIN]\n");
			return -1;
		}
	}

	if(argc > 3){
		int err_chk = sscanf(argv[3], "%i", &MAX);
		if(err_chk!=1){
			printf("Invalid Argument![MAX]\n");
			return -1;
		}
	}
	
	double *list;
	list = calloc( N, sizeof(double));

	srand(time(NULL));

	for(i = 0; i < N; i++){
		double mul = (double)rand()/RAND_MAX;
		double rand_val = (MAX - MIN + 1) * mul + MIN;
		list[i] = rand_val;
	}
	
	double sum = tab_sort_sum(list, N);

	printf("Sum=%f\n",sum);
	
	for(i = 0; i < N; i++){
		printf("%i. %f\n",i,list[i]);
	}

	free(list);	

	return 0;
}
