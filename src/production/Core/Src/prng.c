/**
 * Implementation of the pseudo-random number generator (PRNG) functions.
 *
 * This file provides the implementation of the PRNG functions declared in prng.h. The PRNG is
 * designed to use a predefined array of numbers to simulate random number generation. This approach
 * allows for deterministic and reproducible generation of pseudo-random numbers, which is useful in
 * scenarios where predictability of the random sequence is necessary.
 *
 * The file defines a global PseudoRNG object 'rng' and includes functions for initializing the PRNG
 * with a specific array of numbers and fetching pseudo-random numbers from the array based on the 
 * PRNG's current state.
 *
 * Note: The PRNG's randomness is limited to the diversity and ordering of the numbers in the
 * predefined array. As such, it is not suitable for scenarios requiring high levels of true 
 * randomness or unpredictability.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "prng.h"

PseudoRNG rng;

/**
 * Initializes the PseudoRNG struct with a pre-generated list of random numbers.
 *
 * Parameters:
 *   rng: A pointer to the PseudoRNG struct to be initialized.
 *   numbers: A pointer to an array of pre-generated random numbers.
 *   size: The size of the 'numbers' array.
 *
 * Description:
 *   `initPRNG` sets up the PseudoRNG structure with the provided array of numbers and its size.
 *   This function initializes the PRNG's current index to 0 and assigns the array and its size
 *   to the corresponding fields in the PseudoRNG struct. The PRNG is then ready to provide
 *   pseudo-random numbers from the array.
 */
void initPRNG(PseudoRNG* rng, int* numbers, int size) {
    rng->num = numbers;
    rng->ind = 0;
    rng->size = size;
}

/**
 * Retrieves the next pseudo-random number from the PRNG's number array.
 *
 * Parameters:
 *   rng: A pointer to the PseudoRNG struct from which the number will be retrieved.
 *
 * Return:
 *   int: The next pseudo-random number from the array.
 *
 * Description:
 *   `getRand` fetches the next number in the PRNG's predefined array based on the current index.
 *   It then increments the index (wrapping around to the beginning of the array if necessary) to
 *   prepare for the next call. This function provides a simple way to iterate through the array
 *   of pseudo-random numbers in a cyclic manner.
 */
int getRand(PseudoRNG *rng) {
    rng->ind = (rng->ind + 1) % rng->size;
    return rng->num[rng->ind];
}
