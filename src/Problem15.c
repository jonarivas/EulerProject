/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #15
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long numberofRoutes(int sizeofSquare){
	long long square[sizeofSquare + 1][sizeofSquare + 1];
	int i,j;
	for (i = 0; i< sizeofSquare; i++){
		square[i][sizeofSquare] = 1;
		square[sizeofSquare][i] = 1;
	}
	for (i = sizeofSquare - 1; i >= 0; i--) {
	    for (j = sizeofSquare - 1; j >= 0; j--) {
	    	square[i][j] = square[i+1][j] + square[i][j+1];
	    }
	}

	return square[0][0];
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	long long routes = 0;
	routes = numberofRoutes(20);
	printf("# of Routes: %lld", routes);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
