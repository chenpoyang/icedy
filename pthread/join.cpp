#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS 5
#define MAX 1000000

void *thread_run(void *threadid)
{
	double res;
	int id, i;

	id = (int)threadid;
	printf("Thread %d starting...\n", id);
	res = 0.0;
	for (i = 0; i < MAX; ++i)
	{
		res += sin(i) * tan(i);
	}
	printf("Thread %d done. Result = %e\n", id, res);
	pthread_exit(threadid);
}

int main()
{
	int ret, id;
	void *status;
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (id = 0; id < NUM_THREADS; ++id)
	{
		printf("Main: creating thread %d\n", id);
		ret = pthread_create(&threads[id], &attr, thread_run, (void*)id);
		if (ret)
		{
			printf("ERROR; return code from pthread_create() is %d\n", ret);
			exit(-1);
		}
	}

	/* Free attribute and wait for other threads */
	pthread_attr_destroy(&attr);
	for (id = 0; id < NUM_THREADS; ++id)
	{
		ret = pthread_join(threads[id], &status);
		if (ret)
		{
			printf("ERROR; return code from pthread_create() is %d\n", ret);
			exit(-1);
		}
		printf("Main: completed join with thread %d having a status of %d\n", id, (int)status);
	}
	printf("Main: program completed. Exiting.\n");
	pthread_exit(NULL);

	return 0;
}
