// destructive quick sort for lists
// Takuo Watanabe

#include <stdlib.h>

#include "elem.h"
#include "list.h"

list list_sort1 (list xs, list ws) {
    while (xs != NULL) {
        struct list_cell lc, hc;
        list ls = &lc, hs = &hc, ms = xs, ms0 = ms;
        elem_t pvt = xs->val;
        for (list ts = xs->next; ts != NULL; ts = ts->next) {
            int cmp = comp(ts->val, pvt);
            if (cmp < 0)
                ls = ls->next = ts;
            else if (cmp > 0)
                hs = hs->next = ts;
            else // ts->val == pvt
                ms = ms->next = ts;
        }
        ls->next = hs->next = NULL;
        ms->next = list_sort1(hc.next, ws);
        ws = ms0;
        xs = lc.next;
    }
    return ws;
}

list list_sort (list xs) {
    return list_sort1(xs, NULL);
}
