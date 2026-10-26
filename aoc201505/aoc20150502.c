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
 * day 5:
 *
 * naughty or nice
 *
 * nice string
 *
 * - it contains at least three vowels
 *      - aeiou
 *      - aei
 *      - xazegov
 *      - aeiouaeiouaeiou
 * - it contains at least one letter that appears twice in a row, like xx, abcdde (dd)
 *   - or aabbccdd (aa, bb, cc, or dd)
 * - it does not contain the strings ab, cd, pq, or xy, even if they are part of one or the other requirements
 *
 * 
 * */




/*
 *
 * observations:
 *
 * - there are 3 conditions
 * - i think we can do this in 1 pass...
 *   - we can check all 3 conditions while traversing string
 *   - these 3 conditions can have flags
 *
 * 
 * */
