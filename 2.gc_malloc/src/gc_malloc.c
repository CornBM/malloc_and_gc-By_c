#include "gc_malloc.h"
#include <stdio.h>

__u32 MAX_HEAP_SIZE = 0;
void* MAIN_RBP = 0;

/*
    This function is called by the program to initialize the garbage collector.
*/
void gc_init(__u32 heap_size) {
    MAX_HEAP_SIZE = heap_size;
    MAIN_RBP = __builtin_frame_address(1); // assuming the prev frame is main
    // initialize the malloc
    init_malloc(MAX_HEAP_SIZE);
}

/*
    This function is to mark a block as referenced.
*/
void mark(Block* block) {
    if (block->used) {
        block->size |= 1; // mark the block as be referenced
    }
}
/*
    This function is to unmark a block as referenced.
*/
void unmark(Block* block) {
    if (block->used) {
        block->size &= ~1; // unmark the block as be referenced
    }
}

/*
    This function is to check if a ptr is a reference to a block.
*/
Block* contains(void* ptr) {
    if ((__u64)ptr & 0x3 != 0) // if the ptr is not 4-byte aligned
        return NULL;
    // loop through the heap area
    Block* current = LIST_HEAD;
    while (current != NULL) {

        if (current->used)
            // check if the ptr is within the block
            if ((__u64)ptr >= (__u64)((__u8*)current + sizeof(Block)) && 
                (__u64)ptr < (__u64)((__u8*)current + sizeof(Block) + current->size)) {
                return current; // found the block
            }

        current = current->next;
        if (current == LIST_HEAD) break; // reached the end of the list
    }
    return NULL;
}

Block* sweep(Block* block) {
    Block* current = block;
    if (current->used == 0) return current->next; // skip the free block
    if (current->used != 1) return NULL; // Invalid block

    if ((block->size & 1) == 0) { // if the block is not marked
        current = free((__u8*)block + BLOCK_SIZE); // free the block
        if (current == NULL) {
            return NULL; // Invalid pointer
        }
    }
    else { // if the block is marked
        unmark(block); // unmark the block
    }
    return current->next; // return the next block
}

void gc() {
    // 1. loop through the stack area
    __u8* current_rbp = __builtin_frame_address(0);
    for (__u8* p = current_rbp; (__u64)p < (__u64)MAIN_RBP; p += 4){
        Block* block = contains((void*)*(__u64*)p);
        if (block != NULL) {
            mark(block);
        }
    }

    // 2. loop through the heap area
    // TODO

    // 3. sweep the heap area
    Block* current = LIST_HEAD;
    while (current != NULL) {
        current = sweep(current);
        if (current == LIST_HEAD) break; // reached the end of the list
    }
}

void* gc_malloc(__u32 size) {
    Block* block = find_block(size);
    if (block == NULL && LIST_TAIL + size > (__u8*)LIST_HEAD + MAX_HEAP_SIZE) {
        gc(); // try to free up some memory
        /*
            but there is still a problem
            that is when we out of memory
            it will call gc every time as mallocing a new block
            because we didn't expand the MAX_HEAP_SIZE
        */
    }
    return malloc(size); // then whethere there is enough memory, allocate a new block
}
