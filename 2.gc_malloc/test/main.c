#include <stdio.h>
#include "gc_malloc.h"
#include <unistd.h>

void memory_leak(int size) {
    int *p = (int*)gc_malloc(size);
}

void gc_test(){
    int max_size = 1024;
    gc_init(max_size);
    show_free_list();

    for (int i = 0; i < 10; i++) {
        // you could see what's the difference here
        //int *p = (int*)gc_malloc(100);
        memory_leak(100);
        show_free_list();
        sleep(1);
    }

    __u64 heap_size = (__u64)LIST_TAIL - (__u64)LIST_HEAD - BLOCK_SIZE;
    if (heap_size > max_size){
        printf("Memory leak detected\n");
        return;
    }
    printf("Now you win\n");
}

int main() {
    gc_test();
}