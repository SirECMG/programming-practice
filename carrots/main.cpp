/*
 *  carrots
 *
 *  output:
 *
 *  # of carrots that will be handed out during the contest
 *
 *  input:
 *
 *  two integers 1 <= N,, P <= 1000  (on single line)
 *
 *  number of contestants in the contest
 *  the number of huffle-puff problems solved.
 *
 *  Then follow N lines, each consisting of a single non-empty line in which the contestant describes him or herself. You may assume taht the contestants are good at describing themselves, in a way such that an arbitrary 5-year old with hearing problems could understand it.
 *
 *  you earn a carrot for each difficult problem you solve, or huffle-puff problems.
 *
 *
 *
 *  example 1:
 *
 *  2 1
 *  carrots?
 *  bunnies
 *
 *  example 2:
 *
 *  1 5
 *  sovl problmz
 *
 *  approach:
 *
 *  num_of_carrots = num_of_people * problem_solved
 *
 * */

#include <iostream>

int main() {

    int num_of_people = 0;
    int problems_solved = 0;

    int carrots = 0;


    std::cin >> num_of_people >> problems_solved;

    carrots = problems_solved;

    std::cout << carrots << "\n";

    return 0;
}
