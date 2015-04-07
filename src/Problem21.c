/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #21
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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

int getSumDivisors(int number){
	int i=1, sum = 0;
	while(i <= number/2)
	{
		if(number%i == 0){
			sum+= i;
		}
		i++;
	}
	return sum;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	int i, sum, total=0;
	for(i=2; i<=10000; i++){
		sum = getSumDivisors(i);
		if (sum > i && getSumDivisors(sum) == i){
			total += sum + i;
		}
	}
	printf("%d", total);


	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
