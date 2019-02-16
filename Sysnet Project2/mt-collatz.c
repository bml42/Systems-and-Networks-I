#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#define MAXSTEPS 1000
#define MAXTHREADS 1000

long counter, maxNumber;
int steps[MAXSTEPS];
int threadNumber;
int lock = 1;
pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_t tid[MAXTHREADS];
struct timespec diff;

void *collatzThread(void *p);

int main(int argc, char **argv)
{
	int n;

	counter = 2;
	maxNumber = atoi(argv[1]);
	threadNumber = atoi(argv[2]);	
	pthread_mutex_init(&lock1,NULL);
	pthread_mutex_init(&lock2,NULL);

	if(argv[3] != NULL)
		if(strcmp(argv[3],"-nolock")==0)
			lock = 0;

	for(n=0;n<MAXSTEPS;++n)
		steps[n]=0;

	for(n=0;n<threadNumber;++n)
		pthread_create(&tid[n],NULL,collatzThread,(void*)&tid[n]);

	for(n=0;n<threadNumber;++n)
		pthread_join(tid[n],NULL);
	
	for(n=1;n<MAXSTEPS;++n)
		fprintf(stderr,"%d,%d\n",n,steps[n]);
	
	printf("\n%ld,%d,%ld.%09ld\n",maxNumber,threadNumber,diff.tv_sec,diff.tv_nsec);

	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	
	return 0;
}

void *collatzThread(void *p)
{
	int currentSteps=0;
	long currentNumber=0;
	pthread_t m = *(pthread_t *)p;
	clockid_t cid = 0;
	struct timespec start, end;

	if(m==tid[0])
		clock_gettime(cid,&start);
	
	while(counter<=maxNumber)
	{
		currentSteps=0;
		if(lock)
		{
			pthread_mutex_lock(&lock1);
			currentNumber = counter++;
			pthread_mutex_unlock(&lock1);
		}
		else
			currentNumber = counter++;
			
		while(currentNumber!=1)
		{
			++currentSteps;
			if(currentNumber%2==0)
				currentNumber/=2;
			else
				currentNumber=3*currentNumber+1;
		}
		if(lock)
		{
			pthread_mutex_lock(&lock2);
			++steps[currentSteps];
			pthread_mutex_unlock(&lock2);
		}
		else
			++steps[currentSteps];
	}

	if(m==tid[0])
	{
		clock_gettime(cid, &end);
		diff.tv_sec = end.tv_sec - start.tv_sec;
		diff.tv_nsec = end.tv_nsec - start.tv_nsec;
		if(diff.tv_nsec < 0)
		{
			diff.tv_sec--;
			diff.tv_nsec += 1000000000;
		}
	}
		
	pthread_exit(NULL);
}
