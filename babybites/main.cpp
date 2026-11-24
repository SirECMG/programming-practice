/*
 *  baby bites
 *
 *  arild is learning how to count.
 *
 *  count mouthfuls he has a meal.
 *  every time he bites, he will count it by sayin the number out loud.
 *
 *  write a program to determine whether arild's counting makes sense
 *  or not.
 *
 *  input:
 *
 *  integer n - ( 1<= n <= 1000) the number of bites arild receives
 *
 *  then second line contains n space-separated words spoke by Arild, the ith of which is either a non-negative integer ai (0 <= ai <= 10000) or string "mumble"
 *
 *
 *  output:
 *
 *  if arild's counting might make sense print the string
 *  "makes sense" else
 *  "something is fishy"
 *
 *  sample:
 *
 *  5
 *  1 2 3 mumble 5
 *
 *  algorithm:
 *
 *  parse first line
 *  parse each word in line 2. 
 *
 *  starting number should be 1.
 *
 *  compare each word (save it to a number).
 *
 *  we should have an independent i to compare against (because firs could be mumble)
 *
 *  if it is mumble we can continue
 *
 *  the amount of parsing should match our current i and should end until our N (from the first line)
 * */

#include <iostream>
#include <string>
//#include <sstream>

int main() {

    int n;
    std::cin >> n;

    int is_valid = 1;
    std::string cur;
    for(int i = 1; i <= n; ++i) {
        std::cin >> cur;

        // what is our invariant?
        if(cur != "mumble" && cur != std::to_string(i)) {
            is_valid = 0;
        }

        /*
        std::istringstream iss(cur);

        int num;
        if(iss >> num && iss.eof()) {
            if(num != i) {
                is_valid = 0;
            }
        } else {
            if(cur != "mumble") {
                is_valid = 0;
            }
        }
        */
    }

    if(!is_valid) {
        std::cout << "something is fishy\n";
    } else {
        std::cout << "makes sense\n";
    }

    return 0;
}


