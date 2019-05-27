/**
 * Test file that contains tests for common functionality
 * between encoding and decoding
 * 
 * Author: Jakub Wlodek
 * Created on: Dec 30, 2018
 */


#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stdio.h>
#include <string.h>

#include "common.h"

char* key_one = "FIRST";
char* key_two = "SECOND";
char* message = "MESSAGE";

char* key_three = "HELLO";
char* key_four = "WORLD";
char* message_two = "CRYPTOGRAM";

char* key_five = "SNOWSTORM";
char* key_six = "SLEDS";
char* message_three = "";
char* decoded_three = "";


/* Test to check if duplicates removed successfully */
Test(asserts, remove_duplicates_test) {
    printf("-----------------------\n");
    printf("Testing removing duplicates\n");
    char* result = remove_duplicates(key_three);
    cr_assert(strcmp(result, "HELO") == 0, "Duplicates not removed successfully");
    printf("Removed duplicates successfully");
}

/* Test to see if functions correctly with no duplicates */
Test(asserts, no_duplicates_test){
    printf("-----------------------\n");
    printf("Testing removing duplicates\n");
    char* result = remove_duplicates(key_one);
    cr_assert(strcmp(result, key_one) == 0, "Duplicates not removed successfully");
    printf("Removed duplicates successfully");
}