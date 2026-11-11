#include <iostream>
#include <vector>

int main() {

    int n;
    std::cin >> n;

    std::vector o(n,0);
    int cur_dist;
    int cur_per = 2;

    o[0] = 1;

    int index;
    while(std::cin >> cur_dist && cur_per <= n) {
        index = cur_dist + 1;
        o[index] = cur_per;
        cur_per++;
    }


    for(auto e: o) {
        std::cout << e << " ";
    }
    std::cout << "\n";
        
    return 0;
}

/*
 *  https://open.kattis.com/problems/lostlineup
 *
 *  Jimmy and friends were standing in line for ice scream.
 *  A gust of wind blew them all around.
 *
 *  Friends want to keep things fair and make sure every one gets their ice scream
 *  in the order they started with.
 *
 *  Thef reinds do not remember the order, but each of them remembers exactly
 *  how many people were between them and Jimmy.
 *
 *  Jimmy is always the first person in the line. Can you help him and his friends remember
 *  the order?
 *
 *
 *  Input: 
 *
 *  first line contains a single integer n ( 1 <= n <= 100), the number of people in the line
 *
 *  second line contains n - 1 space separated integers, where d_i (0 <= d_i <= n - 2) is the number of people between the (i + 1) th person and Jimmy
 *
 *
 *
 *
 *
 * facts:
 *
 * jimmy is always the first person in the line.
 *
 *
 * goal:
 *
 * print a single line with n integer,
 * the people in the order of the original lineup.
 * it is guaranteed that there is always a unique solution.
 *
 *
 * notes:
 *
 * i am having a hard time interpretting second line.
 *
 * contains n - 1 space separated integers. (n - 1)  is because we don't include jimmy (refers to the space)
 *
 * d_i is the number of people between the (i + 1)th person and Jimmy.
 *
 * 0 <= d_i <= n - 2
 *
 
 *
 * what is di?
 *
 * the number of people standing between jimmy (also the first person in line)
 *
 * and the person ith in the origina line.
 *
 *
 *
 * example:
 *
 * 2
 * 0
 *
 *
 * 2 people
 * 0 distance between them
 *
 * [ 1, 2 ]
 *   ^ index 0 (Jimmy) (N - di + 1) 
 *      ^ index 1 (N - di + 2)
 *
*
*
*  4
*  1 2 0    
*
*
*  output: 1 4 2 3
*
*
*  ## ending notes
*
*
* ### what made this problem a bit difficult?
*  - problem statement was difficult to interpret
*   - i was confused between person name (di)
    - and how to create index (which was the current distance being read + 1\    - i need to work on breaking down problems

    - don't start coding until you fully understand the problem
    - maybe i need to write it in plain english completely and solve
    mini problems vs thinking everything all at once
*
*
*                    
*
*
 *
 *
 *
* 
 *
 *
 *
 *  
 * */

