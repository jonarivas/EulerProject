/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getSize(long palindrome){
	int size = 0;
	do{
		size++;
	}while (palindrome/=10);
	return size;
}
int isPalindrome(long palindrome){
	int size, odd = 0,i;
	long highMask, lowMask, reverseLowMask = 0, aux;
	size = getSize(palindrome);
	if (size%2 != 0){
		odd = 1;
	}
	aux = pow(10,size/2);
	lowMask = palindrome % aux;
	if (odd){
		aux = pow(10,(size/2)+odd);
	}
	highMask = palindrome / aux;
	for (i=0;i<size/2;i++){
		aux = lowMask / pow(10,(size/2)-(1+i));
		lowMask -= aux * pow(10,(size/2) - (1+i));
		reverseLowMask += aux * pow(10,i);
	}
	if (highMask == reverseLowMask)
		return 1;
	return 0;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	long result, palindrome=0;
	int i,j;
	for(i=100;i<=999;i++){
		for(j=i;j<=999;j++){
			result = i*j;
			if (isPalindrome(result) && result > palindrome){
				palindrome = result;
			}
		}
	}
	printf("%lu", palindrome);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
