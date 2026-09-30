/*
 * aoc2015, 01
 *
 * santa is delivering presents
 *
 * can't find the right floor
 *
 * directions are confusing
 *
 * starts are ground floor
 *
 * follows one instruction at a time.
 *
 *
 * ( go up 1 floor
 * ) go down one floorA
 *
 *
 * example1:
 *
 * (()) 0
 * () () 0
 * ((( 3
 * (()(()( 3
 * ()) -1
 * ))( -1
 * ))) -3
 * )())()) -3
 *
 *
 * things to do:
 *
 * 1. i need to read input
 * 2. need to input file line by line.... reading the newline
 * 3. need to hold variable for count
 * 4. eof termination
 *
 * 
 * */

#include <stdio.h>
#include <stdlib.h>

#define INPUT "input.txt"

void update_count(int current_char, int *count) {
   if(current_char == '(') *count += 1;
   if(current_char == ')') *count -= 1;
   return;
}

int main() {
    FILE *fp;
    fp = fopen(INPUT, "r");
    if(fp == NULL) {
        printf("error trying to open file, check if it exists.\n");
        return EXIT_FAILURE;
    }

    int ch;
    int count = 0;

    while((ch = getc(fp)) != EOF) {
       printf("%c", ch);
       update_count(ch, &count);
    }

    printf("count: %d\n", count);

    fclose(fp);

    return 0;
}

