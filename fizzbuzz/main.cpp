/*
 * fizzbuzz
 *
 * fizzbuzz is a groupo word game for children to teach them about
 * division.
 *
 * used to screen young computer science graduates during programming
 * interviews.
 *
 * basically, this is how it works: you print integers
 * from 1 to N, replacing any of them divisible by X with Fizz
 * or if they are divisible by Y, Buzz.
 *
 * If the nubmer is divisible by both X and Y, you print FizzBuzz instead.
 *
 * input:
 *
 * if input contains a single test case.
 * each test case contains three integers
 * X, Y, N
 *
 * 1 <= X < Y <= N <= 100).
 *
 *
 * Output:
 *
 * 2 3 7
 *
 * Sample Output 1:
 *
 * 1 to N.
 * divisible by both X and Y FizzBuzz
 * divisible by X Fizz
 * divisible by Y Buzz
 *
 * constraint 100
 *
 * *
 * int cur = 1
 *
 * while cur <= n || cur == 100
 * int remainder = cur % (X + Y);
 * if remainder == 0
 *  print fizzbuzz
 * 
 * remainder =  cur % x;
 * if remainder == 0 
 *  prin fizz
 *
 * remainder = cur % y;
 * if reaminder == 0
 *  prin buzz
 *
 * cur += 1
 * */


/*
 *  capture x
 *  capture y
 *  capture n
 *
 *
 *  fizzbuzz(cur, n)
 *      if cur == n || cur == 100
 *          return
 *
 *      if(cur % n == 0 && cur % y == 0)
 *          print fizzbuzz
 *      else if cur % n == 0
 *          prin fizz
 *      else if cur % y == 0
 *          print buzz
 *      else 
 *          print cur
 *
 *      fizzbuzz(cur + 1, x,y, n);
 *
 *
 * */

#include <iostream>

void fizzbuzz(int cur, int x, int y, int n) {
    if (cur > n || cur > 100) return;
    else if (cur % x == 0 && cur % y == 0) std::cout << "FizzBuzz\n";
    else if (cur % x == 0) std::cout << "Fizz\n";
    else if (cur % y == 0) std::cout << "Buzz\n";
    else std::cout << cur << "\n";

    fizzbuzz(cur + 1, x, y, n);
}


int main() {
    int x,y,n;
    std::cin >> x >> y >> n;

    int cur = 1;
    fizzbuzz(cur,x,y,n);

    return 0;
}
