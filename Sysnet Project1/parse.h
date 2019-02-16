/*
 *	COP4634 - Systems and Networks I
 *	Project 1 - Creating Your Own Shell
 *	Created By:	Ali Al-Senan
 *			Benjamin Linam
 *
 *	Filename: parse.h
 *
 * */
#ifndef PARSE
#define PARSE

#define MAXARGS 32

struct PARAM  //parameter struct that holds information vital to IO from the command line
{
	char *inputRedirect;
	char *outputRedirect;
	int background; //used to determine if process is to be run in background
	int argumentCount; //holds total number of arguments tokenized from input string
	char *argumentVector[MAXARGS];//holds arguments input on command line
};

typedef struct PARAM Param_t;

/* 	Function parseTokenize
 * 	Parameter 1: char* which takes in a string that needs to be parsed and tokenized.
 * 	Parameter 2: int* which takes in a pointer to an integer that would hold the value of error. 
 *
 *	Return: Param_t struct that was initialized within the functions.
 */
Param_t parseTokenize(char*,int*);

/*	Funtion printParam
 *	Parameter 1: Param_t struct which would be printed to the terminal.
 *
 *	Return: void.
 */
void printParam(Param_t);

#endif
