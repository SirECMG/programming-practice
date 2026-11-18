/*
 *  jollyjumpers
 *
 *
 *  input:
 *
 *  for each line
 *      contains an integer n <= 3000 followed by
 *      n integerse representing the sequence.
 *
 *      the values in the sequence are at most 300,000 in absolute value.
 *      input contains at most 10 lines.
 *
 *      n [ numbers ] 
 *
 *      where n  <= 3000
 *      where numbers in the sequence at most 300,000 in absolute value (diff?)
 *
 *  output:
 *
 *  for line
 *      say jolly
 *      or not jolly
 *
 *
 *  details:
 *
 *  a sequence of n > 0 integers is called a jolly jumper.
 *
 *  if the absolute values of the difference between successive elements take on
 *  all the values 1 through n - 1
 *
 *  example 0:
 *
 *  1 4 2 3
 *
 *  is a jolly jumper because the absolute differences are 3, 2, 1 respectively.
 *  the definition implies that any sequence of a single integer is a jolly jumper.
 *
 *  You are to write a program to determine whether or not each of a number of sequences
 *  is a jolly jumper.
 *
 *  observarions:
 *
 *
 *  4 1 4 2 3
 *  ^
 *
 *  this is n
 *  
 *  1 4 2 3
 *  is the sequence
 *
 *  from here how can we check if jolly jumper? if all elements have abs diff of 1 through n - 1.
 *
 *  where do we start?
 *
 *  1 4
 *    4 2
 *      2 3
 *  0 1 2 3 (this is n, we want to stop at n - 1)
 *
 *  how will we capture input?
 *      cin
 *
 *  what is our ending condition? (n - 1)
 *
 *  [ , ,1,1]
 *   0 1 2 3
 *
 
 *  is_jolly = -1
 *  arr(n)
 *  first = captured value
 *
 *  i = 1
 *  while i < n - 1:
*     second = cin
*     abs_val = abs(second - first)
      if(arr[abs_val] == 1)
        is_jolly = false
      else 
        arr[abs_val] = 1

      first = second

      ++i


  i think the loop makes sense, but I have multiple lines to parse and i don't think it's strong enough

  4 1 4 2 3  
  5 1 4 2 - 1 6

  n
  while cin >> n
 *  is_jolly = -1
 *  arr(n)
 *  first = captured value
 *
 *  i = 1
 *  while i < n - 1:
*     second = cin
*     abs_val = abs(second - first)
      if(arr[abs_val] == 1)
        is_jolly = false
      else 
        arr[abs_val] = 1

      first = second

      ++i

    if is_jolly != true
        Jolly
    else
        not Jolly
      



 *
 *
 *  below is my thought process of what should be in the array. we need an array to store the tracking of what has been computed (abs)
 *
 *  1 to n - 1 (means everything not zero).
 *  if i have [1] 1 is a jolly jumper because 1 is in it. (this seems to be an edge case)
 *  if i have [1 2] is also a jolly jumper because it satisfies [1 to n - 1] (1 to 1)
 *
 *  [1,2,3,4] (sequence of 4)
 *   0 1 2 3
 *
 *   so basically, i will need to keep track of the jollyjumper critiera and the valid keys are
 *   1 to n - 1 (this is the key/value in the array, index is different)
 *
 *   4 1 4 2 3
 *       1 2 3
 *
 *
 *
 *  mini problems:
 *
 *  - capture n
 *  - absolute difference between two
 *
 *
 * */

#include <iostream>
#include <vector>

int main() {

    int n;
    while(std::cin >> n) {

        //std::cout << "n: " << n << "\n";
        std::vector<int> v(n);
        int is_jolly = 1;
        int first;
        std::cin >> first;

        int i = 1;
        while(i < n) {

            //std::cout << "i: " << i << "\n";
            //std::cout << "n: " << n << "\n";



            int second;
            std::cin >> second;
            
            int abs_val = std::abs(second - first); // also the key to the array

            //std::cout << "first: " << first << "\n";
            //std::cout << "second: " << second << "\n";
            //std::cout << "abs_val: " << abs_val << "\n";
            //std::cout << "\n";

            if(abs_val < 1 || abs_val > n - 1) {
                is_jolly = 0;
            } else if(v[abs_val] == 1) {
                is_jolly = 0;
            } else {
                v[abs_val] = 1;
            }

            first = second;
            ++i;
        }

        if(is_jolly == 1)
            std::cout << "Jolly\n";
        else
            std::cout << "Not jolly\n";
    }

    return 0;
}


/*
 *
 *  reflection:
 *
 *  i solved this problem yesterday with struggle,
 *  i was able to solve it again today, this time withoout any help. i ran into some bugs
 *  and was able to debug it (by staying calm, printing out values, looking at my constraints,
 *  and even made improvements to my code)
 *
 *  i need to celebrate this improvement!
 * */
