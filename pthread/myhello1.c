#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 8

char *msg[NUM_THREADS];

void *run(void *id)
{
	int tid;
	tid = *((int *)id);
	printf("Thread %d : %s\n", tid, msg[tid]);
	
	pthread_exit(NULL);
}

int main()
{
	int ret, i;
	int *id[NUM_THREADS];
	pthread_t thrd[NUM_THREADS];

	msg[0] = "English: Hello World!";
	msg[1] = "French: Bonjour, le monde!";
	msg[2] = "Spanish: Hola al mundo";
	msg[3] = "Klingon: Nuq neH!";
	msg[4] = "German: Guten Tag, Welt!"; 
	msg[5] = "Russian: Zdravstvytye, mir!";
	msg[6] = "Japan: Sekai e konnichiwa!";
	msg[7] = "Latin: Orbis, te saluto!";

	for (i = 0; i < NUM_THREADS; ++i)
	{
		printf("Creating thread %d\n", i);
		id[i] = (int*) calloc (1, sizeof(int));
		*id[i] = i;

		ret = pthread_create(&thrd[i], NULL, run, (void *)id[i]);
		if (ret)
		{
			printf("ERROR; return code from pthread_create() is %d\n", ret);
			exit(-1);
		}
	}

	pthread_exit(NULL);	/* wait for all threads to exit */
	
	/* clean up */
	for (i = 0; i < NUM_THREADS; ++i)
	{
		free(id[i]);
		id[i] = NULL;
	}

	return 0;
}
