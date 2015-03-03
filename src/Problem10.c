/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #10
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define limit 2000000

int isPrime(long number) {
	int i;
	if (number != 2){
		if(number % 2 == 0) {
			return 0;
		}
		for(i= 3; (i * i) <= number; i+=2) {
			if(number % i == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	long i=3;
	long long sum=2;
	for(;i<=limit;i+=2){
		if(isPrime(i)){
			sum+=i;
		}
	}
	printf("the sum is: %lld", sum);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
