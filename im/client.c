#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include "global.h"

static char buf[MAX_BUF_LEN];

void *recv_thrd(void *arg); /* 接收线程 */

int main(int argc, char *argv[])
{
    struct sockaddr_in cli;
    int sock_fd, chk;
    pthread_t tid;
    pthread_attr_t attr;

    if (argc != 3)
    {
        printf("usage: %s ipaddr port", argv[0]);
        return -1;
    }
    
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket error!");
        return -1;
    }

    bzero(&cli, sizeof(cli));
    cli.sin_family = AF_INET;
    cli.sin_port = htons(atoi(argv[2])); /* port */
    chk = inet_pton(AF_INET, argv[1], &cli.sin_addr); /* x.x.x.x to network ipaddr */
    if (chk < 0)
    {
        printf("illegal ip address!");
        return -1;
    }

    chk = connect(sock_fd, (struct sockaddr *)&cli, sizeof(cli));
    if (chk < 0)
    {
        printf("connect error!");
        return -1;
    }

    /* 接收消息的线程 */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    chk = pthread_create(&tid, &attr, &recv_thrd, (void *)sock_fd);    /* 接收线程 */
    if (chk)
    {
        printf("create thread error!");
        return -1;
    }

    while (fgets(buf, sizeof(buf), stdin) != NULL)
    {
        send(sock_fd, buf, sizeof(buf), 0);
    }

    chk = pthread_join(tid, NULL);
    pthread_attr_destroy(&attr);

    close(sock_fd);
    
    return 0;
}

void *recv_thrd(void *arg) /* 接收线程 */
{
    int sock_fd = (int)arg;
    int rec_bytes;

    while ((rec_bytes = recv(sock_fd, buf, sizeof(buf), 0)) > 0)
    {
        puts(buf);
    }
    
    pthread_exit(NULL);
}
