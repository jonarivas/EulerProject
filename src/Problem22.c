/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #22
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countNumberofStrings(char *buffer, long length, char c){
	int counter = 0, i;
	for(i=0; i< length; i++){
		if (buffer[i] == c){
			counter++;
		}
	}
	return counter+1;
}

int getStringSize(char * string){
	int size = 0;
	while(string[++size] != '\x0');
	return size;
}

void quicksort(char *strings[], int first,int last){
	int pivot,j,i;
	char *temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while( strcmp(strings[i],strings[pivot])<=0 && i<last)
				i++;
			while( strcmp(strings[j],strings[pivot])>0)
				j--;
			if(i<j){
				temp=strings[i];
				strings[i]=strings[j];
				strings[j]=temp;
			}
		}

	 temp=strings[pivot];
	 strings[pivot]=strings[j];
	 strings[j]=temp;
	 quicksort(strings,first,j-1);
	 quicksort(strings,j+1,last);

    }
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	FILE *file;
	char * buffer;
	long length;
	int numberofStrings;
	long long score = 0;
	file = fopen("/home/jrivas/Downloads/p022_names.txt", "r");
	if (file == NULL) {
		printf("error opening");
	}
	fseek (file, 0, SEEK_END);
	length = ftell (file);
	fseek (file, 0, SEEK_SET);
	buffer = malloc (length * sizeof(char));
	if (buffer)
	{
		fread (buffer, 1, length, file);
	}
	fclose (file);

	numberofStrings = countNumberofStrings(buffer,length,',');
	char * names[numberofStrings];
	int i=0, j=0, temp = 0;
	char *token = strtok(buffer+1, "\",\"");
	names[i++] = token;
	while (token != NULL) {
		token = strtok(NULL, "\",\"");
		names[i++] = token;
	}

	quicksort(names,0,numberofStrings-1);

	for(i=0; i< numberofStrings; i++){
		temp = 0;
		for(j = getStringSize(names[i]) - 1; j >= 0; j--){
			temp += names[i][j] - ('A') +1;
		}
		score += temp * (i+1);

	}

	printf("score: %lld\n", score);

	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
