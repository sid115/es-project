#ifndef SRC_PRNG_H_
#define SRC_PRNG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* saves PRNG state */
typedef struct {
    int* num; /* pointer to array of pre-generated random numbers */
    int ind;  /* current index in array */
    int size;
} PseudoRNG;

extern PseudoRNG rng;

void initPRNG();
int getRand();

#endif /* SRC_MAZE_H_ */
