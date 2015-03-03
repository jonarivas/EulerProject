/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #12
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numberofDivisors(long long trianglenumber){
	long long i = 2;
	int divisorcounter = 2; //1 & trianglenumber
	while(i*i <= trianglenumber)
	{
		if(trianglenumber%i == 0){
			divisorcounter+=2;
		}
		i++;
	}
	return divisorcounter;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	long long trianglenumber = 1, i=2;
	int divcounter = 0;
	while(divcounter < 500){
		trianglenumber+=i;
		i++;
		divcounter = numberofDivisors(trianglenumber);
	}
	printf("%d\n",divcounter);
	printf("%lld",trianglenumber);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
