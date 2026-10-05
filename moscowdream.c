#include "stdio.h"
#include "stdlib.h"

int is_valid(int a, int b, int c, int n) {
    if(a >= 1 && b >= 1 && c >= 1 && a + b + c >= n) {
        return 1;
    }

    return 0;
}

int main() {

    int a,b,c,n;
    fscanf(stdin, "%d %d %d %d", &a, &b, &c, &n);

    if(!is_valid(a,b,c,n)) { 
        printf("NO\n");
    } else {
        printf("YES\n"); 
    }
    
    return EXIT_SUCCESS;
}


/*
 *
 *
 *
 * input contains 4 integers
 *
 * a, b, c and n
 *
 * print "YES" if it is possible to create a problem set satisfying the above requirements and NO otherwise
 *
 *
 * consist of exactly N problems
 *
 * 1 easy problem
 * 1 medium problem
 * 1 hard
 *
 * 0 <= a,b,c <= 10
 *
 * 1 <= n <= 20
 *
 * */
