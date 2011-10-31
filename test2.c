#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "elem.h"
#include "list.h"

list list_sort (list);

list random_list (int n) {
    list xs = NULL;
    for (int i = 0; i < n; i++)
        xs = list_cons(random() % 100, xs);
    return xs;
}

bool list_sorted (list xs) {
    if (xs != NULL) {
        int p = xs->val;
        for (list ys = xs->next; ys != NULL; ys = ys->next) {
            if (p > ys->val) return false;
            p = ys->val;
        }
    }
    return true;
}

void list_sort_test (int n) {
    printf("length=%d: ", n);
    list xs = random_list(n);
    // list_show(xs);
    xs = list_sort(xs);
    list_delete(xs);
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s n\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int n = atoi(argv[1]);
    comp_count = 0;
    // srandomdev();
    list_sort_test(n);
    printf("#comp=%ld\n", comp_count);
    return EXIT_SUCCESS;
}
