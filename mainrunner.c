#include <stdio.h>
#include <stdlib.h>
#include "encoder.h"

int main(int argc, char** argv){
    char* message = *(argv+1);
    char* no_dup = remove_duplicates(message);
    printf("The original was %s, without duplicates it is %s\n",message, no_dup);
    return 0;
}
