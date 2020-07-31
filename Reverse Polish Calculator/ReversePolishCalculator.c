// Bashier Dahman 
// Reverse Polish Calculator

#include "RPC_header.h"

/////////////////////////////////////////////////////////////////////////////
// my main function
int main(int argc,char **argv){

	int i;
	struct stack* stack = newStack(MAX_CAPACITY);

	printf("Amount of arguments:  %d\n", argc);
	printf("Your file name:  %s\n", argv[0]);
	printf("Your arguments: ");
	for (i = 1; i < argc; ++i) {
		printf("%s ", argv[i]);
	}
	for (i = 1; i < argc; ++i) {
		if (argc == 1) {
			printf("No arguments were passed.\n");

		}
		else if (isNumber(argv[i])){
			push(stack, atoi(argv[i]));

		}
		else if (strcmp(argv[i], "+") == 0) {
			
			int op1 = pop(stack);
			int op2 = pop(stack);

			int result = calcAdd(op1, op2);
			
			push(stack, result);

		}
		else if (strcmp(argv[i], "-") == 0) {

			int op1 = pop(stack);
			int op2 = pop(stack);
			
			int result2 = calcMinus(op1, op2);

			push(stack, result2);

		}
		else if (strcmp(argv[i], "*") == 0) {

		// this will tell the user that you can't multiply with * in edoras and must use "x"
			printf("\n\nI apoligze but there seems to be an error with your arguments...");
			printf("\nEdoras does not let us use '*' for multiplying, please use the letter 'x' instead, please run the program again\n");
			return -1;

		}
		// this calculates multiplication, as edoras does not factor in the "*"
		else if (strcmp(argv[i], "x") == 0) {

			int op1 = pop(stack);
			int op2 = pop(stack);

			int result2 = calcMult(op1, op2);

			push(stack, result2);

		}
		else if (strcmp(argv[i], "/") == 0) {

			int op1 = pop(stack);
			int op2 = pop(stack);

			int result2 = calcDiv(op1, op2);

			push(stack, result2);

		}
		else {
			printf("\nThere's an error in your arguments!\n");
		
			return -1;
		}	

	}
	printf("\nHere is your answer in your Reverse Polish Notation: ");
	printf("%i \n", pop(stack));



	return 0;
}
