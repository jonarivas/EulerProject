/*
 ============================================================================
 Name        : Euler.c
 Author      : Jonathan Rivas
 Version     :
 Copyright   : 
 Description : Problem #16
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define int2char(x) (x+'0')
#define char2int(x) (x-'0')

struct stack {
  char *contents;
  int size;
  int top;
};

void stackInit(struct stack *stack, int size)
{
  char *newStackContents;

  newStackContents = (char *)malloc(sizeof(char) * size);


  stack->contents = newStackContents;
  stack->size = size;
  stack->top = -1;
}

void stackDestroy(struct stack *stack)
{

  free(stack->contents);
  stack->contents = NULL;
  stack->size = 0;
  stack->top = -1;
}

int stackIsEmpty(struct stack *stack)
{
  return stack->top < 0;
}

int stackIsFull(struct stack *stack)
{
  return stack->top >= stack->size - 1;
}

void stackPush(struct stack *stack, char element)
{
  if (stackIsFull(stack)) {
	  printf("stack is Full");
  }
  else{
	  stack->contents[++stack->top] = element;
  }
}

char stackPop(struct stack *stack)
{
  if (stackIsEmpty(stack)) {
	  printf("stack is Empty");
	  return '\x0';
  }
  else
	  return stack->contents[stack->top--];
}

char * doublestring(char * number){
	char * result;
	int size = 0;
	struct stack numberStack;
	while(number[++size] != '\x0');
	int i = 0 , j = 0, totalnumbers = 2;
	int sum = 0, carry = 0;
	stackInit(&numberStack, size + 1);
	for(j= size - 1; j>=0; j--){
		sum=carry;
		for(i=0;i<totalnumbers;i++){
			sum += char2int(number[j]);
		}
		carry = sum/10;
		stackPush(&numberStack,int2char(sum%10));
	}
	if (carry){
		stackPush(&numberStack,int2char(carry));
	}
	result = (char *)malloc(sizeof(char) * numberStack.size + 1);
	i = 0;
	while(!stackIsEmpty(&numberStack)){
		result[i++] = stackPop(&numberStack);
	}
	result[i] = '\x0';
	stackDestroy(&numberStack);
	return result;
}

char * stringpow(char * number, int grade){
	char * result;
	int i;
	result = number;
	for(i = 2; i <=grade; i++){
		result = doublestring(result);
	}
	return result;
}

int sumofdigits(char * number){
	int sum = 0, size = 0, i = 0;
	while(number[++size] != '\x0');
	for(i=0; i<size; i++){
		sum += char2int(number[i]);
	}
	return sum;
}

int main(void) {
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	char * result;
	int sum;
	result = stringpow("2",1000);
	sum = sumofdigits(result);
	printf("%d", sum);
	gettimeofday(&stop, NULL);
	printf("\ntook %lu usec\n", stop.tv_usec - start.tv_usec);
	return 0;
}
