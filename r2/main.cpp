/*
 *
 *  r2
 *
 *  output:
 *
 *  R2 on a single line
 *
 *  
 *  input:
 *
 *  The first and only line of input contains two integers R1 and S.
 *  both between -1000 and 1000.
 *
 *  notes:
 *
 *  S - mean of two numbers R1 and R2.
 *
 *  S = R1 + R2 / 2.
 *
 *  solve for R2.
 *  2S - R1 = R2
 *
 *  11 15.
 *
 *  30 - 11 = 19
 *
 *
 *  S is second
 *  R1 is first
 *
 *  2(3) - 4 = 5
 *
 * */

#include <iostream>

int main() {

    int first;
    int second;
    int result;

    std::cin >> first >> second;

    result = 2 * second - first;

    std::cout << result << "\n";

    return 0;
}
