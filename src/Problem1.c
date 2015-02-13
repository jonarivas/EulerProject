/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #1 projecteuler.net
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	int i, acum = 0;
	for (i=1;i<1000; i++){
		if (i%3 == 0 || i%5 == 0){
			acum += i;
		}
	}
	printf("number = %d\n", acum);
	gettimeofday(&stop, NULL);
	printf("took %lu usec\n", stop.tv_usec - start.tv_usec);
}
