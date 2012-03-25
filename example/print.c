#include <stdarg.h>
#include <string.h>
#include <stdio.h>

void print(char *buf, ...)
{
	va_list lst;
	char *str;
	int flg;

	va_start(lst, buf);
	flg = 0;
	for (str = buf; !flg; str = va_arg(lst, char *))
	{
		printf("%s", str);
		if (strcmp(str, "sample!") == 0)
		{
			flg = 1;
			putchar('\n');
		}
		else
		{
			putchar(' ');
		}
	}
	va_end(lst);
}

int main(int argc, char *argv[])
{
	print(__FILE__, __func__, "this", "is", "sample!");

	return 0;
}
