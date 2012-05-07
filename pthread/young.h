void *run(void *args)
{
	int id;

	id = (int)args;

	printf("subthread: after thrd_id - 5...\r\n");
	id -= 5;
	printf("I am subthresd with id %d!\r\n", id);

	pthread_exit(NULL);
}
