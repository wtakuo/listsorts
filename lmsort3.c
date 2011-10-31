// destructive merge sort for lists
// Takuo Watanabe

#include <stdlib.h>

#include "elem.h"
#include "list.h"

list list_merge (list xs, list ys) {
    struct list_cell dc = { 0, NULL };
    list p = &dc;
    while (xs != NULL && ys != NULL) {
        if (comp(xs->val, ys->val) < 0) {
            p->next = xs;
            xs = xs->next;
        }
        else { // xs->val >= ys->val
            p->next = ys;
            ys = ys->next;
        }
        p = p->next;
    }
    p->next = xs == NULL ? ys : xs;
    return dc.next;
}

list list_sort (list xs) {
    if (xs == NULL || xs->next == NULL)
        return xs;

    list p = xs, q = xs->next->next;
    while (q != NULL) {
        q = q->next;
        if (q == NULL) break;
        p = p->next;
        q = q->next;
    }
    list ys = p->next;
    p->next = NULL;
    return list_merge(list_sort(xs), list_sort(ys));
}
