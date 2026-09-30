/*
 * elves need to submit order for wrapping paper
 *
 * they have list of dimensions
 *
 * length
 * width
 * height
 *
 *
 * they want to order as much as they need
 *
 * find the SA of the box which is:
 *
 * 2 * l * w
 * +
 * 2 * w * h
 * +
 * 2 * w * l
 *
 * the elves also need extra paper for each present: the area of the smallest side
 *
 * how many total square wrapping paper should they order?
 *
 *
 * notes:
 *
 * i need to understand formatted input
 *
 * assign 3 variables for lenght width and height for each iteration
 *
 * i need to plug in that equation + SA
 *
 *
 *
 * */

#include "stdio.h"
#include "stdlib.h"

#define FILENAME "input.txt"

int main() {

    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL) {
        printf("something went wrong with reading file.\n");
        return EXIT_FAILURE;
    }

    int len = 0;
    int width = 0;
    int height = 0;
    fclose(fp);
    return EXIT_SUCCESS;
}
