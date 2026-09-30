#include "stdio.h"
#include "stdlib.h"

/*
 * 8 = 100
 * 7 = 111
 * */

unsigned int num_bits(unsigned int n) {
    unsigned int num_bits = 0;
    while(n != 0) { // in c conditions are 0 == false  and > 0 true
        num_bits += n & 1;
        n >>= 1;
    }

    return num_bits;
}

int main() {

    unsigned int n = 7;
    unsigned int result = num_bits(n);

    printf("%d\n", result);

    return EXIT_SUCCESS;
}
