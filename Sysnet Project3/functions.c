/*
 *	COP4634 - Systems and Networks I
 *	Project 3 - Large Arrays
 *	Created By:	Ali Al-Senan
 *			Benjamin Linam
 *
 *	Filename: functions.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

struct timespec start,end;	//Struct that store the start and end times of each function.
char matrix[ROW][COL];		//Large array of size 20480 x 4096.

struct timespec readRow()
{
	int i,j;
	char temp;	//Temporary variable to store array elements in.
	struct timespec diff;	//Struct that stores the difference in time from the beginning and the end of the function.
	clockid_t cid = 0;

	//Obtains clock time at the start of the function and stores it in start.
	clock_gettime(cid,&start);		

	//Nested loop that goes through the elements one by one in row major order and stores it in temp.
	for(i=0;i<ROW;++i)
		for(j=0;j<COL;++j)
			temp = matrix[i][j];

	if(i==ROW+1)
		printf("\nError: Out of Bounds\nCharacter: %c\n",temp);

	//Obtains clock time at the end of the function and stores it in end.
	clock_gettime(cid,&end);
	
	//Sends in struct start and end, and calculates the difference and stores it in struct diff.
	diff = diffTime(start,end);

	return diff;
}

struct timespec writeRow()
{
	int i,j;
	struct timespec diff;	//Struct that stores the difference in time from the beginning and the end of the function.
	clockid_t cid = 0;

	//Obtains clock time at the start of the function and stores it in start.
	clock_gettime(cid,&start);
	
	//Nested loop that goes through the elements one by one in row major order and stores 'A'.
	for(i=0;i<ROW;++i)
		for(j=0;j<COL;++j)
			matrix[i][j]=65;

	//Obtains clock time at the end of the function and stores it in end.
	clock_gettime(cid,&end);

	//Sends in struct start and end, and calculates the difference and stores it in struct diff.	
	diff = diffTime(start,end);

	return diff;
}

struct timespec readCol()
{
	int i,j;
	char temp;	//Temporary variable to store array elements in.
	struct timespec diff;	//Struct that stores the difference in time from the beginning and the end of the function.
	clockid_t cid = 0;

	//Obtains clock time at the start of the function and stores it in start.
	clock_gettime(cid,&start);
	
	//Nested loop that goes through the elements one by one in column major order and stores it in temp.
	for(i=0;i<COL;++i)
		for(j=0;j<ROW;++j)
			temp = matrix[j][i];

	if(i==COL+1)
		printf("\nError: Out of Bounds\nCharacter: %c\n",temp);

	//Obtains clock time at the end of the function and stores it in end.
	clock_gettime(cid,&end);

	//Sends in struct start and end, and calculates the difference and stores it in struct diff.
	diff = diffTime(start,end);

	return diff;
}

struct timespec writeCol()
{
	int i,j;
	struct timespec diff;	//Struct that stores the difference in time from the beginning and the end of the function.
	clockid_t cid = 0;

	//Obtains clock time at the start of the function and stores it in start.
	clock_gettime(cid,&start);
	
	//Nested loop that goes through the elements one by one in column major order and stores 'A'.
	for(i=0;i<COL;++i)
		for(j=0;j<ROW;++j)
			matrix[j][i]=65;

	//Obtains clock time at the end of the function and stores it in end.
	clock_gettime(cid,&end);
	
	//Sends in struct start and end, and calculates the difference and stores it in struct diff.
	diff = diffTime(start,end);

	return diff;
}

struct timespec diffTime(struct timespec start, struct timespec end)
{
	struct timespec diff;	//Struct that stores the difference in time.

	diff.tv_sec = end.tv_sec - start.tv_sec;
	diff.tv_nsec = end.tv_nsec - start.tv_nsec;

	//If statement that checks if the nanoseconds element needs to carry from the seconds element.
	if(diff.tv_nsec < 0)
	{
		diff.tv_sec--;
		diff.tv_nsec += 1000000000;
	}

	return diff;
}




