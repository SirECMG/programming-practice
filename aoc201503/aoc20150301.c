#include "stdio.h"
#include "stdlib.h"

#define FILENAME "input.txt"
#define X_MAX 1024
#define Y_MAX 1024

void process_instruction(int instruction, int *count, int *cur_x, int *cur_y, int visited[X_MAX][Y_MAX]) {
   switch(instruction) {
       case '^':
           *cur_y += 1;
           break;
       case '>':
           *cur_x += 1;
           break;
       case 'v':
           *cur_y -= 1;
           break;
       case '<':
           *cur_x -= 1;
           break;
       default:
           break;
   } 

   if (visited[*cur_x][*cur_y] == 0) {
        (*count)++;
        visited[*cur_x][*cur_y] = 1;
    }
   return;
}

int main() {
    int cur_x = X_MAX / 2;
    int cur_y = Y_MAX / 2;
    int count = 1;
    int visited[X_MAX][Y_MAX] = {0};
    visited[cur_x][cur_y] = 1;
    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL) {
        printf("there was an issue opening the file %s\n", FILENAME);
        return EXIT_FAILURE;
    }

    int ch;
    while((ch = getc(fp)) != EOF) {
        printf("%c", ch);
        process_instruction(ch, &count, &cur_x, &cur_y, visited);
    }
    printf("\n");

    printf("houses: %d\n", count);


    fclose(fp);
    return EXIT_SUCCESS;
}

/*
 *  santa is delivering presents to an infinite two-dimensional grid of houses.
 *
 *  santa has a starting location. elf calls tells him where to go
 *
 *  ^ north
 *  v south
 *  > east
 *  < west
 *
 *  elf gets drunk and accidentally directs him to same house
 *
 *  how many houses receive at least one present
 *
 *  example:
 *
 *  > delivers presents to 2 houses: one at the starting location, and one to the east.
 *
 *  ^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
 *
 *  ^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.
 *
 *
 *
 * */
