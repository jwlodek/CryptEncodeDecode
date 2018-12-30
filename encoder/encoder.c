/*
 * This program is based on a final project I had for my AMS 303 Graph Theory class.
 * at Stony Brook University
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
 * @params: first_key -> the keyword used to generate the transpose alphabet
 * @return: coded message after first encoding pass
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
    free(message);
    free(transpose_alpha);
    return after_first;
}

/*
 * The second encoding uses a key to generate several alphabets. 
 * that then map to the letters of a given alphabet
 * More details can be found in the README file 
 * 
 * @params: message -> the initial message to encode
 * @params: second_key -> the keyword used for the second encoding
 */
char* second_encoding(char* message, char* second_key){
    int len = strlen(second_key);
    struct alphabet_set* alphabets = create_alphabets_on_key(second_key);
    char** alphas = alphabets->alphas;
    char* encoded = (char*) calloc(1, 1024);
    int i;
    int counter = 0;
    for(i=0; i<strlen(message); i++){
        encoded[i] = alphas[counter][message[i]-65];
        counter++;
        if(counter==len) counter = 0;
    }
    free(message);
    int j;
    for(j=0; j<alphabets->num_alphas; j++){
        free(alphabets->alphas[j]);
    }
    free(alphabets->alphas);
    free(alphabets);
    return encoded;
}

/*
 * Function that combines the two encodings and returns an encoded message
 * 
 * @params: message -> messgae to be encoded
 * @params: first_key -> key for first encoding
 * @params: second_key -> key for second encoding
 * @return: after_second -> encoded message after both rounds
 */
char* encode_message(char* message, char* first_key, char* second_key){
    printf("Encoding message...\n");
    char* after_first = first_encoding(message,first_key);
    char* after_second = second_encoding(after_first, second_key);
    printf("The encoded message reads: %s\n", after_second);
    return after_second;
}