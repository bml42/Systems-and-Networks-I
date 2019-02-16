/*
 *	COP4634 - Systems and Networks I
 *	Project 3 - Large Arrays
 *	Created By:	Ali Al-Senan
 *			Benjamin Linam
 *
 *	Filename: matrix.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main(int argc, char **argv)
{
	int i;
	//Struct timespec diff is an array of size 10 to hold all 10 times from the functions.
	//Struct timespec avg contains the average time it takes to execute a function.
	struct timespec diff[10], avg;
	avg.tv_sec = 0;
	avg.tv_nsec = 0;

	//Loop that iterates 10 times executing writeRow and storing its time values in the diff array.
	for(i=0;i<10;++i)
	{
		diff[i] = writeRow();
		avg.tv_sec += diff[i].tv_sec;
		avg.tv_nsec += diff[i].tv_nsec;
	}
	//Calculates the average time.
	avg.tv_sec /= 10;
	avg.tv_nsec /= 10;
	
	printf("\nWriteRow: %ld.%09ld\n",(long)avg.tv_sec,avg.tv_nsec);

	avg.tv_sec = 0;
	avg.tv_nsec = 0;

	//Loop that iterates 10 times executing writeCol and storing its time values in the diff array.
	for(i=0;i<10;++i)
	{
		diff[i] = writeCol();
		avg.tv_sec += diff[i].tv_sec;
		avg.tv_nsec += diff[i].tv_nsec;
	}
	//Calculates the average time.
	avg.tv_sec /= 10;
	avg.tv_nsec /= 10;
	
	printf("\nWriteCol: %ld.%09ld\n",(long)avg.tv_sec,avg.tv_nsec);
	
	avg.tv_sec = 0;
	avg.tv_nsec = 0;

	//Loop that iterates 10 times executing readRow and storing its time values in the diff array.
	for(i=0;i<10;++i)
	{
		diff[i] = readRow();
		avg.tv_sec += diff[i].tv_sec;
		avg.tv_nsec += diff[i].tv_nsec;
	}
	//Calculates the average time.
	avg.tv_sec /= 10;
	avg.tv_nsec /= 10;
	
	printf("\nReadRow: %ld.%09ld\n",(long)avg.tv_sec,avg.tv_nsec);
	
	avg.tv_sec = 0;
	avg.tv_nsec = 0;

	//Loop that iterates 10 times executing readCol and storing its time values in the diff array.
	for(i=0;i<10;++i)
	{
		diff[i] = readCol();
		avg.tv_sec += diff[i].tv_sec;
		avg.tv_nsec += diff[i].tv_nsec;
	}
	//Calculates the average time.
	avg.tv_sec /= 10;
	avg.tv_nsec /= 10;
	
	printf("\nReadCol: %ld.%09ld\n",(long)avg.tv_sec,avg.tv_nsec);

	return 0;
}
