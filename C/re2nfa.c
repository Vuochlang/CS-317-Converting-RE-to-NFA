#include "all.h"

/**
 * @function    reToNfa
 * @abstract    converting a Regular Expression to Nondeterministic Finite Automata
 * @param       in      char[120], a regular expression in postfix form
 */
void reToNfa(char in[]) {
	char c;
	NFA nfa = newNFA();
	LIST sentinel, list, newList;
	int stateCount = 1;
	int s1, s2;

	sentinel = newTransition(0,0,0);

	for(int i = 0; i < strlen(in); i++) {
        c = in[i];
        if(isOperand(c)) { // when a, b, c, d, e and E
            if(sentinel -> next == NULL) {
                s1 = stateCount;
                s2 = ++stateCount;
                list = newTransition(s1, s2, c);
                sentinel -> next = list;
                nfa -> first = sentinel;
                ++stateCount;
            }
            else {
                s1 = stateCount;
                s2 = ++stateCount;
                list = newTransition(s1, s2, c);
                addLast(sentinel, list);
                ++stateCount;
            }
        }
        else { // when |, *, &
            switch(c) {
                case '|':
                    stateCount = orOperation(sentinel, stateCount);
                    break;
                case '&':
                    concatenation(sentinel);
                    break;
                case'*':
                    stateCount = kleeneStar(sentinel, stateCount);
                    break;
                default:
                    break;
            }
        }
    }
	nfa -> startState = sentinel -> next -> state1;
	nfa -> acceptState = lastList(sentinel) -> state2;
	printf("Start state = q%d\n", nfa -> startState);
	printf("Accept State = q%d\n", nfa -> acceptState);
    printList(sentinel);
    freeList(sentinel);
    freeNFA(nfa);
}

/**
 * @function    concatenation
 * @abstract    concatenate operation
 * @param       sentinel    a pointer to the start of the LIST
 * @brief       create a LIST in between the second from the last LIST and the last LIST
 */
void concatenation(LIST sentinel) {
    LIST secondFromLast = sentinel -> next;
    LIST lastList = secondFromLast -> next;
    while (lastList -> next != NULL) {
        secondFromLast = lastList;
        lastList = secondFromLast -> next;
    }
    int s1 = secondFromLast -> state2;
    int s2 = lastList -> state1;
    LIST list = newTransition(s1, s2, 'E');
    secondFromLast -> next = list;
    list -> next = lastList;
}

/**
 * @function    kleeneStar
 * @abstract    kleene start operation
 * @param       sentinel    a pointer to the start of the LIST
 * @param       stateCount  an int of the current number of state(s)
 * @brief       create two new LIST, one connect to the beginning of the LIST
 *              and another one connect to the end of the LIST
 * @return      an int, a new number of state(s) count
 */
int kleeneStar(LIST sentinel, int stateCount) {
    LIST first = sentinel -> next;
    LIST last = lastList(sentinel);
    int s1 = first -> state1;
    int s2 = last -> state2;
    LIST list = newTransition(stateCount, s1, 'E');
    addFist(sentinel, list);
    list = newTransition(s2, stateCount, 'E');
    addLast(sentinel, list);
    ++stateCount;
    return stateCount;
}

/**
 * @function    orOperation
 * @abstract    OR / Union operation
 * @param       sentinel    a pointer to the start of the LIST
 * @param       stateCount  an int, the current number of state(s)
 * @brief       create 4 new LIST, 2 lists connect to the beginning of the list
 *              and 2 lists connect to the end of the lists
 * @return      an int, a new number of state(s) count
 */
int orOperation(LIST sentinel, int stateCount) {
    int state = stateCount;
    LIST first = sentinel -> next;
    LIST last = lastList(sentinel);
    int s1 = first -> state1;
    int s2 = first -> state2;
    if(last == NULL) puts("yes");
    int t1 = last -> state1;
    int t2 = last -> state2;
    LIST list = newTransition(state, t1, 'E');
    addFist(sentinel, list);
    list = newTransition(state, s1, 'E');
    addFist(sentinel, list);
    state++;
    list = newTransition(t2, state, 'E');
    addLast(sentinel, list);
    list = newTransition(s2, state, 'E');
    addLast(sentinel, list);
    state++;
    return state;
}

/**
 * @function    newNFA
 * @abstract    create a new struct NFA
 * @return      the pointer to the new struct NFA
 */
NFA newNFA() {
    NFA a;
    a = malloc(sizeof(struct NFA));
    a -> startState = 0;
    a -> acceptState = 0;
    a -> first = NULL;
    return a;
}

/**
 * @function    freeNFA
 * @abstract    free the given NFA
 */
void freeNFA(NFA n) {
    free(n);
    printf("----> freed NFA memory.\n\n");
}

