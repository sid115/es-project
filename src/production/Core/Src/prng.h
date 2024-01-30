/**
 * Header file for a pseudo-random number generator (PRNG) using a predefined array of numbers.
 *
 * This file provides the definition of the PseudoRNG struct and the function prototypes for
 * initializing and using the pseudo-random number generator. The PRNG is designed to use a
 * predefined array of numbers (e.g., from numbers.c) to simulate random number generation.
 * This approach is useful in scenarios where deterministic and reproducible pseudo-random
 * behavior is required.
 *
 * The PseudoRNG struct keeps track of the current state of the generator, including a pointer
 * to the array of pre-generated random numbers, the current index within that array, and the
 * size of the array.
 *
 * Functions included:
 *   - initPRNG: Initializes the PseudoRNG struct with a given array of numbers and its size.
 *               This function sets up the PRNG for subsequent use.
 *   - getRand: Fetches the next pseudo-random number from the array based on the current state
 *              of the PseudoRNG struct and updates the internal index.
 *
 * The PRNG is not truly random; it is deterministic and relies on the sequence of numbers in the
 * provided array. It is suitable for applications where the sequence of 'random' numbers needs to be
 * predictable and repeatable.
 */

#ifndef SRC_PRNG_H_
#define SRC_PRNG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * Represents the state of a pseudo-random number generator (PRNG) that utilizes a predefined array of numbers.
 */
typedef struct {
    int* num; /* pointer to array of pre-generated random numbers */
    int ind;  /* current index in array 'num' */
    int size; /* size of array 'num' */
} PseudoRNG;

/* Global rng variable */
extern PseudoRNG rng;

/* Function prototypes */
void initPRNG(PseudoRNG* rng, int* numbers, int size);
int getRand(PseudoRNG *rng);

#endif /* SRC_PRNG_H_ */
