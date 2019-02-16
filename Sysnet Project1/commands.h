/*
 *	COP4634 - Systems and Networks I
 *	Project 1 - Creating Your Own Shell
 *	Created By: 	Ali Al-Senan
 *			Benjamin Linam
 *
 *	Filename: commands.h
 *
 */
#include "parse.h"
#ifndef COMMANDS
#define COMMANDS

/* 	Funtion runCommand
 * 	Parameter 1: Struct typedefined as Param_t with parsed commands to run instruction using execl.
 *
 *	Return: Int value that lets main know if the program should be terminated.
 */
int runCommand(Param_t);

#endif
