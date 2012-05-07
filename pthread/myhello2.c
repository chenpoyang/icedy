#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 8

char *msg[NUM_THREADS];
struct thread_data {
	int id;
	int sum;
	char *msg;
};

void *run(void *args)
{
	struct thread_data *res;

	res = (struct thread_data *)args;
	printf("Thread %d: %s Sum = %d\n", res->id, res->msg, res->sum);
	pthread_exit(NULL);
}

int main()
{
	int sum, i, ret;
	pthread_t thrd[NUM_THREADS];
	struct thread_data thrd_dat[NUM_THREADS];

	msg[0] = "English: Hello World!";
	msg[1] = "French: Bonjour, le monde!";
	msg[2] = "Spanish: Hola al mundo";
	msg[3] = "Klingon: Nuq neH!";
	msg[4] = "German: Guten Tag, Welt!"; 
	msg[5] = "Russian: Zdravstvytye, mir!";
	msg[6] = "Japan: Sekai e konnichiwa!";
	msg[7] = "Latin: Orbis, te saluto!";

	sum = 0;
	for (i = 0; i < NUM_THREADS; ++i)
	{
		sum += i;
		printf("Creating thread %d\n", i);
		thrd_dat[i].id = i;
		thrd_dat[i].sum = sum;
		thrd_dat[i].msg = msg[i];
		ret = pthread_create(&thrd[i], NULL, run, (void*)&thrd_dat[i]);
		if (ret)
		{
			printf("ERROR; return code from pthread_create() is %d\n", ret);
			exit(-1);
		}
	}

	pthread_exit(NULL);	/* waiting for all threads to exit */

	return 0;
}
