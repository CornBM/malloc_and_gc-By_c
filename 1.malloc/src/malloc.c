#include "malloc.h"
#include <unistd.h>
#include <stdio.h>

Block* LIST_HEAD = NULL;

/*
    This function extends a new block of memory on heap with the given size.
*/
Block* create_block(__u32 size){
    // Allocate memory for the block
    Block* b;
    b = sbrk(0);
    if (sbrk(BLOCK_SIZE + size) == (void*)-1) {
        // Failed to allocate memory
        return NULL;
    }
    // Initialize the block
    b->size = size;
    b->used = 0;
    if (LIST_HEAD == NULL) {
        // This is the first block
        b->next = b;
        b->prev = b;
        return b;
    }
    // Add the block to the free list
    b->next = LIST_HEAD;
    b->prev = LIST_HEAD->prev;
    LIST_HEAD->prev->next = b;
    LIST_HEAD->prev = b;
    return b;
}


/*
    This function is called when the program starts to initialize the malloc system.
*/
void init_malloc(__u32 initial_size){
    // Initialize the first block
    LIST_HEAD = create_block(initial_size);
    if (LIST_HEAD == NULL) {
        // Failed to initialize the heap
        _exit(0);
    }
}

/*
    This function is called to allocate memory on the heap.
    First Fit
*/
Block* find_block(__u32 size) {
    // Find a block of memory of the given size
    Block* current = LIST_HEAD;
    __u32 found = 0;
    while (current!= NULL) {
        if (current->size >= size && current->used == 0) {
            found = 1;
            break;
        }
        current = current->next;
        if (current == LIST_HEAD) {
            break;
        }
    }
    // If found, split the block and return the remaining part
    if (found) {
        return split_block(current, size);
    }
    // If not found, return NULL
    return NULL;
}

/*
    This function splits a block of memory into two parts.
    The first part is of the given size, and the second part is of the remaining size.
*/
Block* split_block(Block* block, __u32 size) {
    __u32 payload_size = BLOCK_ALIGN(size);
    // here must use integer, because we need negative value
    int remaining_size = block->size - payload_size - BLOCK_SIZE;
    if (remaining_size >= 8) {
        // if the block is large enough to split, do it
        Block* remaining_block = (Block*)((char*)block + payload_size + BLOCK_SIZE);
        remaining_block->size = remaining_size;
        remaining_block->used = 0;

        block->size = payload_size;

        // Insert the remaining block into the free list
        remaining_block->next = block->next;
        remaining_block->prev = block;
        block->next->prev = remaining_block;
        block->next = remaining_block;
    }
    // If the block is too small to split, return it directly
    return block;
}


/*
    This function is called to free memory on the heap.
*/
void* my_malloc(__u32 size, const char* file, __u32 line) {
    // Find a block of memory of the given size
    Block* block = find_block(size);
    if (block == NULL) { // Failed to find a block
        block = create_block(size);
        if (block == NULL) return NULL; // Failed to allocate memory
    }
    // Mark the block as used and return the payload
    block->used = 1;
    return (void*)((char*)block + BLOCK_SIZE);
}

/*
    This function is called to merge two adjacent free blocks.
*/
void merge_block(Block* block1, Block* block2) {
    // Merge the two blocks
    block1->size += block2->size + BLOCK_SIZE;

    // Remove the second block from the free list
    block1->next = block2->next;
    block2->next->prev = block1;
}

/*
    This function is called to free memory on the heap.
*/
Block* my_free(void* ptr) {
    // Get the block that contains the po__u32er
    Block* block = (Block*)((char*)ptr - BLOCK_SIZE);

    if (block->used == 1) {
        // The block is used, mark it as free
        block->used = 0;
        // Merge with adjacent free blocks
        if (block->next->used == 0 && (char*)block + block->size + BLOCK_SIZE == (char*)block->next) {
            merge_block(block, block->next);
        }
        if (block->prev->used == 0 && (char*)block == (char*)block->prev + block->prev->size + BLOCK_SIZE) {
            merge_block(block->prev, block);
            block = block->prev;
        }
        return block; // return the block that was freed
    }
    else if (block->used == 0) {
        return block;
    }
    else {
        // If this is not a valid block, return NULL
        return NULL;
    }
}


void show_free_list() {
    // Pr__u32 the free list
    Block* current = LIST_HEAD;
    while (current != NULL) {
        printf("Block: %p, Size: %u, Used: %u\n", current, current->size, current->used);
        current = current->next;

        // Loop through the list until we reach the beginning
        if (current == LIST_HEAD) {
            break;
        }
    }
    printf("\n");
}