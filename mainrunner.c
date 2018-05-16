/*
 * This program is based on a final project I had for my Graph Theory class.
 * 
 * The project envolved decoding a cryptogram that had two different encryptions
 * applied to it. The encryptions are explained in greater detail in the README file
 * 
 * This is the main runner file of the program
 * 
 * Author: Jakub Wlodek
 * Created: 5/16/18
 */

#define KEY_SIZE  256
#define MESSAGE_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encoder.h"

//function used for printing help message
void print_help_message(){
    printf("Cryptogram Encoder/Decoder\n");
    printf("Arguments:\n");
    printf("-h or --help -> prints this help message\n");
    printf("-e or --encode -> encode the message with given keys\n");
    printf("-d or --decode -> decode the message with given keys\n");
    printf("-f KEY1 or --first-key KEY1-> key for first encryption pass.\n");
    printf("-s KEY2 or --second-key KEY2 -> key for second encryption pass\n");
    printf("-m MESSAGE or --message MESSAGE -> message for encoding/decoding\n");
    printf("Required: -e or -d, -m, -f, and -s. key1 must be between 5 and 9 characters long inclusive\n");
}

//function that prints the information passed to the encoder decoder if it is valid
void print_info(int encode_decode_flag, char* key1, char* key2, char* message){
    if(encode_decode_flag==0) printf("Encoding...\n");
    else printf("Decoding...\n");
    printf("The first key is %s and the second key is %s\n", key1, key2);
    printf("The message is %s\n", message);
}

/*
 * function that checks user input flags for errors
 * @params: encode_decode_flag -> flag for encode/decode
 * @params: key1 -> first key
 * @params: key2 -> second key
 * @params: message -> message for encode/decode
 * @return: -1 if error, 0 if valid
 */
int check_user_input(int encode_decode_flag, char* key1, char* key2, char* message){
    if(encode_decode_flag==-1){
        printf("You did not select encode/decode\n");
        print_help_message();
        return -1;
    }
    if(key1==NULL){
        printf("The key for the first encode/deocde was not specified\n");
        print_help_message();
        return -1;
    }
    if(strlen(key1)>9 || strlen(key2)<5){
        printf("The first key must be between 5 and 9 characters long\n");
        print_help_message();
        return -1;
    }
    if(key2==NULL){
        printf("The key for the second encode/decode was not specified\n");
        print_help_message();
        return -1;
    }
    if(message==NULL){
        printf("The message to encode/decode was not specified\n");
        print_help_message();
        return -1;
    }
    print_info(encode_decode_flag, key1, key2, message);
    return 0;
}

/*
 * Main function
 * First parses arguments from command line, then passes them to the correct
 * encoding and decoding functions
 * 
 * @params: argc -> argument counter
 * @params: argv -> arguments
 * @return: int -> return status of program
 */
int main(int argc, char** argv){
    int arg_num = 1;
    int encode_decode_flag = -1;
    char* key_1 = NULL;
    char* key_2 = NULL;
    char* message = NULL;
    while(arg_num<argc){
        //printf("The arg is %s.\n", *(argv+arg_num));
        char* arg = *(argv+arg_num);
        //printf("%d\n",strcmp(arg,"-f"));
        if(strcmp(arg,"-h")==0 || strcmp(arg,"--help")==0){
            print_help_message();
            return 0;
        }
        else if(strcmp(arg,"-d")==0 || strcmp(arg,"--decode")==0){
            encode_decode_flag = 1;
        }
        else if(strcmp(arg,"-e")==0 || strcmp(arg,"--encode")==0){
            encode_decode_flag = 0;
        }
        else if(strcmp(arg,"-m")==0 || strcmp(arg,"--message")==0){
            message = (char*) calloc(1, MESSAGE_SIZE); 
            arg_num++;           
            strcpy(message, *(argv+arg_num));
        }
        else if(strcmp(arg, "-f")==0 || strcmp(arg, "--first-key")==0){
            printf("reading the first key\n");
            key_1 = (char*) calloc(1, KEY_SIZE);
            arg_num++;
            strcpy(key_1, *(argv+arg_num));
        }
        else if(strcmp(arg, "-s")==0||strcmp(arg,"--second-key")==0){
            key_2 = (char*) calloc(1, KEY_SIZE);
            arg_num++;
            strcpy(key_2, *(argv+arg_num));
        }
        else{
            printf("One or more of the entered flags is invalid\n");
            print_help_message();
            return -1;
        }
        arg_num++;
    }
    int check = check_user_input(encode_decode_flag, key_1, key_2, message);
    if(check==-1) return -1;
    else if(encode_decode_flag==0){
        char* after_first = first_encoding(message, key_1);
    }
    else{
        //decode
    }
}
