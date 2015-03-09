/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #18
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left, *right;
	int data;
};

struct node *createNode(int value){
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->data = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void addLeft(struct node *top, struct node *left){
	top->left = left;
}

void addRight(struct node *top, struct node *right){
	top->right = right;
}

void addtoNode(struct node *top, struct node *left, struct node *right){
	int sum;
	addLeft(top,left);
	addRight(top,right);
	if (left->data > right->data){
		sum = left->data;
	}
	else{
		sum = right->data;
	}
	top->data += sum;
}

#define SIZE 15
struct node* createTree(){
	struct node *top, *aux[SIZE], *temp;
	int i,j;

	int row[SIZE][SIZE] = {
			{4,62,98,27,23,9,70,98,73,93,38,53,60,4,23},
			{63,66,4,68,89,53,67,30,73,16,69,87,40,31},
			{91,71,53,38,17,14,91,43,58,50,27,29,48},
			{70,11,33,28,77,73,17,78,39,68,17,57},
			{53,71,44,65,25,43,91,52,97,51,14},
			{41,48,72,33,47,32,37,16,94,29},
			{41,41,26,56,83,40,80,70,33},
			{99,65,04,28,06,16,70,92},
			{88,02,77,73,07,63,67},
			{19,01,23,75,03,34},
			{20,04,82,47,65},
			{18,35,87,10},
			{17,47,82},
			{95,64},
			{75}
	};

	for(i=0;i<SIZE;i++){
		for(j=0;j< (SIZE-i);j++){
			if (i == 0){
				aux[j] = createNode(row[i][j]);
			}
			else{
				temp = createNode(row[i][j]);
				addtoNode(temp,aux[j],aux[j+1]);
				aux[j] = temp;
			}

		}
	}
	top = temp;
	return top;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	struct node *tree;
	tree = createTree();
	printf("Sum of the Max Route: %d",tree->data);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
