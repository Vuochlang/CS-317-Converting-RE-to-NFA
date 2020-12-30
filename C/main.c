#include "all.h"

/**
 * @mainpage    ask for the text file that will be used, contents can be in infix or postfix form
 * @param       argc    number of argc has to be 2
 * @param       argv    specifically looking for the text file name with argv[1]
 * @brief       if argc < 2 then ask for the text file name
 *              if argc == 2 then process the given file in argv[1]
 *              if argc > 2 then print message "too many argc" and return
 * @author      Vuochlang Chang
 */
int main (int argc, char *argv[]) {
	FILE *fp;
	char str[120];
	char fileName[120];
	char inputLine[120]; // expected up to 120 lines of characters
	char in[120];
	bool isPostfix = true;
	char temp[10] = "nth";
	bool wrongAnswer = true;

	if(argc > 2) {
		printf("****\nToo many arguments, expected one argument for file name.\n***\n");
		return 0;
	}	
	else if(argc < 2) {
		printf("****\nWelcome! Please enter the text file that you want to use: ");
		fgets(fileName, 120, stdin);
		fileName[strlen(fileName)-1]='\0';
	}
	else {// argc will be 2
		strcpy(fileName, argv[1]);
	}

	fp = fopen(fileName, "r");
	if(fp == NULL) {
		printf("****ERROR, cannot read < %s >****\n",fileName);
		return 0;
	}
	else
	{	printf("open < %s > successfully\n----READING CONTENTS----\n", fileName);
	}

	while(wrongAnswer) {
		printf("Are the content in postfix notation? (yes/no): ");
		fgets(temp, 10, stdin);
		temp[strlen(temp)-1]='\0';
		if(strcmp(temp, "yes") == 0) { 
			isPostfix = true;
			wrongAnswer = false;
		}
		else if(strcmp(temp, "no") == 0) {
			isPostfix = false;
			wrongAnswer = false;
		}
		else {
			wrongAnswer = true;
		}
	}

	int numLine = 0;
	while(fgets(in,120,fp)!=NULL){
		in[strlen(in)-1]='\0';
		printf("\n**** Expression %d = < %s > ****\n",numLine+1,in);
		if(!isPostfix)	{
			infixToPostfix(in);
		}
		else {
			if(isValidPostfix(in))  reToNfa(in);
			else {
                printf("----< %s > is invalid----\n\n", in);
			}
		}
		numLine++;
	}	

	fclose(fp);
	printf("----CLOSED < %s >----\n",fileName);
	return 0;
}

/**
 * @function    isValidPostfix
 * @abstract    Checks each character in the given postfix form
 * @param       in    The given char[120]
 * @discussion  each character has to belong to the one of the defined operator, operands, and parentheses
 * @return      true or false
 */
bool isValidPostfix(char in[120]) {
    for(int i = 0; i < strlen(in); i++) {
        char c = in[i];
        switch(c) {
            case '+':
                c = '|';
                break;
            case 'x':
                c = '&';
                break;
            default: // '*, (, ), etc' stay the same
                break;
        }
        if(!isOperand(c) && !isOperator(c) && !isParentheses(c)) {
            printf("%c is not in the language...\n", c);
            return false;
        }
    }
    return true;
}
