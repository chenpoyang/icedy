#ifndef _MERROR_H_
#define _MERROR_H_

#include <stdarg.h>
#include <string.h>

#define M_HIDE 0
#define M_SHOW 1

/* max length to storate error message */
#define MAXLINE 4096

/* logical error */
void merr_msg(const char *fmt, ...);

/* system error */
void merr_sys(const char *fmt, ...);

/* fatal system call error */
void merr_dump(const char *fmt, ...);

/* show error messages and quit */
void merr_quit(const char *fmt, ...);

/* deal with error arglist */
void merr_deal(const int flg, const char *fmt, va_list ap);
#endif // _MERROR_H_
