/**
 * Header file for storing an array of predefined numbers used in a pseudo-random number generator.
 *
 * This file defines a global array 'numbers' which holds a collection of integers. The array
 * is intended to be used as a part of a pseudo-random number generation mechanism, where the
 * randomness is derived from the predefined values within this array. The size of the array is
 * defined by SIZE_NUMBERS. The actual contents of the array should be initialized in the 
 * corresponding source file numbers.c and are expected to be populated with random or
 * pseudo-random values. The array and its size definition can be used in various parts of the
 * application where deterministic but seemingly random number generation is required.
 *
 * Constants:
 *   SIZE_NUMBERS: Defines the size of the 'numbers' array. This constant determines how many
 *                 integers the array will contain.
 *
 * Global Variables:
 *   numbers: An array of integers used as a source of pseudo-random values. This array must be
 *            externally defined and initialized with appropriate values to ensure proper functioning
 *            of the pseudo-random number generation.
 */

#ifndef SRC_NUMBERS_H_
#define SRC_NUMBERS_H_

#define SIZE_NUMBERS 999

/* Global numbers array */
extern int numbers[];

#endif /* SRC_NUMBERS_H_ */
