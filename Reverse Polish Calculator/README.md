# This program explores functions and stacks using the C programming langugage

**FILES INCLUDED:** ReversePolishCalculator.c *(contains main())* & RPC_header.h *(contains functions definition)*

### To compile and run

To **compile**: ```gcc -o calculator ReversePolishCalculator.c```

To **run**: ```./calculator (your numbers here followed by operations) ```

EX: ```./calculator 5 4 2 + x``` will result in 30.

### NOTICE: On certain terminal shell's you won't be able to use the * operator for multiplication, this is substituted by being able to use 'x' for multiplication.

### The program shall read in a line of input and then perform the calculation specified. The application will process reverse polish notation on postive integers. 

The program shall request a line of input from the user in reverse polish notation. Using the characters supplied at run-time, the program shall then calculate the mathematical result and display the value to the user.

Reverse Polish Notation is used due to the ambiguity of infix notation. Where the line 1 + 2 * 3 will produce a different result compared to (1 + 2) * 3. Using RPN we can calculate this correctly using 1 2 3 * +.

### The algorithm goes as followed (pseudocode):

```c
while( /* Not at end of line */ )
  if( number ) push( stack, number );
  else if( operator ) {
    /* Get operands from stack */
    op1 = pop( stack )
    op2 = pop( stack )
    /* Perform operation */
    res = calc( operator, op1, op2 )
    /* put result back on stack */
    push( stack, res )
  }
  else /* handle error */;
  ```
