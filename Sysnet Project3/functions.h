/*
 *	COP4634 - Systems and Networks I
 *	Project 3 - Large Arrays
 *	Created By:	Ali Al-Senan
 *			Benjamin Linam
 *
 *	Filename: functions.h
 *
 */
#ifndef FUNCTIONS
#define FUNCTIONS

#define ROW 20480	//Number of rows in the large array.
#define COL 4096	//Mumber of columns in the large array.

/*	Function readRow
 *
 *	Return: timespec struct that holds the time difference from the start of the function and the end.
 */
struct timespec readRow();

/*	Function writeRow
 *
 *	Return: timespec struct that holds the time difference from the start of the function and the end.
 */
struct timespec writeRow();

/*	Function readCol
 *	
 *	Return: timespec struct that holds the time difference from the start of the function and the end.
 */
struct timespec readCol();

/*	Function writeCol
 *
 *	Return: timespec struct that holds the time difference from the start of the function and the end.
 */
struct timespec writeCol();

/*	Function diffTime
 *	Parameter 1: struct timespec that holds the start time of the function.
 *	Parameter 2: struct timespec that holds the end time of the function.
 *
 *	Return: timespec struct that holds the time difference from the start of the function and the end.
 */
struct timespec diffTime(struct timespec,struct timespec);

#endif
