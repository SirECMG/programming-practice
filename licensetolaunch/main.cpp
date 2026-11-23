/*
 *  output:
 *
 *  a single integer, the number of days Birk needs to wait before he launches his rocket
 *
 *  input:
 *
 *  on the first line there is a single integer n (1 <= n <= 100 000)
 *  the number of days for which the launch license is valid.
 *
 *
 *  on the second line follows n integers between 0 and 10^9 where the
 *  ith integer is the amount of space junk on the ith day.
 *  
 *  the first day is i = 0.
 *
 *  5 - number days for which the launch license is valid
 *  3 4 1 7 2 (amount of space junk on ith day
 *
 *
 *
 *  notes/observations:
 *
 *  birk is good to go to launch in n days.
 *
 *  rocket will hit space junk on its way. in order to minimize the risk
 *  of a collision, birk has made a model of how many pieces of space
 *  junk there will be for each of the n days.
 *
 *
 *  he decided that he will launch his rocket on the day with the least space junk and if there are multiple days with the same amount of space junk he wants to send rocket as early as possible.
 *
 *  how many days he has to wait until he spend up his rocket.
 *
 *  5
 *  3 4 1 7 2
 *  0 1 2 3 4
 *      ^ he wants to leve here
 *
 *  we just want to return the index of the least so far.
 *
 *  parse first line save it to n
 *  if n less than 1 or greater than 100000 invalid
 *
 *  since we are dealing with array at least 1. we save min to 0
 *
 *  parse each line while maintaining the least garbage
 *
 *  min = 0
 *  cur = 0
 *  compare min with current and save min to the lowest of the two
 *
 *  return min
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


#include <iostream>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    if (n < 1 || n > 100000)
        return 0;

    int min = INT_MAX;
    int i = 0;
    int day = i;
    while (i < n) {
        int cur;
        std::cin >> cur;
        if (cur < min) {
            min = std::min(min, cur);
            day = i;
        }
        ++i;
    }

    //std::cout << "day : " << day << " min : " << min << "\n";
    std::cout << day << "\n";

    return 0;
}
