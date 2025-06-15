#include <stdlib.h>
#include <time.h>

#include "list.h"

void print_int(int* data) {
    printf("%d", *data);
}

int match_int(int* a, int* b) {
    return *a - *b;
}

/* ================================================================ */

int main(int argc, char** argv) {

    List list;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    void* data = NULL;
    /* ======== */

    srand(time(NULL));

    List_init(&list, NULL);
    list.print = (void (*)(void* data)) print_int;
    list.match = (void (*)(const void* a, const void* b)) match_int;

    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        List_insert_tail(&list, &array[i]);
    }

    int* a = List_find(&list, (array + 1));
    if (a != NULL) {
        printf("Found: %d\n", *a);
    }

    printf("List size: %ld\n", list.size);

    List_print(&list);

    for (; list.size != 0; ) {

        List_print(&list);

        List_remove_tail(&list, &data);
    }

    printf("List size: %ld\n", list.size);

    List_destroy(&list);

    /* ================================================================ */

    List_init(&list, free);

    for (size_t i = 0; i < 10; i++) {

        int* x = malloc(sizeof(int));
        *x = rand() % 100;

        List_insert_tail(&list, x);
    }

    list.print = (void (*)(void* data)) print_int;
    printf("List size: %ld\n", list.size);

    List_print(&list);

    List_destroy(&list);

    /* ======== */
    return EXIT_SUCCESS;
}

/* ================================================================ */
