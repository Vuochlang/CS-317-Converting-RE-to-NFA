#include "all.h"

 /**
  * @function   createStack
  * @abstract   create a stack, and its array with the given cap
  * @param      cap     unsigned integer
  * @return     pointer to the stack
  */
STACK createStack(unsigned int cap) {
    STACK stack = (STACK)malloc(sizeof(struct Stack));
	stack -> capacity = cap;
	stack -> top = 0;
	stack -> array = (char*)malloc(cap * sizeof(char));
	return stack;	
}

/**
 * @function    push
 * @abstract    push the given <a> to the top of the given stack
 * @param       stack   pointer to the STACK
 * @param       a       one character
 */
void push(STACK stack, char a) {
	int top = stack->top;
	int cap = stack->capacity;
	if(top == cap) {
		printf("Stack is full!\n");
		return;
	}	
	stack -> array[top] = a;
	stack -> top++;
	return;
}

/**
 * @function    pop
 * @abstract    pop the top item of the given stack
 * @param       stack
 * @return      a character which is the top item
 */
char pop(STACK stack) { // pop from top to last item in stack
	if(isEmpty(stack))	return '!';
	int top = stack -> top;
	int lastPushIndex = top - 1;
	char popChar = stack -> array[lastPushIndex];
	stack -> array[lastPushIndex] = ' ';
	stack -> top = lastPushIndex;
	return popChar;
}

/**
 * @function    top
 * @abstract    pop the top item of the given stack
 * @param       stack
 * @return      a character which is the top item
 */char top(STACK stack) {
	int top = stack -> top - 1;
	if(isEmpty(stack)) return '!';
	return (stack -> array[(top)]);
}

/**
 * @function    isEmpty
 * @abstract    check if the given stack is empty
 * @param       stack
 * @return      true or false
 */
bool isEmpty(STACK stack) {
	if(stack -> top < 0)	return true; // empty
	else return false;
}

/**
 * @function    itemInStack
 * @abstract    print the character stored in the stack from top to last item
 * @param       stack
 */
void itemInStack(STACK stack) {
	int items = stack -> top;
	for(int i = items; i > -1; i--) {
		printf("stack [%d] = | %c |\n", i, stack -> array[i]);
	}
}
