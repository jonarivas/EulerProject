/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #6
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	int i;
	long sum =0, squared=0, squaredsum=0;
	for (i=1;i<=100;i++){
		sum += i;
		squared += pow(i,2);
	}
	squaredsum = pow(sum,2);
	printf("%lu - %lu = %lu", squaredsum, squared, squaredsum - squared);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
