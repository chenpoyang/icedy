#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "young.h"

extern void *run(void *args);

int main()
{
	int ret, thrd_id;
	pthread_t thrd;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	thrd_id = 10;
	printf("Main: creating subthread %d!\r\n", thrd_id);
	ret = pthread_create(&thrd, &attr, run, (void *)thrd_id);
	if (ret)
	{
		printf("Error; return code from pthread_create():%d\r\n", ret);
		exit(-1);
	}

	pthread_attr_destroy(&attr);
	pthread_join(thrd, NULL);

	pthread_exit(NULL);
}
