#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 31

int main() {
    char buffer[MAX];
    fscanf(stdin, "%s", buffer);

    int i;
    for(i = 0; i <= strlen(buffer) - 1; i++) {
        if(buffer[i] == 's' && buffer[i+1] == 's') {
            printf("hiss\n");
            return EXIT_SUCCESS;
        }
    }

    printf("no hiss\n");

    


    return EXIT_SUCCESS;
}

/*
 * hissing microphone
 *
 * https://open.kattis.com/problems/hissingmicrophone
 *
 *
 * input contains a single string on a single line
 *
 * has between 1 and 30 characters
 *
 * output a single line. if the input string contains two consecutive occurrences of the letter s, then output hiss.
 * otherwise output no hiss....
 *
 *
 *
 * notes:
 *
 * - extract line between 1 and 30 characters
 * - if an input contains two consecutive letters of s..
 *
 *
 *   amiss
 *      ^
 *
 *   octopuses
 *   ^       ^
 *   0       n-1 
 *
 *   i = 0... n-2
 *
 *  
 *   
 *
 *
 *
 *
 *
 *
 * */

