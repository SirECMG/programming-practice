#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void process_line(char *line, int *vowel_cnt, int *same_cnt, int *violation_cnt) {
    int len = strlen(line);
    int i;
    for(i = 0; i < len; i++) {
        char cur = line[i];
        char next = line[i + 1];
        printf("cur: %c\n", cur);
        printf("next: %c\n", next);
        if( (cur == 'a' && next == 'b') ||
                (cur == 'c' && next == 'd') ||
                (cur == 'p' && next == 'q') ||
                (cur == 'x' && next == 'y')) {
            (*violation_cnt)++;
            printf("violation_cnt: %d\n", *violation_cnt);
        }
        if(cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur =='u') {
            (*vowel_cnt)++;
            printf("vowel_cnt: %d\n", *vowel_cnt);
        }

        if(cur == next) {
            (*same_cnt)++;
            printf("same_cnt: %d\n", *same_cnt);
        }
    }
};

int main() {

    char line[100];
    int nice_cnt = 0;
    while(fscanf(stdin, "%s", line) == 1) {
        int violation_cnt = 0;
        int vowel_cnt = 0;
        int same_cnt = 0;
        process_line(line, &vowel_cnt, &same_cnt, &violation_cnt);
        if(violation_cnt > 0) continue;
        if(vowel_cnt >= 3 && same_cnt >= 1) nice_cnt++;
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
