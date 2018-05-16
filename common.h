/*
 * Header file for common function between encoding and decoding
 * 
 * Author: Jakub Wlodek
 * Created 5/16/18
 */

char* remove_duplicates(char* key);

char* get_transpose_alpha(char* key, int width);

void print_alphabets(char** alphabets, int num);

char** create_alphabets_on_key(char* key);