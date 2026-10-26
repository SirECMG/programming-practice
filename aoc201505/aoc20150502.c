#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void process_line(char *line, int *pair_cnt, int *repeat_cnt) {
    int pair_map[26][26];
    int len = strlen(line);
    int i;

    for(int a = 0; a < 26; a++) {
        for(int b = 0; b < 26; b++) {
            pair_map[a][b] = -1;
        }
    }

    for(i = 0; i < len; i++) {

        if(i + 1 < len) {
            char a = line[i] - 'a';
            char b = line[i + 1] - 'a';

            if(pair_map[a][b] == -1) {
                pair_map[a][b] = i;
            } else if(i >= pair_map[a][b] + 2) {
                (*pair_cnt)++;
            }
        }
        /*
        pair_map[cur][next] = i;
        if(i > i + 2) {
            (*pair_cnt)++;
        }*/


        char cur = line[i];
        char matching_ltr = line[i + 2];

        printf("cur: %c\n", cur);
        printf("matching_ltr: %c\n", matching_ltr);

        if(i + 2 < len && cur == matching_ltr) {
            (*repeat_cnt)++;
        }
    }
};

int main() {

    char line[100];
    int nice_cnt = 0;
    while(fscanf(stdin, "%s", line) == 1) {
        int pair_cnt = 0;
        int repeat_cnt = 0;
        process_line(line, &pair_cnt, &repeat_cnt);
        if(pair_cnt > 0 && repeat_cnt > 0) {
            nice_cnt++;
        }
    }

    printf("nice count: %d\n", nice_cnt);

    

    return EXIT_SUCCESS;
}

/*
 *
 * observations:
 *
 * - i saw that we needed a map
 * - it was tricky to use two dimensional array and making decision to use current
 *   index
 * - for the second condition it was pretty straight forward, but knowing when to check     i offset from the end of the array...
 *
 *
 * 
 * */
