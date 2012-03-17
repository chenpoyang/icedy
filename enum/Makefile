CC		= gcc
CFLAGS	= -O2 -Wall -g
RM		= rm -f

ALL_T	= quotearg access
ALL_OBJ	= *.o

all: $(ALL_T)

quotearg: quotearg.o
	$(CC) $(CFLAGS) -o quotearg quotearg.o
access:	access.o
	$(CC) $(CFLAGS) -o access access.o

quotearg.o: quotearg.c
	$(CC) $(CFLAGS) -c quotearg.c
access.o: access.c
	$(CC) $(CFLAGS) -c access.c

.PHONY: clean
clean:
	$(RM) $(ALL_OBJ) $(ALL_T)
