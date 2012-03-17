#include <stdio.h>

/* Names of quoting styles.  */
char const *const quoting_style_args[] =
{
  "literal",
  "shell",
  "shell-always",
  "c",
  "c-maybe",
  "escape",
  "locale",
  "clocale",
  0
};

enum quoting_style
{
  literal_quoting_style,
  shell_quoting_style,
  shell_always_quoting_style,
  c_quoting_style,
  c_maybe_quoting_style,
  escape_quoting_style,
  locale_quoting_style,
  clocale_quoting_style,
  custom_quoting_style,
};

/* Correspondences to quoting style names.  */
enum quoting_style const quoting_style_vals[] =
{
  literal_quoting_style,
  shell_quoting_style,
  shell_always_quoting_style,
  c_quoting_style,
  c_maybe_quoting_style,
  escape_quoting_style,
  locale_quoting_style,
  clocale_quoting_style
};

int main(int argc, char *arg[])
{
	int i, len;

	enum quoting_style sty = quoting_style_vals[3];

	/**
	 * total_size:	count the total bytes the array occupied
	 * member_size:	then count the bytes the array member occupied
	 * len:			the length of the array: total_size / member_size
	 */
	len = sizeof(quoting_style_vals) / sizeof(enum quoting_style);;
	printf("len = %d\r\n", len);
	for (i = 0; i < len; ++i)
	{
		if (sty == quoting_style_vals[i])
		{
			puts(quoting_style_args[i]);
			printf("id = %d\r\n", i);
			break;
		}
	}

	return 0;
}
