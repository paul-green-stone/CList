#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "list.h"

void print_char(char* data) {
    printf("%s", data);
}

int match_char(const char* a, const char* b) {
    return strcmp(a, b);
}

/* ================================================================ */

int main(int argc, char** argv) {

    List list;

    char* array[] = {"Paul", "Katherine", "Valery", "Elizabeth"};
    void* data;
    /* ======== */
    
    List_init(&list, free);
    list.print = (void (*)(void*)) &print_char;
    list.match = (int (*)(const void*, const void*)) match_char;

    void* str = malloc((strlen(*array) * sizeof(char)) + 1);
    strcpy(str, *array);
    List_insert_tail(&list, str);
    str = malloc((strlen(*(array + 1)) * sizeof(char)) + 1);   
    strcpy(str, *(array + 1));

    List_insert_tail(&list, str);
    List_print(&list);

    Node* n = List_find(&list, "Katherine");
    if (n != NULL) {
        
        str = malloc((strlen(*(array + 2)) * sizeof(char)) + 1);
        strcpy(str, *(array + 2));
        List_insert_before(&list, n, str);
    }

    List_print(&list);

    List_destroy(&list);

    /* ======== */
    return EXIT_SUCCESS;
}

/* ================================================================ */
