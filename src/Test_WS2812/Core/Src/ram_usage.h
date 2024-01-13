#ifndef SRC_RAM_USAGE_H_
#define SRC_RAM_USAGE_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

extern uint32_t current_heap_usage;
extern uint32_t max_heap_usage;

void* custom_malloc(size_t size);
void custom_free(void* ptr, size_t size);
void* custom_calloc(size_t num, size_t size);

#endif /* SRC_RAM_USAGE_H_ */
