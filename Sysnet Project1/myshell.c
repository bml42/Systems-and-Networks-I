/*
 *	COP4634 - Systems and Networks I
 *	Project 1 - Creating Your Own Shell
 *	Created By:	Ali Al-Senan
 *			Benjamin Linam
 *
 *	Filename: myshell.c
 *
 */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "parse.h"
#include "commands.h"

int main(int argc, char **argv)
{
	char inputCommand[200];//Array that stores the user input string
	Param_t currentParam;//makes sure there is input and continues to tokenization else it loops back to input
	int exit=0,error=0;
	int* q;
	q = &error;

	while(1)
	{
		printf("$$$ ");
		fgets(inputCommand,200,stdin);//reads input string from command line
		if(inputCommand[0]!='\n')
		{
			currentParam = parseTokenize(inputCommand,q);//function that tokenizes input string
        		if(argv[1]!=NULL)
				if(!strcmp("-debug",argv[1])||!strcmp("-Debug",argv[1]))  //determines if debug mode was desired for shell
					printParam(currentParam);//outputs information about input string
			if(*q)
				printf("\tError Occurred: File required after operator.\n");
			else
				exit = runCommand(currentParam);//if runCommand returns 1, exit command was chosen and shell is exited
			if(exit)
				break;	
		}
		*q = 0;
	}
	printf("\tExiting Shell!\n");//will only exit from shell if while loop is broken out of
	return 0;
}
