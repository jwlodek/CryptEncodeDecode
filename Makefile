IDIR=include
INC=-I$(IDIR)

all:
	gcc $(INC) -c driver/mainrunner.c
	gcc $(INC) -c encoder/encoder.c
	gcc $(INC) -c decoder/decoder.c
	gcc $(INC) -c driver/common.c
	gcc $(INC) mainrunner.o encoder.o decoder.o common.o -o encoder_decoder
	rm -f mainrunner.o
	rm -f encoder.o
	rm -f decoder.o
	rm -f common.o

debug:
	gcc $(INC) -c driver/mainrunner.c -g
	gcc $(INC) -c encoder/encoder.c -g
	gcc $(INC) -c driver/common.c -g
	gcc $(INC) -c decoder/decoder.c -g
	gcc $(INC) mainrunner.o encoder.o decoder.o common.o -o encoder_decoder
	rm -f mainrunner.o
	rm -f encoder.o
	rm -f decoder.o
	rm -f common.o

test:


clean:
	rm -f encoder_decoder