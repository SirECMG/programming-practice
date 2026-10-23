#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

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
    0x
};

static const uint8_t GY[32] = {

};




int main() {

    return EXIT_SUCCESS;
}
