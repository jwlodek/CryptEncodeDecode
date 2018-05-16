all:
	gcc -c mainrunner.c
	gcc -c encoder.c
	gcc -c common.c
	gcc mainrunner.o encoder.o common.o -o encoder_decoder

debug:
	gcc -c mainrunner.c -g
	gcc -c encoder.c -g
	gcc -c common.c -g
	gcc mainrunner.o encoder.o common.o -o encoder_decoder

clean:
	rm -f encoder_decoder
	rm -f mainrunner.o
	rm -f encoder.o
	rm -f common.o