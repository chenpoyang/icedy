####################################################################
# For building: ALL_T
# make version:	GNU Make 3.82
# g++ version:	gcc version 4.5.1
# gcc version:	g++ version 4.5.1
####################################################################

#### === CHANGE THE SETTINGS BELOW TO SUIT YOUR ENVIRONMENT === ####

########## Compiler, tools and options

CC			= gcc
CFLAGS		= -O2 -Wall -g $(DEFINES)
CXXFLAGS	= -O2 -Wall -g $(DEFINES)

# all target
ALL_T		= simple_client_main simple_server_main

# all object
CORE_OBJ = ClientSocket.o ServerSocket.o Socket.o
ALL_OBJ	= $(CORE_OBJ) simple_client_main.o simple_server_main.o

# Targets start here
all:	$(ALL_OBJ) $(ALL_T)

simple_client_main : $(CORE_OBJ) simple_client_main.o
	$(CXX) $(CXXFLAGS) -o $@ $(CORE_OBJ) simple_client_main.o -lpthread

simple_server_main : $(CORE_OBJ) simple_server_main.o
	$(CXX) $(CXXFLAGS) -o $@ $(CORE_OBJ) simple_server_main.o -lpthread

clean:
	$(RM) $(ALL_OBJ) $(ALL_T)

# list targets that do not create files
.PHONY: clean all

# DO NOT DELETE
ClientSocket.o			: ClientSocket.cpp ClientSocket.h SocketException.h
ServerSocket.o			: ServerSocket.cpp ServerSocket.h SocketException.h
Socket.o				: Socket.cpp Socket.h
simple_client_main.o	: simple_client_main.cpp ClientSocket.h SocketException.h
simple_server_main.o	: simple_server_main.cpp ServerSocket.h SocketException.h
