/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	long long number = 600851475143;
	int maxprimenumber = 2, primenumber = 2;
	while (number > 2){
		primenumber = 1;
		while (number%(++primenumber));
		number/=primenumber;
		if (maxprimenumber < primenumber) {
			maxprimenumber = primenumber;
		}
	}
	printf("max prime number = %d", maxprimenumber);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
}
