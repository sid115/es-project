/**
 * Implementation of functions for managing and using a lookup table for LED matrices.
 *
 * This file includes the definitions of functions for initializing and generating a lookup
 * table that maps 2D coordinates to linear indices in a series-wired LED matrix. The lookup
 * table simplifies the process of addressing individual LEDs by their x and y coordinates, 
 * which is especially useful when the wiring order of the LEDs does not match the intuitive 
 * visual layout. This implementation supports matrices of arbitrary dimensions and can 
 * accommodate various LED panel wiring patterns.
 *
 * The file defines the global LookupTable object 'lookupTable' and functions for initializing
 * this table with specified dimensions and generating the lookup indices based on the LED
 * panel's wiring pattern.
 */

#include "lookup_table.h"

LookupTable lookupTable;

/**
 * Initializes the LookupTable struct with specified dimensions.
 *
 * Parameters:
 *   lookupTable: A pointer to the LookupTable struct to be initialized.
 *   rows: The number of rows in the LED matrix.
 *   cols: The number of columns in the LED matrix.
 *
 * Description:
 *   `initLookupTable` sets up the dimensions of the LookupTable and allocates memory for
 *   the 2D index array. Each cell in this array will later hold the linear index of an LED
 *   based on its (x, y) coordinates. The function also initializes all indices in the array 
 *   to zero. It is essential to call this function before using the LookupTable in any 
 *   operations. The function exits the program if rows or cols are non-positive values, 
 *   indicating an invalid LED matrix size.
 */
void initLookupTable(LookupTable* lookupTable, uint16_t rows, uint16_t cols) {
    uint16_t r, c; /* index variables */

    /* check input */
    if (rows <= 0) exit(1); /* number of rows must be greater than 0 */
    if (cols <= 0) exit(1); /* number of cols must be greater than 0 */

    /* allocate memory */
    lookupTable->index = (uint16_t**) malloc(rows * sizeof(uint16_t*));
    for (r = 0; r < rows; r++) {
        lookupTable->index[r] = (uint16_t*) malloc(cols * sizeof(uint16_t));
    }

    /* set attrs */
    lookupTable->rows = rows;
    lookupTable->cols = cols;

    /* initialize index array */
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            lookupTable->index[r][c] = 0;
        }
    }
}

/**
 * Generates the lookup indices for the LookupTable based on the LED panel's wiring pattern.
 *
 * Parameters:
 *   lookupTable: A pointer to the initialized LookupTable struct.
 *   panelWidth: The width of each panel in the LED matrix. This is used to calculate the linear 
 *               index based on the specific wiring pattern of the LED panel.
 *
 * Description:
 *   `generateLookupTable` fills the index array of the LookupTable with the correct linear indices
 *   corresponding to each (x, y) coordinate in the LED matrix. The function assumes a specific
 *   wiring pattern and may need to be adjusted depending on the actual layout of the LED matrix.
 *   After this function is called, the lookupTable can be used to translate (x, y) coordinates
 *   into linear indices, simplifying the process of controlling individual LEDs in the matrix.
 */
void generateLookupTable(LookupTable* lookupTable, uint16_t panelWidth) {
    uint16_t x, y; /* index variables */

    unsigned int widthXRows = panelWidth * lookupTable->rows; /* pre-calculate for speed */

    /* fill index array */
    for (y = 0; y < lookupTable->rows; y++) {
        for (x = 0; x < lookupTable->cols; x++) {
            /* calculate linear index based on wiring pattern */
            lookupTable->index[y][x] = x % panelWidth + y * panelWidth + (x / panelWidth) * widthXRows;
        }
    }
}
