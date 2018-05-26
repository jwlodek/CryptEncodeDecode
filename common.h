/*
 * Header file for common function between encoding and decoding
 * 
 * Author: Jakub Wlodek
 * Created 5/16/18
 */

struct alphabet_set{
    int num_alphas;
    char** alphas;
};

char* remove_duplicates(char* key);

char* get_transpose_alpha(char* key, int width);

void print_alphabets(char** alphabets, int num);

struct alphabet_set* create_alphabets_on_key(char* key);