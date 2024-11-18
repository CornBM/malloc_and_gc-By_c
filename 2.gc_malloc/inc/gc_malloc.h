#ifndef GC_MALLOC_H
#define GC_MALLOC_H
#include "malloc.h"

extern __u32 MAX_HEAP_SIZE;
extern void* MAIN_RBP;

// #define get_rbp(rbp) rbp = __builtin_frame_address(0)
// another way to get rbp: __asm__("mov %%rbp, %0" : "=r"(rbp));

void gc_init(__u32 heap_size);

void* gc_malloc(__u32 size);

void mark(Block* block);
void unmark(Block* block);
Block* sweep(Block* block);

void gc();

#endif