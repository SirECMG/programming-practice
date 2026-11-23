/*
 *
 * oddgnome
 *
 * output:
 *
 * for each group, output the kings position in the group (where the first gnome in line is number one)
 * 
 *
 * king position where the first gnome in line is number one
 *
 * input:
 * 
 * input starts with integer n, where 1 <= n <= 100
 *
 * represents the number of gnome groups. 
 *
 *
 * each of the n following lines contains one group of gnomes.
 *
 * starting with an integer g, where 3 <= g <= 1000
 * representing the number of gnomes in that group.
 *
 * following on the same line are g space-separated integers, representing the gnome ordering.
 * within each group all the integers (including the king) are unique and in the range [0, 10000]. 
 *
 * excluding the king, each integer is exactly one more than the integer preceding it.
 *
 *
 * notes and observations:
 *
 * it seems like i need to save the index of the king.
 * each integer should be at least 1 more than the previous
 * position is i + 1.
 * if we found the king, we can just exit
 *
 * */

/*
 *  pseudocode
 *
 *  save n
 *
 *  i = 0
 *  
 *  while i < n
 *
 *    save g
 *    if g is less than 3 skip
 *
 *    cin >> prev
 *    j = 1
 *    while j < g
 *      cin >> cur
 *      if cur != prev + 1
 *        position = j + 1
 *        break
 *
 *    print j
 *
 * */

#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int i = 0;
    while (i < n) {
        int g;
        std::cin >> g;

        int prev;
        std::cin >> prev;

        //std::cout << "g: " << g << " prev: " << prev << "\n";
        int found = 0;
        int j = 1;
        while (j < g) {
            int cur;
            std::cin >> cur;

            //std::cout << "prev: " << prev << " cur: " << cur << " j: " << j << "\n";
            if(prev != cur - 1 && !found) {
                int position = j + 1;
                std::cout << position;
                found = 1;
                
            }
            prev = cur;
            ++j;
        }
        std::cout << "\n";
        ++i;
    }

    return 0;
}
