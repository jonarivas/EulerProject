/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #14
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define limit (1000000)

int numberofSequences(long number){
	if (number == 1){
		return 1;
	}
	else {
		if(number % 2 == 0){
			return 1 + numberofSequences(number/2);
		}
		else {
			return 1 + numberofSequences(3 * number + 1);
		}
	}
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	long i=0, maxNumber = 0, maxSequence = 0, sequence;
	for (i=1;i<limit;i++){
		sequence = numberofSequences(i);
		if (sequence > maxSequence){
			maxSequence = sequence;
			maxNumber = i;
		}
	}
	printf("%ld",maxNumber);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
