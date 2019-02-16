/*
 *	COP4634 - Systems and Networks I
 *	Project 1 - Creating Your Own Shell
 *	Created By: 	Ali Al-Senan
 *			Benjamin Linam
 *
 * 	Filename: parse.c
 *
 */
#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "commands.h"

Param_t parseTokenize(char *inputCommand, int* error)
{
	Param_t p; //declaration of variable that stores process ID
	int n = 0;
	char *temp;

 	p.inputRedirect = NULL; //initialization of all struct variables to NULL
	p.outputRedirect = NULL;
	p.background = 0;
	p.argumentCount = 0;
	for(n=0;n<MAXARGS;++n)
                p.argumentVector[n] = NULL;
    	n = 0;

	temp = strtok(inputCommand," \t\n"); //feeds tokenized commands or parameters into temp string variable
	do
    	{
        	switch(temp[0])
        	{
        	case '<':  //input redirect - recognizes if redirect has been entered
            		if(*(temp+1)=='\0') //checks to see if input is valid
            		{
                		*error = 1; //if not valid, error is registered
                		break;
            		}
          		p.inputRedirect = temp+1; // name of input redirect stored in temp is entered into input, operator is excluded
            		break;
        	case '>'://output redirect - recognizes if redirect has been entered
            		if(*(temp+1)=='\0')//checks to see if input is valid
            		{
                		*error = 1;//if not valid, error is registered
                		break;
            		}
            		p.outputRedirect = temp+1; // name of output redirect stored in temp is entered into input, operator is excluded
            		break;
        	case '&':  //recognizes if backgrounding is desired
            		p.background = 1;
            		break;
        	case 0:
            		break;
        	default:
            		if(p.argumentVector[0]==NULL)//recognizes if first argument exists.  If not temp fills argument
                		p.argumentVector[n] = temp;
            		else
                		p.argumentVector[++n] = temp;//if first argument does exist, temp fills next element of argumentVector
            		break;
        	}
        	if(*error)//error was registered..no input was found after the redirect operator
			break;
    	}while((temp = strtok(NULL," \t\n")) != NULL);//continues until tokenization of string is completed

	p.argumentCount = n+1;
	return p;
}

void printParam(Param_t p)//lists the values associated with the input string
{
    	int n;
    	printf("\nInput Redirect:\t\t[%s]",p.inputRedirect);
    	printf("\nOutput Redirect:\t[%s]",p.outputRedirect);
    	printf("\nBackground:\t\t[%d]",p.background);
    	printf("\nArgument Count:\t\t[%d]",p.argumentCount);
    	printf("\nArguments:");
    	for(n=0;n<p.argumentCount;++n)
        	if(p.argumentVector[n]!=NULL)
		{
			if(!n)
            			printf("\t\t[%2d] - [%s]\n",n+1,p.argumentVector[n]);
			else
				printf("\t\t\t[%2d] - [%s]\n",n+1,p.argumentVector[n]);
		}
	printf("\n");
}
