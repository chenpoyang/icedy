/* FILE: print_num.c
 * DESC: print [BEGIN, END] through two threads */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BEGIN 1
#define END 100

/* Define globally accessible variables and a mutex */
int num;
pthread_mutex_t mutex_num;

/* thread entrance with arguments: args */
void *run(void *args)
{
	printf("sub thread start!");
	while (num <= END)
	{
		pthread_mutex_lock(&mutex_num);
		printf("thread %d: %d\r\n", (int)args, ++num);
		pthread_mutex_unlock(&mutex_num);
	}
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
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINALBE);

	printf("main thread start!");
	id = 10;
	printf("creating subthread %d\r\n", id);
	ret = pthread_create(&thrd, &attr, run, (void *)id);
	if (ret)
	{
		printf("ERROR; return code from pthread_create(): %d\r\n", ret);
		exit(-1);
	}

	while (num <= END)
	{
		pthread_mutex_lock(&mutex_num);
		printf("thread %d: %d\r\n", id, ++num);
		pthread_mutex_unlock(&mutex_num);
	}
	pthread_mutex_destroy(&mutex_num);
	pthread_attr_destroy(&attr);
	ret = pthread_join(thrd, NULL);
	
	return 0;
}
