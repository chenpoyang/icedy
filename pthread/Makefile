################################################################
# Makefile for building: ALL_T
# Make:		GNU Make 3.82
################################################################

########## Compiler, tools and options

CC			= gcc
CXX			= g++
# DEFINES		= -DNO_DEBUG
DEFINES		=
CFLAGS		= -O2 -Wall -g $(DEFINES)
CXXFLAGS	= -O2 -Wall -g $(DEFINES)
INCPATH		= -I.
LDFLAGS		= $(SYSLDFLAGS) $(MYLDFLAGS)
LIBS		= -l$(SYSLIBS) $(MYLIBS)
RM			= rm -f

# system options
SYSCFLAGS	=
SYSLDFLAGS	=
SYSLIBS		= pthread

# user options
MYCFLAGS	=
MYLDFLAGS	=
MYLIBS		=

# all target
ALL_T		= fork thread example print create sample join \
			  hello_arg1 myhello1 hello_arg2 myhello2
# all object
ALL_OBJ		= *.o

all:	$(ALL_T)

# link object
fork: fork.o
	$(CC) fork.o -o fork
thread: thread.o
	$(CC) $(LIBS) thread.o -o thread
example: example.o
	$(CC) $(LIBS) example.o -o example
print: print.o
	$(CC) $(LIBS) print.o -o print
create: create.o
	$(CC) $(LIBS) create.o -o create
sample: sample.o
	$(CXX) $(LIBS) sample.o -o sample
join: join.o
	$(CXX) $(LIBS) join.o -o join
hello_arg1: hello_arg1.o
	$(CC) $(LIBS) hello_arg1.o -o hello_arg1
myhello1: myhello1.o
	$(CC) $(LIBS) myhello1.o -o myhello1
hello_arg2: hello_arg2.o
	$(CC) $(LIBS) hello_arg2.o -o hello_arg2
myhello2: myhello2.o
	$(CC) $(LIBS) myhello2.o -o myhello2

# compile , but not link
fork.o:	fork.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o fork.o fork.c
thread.o: thread.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o thread.o thread.c
example.o: example.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o example.o example.c
print.o: print.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o print.o print.c
create.o: create.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o create.o create.c
sample.o: sample.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sample.o sample.cpp
join.o: join.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o join.o join.cpp
hello_arg1.o: hello_arg1.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o hello_arg1.o hello_arg1.c
myhello1.o: myhello1.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o myhello1.o myhello1.c
hello_arg2.o: hello_arg2.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o hello_arg2.o hello_arg2.c
myhello2.o: myhello2.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o myhello2.o myhello2.c

.PHONY: clean
clean:
	$(RM) $(ALL_OBJ) $(ALL_T)
