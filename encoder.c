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
 * 
 * @params: message -> the initial message to encode
 * @params: first_key -> the keyword used to
 * @return: coded message
 */
char* first_encoding(char* message, char* first_key){
    char* no_dup = remove_duplicates(first_key);
    int width = strlen(no_dup);
    char* transpose_alpha = get_transpose_alpha(no_dup, width);
    free(no_dup);
    char* after_first = (char*) calloc(1, 1024);
    int i;
    for(i=0; i<strlen(message); i++){
        int location = message[i]-65;
        after_first[i] = transpose_alpha[location];
    }
    printf("The message after the first encoding is: %s\n", after_first);
    free(message);
    free(transpose_alpha);
    return after_first;
}

/*
 * The first encoding is a key transpose cypher. 
 * More details can be found in the README file 
 * 
 * @params: message -> the initial message to encode
 * @params: first_key -> the keyword used to
 */
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