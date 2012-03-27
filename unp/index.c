#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
	struct sockaddr_in addr;
	unsigned int ad = 0;

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(13);
	inet_pton(AF_INET, "127.18.8.10", &addr.sin_addr);

	ad = 168301183;
	printf("%x\r\n", ad);

	return 0;
}
