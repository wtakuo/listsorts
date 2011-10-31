// destructive merge sort for lists
// Takuo Watanabe

#include <stdlib.h>

#include "elem.h"
#include "list.h"

list list_merge (list xs, list ys) {
    list p = &(struct list_cell){ 0, NULL }, p0 = p;
    for (;;) {
        if (xs == NULL) {
            p->next = ys;
            return p0->next;
        }
        else if (ys == NULL) {
            p->next = xs;
            return p0->next;
        }
        else if (comp(xs->val, ys->val) < 0) {
            p->next = xs;
            xs = xs->next;
        }
        else { // xs->val >= ys->val
            p->next = ys;
            ys = ys->next;
        }
        p = p->next;
    }
}

void list_split (list xs, list *yp) {
    list p = xs, q = xs;
    do {
        q = q->next;
        if (q->next == NULL) break;
        p = p->next;
        q = q->next;
    } while (q->next != NULL);
    *yp = p->next;
    p->next = NULL;
}

list list_sort (list xs) {
    if (xs == NULL || xs->next == NULL)
        return xs;
    else {
        list ys;
        list_split(xs, &ys);
        return list_merge(list_sort(xs), list_sort(ys));
    }
}
