/*
 * find the position of the first character that causes him to enter the basement floor (-1)
 *
 * the first character has position 1
 * the second character has position 2
 * etc
 *
 * example:
 *
 * ) causes him to enter the basement at character position 1.
 * () ()) causes him to enter the basement at character position 5.
 **/

#include "stdio.h"
#include "stdlib.h"

#define FILENAME "input.txt"

void update_count(int cur, int *count) {
    if(cur == '(') ++(*count);
    if(cur == ')') --(*count);
    return;
}

int check_basement(int *count) {
    if(*count == -1) {
        return 1;
    }
    return 0;
}


int main() {
    
    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL) {
        printf("something went wrong reading file\n");
        return EXIT_FAILURE;
    }

    int ch;
    int current_pos = 0;
    int count = 0;
    int result = 0;
    while((ch = getc(fp)) != EOF) {
        current_pos += 1;
        update_count(ch, &count);
        result = check_basement(&count);
        if(result == 1) break;
    }

    printf("%d\n", current_pos);

    fclose(fp);


    return 0;
}
