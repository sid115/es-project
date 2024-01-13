#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "numbers.c" /* array of pseudo random numbers */

/* saves PRNG state */
typedef struct {
    uint* numbers;  /* pointer to array of pre-generated random numbers */
    uint index;     /* current index in array */
    uint size;
} PseudoRNG;

void initPRNG(PseudoRNG* rng, uint* numbers, uint size);
uint getRand(PseudoRNG *rng);

/* use main for testing */
int main(int argc, char *argv[]) {
    if (argc != 2) exit(1);

    uint numNums   = atoi(argv[1]);

    PseudoRNG prng;

    initPRNG(&prng, numbers, SIZE_NUMBERS);
    for (uint i = 0; i < numNums; i++) {
        printf("%d: %d % 4 = %d\n", i, prng.numbers[i], prng.numbers[i] % 4);
    }

    return 0;
}

/* init PRNG with a pre-generated list of random numbers */
void initPRNG(PseudoRNG* rng, uint* numbers, uint size) {
    rng->numbers = numbers;
    rng->index = 0;
    rng->size = size;
}

/* get next random number */
uint getRand(PseudoRNG *rng) {
    uint number = rng->numbers[rng->index];
    rng->index = (rng->index + 1) % rng->size;
    return number;
}
