/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #26
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define int2char(x) (x+'0')

int getStringSize(char * string){
	int size = 0;
	while(string[++size] != '\x0');
	return size;
}

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

int checkforRepetition(char* decimals, int i,int j){
	int size = j-i, stringSize = getStringSize(decimals);
	char str1[size+1], str2[size+1], str3[size+1], str4[size+1];
	int k,l;
	k = j+size;
	l = k+size;
	if(stringSize <= ((size*2) + i) || (l+size) > 3999){
		return 0;
	}
	memset(str1,'\x0',size+1);
	memset(str2,'\x0',size+1);
	memset(str3,'\x0',size+1);
	memset(str4,'\x0',size+1);
	strncpy(str1,decimals+i,size);
	strncpy(str2,decimals+j,size);
	strncpy(str3,decimals+k,size);
	strncpy(str4,decimals+l,size);
	if(!strcmp(str1,str2) && !strcmp(str1,str3) && !strcmp(str1,str4)){
		return 1;
	}
	return 0;
}

int maxRepetition(char* decimals){
	int repetitionLenght = 0, length,i=0,j;
	length = getStringSize(decimals);
	j = i+1;
	while(i < (length -1) && !repetitionLenght){
		if (decimals[i] == decimals[j]){
			if(checkforRepetition(decimals,i,j)){
				repetitionLenght = j-i;
			}
		}
		j++;
		if (j >= length){
			i++;
			j=i+1;
		}
	}
	return repetitionLenght;
}

int divisionwithmodule(int dividend, int divisor){
	int aux = dividend;
	int rep = 0;
	char decimals[4000] = {'\x0'};
	int i = 0;
	while(aux && !rep && i<4000){
		aux*=10;
		decimals[i] = int2char(aux/divisor);
		decimals[i + 1] = '\x0';
		aux = aux%divisor;
		i++;
	}
	rep = maxRepetition(decimals);
	//printf("1/%d(%d) =  %s\n", divisor, rep ,decimals);
	return rep;
}



int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	int i, maxrep = 0, maxnumber=0, aux;
	for (i=2; i<1000; i++){
		if(isPrime(i)){
			aux = divisionwithmodule(1,i);
			if ( aux > maxrep){
				maxrep = aux;
				maxnumber = i;
			}
		}
	}

	printf("maxnumber = %d with reps = %d", maxnumber,maxrep);


	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}

