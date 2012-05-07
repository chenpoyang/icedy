#include <stdio.h>

extern int num;
extern int getNum();

int main()
{
	printf("main getNum(): %d\n", getNum());

	return 0;
}
