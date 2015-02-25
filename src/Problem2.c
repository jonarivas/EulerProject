/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	long long limite = 4000000;
	long long fibonacci[2] = {1,2};
	long long bubble = 0, acum = 2;
	bubble = fibonacci[0] + fibonacci[1];
	while (bubble < limite) {
		fibonacci[0] = fibonacci[1];
		fibonacci[1] = bubble;
		if (bubble % 2 == 0){
			acum += bubble;
		}
		bubble = fibonacci[0] + fibonacci[1];
	}
	printf("acum = %d", acum);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
}
