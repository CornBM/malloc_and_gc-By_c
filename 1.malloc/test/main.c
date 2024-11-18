#include <stdio.h>
#include <string.h>
#include "malloc.h"
#include <unistd.h>

void allocate_test(){
    init_malloc(1024);

    int *p = (int*)malloc(100 * sizeof(int));
    if (p == NULL) _exit(0);
    show_free_list();

    int *q = (int*)malloc(100 * sizeof(int));
    if (q == NULL) _exit(0);
    show_free_list();

    int *r = (int*)malloc(100 * sizeof(int));
    if (r == NULL) _exit(0);
    show_free_list();

    printf("allocate_test success!\n");
}

void free_test(){
    init_malloc(1024);

    char *p = (char*)malloc(sizeof(int));
    show_free_list();

    int *q = (int*)malloc(100 * sizeof(int));
    show_free_list();

    int *r = (int*)malloc(100 * sizeof(int));
    show_free_list();

    free(q);
    show_free_list();

    free(r);
    show_free_list();

    free(p);
    show_free_list();

    printf("free_test success!\n");
}

void use_test() {
    init_malloc(1024);

    char *p = (char*)malloc(100);
    if (p == NULL) _exit(0);
    show_free_list();
    strcpy(p, "hello world\0");
    printf("p: %s\n", p);

    free(p);
    show_free_list();
    // could still use p, because it's not trully freed, just be marked as free
    printf("p: %s\n", p);

    printf("use_test success!\n");
}

int main() {
    // allocate_test();
    // free_test();
    use_test();
}