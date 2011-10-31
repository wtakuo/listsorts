// simple list library
// Takuo Watanabe

typedef struct list_cell {
    elem_t val;
    struct list_cell *next;
} *list;

list list_cons (elem_t, list);
void list_delete (list);
void list_show (list);

