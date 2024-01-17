#include "lookup_table.h"

LookupTable lookupTable;

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

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            lookupTable->index[r][c] = 0;
        }
    }
}

void generateLookupTable(LookupTable* lookupTable, uint16_t panelWidth) {
    uint16_t x, y;

    unsigned int widthXRows = panelWidth * lookupTable->rows; /* pre-calculate for speed */

    for (y = 0; y < lookupTable->rows; y++) {
        for (x = 0; x < lookupTable->cols; x++) {
            lookupTable->index[y][x] = x % panelWidth + y * panelWidth + (x / panelWidth) * widthXRows;
        }
    }
}
