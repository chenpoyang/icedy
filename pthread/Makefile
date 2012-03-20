################################################################
# For building: ALL_T
# make version:	GNU Make 3.82
# g++ version:	gcc version 4.5.1
# gcc version:	g++ version 4.5.1
################################################################

#### === CHANGE THE SETTINGS BELOW TO SUIT YOUR ENVIRONMENT === ####

# ENTRANCE
ENTRANCE	= none

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

# == END SETTINGS -- NO NEED TO CHANGE ANYTHING BELOW THIS LINE == #

# all target
ALL_T		= fork thread example print create sample join \
			  hello_arg1 myhello1 hello_arg2 myhello2 stack self \
			  dotprod_serial dotprod_mutex mutex print_num condvar \
			  wait cond

# all object
ALL_OBJ		= *.o

# Targets start here
default:	$(ENTRANCE)

all:	$(ALL_T)

# link object
cond: cond.o
	$(CC) $(LIBS) cond.o -o cond
wait: wait.o
	$(CC) $(LIBS) wait.o -o wait
condvar: condvar.o
	$(CC) $(LIBS) condvar.o -o condvar
print_num: print_num.o
	$(CC) $(LIBS) print_num.o -o print_num
mutex: mutex.o
	$(CC) $(LIBS) mutex.o -o mutex
dotprod_mutex: dotprod_mutex.o
	$(CC) $(LIBS) dotprod_mutex.o -o dotprod_mutex
dotprod_serial: dotprod_serial.o
	$(CC) $(LIBS) dotprod_serial.o -o dotprod_serial
self: self.o
	$(CC) $(LIBS) self.o -o self
stack: stack.o
	$(CC) $(LIBS) stack.o -o stack
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
cond.o: cond.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o cond.o cond.c
wait.o: wait.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o wait.o wait.c
condvar.o: condvar.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o condvar.o condvar.c
print_num.o: print_num.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o print_num.o print_num.c
mutex.o: mutex.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o mutex.o mutex.c
dotprod_mutex.o: dotprod_mutex.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o dotprod_mutex.o dotprod_mutex.c
dotprod_serial.o: dotprod_serial.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o dotprod_serial.o dotprod_serial.c
self.o: self.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o self.o self.c
stack.o: stack.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o stack.o stack.c
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

none:
	@echo "Please do 'make OPTIONS' wehre OPTIONS is one of these:"
	@echo "	$(ALL_T) all"

.PHONY: clean default none
clean:
	$(RM) $(ALL_OBJ) $(ALL_T)
