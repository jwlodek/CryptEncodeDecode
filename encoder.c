/*
 * This program is based on a final project I had for my Graph Theory class.
 * 
 * The project envolved decoding a cryptogram that had two different encryptions
 * applied to it. The encryptions are explained in greater detail in the README file
 * 
 * This file will contain the functions for encoding a message given two key words
 * 
 * Author: Jakub Wlodek
 * Created: 5/16/18
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encoder.h"
/*
 * The first encoding is a key transpose cypher. 
 * More details can be found in the README file 
 * @params: message -> the initial message to encode
 * @params: first_key -> the keyword used to
 */
char* first_encoding(char* message, char* first_key){
    char* no_dup = remove_duplicates(first_key);
    int width = strlen(first_key);
    int height = (26/width)+1;
    char** key_transpose_alpha = (char**) malloc(width*sizeof(char*));
    int i;
    for(i=0; i<width; i++){
        *(key_transpose_alpha+i) = (char*) calloc(1,sizeof(char)*height);
    }
}

char* second_encoding(char* message, char* second_key){
    //TODO
}

char* encode_message(char* message, char* first_key, char* second_key){
    printf("Encoding message...");
    char* after_first = first_encoding(message,first_key);
    char* after_second = second_encoding(after_first, second_key);
    printf("The encoded message reads: %s", after_second);
    return after_second;
}