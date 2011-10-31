#include <stdio.h>
#include <stdlib.h>

#include "elem.h"
#include "list.h"

list list_cons (elem_t val, list next) {
    list l = malloc(sizeof(struct list_cell));
    if (l == NULL) {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    l->val = val;
    l->next = next;
    return l;
}

void list_delete (list l) {
    while (l != NULL) {
        list ll = l->next;
        free(l);
        l = ll;
    }
}

void list_show (list l) {
    printf("(");
    if (l != NULL) {
        print_elem(l->val);
        l = l->next;
        while (l != NULL) {
            printf(" ");
            print_elem(l->val);
            l = l->next;
        }
    }
    printf(")\n");
}
