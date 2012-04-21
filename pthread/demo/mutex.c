/**************************************************************************
 * FILE: mutex.c
 * This example illustrates the use of mutex variables in a threads program.
 * The main data is made available to all threads through a globally 
 * accessible structure. Each thread works on a different part of the data.
 * The main thread waits for all threads to complete their computations, 
 * and then it prints resulting sum.
 *************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
The following structure contains the necessary information to allow 
the function "dotprod" to access its input data and place its output 
into the structure.
*/
typedef struct
{
	double *a;
	double *b;
	double sum;
	int veclen;
}DOTDATA;

/* Define globally accessible variables and a mutex */
#define NUMTHRDS	4
#define VECLEN		100
DOTDATA dotstr;
pthread_t thrd[NUMTHRDS];
pthread_mutex_t mutexsum;

/*
The function dotprod is activated when the thread is created.
All input to this routine is obtained from a structure of type 
DOTDATA and all output from this function is written into this 
structure. The benefit of this approach is apparent for the 
multi-threaded program: when a thread is created we pass a single 
argument to the activated function - typically this argument is a 
thread number. All the other information required by the function 
is accessed from the globally accessiable structure.
*/

void *dotprod(void *arg)
{
/* Define and use local variables for convenience */
	int i, start, end, offset, len;
	double sum, *x, *y;

	len = dotstr.veclen;
	offset = (int)arg;
	start = offset * len;
	end = start + len;
	x = dotstr.a;
	y = dotstr.b;
	
/*
Perform the dot product and assign result 
to the appropriate variable in the structure
*/
	sum = 0;
	printf("Thread %d is calculating [%d, %d)\r\n", offset, start, end);
	for (i = start; i < end; ++i)
	{
		sum += x[i] * y[i];
	}

/*
Lock a mutex prior to updating the value in the shared 
structure, and unlock it upon updating
*/
	printf("thread %d: calculate begin\r\n", offset);
	pthread_mutex_lock(&mutexsum);
	dotstr.sum += sum;
	pthread_mutex_unlock(&mutexsum);
	printf("thread %d: calculate end\r\n", offset);

	pthread_exit(NULL);
}


/*
The main program creates threads which do all the work and then 
print out the result upon completion. Before creating the threads, 
the input data is created. Since all threads update a shared structure, 
we need a mutex for mutual exclusion. The main thread need to wait for 
all threads to complete, it waits for each one of the threads. We specify 
a thread attribute value that allow the main thread to join with the threads 
it creates. Note also that we free up handles when they are no longer needed.
*/
int main(int argc, char *argv[])
{
	int i, ret, len;
	double *a, *b;
	void *status;
	pthread_attr_t attr;

	/* Assign storage and initialize values */
	len = VECLEN * NUMTHRDS;
	a = (double *) calloc (1, sizeof(double) * len);
	b = (double *) calloc (1, sizeof(double) * len);
	for (i = 0; i < len; ++i)
	{
		a[i] = 1;
		b[i] = a[i];
	}

	dotstr.veclen = VECLEN;
	dotstr.a = a;
	dotstr.b = b;
	dotstr.sum = 0;

	/* Create thread to perform the dotproduct */
	pthread_mutex_init(&mutexsum, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < NUMTHRDS; ++i)
	{
	/* Each thread works on a different set of data.
	 * The offset is specified by 'i'. The size of 
	 * the data for each thread is indicated by VECLEN.
	 */
		ret = pthread_create(thrd + i, &attr, dotprod, (void *)i);
		if (ret)
		{
			printf("ERROR; return code from pthread_create(): %d\r\n", ret);
			exit(-1);
		}
	}
	pthread_attr_destroy(&attr);

	/* Wait on the other threads */
	status = NULL;
	for (i = 0; i < NUMTHRDS; ++i)
	{
		ret = pthread_join(thrd[i], &status);
		if (ret)
		{
			printf("ERROR; return code from pthread_create(): %d\r\n", ret);
			exit(-1);
		}
	}

	/* After joining, print out the results and cleanup */
	printf("Sum = %.2lf\r\n", dotstr.sum);
	free(a);
	a = NULL;
	free(b);
	b = NULL;
	pthread_mutex_destroy(&mutexsum);
	pthread_exit(NULL);
}
