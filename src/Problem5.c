/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #5 projecteuler.net
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	struct timeval stop, start;
	int flag = 1;
	int  div, flagdiv = 0;
	int smallest = 20;
	do{
		smallest += 20;
		if (smallest % 19 == 0){
			div = 18;
			flagdiv = 1;
			do {
				if (smallest % div != 0){
					flagdiv = 0;
				}
				else{
					div--;
				}
			}while(flagdiv == 1 && div > 0);
			if (div == 0){
				flag = 0;
			}
		}

	}while (flag == 1);
	printf("\nlower divisor = %d", smallest);
	gettimeofday(&stop, NULL);
	printf("took %lu usec\n", stop.tv_usec - start.tv_usec);
}
