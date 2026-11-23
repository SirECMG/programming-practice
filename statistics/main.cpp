#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {

    std::string line;
    int i = 0;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int j = 0;
        int n;

        if(!(iss >> n) || n <= 0)
            continue;

        
        std::vector<int> v(n);
        while (j < n) {
            iss >> v[j];
            ++j;
        }
        int case_num = i + 1;
        auto [min,max] = std::minmax_element(v.begin(), v.end());
        int range = *max - *min;

        std::cout << "Case " << case_num << ": " << *min << " " << *max << " " << range << "\n";
        ++i;
    }
    return 0;
}


/*
 *  statistics
 *
 *  n numbers
 *  X = (x1, ... , xn)
 *
 *  min(X)
 *  max(X)
 *  range(X): max(X) - min(X)
 *
 *  write a program that will analyze samples of data and report these values for each sample.
 *
 *  input:
 *
 *  1 and 10 test cases (1 test case 1 line)
 *
 *  begins with 1 <= n <= 30 and is followed by n integers
 *  
 *  each value in the sample will be in the range -1,000,000 and 1,000,000
 *
 *
 *  Output:
 *
 *  for each case, display Case X: where X is the case number,
 *  followed by the min, max and range of the sample (in that order).
 *
 *
 *  notes/observations
 *
 *
 *  2 4 10
 *
 *  line
 *
 *  i = 0
 *  while (std::getline(stdin, line, ' '))
 *    j = 0
 *    n = line[j] 
 *
 *    while j < n
 *      case = i + 1
 *      v(n)
 *      v[j] = line[j]
 *      j++
 *
 *    min,max = minmax(v)
 *    range = max - min
 *
 *    std::cout << "Case " << case << ": " << min << " " << max << " " << range << "\n";
 *     
 *
 *   
 *  
 *
 * */


