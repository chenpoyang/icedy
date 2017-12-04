CC			=	clang
CFLAGS		+=	-O0 -fobjc-arc -Wall
CXXFLAGS	+=	-O0
RM			=	rm -f
LDFLAGS		=	-lobjc -framework Foundation

ALL_OBJ		=	AddressBook.o AddressCard.o Complex.o Foo.o Fraction+MathOps.o Fraction.o \
				NSSet+Printing.o Rectangle.o Square.o XYPoint.o main.o
ALL_T		=	main

all:$(ALL_OBJ) $(ALL_T)

main:$(ALL_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(ALL_OBJ) $(ALL_T)

.PHONY: clean all

AddressBook.o: AddressBook.m AddressBook.h AddressCard.h
AddressCard.o: AddressCard.m AddressCard.h
Complex.o: Complex.m Complex.h
Foo.o: Foo.m Foo.h
Fraction+MathOps.o: Fraction+MathOps.m Fraction+MathOps.h Fraction.h
Fraction.o: Fraction.m Fraction.h
NSSet+Printing.o: NSSet+Printing.m NSSet+Printing.h
Rectangle.o: Rectangle.m Rectangle.h XYPoint.h
Square.o: Square.m Square.h Rectangle.h
XYPoint.o: XYPoint.m XYPoint.h
main.o: main.m Complex.h Fraction.h Rectangle.h Square.h XYPoint.h Foo.h \
  Fraction+MathOps.h AddressCard.h AddressBook.h NSSet+Printing.h
