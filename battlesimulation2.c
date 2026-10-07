#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void process_simulation(char *contents, int len, char *output) {
    /*
     * we need to process each character in contents
     *
     * and populate output for the given scenarios
     *
     * we will need a output writer index.
     *
     *
     * but we also need to iterate contents
     *
     * start state i = 0, up to len -  (len - 1 the last) so third to last is len - 3 for
     *
     * if there are any remaining chars we will need to process them too..
     *
     * RBLH
     *
     *
     * i think the bounds are i to N - 1
     *
     * but we need to check for the combination case every iteration
     *
     *
     *
     * */



    /*
     * combination logic
     *
     * if we see any R in first, check for B in the next, for chec L in the last
     * if we see any B in first, check for R in the next, checo for L in the last
     * if we see any L in first, checo for R in the next, check for B in the last
     *
     *
     * */

    int i = 0;
    int w_idx = 0;

    /*
     * a
     * b
     * c <- n - 3
     * d <- n - 2
     * e <- n - 1
     *        
     * */
    while(i < len) {

        /*
         *
         * RBLLLBRR
         *
         * R i == 0
         * B i == 1
         * L i == 2
         * L i == 3
         * L
         * B
         * R
         * R
         * */
        if(i <= len - 3) {
            int a = contents[i];
            int b = contents[i + 1];
            int c = contents[i + 2];

            if((a == 'R' || b == 'R' || c == 'R')
                    && (a == 'B' || b == 'B' || c == 'B')
                    && (a == 'L' || b == 'L' || c == 'L')) {
                output[w_idx++] = 'C';
                i += 3;
                continue;
            }
        }

        if(contents[i] == 'R') {
            output[w_idx++] = 'S';
        }
        if(contents[i] == 'B') {
            output[w_idx++] = 'K';
        }
        if(contents[i] == 'L') {
            output[w_idx++] = 'H';
        }
        ++i;
    }

    output[w_idx] = '\0';
}
int main() {

    /*
     * i need to extract the contents of the file
     *
     * since we need to look ahead we should use string
     * */

    char contents[1000000];
    char output[1000000 + 1];

    if(fscanf(stdin, "%s", &contents) != 1) {
        printf("something went wrong with reading file \n");
        return EXIT_FAILURE;
    }
    int len = strlen(contents);

    process_simulation(contents, len, output);

    printf("%s\n", output);


    return EXIT_SUCCESS;
}



/*
 *
 * retro:
 *
 * what made this problem difficult is understanding the bounds of the processing..
 *
 * i understood what i needed to do, but having to populate output with the index and knowing which counters to increment at given time in code was difficult.
 * we really needed to understand each moving part.
 *
 * also creating the if statement for the combination was difficult and a little confusing, i needed to really break it down and provide examples to create the if statement.
 *
 * and knowing the bounds of the loop.
 *
 * i < len - 2  vs alterantives. i <= len - 3 is easiest to understand..
 *
 *
 * A len - 3
 * B len - 2
 * C len - 1
 *
 *
 * */
