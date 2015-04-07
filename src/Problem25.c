/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #25
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#define int2char(x) (x+'0')
#define char2int(x) (x-'0')

int getStringSize(char * string){
	int size = 0;
	while(string[++size] != '\x0');
	return size;
}

char * addChars(char * number1, char* number2){
//	 number1
//	+number2
//	--------
	int sizenumber1,sizenumber2,i,j, aux, carry, maxlength;
	sizenumber1 = getStringSize(number1);
	sizenumber2 = getStringSize(number2);
	maxlength = (sizenumber1 > sizenumber2 ? sizenumber1 : sizenumber2);
	char *result;
	result = (char *)malloc(sizeof(char) * (maxlength + 2));
	memset( result, '\0', sizeof(char)*(maxlength + 2) );
	i = sizenumber1 -1;
	j = sizenumber2 -1;
	carry = 0;
	while(maxlength >= 0){
		aux = carry;
		if (i >= 0){
			aux += char2int(number1[i]);
			i--;
		}
		if (j >= 0){
			aux += char2int(number2[j]);
			j--;
		}
		carry = aux / 10;
		result[maxlength] = int2char(aux % 10);
		maxlength--;
	}
	if (result[0] == '0'){
		return result+1;
	}
	return result;
}

int getFibonacciNumber(int length){
	char* number1 = "1";
	char* number2 = "1";
	char* aux;
	int term = 2;
	do{
		aux = number2;
		number2 = addChars(number1, number2);
		number1 = aux;
		term++;
	}while(getStringSize(number2)<length);
	return term;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	int term;
	term = getFibonacciNumber(1000);
	printf("%d", term);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}

