#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N_THREADS 4
#define N 1000
#define BASE 1000000
#define size_t unsigned int

pthread_attr_t attr;	/* global */

void *run(void *threadid);

int main(int argc, char *argv[])
{
	int ret, i;
	size_t stacksize;
	pthread_t thrd[N];

	/**
	 * @brief	init pthread attribute
	 *
	 * @param	init attr
	 */
	pthread_attr_init(&attr);

	/**
	 * @brief	the default stack size of the thread attribute
	 *
	 * @param	attr	thread attribute
	 * @param	stacksize	thread's stack size
	 */
	pthread_attr_getstacksize(&attr, &stacksize);
	printf("Default stack size = %u\r\n", stacksize);

	/* specified thhread's stacksize explicitly */
	stacksize = sizeof(double) * N * N + BASE;
	pthread_attr_setstacksize(&attr, stacksize);
	printf("Amount of stack needed per thread = %u\r\n", stacksize);
	for (i = 0; i < N_THREADS; ++i)
	{
		printf("Creating threads with stack size = %u", stacksize);
		ret = pthread_create(thrd + i, &attr, run, (void *)i);
printf("pthread_create(): %d\r\n", ret);
		if (ret)
		{
			printf("ERROR; return code from pthread_create():%d\r\n", ret);
			exit(-1);
		}
	}
	printf("Created %d threads.\r\n", N_THREADS);
	pthread_exit(NULL);
printf("have return 0!\r\n");

	return 0;
}

void *run(void *threadid)
{
	int id, i, j;
	size_t stacksize = 0;
	double res[N][N];

	id = (int)threadid;
	stacksize = pthread_attr_getstacksize(&attr, &stacksize);
	printf("Thread %d: stack size = %u bytes\r\n", id, stacksize);
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			res[i][j] = (i * j) / 3.452 + (N - i);
		}
	}

	pthread_exit(NULL);
}
