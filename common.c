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
 * Function used to get the key-transpose alphabet
 * First, the key is placed in front of the standard alphabet,
 * then, the duplicate letters are removed. Then, the alphabet is re-
 * structured into a keyword transpose table of the given key's width
 * 
 * @params: key -> key without duplicate letters
 * @params: width -> length of the key without duplicates
 * @return: alphabet in keyword transpose form
 */ 
char* get_transpose_alpha(char* key, int width){
    char* temp = (char*) calloc(1, 50);
    int counter = 0;
    int i;
    for(i=0; i<strlen(key); i++){
        temp[counter] = key[counter];
        counter++;
    }
    int j = 0;
    for(j=0; j<26; j++){
        temp[counter] = alphabet[j];
        counter++;
    }
    char* transpose_no_dup = remove_duplicates(temp);
    char* transpose_alpha = (char*) calloc(1, 50);
    int prevp = 0;
    int p = 0;
    int letter_counter = 0;
    while(letter_counter<26){
        transpose_alpha[letter_counter] = transpose_no_dup[p];
        p = p+width;
        if(p >= 26){
            p = prevp+1;
            prevp = prevp+1;
        }
        letter_counter++;
    }
    printf("The new alphabet is %s\n", transpose_alpha);
    return transpose_alpha;
}
