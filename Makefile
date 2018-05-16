all:
	gcc -c mainrunner.c
	gcc -c encoder.c
	gcc mainrunner.o encoder.o -o encoder_decoder

debug:
	gcc -c mainrunner.c -g
	gcc -c encoder.c -g
	gcc mainrunner.o encoder.o -o encoder_decoder

clean:
	rm -f encoder_decoder