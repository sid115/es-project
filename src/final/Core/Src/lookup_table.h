#ifndef SRC_LOOKUP_TABLE_H_
#define SRC_LOOKUP_TABLE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    uint16_t rows;
    uint16_t cols;
    uint16_t** index; /* index[y][x] will return index of LED in matrix at (x, y) */
} LookupTable;

extern LookupTable lookupTable;

void initLookupTable(LookupTable* lookupTable, uint16_t rows, uint16_t cols);
void generateLookupTable(LookupTable* lookupTable, uint16_t panelWidth);

#endif /* SRC_LOOKUP_TABLE_H_ */
