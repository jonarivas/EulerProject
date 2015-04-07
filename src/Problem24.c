/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #24
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printArray(int numbers[], int length){
	int i;
	for(i=0; i<length; i++){
		printf("%d", numbers[i]);
	}
	printf("\n");
}

void swap(int *number1, int* number2){
	int temp;
	temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}

int getLowerValuePosition(int numbers[], int referenceNumber, int length){
	int position = 0, i;
	for(i = 1; i < length; i++){
		if(numbers[i] < numbers[position] && numbers[i]>referenceNumber){
			position = i;
		}
	}
	return position;
}

void quicksort(int numbers[], int first,int last){
	int pivot,j,i;
	int temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while( numbers[i] <= numbers[pivot] && i<last)
				i++;
			while(numbers[j]>numbers[pivot])
				j--;
			if(i<j){
				temp=numbers[i];
				numbers[i]=numbers[j];
				numbers[j]=temp;
			}
		}

	 temp=numbers[pivot];
	 numbers[pivot]=numbers[j];
	 numbers[j]=temp;
	 quicksort(numbers,first,j-1);
	 quicksort(numbers,j+1,last);

    }
}

int isScrambled(int numbers[], int lenght){
	int i = lenght -2 ,islastnumber = 1;
	if (lenght == 1){
		return 1;
	}
	while(islastnumber && i >= 0){
		if(numbers[i] < numbers[i+1]){
			islastnumber = 0;
		}
		i--;
	}
	return islastnumber;
}

int getScrambledSize(int numbers[], int lenght){
	int size=1, scrambled=0, len = lenght - 1;
	while(!scrambled){
		if(numbers[len] > numbers[len - 1]){
			scrambled = 1;
		}
		else{
			len--;
			size++;
		}
	}
	return size;
}

void getCombination(int numbers[], int lenght, int combination){
	int j, end, size, position;
	end = lenght-1;
	size = getScrambledSize(numbers,lenght);
	j = lenght-size;
	combination--;
	while(combination){
		if (isScrambled(numbers+j, size)){
			position = getLowerValuePosition(numbers+j, numbers[j-1],size);
			swap(&numbers[j-1],&numbers[j+position]);
			quicksort(numbers,j,end);
		}
		size = getScrambledSize(numbers,lenght);
		j = lenght-size;
		combination--;
	}

}

#define LENGHT 10
int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	int numbers[LENGHT] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	getCombination(numbers,LENGHT,1000000);
	printArray(numbers,LENGHT);

	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
