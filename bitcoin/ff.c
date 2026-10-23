#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

/*
 * to get comfortable with elliptic curve we first must create the curve.
 *
 * the equation is y^2 = ax^3 + b + c
 *
 * T = (p, a, b, G, n, h)
 *
 * the easiest we can define now is G.
 * G is a coordinate consist of (G_x, G_y)
 *
 * GX =  
 * 79BE667E 
 * F9DCBBAC 
 * 55A06295 
 * CE870B07 
 * 029BFCDB 
 * 2DCE28D9
 * 59F2815B 
 * 16F81798 
 *
 * GY = 
 * 483ADA77 
 * 26A3C465 
 * 5DA4FBFC 
 * 0E1108A8 
 * FD17B448
 * A6855419 
 * 9C47D08F 
 * FB10D4B8
 *
 * This constant was defined by NIST https://www.secg.org/sec2-v2.pdf
 *
 * it is represented in HEX
 *
 * in C we can fit this in uint8_t (because it is easy to work with bytes/8bits)
 * we can represent a byte as 0x79 in c.
 * */

static const uint8_t GX[32] = {
    0x79, 0xBE, 0x66, 0x7E,
    0xF9, 0xDC, 0xBB, 0xAC,
    0x55, 0xA0, 0x62, 0x95,
    0xCE, 0x87, 0x0B, 0x07,
    0x02, 0x9B, 0xFC, 0xDB,
    0x2D, 0xCE, 0x28, 0xD9,
    0x59, 0xF2, 0x81, 0X5B,
    0x16, 0xF8, 0x17, 0x98
};

static const uint8_t GY[32] = {
    0x48, 0x3A, 0xDA, 0x77,
    0x26, 0xA3, 0xC4, 0x65,
    0x5D, 0xA4, 0xFB, 0xFC,
    0x0E, 0x11, 0x08, 0xA8,
    0xFD, 0x17, 0xB4, 0x48,
    0xA6, 0x85, 0x54, 0x19,
    0x9C, 0x47, 0xD0, 0x8F,
    0xFB, 0x10, 0xD4, 0xB8
};


typedef struct {
    uint8_t prime[32];
    uint8_t num[32]; // it looks weird but finite fields are supposed to represent extremly large numbers.
} FiniteField;


// the prime is provided given the curve, that is why it is in the function and not set by the caller.
void create_fe(FiniteField *fe, uint8_t num);

void create_fe(FiniteField *fe, uint8_t num) {
    // 2^256 - 2^32 - 977
    static const uint8_t prime[32] = {
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFE,
        0xFF, 0xFF, 0xFC, 0x2F
    };

    /*
     * this sets prime and number obviously
     * but need to understand what memcpy and memset does..
     *
     * and why are we setting num[31]?? little vs big endian...
     * */
    memcpy(fe->prime, prime, 32);
    memset(fe->num, 0, 32);
    fe->num[31] = num;
    return;
}

void print_num(const uint8_t num[32]) {
    for(int i = 0; i < 32; i++) {
        printf("%02x", (unsigned) num[i]);
    }
    printf("\n");
}


/*
 *  adding, substracting, multiplying, exponent functions...
 *  
 * */



int main() {

    FiniteField fe1;
    create_fe(&fe1, 9);

    printf("num: ");
    print_num(fe1.num);
    printf("prime: ");
    print_num(fe1.prime);

    return EXIT_SUCCESS;
}


/*
 * concept check:
 *
 * Define a point and G. Store x, y, and a flag for the point at infinity.
Implement modular arithmetic. Addition, subtraction, multiplication, and modular inverse.
Check whether a point is on the curve. Verify its coordinates satisfy the curve equation.
Implement point addition and doubling. Handle special cases such as adding a point to its negative.
Implement scalar multiplication. Compute kG using double-and-add.
 * */




/*
 *  questions to ask while implementing...
 *
 *  - what does memset do? used to fill a block of memory with a particular value
 *  - what does memcpy do? used to copy blocks of memory....
 *  - what does %02x do? print at least 2 digits, prepend it with 0 if there's less
 *      - %x is a format specifier that format and output the hex value
 *          - if you are providing an int or long value
 *      - %02x
 *          - if your provided value is less than two digits, then 0 will be prepended.
 *  - how is 2^256 - 2^32 - 977 derived?
 *
 *
 * */
