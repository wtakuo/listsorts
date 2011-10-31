#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "elem.h"
#include "list.h"

list list_sort (list);

list random_list (int n) {
    list xs = &(struct list_cell){ 0, NULL }, xs0 = xs;
    for (int i = 0; i < n; i++) {
        xs->next = list_cons(random() % 200 - 100, NULL);
        xs = xs->next;
    }
    return xs0->next;
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
    if (list_sorted(xs)) {
        printf("OK: ");
        printf("\n");
        //        list_show(xs);
    }
    else {
        printf("NG: ");
        list_show(xs);
    }
    list_delete(xs);
}

int main (void) {
    // srandomdev();

    list_sort_test(0);

    for (int i = 0; i < 2; i++)
        list_sort_test(1);

    for (int i = 0; i < 4; i++)
        list_sort_test(2);

    for (int i = 0; i < 4; i++)
        list_sort_test(3);

    for (int i = 0; i < 4; i++)
        list_sort_test(5);

    for (int i = 0; i < 4; i++)
        list_sort_test(10);

    for (int i = 0; i < 4; i++)
        list_sort_test(20);

    for (int i = 0; i < 4; i++)
        list_sort_test(100);

    for (int i = 0; i < 4; i++)
        list_sort_test(1000);

    for (int i = 0; i < 4; i++)
        list_sort_test(10000);

    for (int i = 0; i < 4; i++)
        list_sort_test(100000);

    return 0;
}
