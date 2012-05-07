/* wait.c : a thread_wait() function insteed of sleep() */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

/**
 * @brief	current thread wait some time.
 *
 * @param	sec: timestamp the thread wait.
 */
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

	/* mutex variable for protect variable timeout */
	pthread_mutex_init(&mutex, NULL);
	/* condiction variable for timeout */
	pthread_cond_init(&cond, NULL);

	/* lock the code */
	pthread_mutex_lock(&mutex);

	/* timeout point: current_time + interval */
	timeout.tv_sec = time(NULL) + sec;
	timeout.tv_nsec = 0;
	/* wait until timeout.tv_sec + sec from 1970-01-01::00:00:00 */
	pthread_cond_timedwait(&cond, &mutex, &timeout);

	/* unlock the code */
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	struct tm *cur_time;
	time_t begin, end;

	/* begin: time interval from 1970-01-01::00:00:00 */
	begin = time(&begin);
	cur_time = localtime(&begin);
	printf("begin time is %d:%d:%d\r\n", 
			cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);

	/* wait for a while */
	thread_wait(5);

	/* end: time interval from 1970-01-01::00:00:00 */
	end = time(&end);
	cur_time = localtime(&end);
	printf("end time is %d:%d:%d\r\n", 
			cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);

	return 0;
}
