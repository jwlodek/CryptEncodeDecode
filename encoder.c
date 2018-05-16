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

//the double alphabet is used to generate alphabets for the second encoding step
char* double_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
 * Function that is used to remove duplicate letters from the first key
 * 
 * @params: key -> the first encoding key
 * @return: key without duplicates
 */
char* remove_duplicates(char* key){
    char* without_dup = (char*) calloc(1, strlen(key));
    int counter_key = 0;
    int counter_wd = 0;
    int used[26];
    while(*(key+counter_key)!='\0'){
        int i;
        int found_dup = 0;
        for(i=0; i<counter_wd; i++){
            if(*(without_dup+i)==*(key+counter_key)) found_dup = 1;
        }
        if(found_dup==0){
            *(without_dup+counter_wd) = *(key+counter_key);
            counter_wd++;
        }
        counter_key++;
    }
    free(key);
    return without_dup;
}

/*
 * The first encoding is a key transpose cypher. 
 * More details can be found in the README file 
 * @params: message -> the initial message to encode
 * @params: first_key -> the keyword used to
 */
char* first_encoding(char* message, char* first_key){
    //TODO
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