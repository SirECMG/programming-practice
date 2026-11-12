#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> ns;
    int n;
    while(std::cin >> n) {
        ns.push_back(n);
    }

    std::sort(ns.begin(), ns.end());

    int d1 = ns[1] - ns[0];
    int d2 = ns[2] - ns[1];

    if(d1 == d2) {
        std::cout << ns[2] + d1 <<  "\n";
    } else if(d2 > d1) {
        std::cout << ns[1] + d1 << "\n";
    } else {
        std::cout << ns[0] + d2 <<  "\n";
    }



    return 0;
}
/*
 * 10 1 4
 *
 * 1 4 10
 * 0 1 2 3
 *
 * kirko has chosen four integers which fomr an arithmetic progression.
 *
 * when four numbers are sorted, then the difference between each pairof adjacent elements is constant.
 *
 * as has become usual, mirko lost one of the numbers and also is not sure whether
 * the remaining three are in teh correct (sorted) order.
 *
 * write a program that, given the three remaining numbers, finds the forth number.
 *
 *
 * input: integers separated by spaces
 *
 * output: a number - any number which could have been the fourth number in that sequence
 *
 *
 * example 
 *
 * 4 6 8 (progressiing) difference is constant (2)
 *
 *
 * example 2:
 *
 * 10 1 4
 *
 * 1 4 10 (progressing but with missing number included... diff is 7 and short fill in the gap between 4 and 10
 *
 * 1 4 (3)
 * 4 10 (10) // here smaller of the diff is 3 (3 vs 10).
 * 10 - [smallest_diff] = 7 (missing number is 7)
 *
 *
 *
 * - so i am trying to find the missing number.
 * - there could be an inconstency between the differences of adjacent number (in that case we should take the smaller)
 * - we are only dealing with 4 numbers so if there is an inconsistency 
 *   it will be that number.
 *
 *
 *
 *   7 1 4
 *
 *   1 4 7
 *
 *
 *   will need store input in an array. // done
 *   sorted it. // done
 *   find all adjacent pairs (there could only be 3) // done
 *   get the smallest. (not needed)
 *   if smaller compute the missing number, else return the last number
 *
 *
 *   ## answer notes:
 *
 *   - i was doing so well on this problem, until it got to finding the missing number
 *   - i was trying to force myself to loop through to array to get the answer, but I actually didn't need to.
 *   - since there was only 4 possible numbers we could figure out the missing nynber by direct observation.
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
 *
 * 
 *
 * */
