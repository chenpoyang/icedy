/* FILE: print_num.c
 * DESC: print [BEGIN, END] through two threads */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BEGIN 0
#define END 100

/* Define globally accessible variables and a mutex */
int num;
pthread_mutex_t mutex_num;

/* thread entrance with arguments: args */
void *run(void *args)
{
	while (num < END)
	{
		pthread_mutex_lock(&mutex_num);
		if (num < END)
		{
			printf("subthread %d: %d\r\n", (int)args, ++num);
		}
		pthread_mutex_unlock(&mutex_num);
	}

	printf("subthread finished!\r\n");
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int ret, id;
	pthread_t thrd;
	pthread_attr_t attr;

	/* initialise mutex_num */
	pthread_mutex_init(&mutex_num, NULL);
	/* initialise thread attribute */
	pthread_attr_init(&attr);
	/* set attribite joinable */
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	id = 10;
	ret = pthread_create(&thrd, &attr, run, (void *)id);
	if (ret)
	{
		printf("ERROR; return code from pthread_create(): %d\r\n", ret);
		exit(-1);
	}

	num = BEGIN;
	while (num < END)
	{
		pthread_mutex_lock(&mutex_num);
		if (num < END)
		{
			printf("main thread: %d\r\n", ++num);
		}
		pthread_mutex_unlock(&mutex_num);
	}
	pthread_mutex_destroy(&mutex_num);
	pthread_attr_destroy(&attr);
	printf("mainthread finished!\r\n");
	pthread_exit(NULL);
	
	return 0;
}
