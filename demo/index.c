#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	//char *host = "172.18.8.10";
	char *host = "127.0.0.1";
	struct in_addr localhost;
	unsigned int addr = 0;

	localhost.s_addr = inet_addr(host);
	/* 点分十进制到二进制的转换:00001010, 00001000, 00010010, 10101100 */
	addr = inet_addr(host);

	/* 返加网络号 */
	printf("%x\r\n", addr);
	addr = inet_netof(localhost);
	printf("%x\r\n", addr);
	addr = inet_network(host);

	/* 返加点分十进制地址 */
	printf("%s\r\n", inet_ntoa(localhost));

	return 0;
}
