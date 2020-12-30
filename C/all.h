/**
 * @header      all.h
 * @abstract    All functions, struct(s) and all #include
 * @discussion  This file contains all declarations for all functions, structs and all #include that will
 *              be used in .c files
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * @struct      Stack
 * @abstract    Contains necessary information of a stack
 * @discussion  The struct will make the <array> field to act as a stack which
 *              has the <top> field as an indicator to the top of the stack
 *              and the <capacity> field as the maximum capacity of the array.
 * @field       top         int, to store the value of the top of the stack.
 * @field       capacity    unsigned int, to store the maximum capacity of the stack.
 * @field       array       char*, pointer to the beginning of the array with size of <capacity>
*/
struct Stack {	
	int top; // top stack
 	unsigned int capacity; 
	char* array; 
};

/**
 * @struct      NFA
 * @abstract    Nondeterministic Finite Automata
 * @brief       This struct will contain the start state, accept state and a pointer to the struct Transition
 * @field       startState      start state of the NFA
 * @field       acceptState     accept state of the NFA
 * @field       first           a pointer to the struct Transition that stores all the transition between states
 */
struct NFA {
	int startState;
	int acceptState;
	struct Transition* first; // firstTransition
};

/**
 * @struct      Transition
 * @brief       Store information of a transition such as state1, state2, symbol and a pointer to the next transition
 * @field       state1      the first state number
 * @field       state2      the next state number
 * @field       symbol      the character for the the state1 goes to state2
 * @field       next        a pointer to the next struct Transition
 */
struct Transition {
	int state1;
	int state2;
	char symbol;
	struct Transition* next;
};

typedef struct Transition* LIST;
typedef struct Stack* STACK;
typedef struct NFA* NFA;

// include in infixToPostfix.c
void infixToPostfix(char[120]);
bool isOperand(char);
bool isOperator(char);
bool isParentheses(char);
bool isHigherPrecedence(char, STACK);
int orderOfPrecedence(char);

// include in stack.c
STACK createStack(unsigned int);
void push(STACK, char);
char pop(STACK);
bool isEmpty(STACK);
void itemInStack(STACK);
char top(STACK);

// include in linkedList.c
LIST newTransition(int , int , char);
void printTransition(LIST);
void printList(LIST);
void freeList(LIST);
LIST lastList(LIST );
void addFist(LIST, LIST);
void addLast(LIST, LIST);

// include in re2nfa.c
void reToNfa(char[120]);
NFA newNFA();
void freeNFA(NFA);
int orOperation(LIST, int);
int kleeneStar(LIST, int);
void concatenation(LIST);

// include in main.c
bool isValidPostfix(char[120]);







