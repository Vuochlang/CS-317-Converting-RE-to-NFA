#include "all.h"

/**
 * @function    newTransition
 * @abstract    create a new struct Transition with given param
 * @param       a   an int
 * @param       b   an int
 * @param       c   a char
 * @return      pointer of that new struct Transition
 */
LIST newTransition(int a, int b, char c) {
    LIST st; // transition
    st = malloc(sizeof(struct Transition));
    st -> state1 = a;
    st -> state2 = b;
    st -> symbol = c;
    st -> next = NULL;
    return st;
}

/**
 * @function    printList
 * @abstract    print every LIST that can be reached from sentinel
 * @param       sentinel    pointer to the start of LIST
 */
void printList(LIST sentinel) {
    LIST currentList = sentinel -> next;
    while (currentList != NULL ) {
        printTransition(currentList);
        currentList = currentList -> next;
    }
}

/**
 * @function    printTransition
 * @abstract    print the given list in the defined string format
 * @param       a   pointer of a LIST
 */
void printTransition(LIST a) {
    printf("(q%d, %c) -> q%d\n", a->state1, a->symbol, a->state2);
}

/**
 * @function    freeList
 * @abstract    free every list that can be reached from sentinel
 * @param       sentinel    pointer to the start of the list
 */
void freeList(LIST sentinel) {
    LIST currentList = sentinel;
    LIST temp;
    while (currentList != NULL ) {
        temp = currentList -> next;
        free(currentList);
        currentList = temp;
    }
    printf("----> freed LinkedList memory.\n");
}

/**
 * @function    addFirst
 * @abstract    add the given LIST b right after the LIST sentinel
 * @param       sentinel    pointer to the start of the list
 * @param       b           pointer to a list
 */
void addFist(LIST sentinel, LIST b) {
    LIST first = sentinel -> next;
    sentinel -> next = b;
    b -> next = first;
}

/**
 * @function    addLast
 * @abstract    add the given LIST b at the end of the list
 * @param       sentinel    pointer to the start of the list
 * @param       b           pointer to a list
 */
void addLast(LIST sentinel, LIST b) {
    LIST current = lastList(sentinel);
    current -> next = b;
}

/**
 * @function    lastList
 * @abstract    starting from sentinel, go through the list and look for the last list
 * @param       sentinel    pointer to the start of the list
 * @return      a pointer to the last list from the sentinel
 */
LIST lastList(LIST sentinel) {
    LIST current = sentinel -> next;
    LIST nextList = current -> next;
    while (nextList != NULL) {
        current = nextList;
        nextList = current -> next;
    }
    return current;
}
