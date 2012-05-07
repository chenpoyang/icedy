#include <stdio.h>

enum access_mode
{
	ACCESS_READ, 
	ACCESS_WRITE, 
	ACCESS_UPDATE
};

int main()
{
	enum access_mode ac_mode = ACCESS_READ;
	printf("%d\n", ac_mode);
	switch (ac_mode)
	{
		case ACCESS_READ:
			puts("READ");
			break;
		default:
			puts("NOT READ");
			break;
	}

	return 0;
}
