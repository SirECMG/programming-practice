/*
 *
 *  ## output:
 *
 *  print a single character, either A or B:
 *  the winner of the recorded game
 *
 *
 *  ## input
 *
 *  single line with no more than 200 characters:
 *
 *  - the record of one game
 *      - single letter A or B
 *      - alternating with single numbers (1 or 2)
 *      - includes no spaces or other extraenous characters.
 *  - each record will be a correct scoring history of a single completed game,
 *
 *
 *
 *  - rules
 *      - each successful shot by a player earns them either one or two points
 *      - first player to eleven point wins 
 *          - one exception:
 *          - if the score is tied 10-10
 *              - the previous rule is replaced by a "win by 2" rule:
 *                  - the first player to lead the other by at least two point wins
 *  Example:
 *      11 - 7, 9 - 11, and 14 - 12 are possible final scores (but not 14-13)
 *
 *
 *  - When Alice or Barbara scored points, you jotted down an A or B (indicating a Score by Alice or Barbara) followed by a 1 or 2 (the number of poins scored)
 *
 *  - Create a function to determine who one by printing A or B
 
 * Examples
 *
 *  Example Input 1:
 *
 *  A2B1A2B2A1A2A2A2
 *
 *
 *  Output: A
 *
 *
 *  notes:
 *
 *  - we need to parse two parts
 *    - player
 *    - score
 *
 *    ## player representation
 *
 *  - we only have two people and it seems like we need a flipping mechanism to detect player A or B. 
 *      - i guess we can use 0 or 1 to represent A or B.
 *      - i can create an int player to represent who scored
 *
 *
 *    ## current player detection
 *
 *    if A player 
 *      score_array[0] += score
 *    else if B player
 *      score_array[1] += score
 *
 *
 *
 *
 *    ## input traversal
 *
 *    we know we need to parse two values
 *
 *    player = current[i];
*     score = current[i+1]
*
*     we can increment i + 2 every time
*
*
*     ## how do we know the game is ended?
*
*     if any player scores 11 (with exception of tie)
*
*     after every parse we check if the game is over
*
*     if (score_array[0] == score_array[1] && score_array[0] == 10)
    *     diff = score[0] - score[1] // 2 or -2
    *
    *     if(diff >= 2) output "A"
    *     else if(diff <= -2) output "B"
    *
        *
    *    
    *
    *
    *
*
*
*
*     ## constraint
*     i = 0
*     to the end (n - 2)   so i < n - 1
     
      [0, 1, 2, ...,    , N - 1]


      for(i = 0; i < n - 1), ++i)
 *
 *
 *  A2B1
 *
 *
 *  pseudocode:
 *
 *  score_array[2]
 *  point
 *  current
 *  exception = 0
 *
 *  while cin current, point
 *
 *      if current == "A"
 *          score_array[0] += point
 *      else if current == "B"
 *          score_array[1] += point
 *      end
 *
*      if(score_array[0] == score_array[1] && score_array[0] == 10) 
    *      exception = 1
    *  end
    *
    *  if exception == 1
    *   diff = score_array[0] - score_array[1]
    *
    *   if diff >= 2
    *       output "A"
    *   else if diff <= 2
    *       output "B"
    *  else if score_array[0] >= 11
    *   output "A"
    *  else if score_array[1] >= 11
    *   output "B"
    end
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


 int main() {

     int score_array[2] = {0};
     int exception = 0;

     char player;
     int score;

     std::string line;
     std::getline(std::cin, line);

     int i = 0;
     while (i < line.size()) {
         //std::cout << "score_array: A " << score_array[0] << "\n";
         //std::cout << "score_array: B " << score_array[1] << "\n";


         player = line[i];
         score = line[i+1] - '0';

         //std::cout << "player: " << player << "\n";
         //std::cout << "score : " << score << "\n";


         if(player == 'A') {
             score_array[0] += score;
         } else if(player == 'B') {
             score_array[1] += score;
         }
         
         
         if(score_array[0] == 10 && score_array[1] == 10) {
             exception = 1;
         }
         

         if(exception == 1) {
             int diff = score_array[0] - score_array[1];
             if(diff >= 2) {
                 std::cout << "A" << "\n";
                 return 0;
             } else if(diff <= -2) {
                 std::cout << "B" << "\n";
                 return 0;
             }
         } else {
             if(score_array[0] >= 11) {
                 std::cout << "A" << "\n";
                 return 0;
            } else if(score_array[1] >= 11) {
                 std::cout << "B" << "\n";
                 return 0;
            }
         }
         
        
         i += 2;
     }

     std::cout << "bad input: this should never reach.\n";

     return 0;
 }


/*
 *
 *  reflection:
 *
 *  i was able to finsih the problem but i did get stuck on implementation..
 *
 *  1.
 *
 *  the winning detection algorithm was incorrect
 *
 *  i had a bug 
 *      if( diff <= 2) instead of if (diff <= -2)
 *
 *
 *  2.
 *
 *  also i needed to use readline and couldn't use cin directly since there are no whitespaces
 *
 *  3.
 *
 *  also i need to parse the input int using
 *
 *  c - '0' (since it came as a char)
 *
 *
 *
 *
 *
 *
 * */
