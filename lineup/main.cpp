#include <iostream>

int main() {

    int n;
    std::cin >> n;

    std::string prev;
    std::cin >> prev;

    std::string current;
    int direction = 0;
    int i = 1;
    while (std::cin >> current) {
      if (i > n - 1) break;
       if (prev > current) {
           if (direction > 0) {
               std::cout << "NEITHER\n";
               return 0;
           }
           direction = -1;
       } else if (prev < current) {
           if (direction < 0) {
               std::cout << "NEITHER\n";
               return 0;
           }

           direction = 1;
       }

       prev = current;
       i++;
    }

    if (direction > 0) {
        std::cout << "INCREASING\n";
    } else {
        std::cout << "DECREASING\n";
    }



    return 0;
}
/* *  line them up *
 *  ## output
 *
 *  a single word: 
 *
 *  INCREASING - if the list is in increasing alphabetical order
 *  DECREASING - if it is in decreasing alphabetical order
 *  NEITHER
 *
 *  ## input:
 *
 *  N - people on the team (2 <= N <= 20)
 *
 *  Following N lines:
 *
 *  containing the name of one person.
 *
 *  ## constraints
 *
 *  name:
 *      1. at least two characters
 *      2. at most 12 characters
 *      3. only capital letters
 *      4. no whitespaces
 *      5. duplicate names not allowed
 *
 *
 *
 * ## notes
 *
 * - i will need a data structure to hold the names possibly...
 * - i won't be able to tell otherwise if the list is increasing or decreasing.
 *  - but maybe i don't maybe i can detect as i am parsing the input...
 *  - otherwise why would they give me N?
 *
 * - I think I will need a state to determine whether or not the current_status
 *
 *  pseudo code:
 *
 *
 *  - starting state = NEITHER
 *
 *  If N > 1
 *  need a starting point i = 0
 *
 *  while i < N - 1 (we need to compare at least two people)
 * - get n[i] and n[i+1]
 * - if n[i] > n[i+1]
 *      state = DECREASING
 *   else if n[i] < n[i+1]
 *      state = INCREASING
 *   else
 *      state = NEITHER
 *
 *
 *  example 2:
 *
 *
 *  11
 *  HOPE
 *  ALI
 *  BECKY
 *  JULIE
 *  MEGHAN
 *  LAUREN
 *  MORGAN
 *  CARLI
 *  MEGAN
 *  ALEX
 *  TOBIN
 *
*  
 *  STATE = NEITHER
 *  HOPE < ALI
 *  STATE = DECREASING 
 *
 *  ALI < BECKY
 *  STATE = NEITHER  // here i think we are done.
 *                  //  we are detecting whether or not it is alphabetically ordered
 *                  // so we can't flip state more than once.
 *
 *
 *
 *  APPROACH 2:
 *
 *  we need to compare that input is alphabetical. we can do this by keeping track. 
 *  i can introduce a variable tally.
 *  if increasing then tally after comparing N people will equal to 11 if increasing
 *  if tally is less than 0 and equal to N * -1 = DECREASING
 *
 *
 *  APPROACH 3:
 *
 *  we can introduce two flags
 *  - is increasing
 *  - did flip
 *
 *  introduce i (to show where we are in parsing)
    state (-1, 0, 1)
    - did_flip 1 if current comparision does not match state
 *
 *  -1 0 1.
 *
 *  i = 0;
 *  
 *  HOPE < ALI
 *  DECREASING
 *
 *  i = 1
 *  ALI > BECKY
 *  if (state < 0) return NEITHER and we are done
 *
 *
 *
 *  pseudo code for approach 3:
 *
 *  i = 0
 *  state = neither
 *  current
 *  next
 *
 *  if current < next
 *      if(state != increasing) NEITHER
 *      state = increasing
 *  else if current > next
 *      if(state != decerasing) NEITHER
 *      state = decreasing
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
 * ## reflection
 *
 * i had the right high-level algorithm, but i got bogged down on the implementation details
 *
 * i guess looking back, i needed to understand two things
 *
 * when to start the iteration
 *
 * when to end it
 *
 *
 *
 * as i am implementing, i need to run it through the example maybe with a simple case.
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
