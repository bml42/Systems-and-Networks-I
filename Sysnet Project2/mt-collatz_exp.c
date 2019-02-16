#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#define MAXSTEPS 1500
#define MAXTHREADS 1000

long counter, maxNumber;
int steps[MAXSTEPS];
int threadNumber;
int lock = 1;
pthread_mutex_t lock1;
pthread_mutex_t lock2;
int j;

struct timespec array[1000];
struct timespec avg;


void *collatzThread(void *p);

int main(int argc, char **argv)
{
//struct timespec start, end, diff;
//clockid_t cid = 0;
	pthread_mutex_init(&lock1,NULL);
	pthread_mutex_init(&lock2,NULL);
	int n;
	long tot=0,i=0;
	if(argv[3] != NULL)
		if(strcmp(argv[3],"-nolock")==0)
			lock = 0;	
	pthread_t tid[MAXTHREADS];
//struct timespec array[1000];
//struct timespec avg;
for(j=0;j<1000;++j){
	counter = 2;
	maxNumber = atoi(argv[1]);
	threadNumber = atoi(argv[2]);
	for(n=0;n<MAXSTEPS;++n)
		steps[n]=0;
//clock_gettime(cid,&start);
	for(n=0;n<threadNumber;++n)
		pthread_create(&tid[n],NULL,collatzThread,(void*)&n);

	for(n=0;n<threadNumber;++n)
		pthread_join(tid[n],NULL);
//clock_gettime(cid, &end);
	//for(i=0;i<MAXSTEPS;++i)
	//	tot+=(long)steps[i];
//diff.tv_sec = end.tv_sec - start.tv_sec;
//diff.tv_nsec = end.tv_nsec - start.tv_nsec;
//if(diff.tv_nsec < 0){
//	diff.tv_sec--;
//	diff.tv_nsec += 1000000000;
//}
//array[j].tv_sec = diff.tv_sec;
//array[j].tv_nsec = diff.tv_nsec;
//avg.tv_sec += diff.tv_sec;
//avg.tv_nsec += diff.tv_nsec;
}
	
for(j=0;j<1000;++j)
{
	avg.tv_sec += array[j].tv_sec;
	avg.tv_nsec += array[j].tv_nsec;
}
avg.tv_sec /= 1000;

avg.tv_nsec /= 1000;

	
	
	
	
	
printf("%ld %ld\n", (long)avg.tv_sec, avg.tv_nsec);	
	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	return 0;
}

void *collatzThread(void *p)
{
	int currentSteps=0;
	long currentNumber=0;
int *n = (int *)p;
clockid_t cid = 0;
struct timespec start, end, diff;
if(*n==0)
	clock_gettime(cid,&start);
	while(counter<=maxNumber)
	{
		currentSteps=0;
		if(lock){
			pthread_mutex_lock(&lock1);
			currentNumber = counter++;
			pthread_mutex_unlock(&lock1);
		}else
			currentNumber = counter++;
			
		while(currentNumber!=1)
		{
			++currentSteps;
			if(currentNumber%2==0)
				currentNumber/=2;
			else
				currentNumber=3*currentNumber+1;
		}
		if(lock){
			pthread_mutex_lock(&lock2);
			++steps[currentSteps];
			pthread_mutex_unlock(&lock2);
		}else
			++steps[currentSteps];
	}
if(*n==0){
	clock_gettime(cid, &end);
	diff.tv_sec = end.tv_sec - start.tv_sec;
	diff.tv_nsec = end.tv_nsec - start.tv_nsec;
	if(diff.tv_nsec < 0){
		diff.tv_sec--;
		diff.tv_nsec += 1000000000;
	}

	array[j].tv_sec = diff.tv_sec;
	array[j].tv_nsec = diff.tv_nsec;
}	
	pthread_exit(NULL);
}
