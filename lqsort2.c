// destructive quick sort for lists
// Takuo Watanabe

#include <stdlib.h>

#include "elem.h"
#include "list.h"

list list_sort1 (list xs, list ws) {
    while (xs != NULL) {
        struct list_cell yc, zc;
        list ys = &yc, zs = &zc;
        elem_t pvt = xs->val;
        for (list ts = xs->next; ts != NULL; ts = ts->next)
            if (comp(ts->val, pvt) < 0)
                ys = ys->next = ts;
            else
                zs = zs->next = ts;
        ys->next = zs->next = NULL;
        xs->next = list_sort1(zc.next, ws);
        ws = xs;
        xs = yc.next;
    }
    return ws;
}

list list_sort (list xs) {
    return list_sort1(xs, NULL);
}
