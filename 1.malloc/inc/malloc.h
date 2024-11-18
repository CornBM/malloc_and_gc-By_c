#ifndef MALLOC_H
#define MALLOC_H
#include <linux/types.h>

#define malloc(size) my_malloc(size, __FILE__, __LINE__)
#define free(ptr) my_free(ptr)

typedef struct Block {
    __u32 size;
    __u32 used;
    struct Block* prev;
    struct Block* next;
} Block;

#define BLOCK_SIZE sizeof(Block) // 24 bytes

extern Block* free_list;
#define LIST_HEAD free_list
#define LIST_TAIL ((__u8*)free_list->prev + free_list->prev->size + BLOCK_SIZE)

#define BLOCK_ALIGN(s) ((s & 0x7) == 0 ? s : ((s >> 3) + 1) << 3) // align to 8 bytes

void init_malloc(__u32 initial_size);

Block* find_block(__u32 size);
Block* split_block(Block* block, __u32 size);
Block* create_block(__u32 size);
void* my_malloc(__u32 size, const char* file, __u32 line);

void merge_block(Block* block1, Block* block2);
Block* my_free(void* ptr);

void show_free_list();

#endif

