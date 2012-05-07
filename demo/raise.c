#include <signal.h>
#include <stdio.h>

/* 程序结束前按Ctrl + C, 此函数执行 */
void sig_int(int sig)
{
	printf("Catch a single %d!\r\n", sig);
}

int main(int argc, char *argv[])
{
	signal(SIGINT, &sig_int);
	sleep(5);
	/* 手动发出中断信号! */
	raise(2);

	return 0;
}
