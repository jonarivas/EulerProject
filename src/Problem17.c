/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #17
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int getlength(char * string){
	int size = 0;
	while(string[++size] != '\x0');
	return size;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	char * numbers[90] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen" ,"sixteen", "seventeen", "eighteen", "nineteen"};
	numbers[20-1] = "twenty";
	numbers[30-1] = "thirty";
	numbers[40-1] = "forty";
	numbers[50-1] = "fifty";
	numbers[60-1] = "sixty";
	numbers[70-1] = "seventy";
	numbers[80-1] = "eighty";
	numbers[90-1] = "ninety";
	int i, aux;
	long long sum = 0;
	for (i = 1; i<= 1000; i++){
		if (i <= 90 && numbers[i - 1] != 0){
			sum+= getlength(numbers[i-1]);

		}
		else{
			aux = i;
			if (aux / 1000){
				sum+= getlength(numbers[aux/1000 -1]);

				sum+= getlength("thousand");

			}
			if (aux % 1000){
				aux %= 1000;
				if (aux / 100){
					sum+= getlength(numbers[aux/100 -1]);

					sum+= getlength("hundred");

					if (aux % 100){
						sum+= getlength("and");

					}
				}
				if (aux % 100){
					aux %= 100;
					if (aux <= 20){
						sum+= getlength(numbers[aux - 1]);

					}
					else {
						sum+= getlength(numbers[(aux/10) * 10 -1]);

						if (aux%10){
							sum+= getlength(numbers[aux%10 -1]);

						}
					}
				}
			}
		}

	}
	printf("%lld\n", sum);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
