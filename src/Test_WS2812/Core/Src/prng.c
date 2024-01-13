#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "prng.h"

PseudoRNG rng;

/* init PRNG with a pre-generated list of random numbers */
void initPRNG(PseudoRNG* rng, int* numbers, int size) {
    rng->num = numbers;
    rng->ind = 0;
    rng->size = size;
}

/* get next random number */
int getRand(PseudoRNG *rng) {
    int number = rng->num[rng->ind];
    rng->ind = (rng->ind + 1) % rng->size;
    return number;
}
