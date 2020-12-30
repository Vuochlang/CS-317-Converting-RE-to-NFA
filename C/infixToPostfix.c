#include "all.h"

/**
 * @function    infixToPostfix
 * @param       input   char[120]
 * @abstract    converting the given input from infix to postfix form
 *              and call reToNfa() to convert the Regular Expression in postfix form to Nondeterministic Finite Automata
 */
void infixToPostfix(char input[120]) {
    char line[120];
    char postfix[120] = "";
    bool invalidInput = false;
    bool operator, operand;
    char popChar;
	
    strcpy(line,input);
    struct Stack* stack = createStack(100); // expect up to 100 signs per line

    for(int i = 0 ; i < strlen(line)+1 ; i++) {
        switch(line[i]) {
            case '+':
                line[i] = '|';
                break;
            case 'x':
                line[i] = '&';
                break;
            default: // '*, (, ), etc' stay the same
                break;
        }
        if(invalidInput) {
            printf("----< %s > is invalid----\n\n", line);
            return;
        }
	    operator = isOperator(line[i]);
	    operand = isOperand(line[i]);
	    if(!operator && !operand) { // not parentheses, !operator and !operand
	        if(!isParentheses(line[i])) {
	            invalidInput = true;
	        }
	        else { // is parentheses
	            if(line[i] == '(') {
	                push(stack, '(');
	            }
	            else { // line[i] == ')'
	                while(!isEmpty(stack) && top(stack) != '(') {
        		        popChar = pop(stack);
	    	                strncat(postfix, &popChar, 1);
	                }
	                pop(stack); // pop '('
	            }
	        }
	    }
        else if(operator && !operand) {
            if(isEmpty(stack)) {
                push(stack, line[i]);
            }
            else {
                if(top(stack) == '(') {
                    push(stack, line[i]);
                }
                else if(!isEmpty(stack) && isHigherPrecedence(line[i], stack)) {
                    popChar = pop(stack);
                    strncat(postfix, &popChar, 1);
		    while(!isEmpty(stack) && isHigherPrecedence(line[i], stack)) {
		    	popChar = pop(stack);
			if(popChar != '(')	strncat(postfix, &popChar, 1);
		    }		    
		    push(stack, line[i]);
                }
                else {
                    push(stack, line[i]);
                }
            }
        }
        else { // !operator && operand
            popChar = line[i];
            strncat(postfix, &popChar, 1);
        }
    }
    while(!isEmpty(stack)) {
        popChar = pop(stack);
	    strncat(postfix, &popChar, 1);
    }
    printf("Converted to postfix string = < %s >\n", postfix);
    free(stack);
    printf("----> freed stack. \n\n");
    reToNfa(postfix);
}

/**
 * @function    isOperand
 * @abstract    check the given character if it is one of the operands ( a, b, c, d, e, E )
 * @param       i   a character
 * @return      true or false
 */
bool isOperand(char i) {
	if (i == 'a' || i == 'b' || i == 'c' || i == 'd' || i == 'e' || i == 'E')	return true;
	return false;
}

/**
 * @function    isOperator
 * @abstract    check the given character if it is one of the operators ( |, *, + )
 * @param       i   a character
 * @return      true or false
 */
bool isOperator(char i) {
	if(i == '|' || i == '*' || i == '&') return true;
	return false;
}

/**
 * @function    isParentheses
 * @abstract    check the given character if it is parentheses
 * @param       i   a character
 * @return      true or false
 */
bool isParentheses(char i) {
	if(i == '(' || i == ')') return true;
	return false;
}

/**
 * @function    isHigherPrecedence
 * @abstract    check if the operator at the top of the stack has a higher or equal order of precedence with the given i
 * @param       i       an operator ( |, *, +, )
 * @param       stack   pointer to a stack
 * @return      true or false
 */
bool isHigherPrecedence(char i, STACK stack) {
	if(orderOfPrecedence(top(stack)) >= orderOfPrecedence(i))	return true;
	else return false;
}

/**
 * @function    orderOfPrecedence
 * @abstract    check the order of precedence given i, the higher the return int the higher the order of precedence
 * @param       i   an operator
 * @return      return an int as the order of precedence of the given i
 */
int orderOfPrecedence(char i) {
	switch(i) {
		case '|': 
			return 1;
		case '&':
			return 2;
		case '*':
			return 3;
		default: // case '(' or ')', unlikely to happen
			return 4;
	}
}
