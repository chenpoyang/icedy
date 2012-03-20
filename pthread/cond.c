#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 3
#define LIMIT		12
#define ADD_COUNT	125
pthread_t thrd[NUM_THREADS];
pthread_mutex_t mutex;
pthread_cond_t cond;
int count;

/* a thread function for accumulating count */
void *inc_count(void *args);
/* a thread function for changing the count while the condition is true */
void *watch_count(void *args);
/* timestamp the thread wait */
void thread_wait(const int sec);

int main(int argc, char *argv[])
{
	int i, ret, thrd_id_a, thrd_id_b, thrd_id_c;
	pthread_attr_t attr;
	void *status;

	/* initialise mutex and condition variables for synchronization */
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	/* initialise threads attributes and set threads joinable */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	thrd_id_a = 1;
	thrd_id_b = 2;
	thrd_id_c = 3;
	count = 0;	/* initialise the begin value */
	pthread_create(thrd + 0, &attr, watch_count, (void*)thrd_id_a);
	pthread_create(thrd + 1, &attr, inc_count, (void*)thrd_id_b);
	pthread_create(thrd + 2, &attr, inc_count, (void*)thrd_id_c);

	status = NULL;
	for (i = 0; i < NUM_THREADS; ++i)
	{
		ret = pthread_join(thrd[i], &status);
		if (ret)
		{
			printf("ERROR; return code from pthread_create(): %d\r\n", ret);
			exit(-1);
		}
	}

	printf("Main(): Waited on %d threads. Final value of count = %d.Done!", 
			NUM_THREADS, count);
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	pthread_exit(NULL);
}

/* a thread function for accumulating count */
void *inc_count(void *args)
{
	int id;

	id = (int)args;

	pthread_mutex_lock(&mutex);

	++count;
	if (count == LIMIT)
	{
		printf("inc_count(): thread %d, count = %d Threadhold reached.", 
				id, count);
		pthread_cond_signal(&cond);
		printf("Just send signal!\n");
	}
	printf("inc_count(): thread %d, count = %d, unlocking mutex\r\n", 
			id, count);

	pthread_mutex_unlock(&mutex);
	thread_wait(1);
}

/* a thread function for changing the count while the condition is true */
void *watch_count(void *args)
{
	int id;

	id = (int)args;
	printf("Starting watch_count(): thread %d\r\n", id);

	pthread_mutex_lock(&mutex);

	if (count < LIMIT)
	{
		printf("watch_count(): thread %d is going into wait...", id);
		/* block there waiting for condition(count >= LIMIT), and then unlock */
		pthread_cond_wait(&cond, &mutex);
		/* got the lock */
		printf("watch_count(): thread %d condition signal received!", id);
		count += ADD_COUNT;
		printf("watch count(): thread %d count now = %d\r\n", 
				id, ADD_COUNT);
	}

	pthread_mutex_unlock(&mutex);
}

void *watch_count(void *args);
/* timestamp the thread wait */
/* timestamp the thread wait */
void thread_wait(const int sec)
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	struct timespec timeout;

	/* there is no need to wait */
	if (sec < 0)
	{
		return;
	}

	/* mutex for protect the code */
	pthread_mutex_init(&mutex, NULL);
	/* condition for making current thread to wait some time */
	pthread_cond_init(&cond, NULL);

	pthread_mutex_lock(&mutex);

	/* timeout point: current_time + sec */
	timeout.tv_sec = time(NULL) + sec;
	timeout.tv_nsec = 0;
	pthread_cond_timedwait(&cond, &mutex, &timeout);

	pthread_mutex_unlock(&mutex);
}
