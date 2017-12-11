CC			=	clang
CFLAGS		+=	-O0 -fobjc-arc -Wall -g
CXXFLAGS	+=	-O0
RM			=	rm -rf
LDFLAGS		=	-lobjc -framework Foundation

ALL_OBJ		=	AddressBook.o AddressCard.o Complex.o Foo.o Fraction+MathOps.o Fraction.o \
				NSSet+Printing.o Rectangle.o Square.o XYPoint.o main.o
ALL_T		=	main index

all:$(ALL_OBJ) $(ALL_T)

main:$(ALL_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

index:index.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(ALL_OBJ) $(ALL_T)

.PHONY: clean all
