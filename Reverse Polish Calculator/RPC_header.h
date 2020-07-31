// Header File for ReversePolishCalculator.c
// Contains all my functions definitions

#include <stdio.h>
#include <stdlib.h>
#define	 MAX_CAPACITY 100


////////////////// THIS IS MY STACK DATA STRUCTURE /////////////////////
struct stack
{
	int items[MAX_CAPACITY];	// define max capacity of stack
	int size;

};

// Utility function to initialize stack
struct stack* newStack()
{
	struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
	stack->size = 0;
	return stack;
};


// Utility function to add an element x in the stack
void push(struct stack* stack, int x) {

	stack->items[stack->size] = x;
	stack->size += 1;
}

// Utility function to pop top element from the stack
int pop(struct stack* stack)
{
	// decrement stack size by 1 and (optionally) return the popped element
	return stack->items[stack->size-- - 1];
}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// method to check if it's a number
int isNumber(char number[]) {
	int i = 0;


	for (; number[i] != 0; i++)
	{
		//if (number[i] > '9' || number[i] < '0')
		if (!isdigit(number[i]))
			return 0;
	}
	return 1;
}
////////////////////////////////////

// method to check if it's an + operator

int isAddOperator(char argv[]){

	// check if it's an +
	if (strcmp(argv[0], "+" == 0)) {
		return 1;
	}
}

int calcAdd(int op1, int op2) {
	return op1 + op2;
}
/////////////////////////////////////////

// method to check if it's an - operator

int isMinusOperator(char argv[]) {
	
	// check if it's an -
	if (strcmp(argv[0], "-") == 0) {
		return 1;
	}
}

int calcMinus(int op3, int op4) {
	return op4 - op3;
}
/////////////////////////////////////////

// method to check if it's an * operator

int isMultOperator(char argv[]) {

	// check if it's an *
	if (strcmp(argv[0], "*") == 0) {
		return 1;
	}
}

int calcMult(int op3, int op4) {
	return op3 * op4;
}
/////////////////////////////////////////

// method to check if it's an / operator

int isDivideOperator(char div[]) {

	// check if it's an /
	if (strcmp(div[0], "/") == 0) {
		return 1;
	}
}

int calcDiv(int op3, int op4) {
	
	return op4 / op3;
}
/////////////////////////////////////////