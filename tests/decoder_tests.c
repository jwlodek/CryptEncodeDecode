/**
 * Test file that contains tests decoding messages
 * 
 * Author: Jakub Wlodek
 * Created on: May 26, 2019
 */


#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "decoder.h"


char* key_one           = "FIRST";
char* key_two           = "SECOND";
char* message           = "MESSAGE";
char* mid_decode_one    = "CUKKFIU";
char* decoded_one       = "UZMYSLM";

char* key_three         = "HELLO";
char* key_four          = "WORLD";
char* message_two       = "CRYPTOGRAM";
char* mid_decode_two    = "";
char* decoded_two       = "";

char* key_five          = "SNOWSTORM";
char* key_six           = "SLEDS";
char* message_three     = "";
char* mid_decode_three  = "";
char* decoded_three     = "";



/* Test to check if first decoding step is performed correctly */
Test(asserts, first_decoding_test) {
    printf("-----------------------\n");
    printf("Testing first decoding step...\n");
    char* res_one = first_decoding(message, key_two);
    cr_assert(strcmp(res_one, mid_decode_one) == 0, "First decoding failed for message: %s", message);
    char* res_two = first_decoding(message_two, key_four);
    cr_assert(strcmp(res_two, mid_decode_two) == 0, "First decoding failed for message: %s", message_two);
    char* res_three = first_decoding(message_three, key_six);
    cr_assert(strcmp(res_three, mid_decode_three) == 0, "First decoding failed for message: %s", message_three);
    free(res_one);
    free(res_two);
    free(res_three);
    printf("First decoding step done.\n");
}


/* Test to check if second decoding step is performed correctly */
Test(asserts, second_decoding_test) {
    printf("-----------------------\n");
    printf("Testing second decoding step...\n");
    char* res_one = second_decoding(message, key_one);
    cr_assert(strcmp(res_one, message) == 0, "Second decoding failed for message: %s", message);
    char* res_two = second_decoding(message_two, key_three);
    cr_assert(strcmp(res_two, message_two) == 0, "Second decoding failed for message: %s", message_two);
    char* res_three = second_decoding(message_three, key_five);
    cr_assert(strcmp(res_three, message_three) == 0, "Second decoding failed for message: %s", message_three);
    free(res_one);
    free(res_two);
    free(res_three);
    printf("Second decoding step done.\n");
}


/* Test to check if full decoding is correct */
Test(asserts, full_decoding_test) {
    printf("-----------------------\n");
    printf("Testing full decoding process...\n");
    char* res_one = decode_message(message, key_one, key_two);
    cr_assert(strcmp(res_one, message) == 0, "Second decoding failed for message: %s", message);
    char* res_two = decode_message(message_two, key_three, key_four);
    cr_assert(strcmp(res_two, message_two) == 0, "Second decoding failed for message: %s", message_two);
    char* res_three = decode_message(message_three, key_five, key_six);
    cr_assert(strcmp(res_three, message_three) == 0, "Second decoding failed for message: %s", message_three);
    free(res_one);
    free(res_two);
    free(res_three);
    printf("Decoding done.\n");
}