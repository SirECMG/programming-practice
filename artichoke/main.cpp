/*
 * output:
 *
 * display the maximum decline in the stock prices.
 * if there is no decline, display the number 0.
 * your output should have an absolute or relative error of at most 10^-6
 *
 *
 * input:
 *
 * input consist of a single line containing 6 integers 
 * p (1 <= p <= 1000)
 * a , b, c, d (0 <= a,b,c,d <= 1000) and
 * n (1 <= n <= 10^6).
 *
 * The first 5 integers are described above. 
 *
 *
 * The sequence of stock prices to consider is price(1), price(2), ..., price(n).
 *
 *
 * detail:
 *
 * - fatima wants to determine the largest decline in stock prices over various
 *   time spans.
 *
 *   For example, if over a span of time the stock prices were 19,12,13,11,20,14 then the largest decline would be 8 between the frist and forth price.
 *
 *   If the last price had been 10 instead of 14, then the largest price would have been 10 between the last two prices.
 *
 *
 *   Stock price over any period of time can be modelled reasonably accurately with the following equation
 *
 *
 *   price(k) = p * (sin(a * k + b) + cos (c * k + d) + 2
 *
 *   where p, a, b, c, d are constants.
 *
 *
 *   Fatima would like you to write a program to determine the largest price decline over
 *   a given sequence of prices.
 *
 *   You have to consider the prices only for integers values of k
 * */


#include <iostream>
#include <cmath>
#include <algorithm>

double get_current_price(int p, int a, int b, int c, int d, int k) {
    return p * (std::sin(a * k + b) + std::cos(c * k + d) + 2);
}


int main() {

    int p;
    int a,b,c,d;
    int n;

    std::cin >> p >> a >> b >> c >> d >> n;

    double highest_price = 0;
    double biggest_drop = 0;

    int k = 1;

    while ( k <= n ) {
        double current_price = get_current_price(p,a,b,c,d,k);
        highest_price = std::max(highest_price, current_price);
        biggest_drop = std::max(biggest_drop, highest_price - current_price);
        
        std::cout << "current: price " << current_price << "\n";
        std::cout << "highest price: " << highest_price << "\n";
        std::cout << "biggest drop: " << biggest_drop << "\n";
        std::cout << "\n";
        k++;
    }



    std::cout << "biggest drop: " << biggest_drop << "\n";

    return 0;
}


/*
 *
 *  reflection:
 *
 *  what exactly am i trying to find.
 *  what information am i repeatedly calculating?
 *  use simple examples
 *
 *
 * */

