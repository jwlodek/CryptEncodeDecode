#
# Makefile for CryptEncodeDecode
#
# Options:
# all   -> standard compilation
# debug -> compile with debug headers
# tests -> compile Criterion unit tests
# clean -> removes all created binary files from previous compile
#
# Author: Jakub Wlodek
#


# File directories + locations
SRC_DIR=src
TEST_DIR=test
IDIR=include
INC=-I$(IDIR)


# Standard Compilation
all:
	gcc $(INC) -c $(SRC_DIR)/mainrunner.c
	gcc $(INC) -c $(SRC_DIR)/encoder.c
	gcc $(INC) -c $(SRC_DIR)/decoder.c
	gcc $(INC) -c $(SRC_DIR)/common.c
	gcc $(INC) mainrunner.o encoder.o decoder.o common.o -o encoder_decoder
	rm -f mainrunner.o
	rm -f encoder.o
	rm -f decoder.o
	rm -f common.o

# Debug Compilation
debug:
	gcc $(INC) -c $(SRC_DIR)/mainrunner.c -g
	gcc $(INC) -c $(SRC_DIR)/encoder.c -g
	gcc $(INC) -c $(SRC_DIR)/common.c -g
	gcc $(INC) -c $(SRC_DIR)/decoder.c -g
	gcc $(INC) mainrunner.o encoder.o decoder.o common.o -o encoder_decoder
	rm -f mainrunner.o
	rm -f encoder.o
	rm -f decoder.o
	rm -f common.o

# Unit test Compilation
test:
	LIB_DIR=libs
	LIB=-L$(LIB_DIR)
	gcc $(INC) -c $(SRC_DIR)/encoder.c
	gcc $(INC) -c $(SRC_DIR)/decoder.c
	gcc $(INC) -c $(SRC_DIR)/common.c
	gcc $(INC) $(INC_TEST) -c $(TEST_DIR)/common_tests.c
	gcc encoder.o decoder.o common.o common_tests.o -o enc_dec_tests $(LIB)


# Cleanup
clean:
	rm -f mainrunner.o
	rm -f encoder.o
	rm -f decoder.o
	rm -f common.o
	rm -f enc_dec_tests
	rm -f encoder_decoder