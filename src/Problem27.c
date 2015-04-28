/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #27
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int number) {
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

int checkForPrimes(int a, int b){
	int n =0, prime = n*n + a*n + b;
	while(isPrime(prime) && prime > 0){
		n++;
		prime = n*n + a*n + b;
	}
	return n;
}

int getProduct(){
	int i,j,a,b,numberofPrimes =0, aux;
	for(i = -1000; i<1000; i++){
		for(j = -1000; j<1000; j++){
			aux = checkForPrimes(i,j);
			if (aux > numberofPrimes){
				numberofPrimes = aux;
				a = i;
				b = j;
			}
		}
	}
	return a*b;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);



	printf("maxproduct = %d", getProduct());


	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}

