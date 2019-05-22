/*
 * This program is based on a final project I had for my AMS 303 Graph Theory class
 * at Stony Brook University.
 * 
 * The project envolved decoding a cryptogram that had two different encryptions
 * applied to it. The encryptions are explained in greater detail in the README file
 * 
 * This file will contain the functions for decoding a message given two key words
 * 
 * Author: Jakub Wlodek
 * Created: 5/16/18
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "decoder.h"
#include "common.h"

char* alphabetFull = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
 * Function that handles the first decoding step. First, it generates an
 * alphabet set, like the second encoding. Next, it iterates over the message
 * and calls get_pos() on each character and the appropriate alphabet to decrypt
 * the second encoding.
 * 
 * @params: message -> the twice-encrypted message
 * @params: second_key -> the second encoding/decoding key
 * @return: the message after the first decoding.
 * 
 */ 
char* first_decoding(char* message, char* second_key){
    int width = strlen(second_key);
    struct alphabet_set* alphabets = create_alphabets_on_key(second_key);
    char** alphas = alphabets->alphas;
    char* decoded = (char*) calloc(1, 1024);
    int i;
    int counter = 0;
    int message_length = strlen(message);
    for(i=0; i<message_length; i++){
        char letter = get_pos(message[i], alphas[counter]);
        decoded[i] = letter;
        counter++;
        if(counter==width) counter=0; 
    }
    free(message);
    int j;
    for(j=0; j<alphabets->num_alphas; j++){
        free(alphabets->alphas[j]);
    }
    free(alphabets->alphas);
    free(alphabets);
    return decoded;
}

/*
 * Function responsible for the second decoding, that ultimately returns
 * the original message. First we remove duplicates and generate a transpose
 * alphabet. From there, we find each letter in the message in the transpose
 * alphabet, find the corresponding letter in the standard alphabet, and
 * use this information to get the original message
 * 
 * @params: message -> the message after the first decoding step
 * @params: first_key -> the first encoding key
 * @return: the fully decoded message
 */ 
char* second_decoding(char* message, char* first_key){
    char* no_dup = remove_duplicates(first_key);
    int width = strlen(no_dup);
    char* transpose_alpha = get_transpose_alpha(no_dup, width);
    //printf("The transpose alphabet is %s\n\n", transpose_alpha);
    //free(transpose_alpha);
    //char* transpose_alpha = "SAHUNBIVOCJXWDKYTELZRFPMGQ";
    free(no_dup);
    char* final_decoded = (char*) calloc(1, 1024);
    int i;
    for(i=0; i<strlen(message); i++){
        //final_decoded[i] = get_pos(message[i], transpose_alpha);
        int counter = 0;
        while(message[i] != alphabetFull[counter]){
            counter++;
        }
        final_decoded[i] = transpose_alpha[counter];
    }
    free(message);
    free(transpose_alpha);
    return final_decoded;
}

/*
 * Function that combines the two decodings and returns a decoded message
 * 
 * @params: message -> messgae to be decoded
 * @params: first_key -> key for first encoding/second decoding
 * @params: second_key -> key for second encoding/first decoding
 * @return: after_second -> decoded message after both rounds
 */
char* decode_message(char* message, char* first_key, char* second_key){
    printf("Decoding message...\n");
    char* after_first = first_decoding(message, second_key);
    //printf("The first decoding is %s\n", after_first);
    //printf("=================================\n\n");
    char* after_second = second_decoding(after_first, first_key);
    printf("The decoded message reads: %s\n", after_second);
    return after_second;
}