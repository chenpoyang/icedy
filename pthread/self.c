#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * run(void *args)
{
	int thrd_id;

	thrd_id = *((int *)args);
	printf("subthread %d is running\r\n", thrd_id);
	printf("sub pthread_self(): %ld\r\n", pthread_self());
	
	pthread_exit(NULL);
}

int main()
{
	int ret;
	pthread_t thrd;
	pthread_attr_t attr;
	int thrd_id;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	printf("creating subthread...\r\n");
	thrd_id = 10;
	ret = pthread_create(&thrd, &attr, run, (void *)(&thrd_id));
	if (ret)
	{
		printf("ERROR; return code from pthread_create():%d\r\n", ret);
		exit(-1);
	}
	printf("main pthread_self(): %ld\r\n", pthread_self());

	pthread_attr_destroy(&attr);
	pthread_join(thrd, NULL);
	pthread_exit(NULL);
}
