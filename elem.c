#include <stdio.h>

#include "elem.h"

long comp_count;

int comp (elem_t x, elem_t y) {
    comp_count++;
    return x - y;
}

void print_elem(elem_t x) {
    printf("%d", x);
}
