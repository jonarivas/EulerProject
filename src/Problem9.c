/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #9
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define sumlimit 1000

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	int a =5, b=6, c=0, sqrtc=0;
	int exit = 0;

	while( (a+b+sqrtc) < sumlimit && exit == 0){
		while (a+b+sqrtc < sumlimit && exit == 0){
			c = a*a + b*b;
			sqrtc = (int)sqrt(c);
			if (a+b+sqrtc == 1000 && sqrtc*sqrtc == c){
				exit = 1;
			}
			else{
				b++;
			}
		}
		if (!exit){
			a++;
			b = a + 1;
			c = 0;
		}
	}
	printf("%d*%d + %d*%d = %d = %d*%d = %d\n", a,a,b,b,c,sqrtc,sqrtc,sqrtc*sqrtc);
	printf("a*b*c = %d", a*b*sqrtc);

	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
