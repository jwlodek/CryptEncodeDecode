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
#include "decoder.h"
#include "common.h"

char* first_decoding(char* message, char* second_key){
    int width = strlen(second_key);
    struct alphabet_set* alphabets = create_alphabets_on_key(second_key);
    char** alphas = alphabets->alphas;
    char* decoded = (char*) calloc(1, 1024);
    int i;
    int counter = 0;
    for(i=0; i<strlen(message); i++){
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

char* second_decoding(char* message, char* first_key){
    
}

char* decode_message(char* message, char* first_key, char* second_key){

}