#include <stdio.h>
#include "merror.h"

int main(int argc, char *argv[])
{
	merr_msg("Hello, This is merr_%s()!", "msg");
	merr_quit("Hello, This is merr_%s()!", "quit");
	merr_sys("Hello, This is merr_%s()!", "sys");
	merr_dump("Hello, This is merr_%s()!", "dump");

	return 0;
}
