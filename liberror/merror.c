#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "merror.h"

/* logical error */
void merr_msg(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	merr_deal(M_HIDE, fmt, ap);
	va_end(ap);
	return;
}

/* system error */
void merr_sys(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	merr_deal(M_SHOW, fmt, ap);
	va_end(ap);
	exit(-1);
}

/* fatal system call error */
void merr_dump(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	merr_deal(M_SHOW, fmt, ap);
	va_end(ap);
	abort();
	exit(-1);
}

/* show error messages and quit */
void merr_quit(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	merr_deal(M_SHOW, fmt, ap);
	va_end(ap);
	exit(1);
}

/* deal with error arglist */
void merr_deal(const int flg, const char *fmt, va_list ap)
{
	char buf[MAXLINE];
	int m_errno = 0, len = 0;

	snprintf(buf, sizeof(buf), "TIPS on %s, line %d:\r\n\t", __FILE__, __LINE__);

	len = strlen(buf);
	vsnprintf(buf + len, sizeof(buf) - len, fmt, ap);

	m_errno = errno;	/* get the latest types of error */
	len = strlen(buf);
	if (flg == M_SHOW)	/* show lastest error message */
	{
		snprintf(buf + len, sizeof(buf) - len, ": %s", strerror(m_errno));
	}

	len = strlen(buf);
	strncat(buf, "\r\n", sizeof(buf) - len);

	fflush(stdout);	/* in case stderr and stdout are the same */
	fputs(buf, stderr);
	fflush(stderr);
}
