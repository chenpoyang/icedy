/* @brief	print 1 ~ 100 through two thread, but locked :(((((( */
#include <pthread.h>
#include <stdio.h>

#define P(lock) while(lock++){--lock;}
#define V(lock) --lock;
#define MAX 100
static int num = 0;
static int lock = 0;

void *thread(void *null)
{
	//P(lock)
	while (num < MAX)
	{
		printf("sub:%d\n", ++num);
	}
	//V(lock)

	return null;
}

int main()
{
	int rc;
	pthread_t tid;
	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	rc = pthread_create(&tid, &attr, thread, NULL);
	if (rc)
	{
		printf("ERROR; return code from pthread_create() is %d\n", rc);
		return -1;
	}

	//P(lock)
	while (num < MAX)
	{
		printf("main:%d\n", ++num);
	}
	//V(lock)
	pthread_exit(NULL);

	return 0;
}
