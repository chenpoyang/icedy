####################################################################
# For building: ALL_T
# make version:	GNU Make 3.82
# g++ version:	gcc version 4.5.1
# gcc version:	g++ version 4.5.1
####################################################################

#### === CHANGE THE SETTINGS BELOW TO SUIT YOUR ENVIRONMENT === ####

# ENTRANCE
ENTRANCE	= none

########## Compiler, tools and options
CC			= gcc
CXX			= g++
DEFINES		= -DMY_DEBUG
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
ALL_T		= dthread1 print

# all object
ALL_OBJ		= *.o

# Targets start here
default:	$(ENTRANCE)

all:	$(ALL_T)

# link
print: print.o
	$(CC) -o print print.o
dthread1: dthread1.o
	$(CC) -o dthread1 dthread1.o $(LIBS)

# compile
print.o: print.c
	$(CC) $(CFLAGS) $(INCPATH)	-c -o print.o print.c
dthread1.o: dthread1.c
	$(CC) $(CFLAGS) $(INCPATH)	-c -o dthread1.o dthread1.c


# pseudo target
.PHONY: clean default none

# make entrance with no options
none:
	@echo "Please do 'make OPTIONS' wehre OPTIONS is one of these:"
	@echo "	$(ALL_T) all"

# clean
clean:
	$(RM) $(ALL_OBJ) $(ALL_T)
