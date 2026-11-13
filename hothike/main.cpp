/*
 *  openkattis hothike:
 *
 *  output: 
 *
 *  two integers d and t
 *
 *  d is the best day to start your trip
 *  t is the resulting maximum temperature durin the two hiking days.
 *
 *
 *  if there are many choices of d that minimize the value of t, 
 *  then output the smallest such d
 *
 *
 *
 *  input:
 *
 *  integers n ( 3 <= n <= 50), the length of your vacation in days
 *
 *  n integers t1 t2, ..., tn (-20 <= ti <= 40) where ti is the temperature forecasef ro the ith day of your vacation
 *
 *
 *  details:
 *
 *  hiking to the lake will take you a full day, then you willl stay there for a day to rest and enjoy the scenery, and spend another day hiking home (total of 3 days)
 *
 *  you want to schedule the hiking trip some days where the two hiking days are the least warm. want to minimize the max temperature durin the two hiking days.
 *
 *
 *  given the current forecast of daily maximum temperatures, what are the best days for your trip?
 *
 *
 *  example 1:
 *
 *  5
 *  23 27 31 28 30
 *
 *  2 and 28 (2nd day and max temp durin the two hiking days)
 *
 *
 *
 *  notes and observations
 *
 *  - hiking takes 3 days so we need to consider 3 days in line 2
 *
 *
 *
 *  - need to compare 3 days in the array
 *
 *  - best day to start the trip (i + 1)
 *  - maximum temperature of the hiking day max(s[i], s[i+1])
 *  - we don't care about the s[mid] (i think)
 *
 *  - if there are days with the same max temp we can take the smallest day
 *

 *
 *
 *  mini problems
 *
 *  - get input of first line
 *  - store all the input in the array
 *
 *  - find maximum temperature for 3 day window
 *      best_temp = 0
 *  - save start day
 *      start_idx = i
 *  - if maximum temperature if smaller than the current save d, update d
 *      if min(best_found, best_temp);
 *          d = i
*           t = best_temp
*
*
*   - until i <= n - 3
*    [0, 1, 2]
*   [n-3,n-2,n-1] 
*
*   
*
*   example 1 with pseudocode
*
*   5
*   23 27 31 28 30
*
*
*   5
*   [23, 27, 31, 28,30]
*    0,             n-1
*
*    
*
*   best_temp = 0
*   start_idx = 0 
*
*   i = 0
*   while i <= n - 3
*       going_temp = h[i]
*       back_temp = h[i+2]
*       cur_max_temp = max(going_temp, back_temp)
        
        min(cur_max_temp, best_temp)
            best_temp = cur_max_temp
            start_idx = i


    output start_idx + " " + best_temp
*       
 * */


#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }


    int best_temp = std::max(v[0], v[2]);
    int start_day = 1;
    for(int i  = 0; i <= n - 3; ++i) {
        int going_temp = v[i];
        int back_temp = v[i+2];
        int cur_max_temp = std::max(going_temp, back_temp);

        //std::cout << "going temp: " << going_temp << "\n";
        //std::cout << "back temp: " << back_temp << "\n";
        //std::cout << "cur_max_temp: " << cur_max_temp << "\n";
            if(cur_max_temp < best_temp) {
                best_temp = cur_max_temp;
                start_day = i + 1;
            }

        //std::cout << "best temp: " << best_temp << "\n";
        //std::cout << "start day: " << start_day << "\n";
        //std::cout << "\n";
    }

    std::cout << start_day << " " << best_temp << "\n";
    return 0;
} 
