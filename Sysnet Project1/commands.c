/*
 *	COP4634 - Systems and Networks I
 *	Project 1 - Creating Your Own Shell
 *	Created By: 	Ali Al-Senan
 *			Benjamin Linam
 *
 *	Filename: commands.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include "parse.h"

int runCommand(Param_t p)
{
	pid_t child;
	char directory[100]="/bin/";    //execl() needs loaction to search for program, directory is storage location of commands

	strcat(directory,p.argumentVector[0]); //adds name of command to directory to complete path to desired program
	if((child=fork())==0)        //determines if child process creation was successful
	{
		if(p.inputRedirect!=NULL)		//if an input redirect was recognized, input is taken from the location stored in inputRedirect
			freopen(p.inputRedirect,"r",stdin);
		if(p.outputRedirect!=NULL)		//if an out redirect was recognized, output is pushed to location stored in outputRedirect
			freopen(p.outputRedirect,"w",stdout);

		switch(p.argumentVector[0][0])  
		{
		case '.':  //input was recognized as a program, will execute desired program
			execl(p.argumentVector[0],p.argumentVector[0],p.argumentVector[1], p.argumentVector[2],p.argumentVector[3],p.argumentVector[4],p.argumentVector[5],p.argumentVector[6],p.argumentVector[7],p.argumentVector[8],p.argumentVector[9],p.argumentVector[10],p.argumentVector[11],p.argumentVector[12],p.argumentVector[13],p.argumentVector[14],p.argumentVector[15],p.argumentVector[16],p.argumentVector[17],p.argumentVector[18],p.argumentVector[19],p.argumentVector[20],p.argumentVector[21],p.argumentVector[22],p.argumentVector[23],p.argumentVector[24],p.argumentVector[25],p.argumentVector[26],p.argumentVector[27],p.argumentVector[28],p.argumentVector[29],p.argumentVector[30],p.argumentVector[31],NULL);
			break;
		default:
			if(!strcmp(p.argumentVector[0],"exit"))				//input is recognized to be exit command, returns from function and breaks while loop to end program
				return 1;
			execl(directory,p.argumentVector[0],p.argumentVector[1],p.argumentVector[2],p.argumentVector[3],p.argumentVector[4],p.argumentVector[5],p.argumentVector[6],p.argumentVector[7],p.argumentVector[8],p.argumentVector[9],p.argumentVector[10],p.argumentVector[11],p.argumentVector[12],p.argumentVector[13],p.argumentVector[14],p.argumentVector[15],p.argumentVector[16],p.argumentVector[17],p.argumentVector[18],p.argumentVector[19],p.argumentVector[20],p.argumentVector[21],p.argumentVector[22],p.argumentVector[23],p.argumentVector[24],p.argumentVector[25],p.argumentVector[26],p.argumentVector[27],p.argumentVector[28],p.argumentVector[29],p.argumentVector[30],p.argumentVector[31],NULL);
			break;
		}
		printf("\tError Occured: Invalid Command.\n");  //process was unable to execute
		exit(0);
	}
	else  //parent process
	{
		if(strcmp(p.argumentVector[0], "exit") == 0)  //desired command was exit, ends process
			exit(0);
		if(!p.background)  //recognizes if backgrounding was desired.  
			wait(NULL);
	}
	return 0;
}
