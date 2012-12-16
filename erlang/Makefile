OBJ		=	tut.beam tut1.beam tut2.beam tut3.beam tut4.beam \
			tut5.beam
all: $(OBJ)

%.beam : %.erl
	erlc $<

.PHONEY: clean

clean:
	rm -f *.beam
