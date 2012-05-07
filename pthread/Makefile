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
ALL_C_T		= fork thread example print create wait cond \
			  hello_arg1 myhello1 hello_arg2 myhello2 stack self \
			  dotprod_serial dotprod_mutex mutex print_num condvar \
			  young

ALL_CXX_T	= sample join

ALL_T		= $(ALL_C_T) $(ALL_CXX_T)

# all object
ALL_C_OBJ	= fork.o thread.o example.o print.o create.o wait.o cond.o \
			  hello_arg1.o myhello1.o hello_arg2.o myhello2.o stack.o self.o \
			  dotprod_serial.o dotprod_mutex.o mutex.o print_num.o condvar.o \
			  young.o

ALL_CXX_OBJ	= sample.o join.o

ALL_OBJ		= $(ALL_C_OBJ) $(ALL_CXX_OBJ)

# Targets start here
default:	$(ENTRANCE)

all:	$(ALL_T)

## compile , but not link
#$(ALL_C_OBJ): %.o : %.c
#	$(CC) $(CFLAGS) $(INCPATH)  -c $< -o $@
#$(ALL_CXX_OBJ): %.o : %.cpp
#	$(CXX) $(CXXFLAGS) $(INCPATH)  -c $< -o $@

# link object
$(ALL_C_T): % : %.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(LIBS) -o $@
$(ALL_CXX_T): % : %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

# dependency
fork.o: fork.c
thread.o: thread.c
example.o: example.c
print.o: print.c
create.o: create.c
wait.o: wait.c
cond.o: cond.c
hello_arg1.o: hello_arg1.c
myhello1.o: myhello1.c
hello_arg2.o: hello_arg2.c
myhello2.o: myhello2.c
stack.o: stack.c
self.o: self.c
dotprod_serial.o: dotprod_serial.c
dotprod_mutex.o: dotprod_mutex.c
mutex.o: mutex.c
print_num.o: print_num.c
condvar.o: condvar.c
sample.o: sample.cpp
join.o: join.cpp
young.o: young.c young.h

none:
	@echo "Please do 'make OPTIONS' wehre OPTIONS is one of these:"
	@echo "	$(ALL_T) all"

.PHONY: clean default none all
clean:
	$(RM) $(ALL_OBJ) $(ALL_T)
