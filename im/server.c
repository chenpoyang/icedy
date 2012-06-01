#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include "global.h"

/* 服务器ip和端口号 */
#define _addr_ "127.0.0.1"
#define _port_ 8888

static pthread_t cli_thrd[1024];
static int cli_que_len;
static char buf[MAX_BUF_LEN];

void *recv_thrd(void *arg);   /* server for client */
void remove_client(const int client_id);    /* deal with client quit */

int main(int argc, char *argv[])
{
    struct sockaddr_in srv;
    int sock_fd, chk, con_fd;
    pthread_attr_t attr;

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket error!");
        return -1;
    }

    bzero(&srv, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_port = htons(_port_);

    /* inet_pton: support ipv6 and ipv4, set the ipaddr */
    if (inet_pton(AF_INET, _addr_, &srv.sin_addr) < 0)
    {
        printf("inet_pton error!");
        return -1;
    }

    chk = bind(sock_fd, (struct sockaddr*)&srv, sizeof(srv));
    if (chk < 0)
    {
        printf("bind error!");
        return -1;
    }

    chk = listen(sock_fd, MAX_LISTEN_QUEUE);
    if (chk < 0)
    {
        printf("listen error!");
        return -1;
    }

    /* 初始化线程参数 */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    cli_que_len = 0;
    while (1)
    {
        con_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL);
        printf("a client connected!\n");
        
        /* create server thread for a new client */
        chk = pthread_create(cli_thrd + 0, &attr, recv_thrd, (void *)con_fd);
        if (chk)
        {
            printf("create thread error!");
            continue;
        }
    }
    close(sock_fd);

    return 0;
}

void *recv_thrd(void *arg)   /* server for client */
{
    int sock_fd = (int)arg;
    int rec_bytes;

    while ((rec_bytes = recv(sock_fd, buf, sizeof(buf), 0)) > 0)
    {
        send(sock_fd, buf, sizeof(buf), 0);
    }

    pthread_exit(NULL);
}

void remove_client(const int client_id)    /* deal with client quit */
{
}
