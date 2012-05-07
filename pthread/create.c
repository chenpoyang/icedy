#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

void *print(void *id)
{
	long tid;
	tid = (long)id;
	printf("Hello, Workd! It's me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}

int main()
{
	int rc;
	long id;
	pthread_t threads[NUM_THREADS];

	for (id = 0; id < NUM_THREADS; ++id)
	{
		printf("In main: creating thread%ld\n", id);
		rc = pthread_create(&threads[id], NULL, print, (void *)id);
		if (rc)
		{
			printf("ERROR, return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);

	return 0;
}
