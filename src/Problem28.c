/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #28
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	int sum = 0, n = 1, i, j;
	int size = 1001;
	sum = n;
	for(i = 2; i < size; i+=2){
		for(j = 0; j< 4; j++){
			n += i;
			sum += n;
		}
	}

	printf("diagonal sum = %d", sum);


	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}

