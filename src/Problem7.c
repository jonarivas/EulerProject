/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #7
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(long number) {
	int i;
	if(number % 2 == 0) {
		return 0;
	}
	for(i= 3; (i * i) <= number; i+=2) {
		if(number % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	int numberofprimes=1;
	long long number=2;
	while(numberofprimes<10001){
		if (isPrime(number)){
			numberofprimes++;
			printf("\n%d", numberofprimes);
		}
		number++;
	}
	printf("\nprime = %lu",number-1);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
