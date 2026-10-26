#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

int main() {

    int start_x, start_y, end_x, end_y = 0;
    char line[1024];
    int lit = 0;
    int grid[1000][1000] = {0};

    while(fgets(line, sizeof(line), stdin)) {
        if(sscanf(line, "toggle %d,%d through %d, %d", &start_x, &start_y, &end_x, &end_y) == 4) {

            printf("start_x: %d, start_y: %d, end_x %d, end_y %d\n", 
                    start_x,
                    start_y,
                    end_x,
                    end_y);
            for(int x = start_x; x <= end_x; x++) {
                for(int y = start_y; y <= end_y; y++) {
                    if(grid[x][y] == 1) {
                        grid[x][y] = 0;
                        lit--;
                    } else if(grid[x][y] == 0) {
                        grid[x][y] = 1;
                        lit++;
                    }
                }
            }
        } else if(sscanf(line, "turn on %d,%d through %d, %d", &start_x, &start_y, &end_x, &end_y) == 4) {
            for(int x = start_x; x <= end_x; x++) {
                for(int y = start_y; y <= end_y; y++) {
                    if(grid[x][y] == 0) {
                        grid[x][y] = 1;
                        lit++;
                    }
                }
            }
        } else if(sscanf(line, "turn off %d,%d through %d, %d", &start_x, &start_y, &end_x, &end_y) == 4) {
            for(int x = start_x; x <= end_x; x++) {
                for(int y = start_y; y <= end_y; y++) {
                    if(grid[x][y] == 1) {
                        grid[x][y] = 0;
                        lit--;
                    }
                }
            }
        }


    }

    printf("lit: %d\n", lit);
    return EXIT_SUCCESS;
}

/*
 *  day 6: probably a fire hazard
 *
 *  deploying 1_000_000 lights in a 1000x1000 grid.
 *
 *  santa gives instructions how to display the ideal lighting configuration.
 *
 *  Lights in your grid are numbered from 0 to 999 in each direction;
 *
 *  lights in each corner are at 0,0, 0,999, 999,999 and 999,0. 
 *
 *
 *  the instructions include whether to turn on, turn off, or toggle various
 *  inclusive ranges given as coordinate pairs.
 *
 *
 *
 *  each coodinate pair represents opposite corners of a rectangle, inclusive, 
 *  coordinate pair like 0,0 through 2,2 therefore refers to 9 lights in a 3x3
 *  square.
 *  0 1 2
 *  3 4 5
 *  6 7 8
 *
 *  the lights all start turned off.
 *
 *  to defeat your neighbors this year all you hav eto do is setup your lights by doing the
 *  instructions Santa sent you in order.
 *
 *
 *
 *  Example 1:
 *
 *  turn on 0,0 thorugh 999,999 would turn on (or leave on) every light.
 *
 *  Example 2:
 *
 *  toggle 0,0 through 999,0 would toggle the first line of 1000 lights,
 *  turning off the ones that were on, and turning on the ones that were off.
 *
 *  Example 3:
 *
 *  turn off 499,499 through 500,500 would turn off (or leave off) the middle four lghts
 *
 *  After the following instructions, how many lights are lit?
 *
 *
 *
 *
 *
 * example input
 *
 *  turn off 199,133 through 461,193
    toggle 322,558 through 977,958
    turn on 226,196 through 599,390
 * */





/*
 *  notes and observations
 *
 *  - fgets() - what does it do?
 *
 *
 * - how many lights are lit?
 *
 *   lit - need to keep track of how many lights are lit
 *
 *   natural data structure is a grid.
 *
 *   int grid[x][y];
 *
 *   we can represent on by 1 and off by 0.
 *
 *
 *   it is possible in 1 pass
 *
 *   toggle on == count ++
 *   togle off == count --
 *   toggle opposite of detected light (need an if else)
 *
 *   00
 *   11
 *
 *
 *
 *   implementation notes
 *   - create grid // done
 *   - populate grid with initialization values // done
 *   
 *
 *   - parse line // done
 *   - keep count of lit and not lit // done
 *   - create if else logic per line
 *
 *
 *   - my initial code was correct...
 *   - one tip that i have to myself is that don't assume... verify.
 *
 * */

