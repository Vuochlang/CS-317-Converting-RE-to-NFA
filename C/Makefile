main: main.o infixToPostfix.o stack.o re2nfa.o linkedList.o all.h
	gcc -o main main.o infixToPostfix.o stack.o re2nfa.o linkedList.o

main.o:	main.c infixToPostfix.c re2nfa.c all.h
	gcc -c main.c infixToPostfix.c re2nfa.c

infixToPostfix.o: infixToPostfix.c stack.c re2nfa.c all.h
	gcc -c infixToPostfix.c stack.c re2nfa.c

stack.o: stack.c all.h
	gcc -c stack.c

re2nfa.o: re2nfa.c linkedList.c all.h
	gcc -c re2nfa.c linkedList.c

linkedList.o: linkedList.c all.h
	gcc -c linkedList.c
