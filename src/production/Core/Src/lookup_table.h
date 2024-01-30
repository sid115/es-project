/**
 * Header file for handling a lookup table for LED matrix coordinates.
 *
 * This file provides the definition and initialization functions for a LookupTable struct,
 * which is used to map x and y coordinates to the corresponding index of an LED in a
 * series-wired LED matrix. This mapping is especially useful for working with LED matrices
 * where the wiring order does not intuitively match the visual layout of the LEDs, thereby
 * simplifying the process of addressing individual LEDs based on their x and y coordinates.
 *
 * The LookupTable struct contains the dimensions of the matrix (rows and cols) and a 2D
 * array (index) where index[y][x] provides the linear index of the LED at the given coordinates.
 *
 * Functions included:
 *   - initLookupTable: Initializes a LookupTable struct with given dimensions.
 *   - generateLookupTable: Fills the lookup table according to the wiring pattern of the LED panel.
 *
 * The generateLookupTable function is designed to be customized based on the specific wiring
 * pattern of the LED matrix being used, which may vary between different hardware implementations.
 */

#ifndef SRC_LOOKUP_TABLE_H_
#define SRC_LOOKUP_TABLE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Represents a lookup table for mapping 2D coordinates to linear indices in an LED matrix.
 */
typedef struct {
    uint16_t rows; /* number of rows in the LED matrix. */
    uint16_t cols; /* number of columns in the LED matrix. */
    uint16_t** index; /* index[y][x] will return index of LED in matrix at (x, y) */
} LookupTable;

/* Global lookup table variable */
extern LookupTable lookupTable;

/* Function prototypes */
void initLookupTable(LookupTable* lookupTable, uint16_t rows, uint16_t cols);
void generateLookupTable(LookupTable* lookupTable, uint16_t panelWidth);

#endif /* SRC_LOOKUP_TABLE_H_ */
