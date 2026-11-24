/*
 *  
 *  output:
 *
 *  A, B C in the desired order on a single line, separated by spaces
 *
 *  intput:
 *
 *  first line contains three positive integers A,B,C
 *
 *  three numbers will be less or equal to 100.
 *
 *  second line will be A,Bor C representing the desired order.
 *
 *  example:
 *
 *  1 5 3
 *  A B C
 *
 *  1 5 3
 *  A B C
 *
 *  1 3 5
 *  A B C
 *
 *  example 2:
 *
 *  6 4 2
 *  C A B
 *
 *
 *  A is less than B and B is less than C.
 *
 *  note and obs:
 *
 *
 *  we can save integer in array and sort them.
 *
 *  int nums[3];
 *  sort nums
 *
 *  for c in chars
 *  if a
 *    nums[0]
 *
 *  else if b
 *    nums[1]
 *  else 
 *    nums[2]
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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> nums(3,0);
    for(int i = 0; i < 3; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    std::string line;
    std::cin >> line;
    for(int i = 0; i < 3; ++i) {
        char cur = line[i];
        if(cur == 'A') std::cout << nums[0] << " ";
        if(cur == 'B') std::cout << nums[1] << " ";
        if(cur == 'C') std::cout << nums[2] << " ";
    }
    std::cout << "\n";

    return 0;
    
}


/*
 *  reflection:
 *
 *  this was suprisingly hard.
 *
 *  i was trying to manually sort the 3 elements by a bunch of if statements
 *
 *  but needed to just save the input to a data structure and sort the array.
 *
 *  this lead to cleaner code.
 *
 *  i needed to just understand which data structure to zoom out and figure out what data structure to use.
 * */
