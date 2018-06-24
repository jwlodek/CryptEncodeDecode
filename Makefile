all:
	gcc -c mainrunner.c
	gcc -c encoder.c
	gcc -c decoder.c
	gcc -c common.c
	gcc mainrunner.o encoder.o decoder.o common.o -o encoder_decoder

debug:
	gcc -c mainrunner.c -g
	gcc -c encoder.c -g
	gcc -c common.c -g
	gcc -c decoder.c -g
	gcc mainrunner.o encoder.o decoder.o common.o -o encoder_decoder

clean:
	rm -f encoder_decoder
	rm -f mainrunner.o
	rm -f encoder.o
	rm -f decoder.o
	rm -f common.o