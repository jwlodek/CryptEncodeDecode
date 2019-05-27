/**
 * Test file that contains tests encoding messages
 * 
 * Author: Jakub Wlodek
 * Created on: May 26, 2019
 */


#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "encoder.h"

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