/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #23
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 28123
#define SMALLEST 24

int isAbundant(int number){
	int i=(int)sqrt(number), sum = 1, isAbundant = 0;
	while(i > 1 && isAbundant == 0)
	{
		if(number%i == 0){
			if (i == number/i){
				sum+= i;
			}
			else{
				sum+= (i + number/i);
			}
			if (sum > number){
				isAbundant = 1;
			}
		}
		i--;
	}
	return isAbundant;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	int i,j,k, isASum = 0;
	long long sum = 0;

	for(i=1;i<SMALLEST;i++){
		sum+=i;
	}

	for(;i<LIMIT;i++){
		j=12;
		k=i-j;
		isASum = 0;
		while(j<k && !isASum){
			if(isAbundant(j)){
				if (isAbundant(k)){
					isASum = 1;
				}
			}
			j++;
			k--;
		}
		if(j==k && !isASum){
			if (isAbundant(j)){
				isASum = 1;
			}
		}
		if(!isASum){
			sum += i;
		}
	}

	printf("SUM = %lld", sum);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
