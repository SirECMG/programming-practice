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
 * 2 * h * l
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

int calculate_sa(int s0, int s1, int s2) {

    s0 = 2 * s0;
    s1 = 2 * s1;
    s2 =  2 * s2;
    int sa = s0 + s1 + s2;

    return sa;
}

int get_smallest_area(int s0, int s1, int s2) {
    int smallest = s0;
    if(s1 < smallest) smallest = s1;
    if(s2 < smallest) smallest = s2;
    return smallest;
}

int calculate_output(int len, int width, int height) {

    int s0 = len * width;
    int s1 = width * height;
    int s2 = height * len;
    return calculate_sa(s0, s1, s2) + get_smallest_area(s0, s1, s2);
}

int main() {

    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL) {
        printf("something went wrong with reading file.\n");
        return EXIT_FAILURE;
    }

    int len;
    int width;
    int height;
    int output = 0;
    while(fscanf(fp,"%dx%dx%d\n", &len, &width, &height) == 3) {
        output += calculate_output(len, width, height);
    }
    printf("%d\n", output);





    
    fclose(fp);
    return EXIT_SUCCESS;
}

/*
 * 
 * notes:
 *
 * this is pretty straight forward.. but teaches me how to process formatted inputs
 *
 *
 * */
