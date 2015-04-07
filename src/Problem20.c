/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #20
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

char * substractChars(char * number1, char* number2){
//	 number1
//	-number2
//	--------
	int sizenumber1,sizenumber2,i,j, aux, carry;
	sizenumber1 = getStringSize(number1);
	sizenumber2 = getStringSize(number2);
	char *result;
	result = (char *)malloc(sizeof(char) * sizenumber1);
	carry = 0;
	for(i=sizenumber1-1, j=sizenumber2-1; i>=0; i--,j--){
		aux = (j>=0)? char2int(number2[j]):0;
		if (carry){
			aux += carry;
			carry = 0;
		}
		if (char2int(number1[i]) - aux < 0){
			aux -= 10;
			carry = 1;
		}
		result[i] = int2char(char2int(number1[i]) - aux);
	}
	return result;
}


char * multiplyChars(char * number1, char* number2){
//	 number1
//	xnumber2
//	---------
	int sizenumber1,sizenumber2,i,j, aux, carry, resultposition;
	sizenumber1 = getStringSize(number1);
	sizenumber2 = getStringSize(number2);
	char prelimresults[sizenumber2][sizenumber1+sizenumber2];
	char *result;
	result = (char *)malloc(sizeof(char) * sizenumber1+sizenumber2);
	for (i=0; i< sizenumber2; i++){
		memset (prelimresults[i],'0',(sizenumber1+sizenumber2-1));
	}
	for(i=sizenumber2 - 1; i>= 0 ; i--){
		carry = 0;
		resultposition = ((sizenumber2+sizenumber1)-1) - (sizenumber2-i);
		for(j=sizenumber1 - 1; j>=0; j--){
			aux = char2int(number2[i]) * char2int(number1[j]) + carry;
			prelimresults[(sizenumber2-1)-i][resultposition] = int2char(aux%10);
			resultposition--;
			carry = aux/10;
		}
		if (carry){
			prelimresults[i][resultposition] = int2char(carry);
		}
	}
	carry = 0;
	for (j=(sizenumber2+sizenumber1)-2; j >=0 ; j--){
		aux = carry;
		for (i=0; i<sizenumber2; i++){
			aux += char2int(prelimresults[i][j]);
		}
		result[j] = int2char(aux%10);
		carry = aux/10;
	}
	if(carry){
		result[j] = int2char(carry);
	}
	return result;
}

int string2int(char * number){
	int size,i, value = 0;
	size = getStringSize(number);
	for(i = size-1; i>=0; i--){
		value += char2int(number[i]) * (int)pow(10,(size-1)-i);
	}
	return value;
}

char * factorial(char *number){
	int value = 0;
	char* result;
	result = number;
	while(value != 1){
		number = substractChars(number,(char *) "1");
		result = multiplyChars(result, number);
		value = string2int(number);
	}
	return result;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	char * result;
	int size, i, sum =0;
	result = factorial("100");
	size = getStringSize(result);
	for(i = 0; i< size; i++){
		sum+= char2int(result[i]);
	}
	printf("%d", sum);

	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
