/*
 *  thelastproblem
 *
 *  input:
 *
 *  Twilight
 *
 *  output:
 *
 *  Output a single line containing the string "Thank you, S , and farewall!
 *
 *  where S is the name of the one you will bid farewell to.
 *
 *  Thank you, Twilight, and farewell!
 * */

#include <iostream>
#include <string>

int main() {

    std::string name;

    std::getline(std::cin, name);

    std::cout << "Thank you, " << name << ", and farewell!\n";

    return 0;
}
