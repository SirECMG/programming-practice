#include "stdio.h"
#include "stdlib.h"

/*
 * 00000010
 * */

void print_bit(unsigned int n) {

    int i = 7;
    while(i >= 0) {
        printf("%d", (n >> i) & 1);
        i--;

    }
    printf("\n");
    return; 
}

int main() {
    unsigned int a = 2;
    print_bit(a);
    printf("%d\n", a);

    a &= a; // a |= (1 << 2) set bit
                    // a = ~a // flip all bits
                   // a &= (1 << 2) clear bit
                   // a ^= (1 << 2) flip bit
    print_bit(a);
    printf("%d\n", a);

    printf("%d\n", 1 ^ 2);
}
