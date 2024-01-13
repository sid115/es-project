#include "ram_usage.h"

uint32_t current_heap_usage = 0;
uint32_t max_heap_usage = 0;

void* custom_malloc(size_t size) {
    void *p = malloc(size);
    if (p) {
        current_heap_usage += size;
        if (current_heap_usage > max_heap_usage) {
            max_heap_usage = current_heap_usage;
        }
    }
    return p;
}

void custom_free(void* ptr, size_t size) {
    free(ptr);
    current_heap_usage -= size;
}

void* custom_calloc(size_t num, size_t size) {
    size_t total_size = num * size;
    void *p = malloc(total_size);

    if (p) {
        memset(p, 0, total_size); // init allocated memory to zero
        current_heap_usage += total_size;
        if (current_heap_usage > max_heap_usage) {
            max_heap_usage = current_heap_usage;
        }
    }
    return p;
}
