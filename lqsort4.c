// destructive quick sort for lists
// Takuo Watanabe

#include <stdlib.h>

#include "elem.h"
#include "list.h"

void list_sort1 (list ps, list xs, list ws) {
    while (xs != NULL) {
        struct list_cell lc, hc;
        list ls = &lc, hs = &hc, ms = xs, ms0 = ms;
        elem_t pvt = xs->val;
        long c = 0;
        for (list ts = xs->next; ts != NULL; ts = ts->next) {
            int cmp = comp(ts->val, pvt);
            if (cmp < 0) {
                ls = ls->next = ts;
                c++;
            }
            else if (cmp > 0) {
                hs = hs->next = ts;
                c--;
            }
            else // ts->val == pvt
                ms = ms->next = ts;
        }
        ls->next = hs->next = NULL;
        if (c > 0) {
            list_sort1(ms, hc.next, ws);
            xs = lc.next;
            ws = ms0;
        }
        else {
            list_sort1(ps, lc.next, ms0);
            ps = ms;
            xs = hc.next;
        }
    }
    ps->next = ws;
}

list list_sort (list xs) {
    struct list_cell pc;
    list_sort1(&pc, xs, NULL);
    return pc.next;
}
