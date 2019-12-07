#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct _node {
    int val;
    struct _node *prev;
    struct _node *next;
} node; 

typedef struct {
    node *first;
    node *last;
    int size;
} doubly_linked_list;

doubly_linked_list* dll_create();
void dll_push(doubly_linked_list *l, int elem);
int dll_pop(doubly_linked_list *l);
void dll_append(doubly_linked_list *l, int elem);
int dll_size(doubly_linked_list *l);
int dll_is_empty(doubly_linked_list *l);
int dll_remove(doubly_linked_list *l, int elem);
void dll_print(doubly_linked_list *l);
void dll_println(doubly_linked_list *l);
void dll_free(doubly_linked_list *l);
void dll_concat(doubly_linked_list *l1, doubly_linked_list *l2);
doubly_linked_list *dll_copy(doubly_linked_list *l);

#endif // DOUBLY_LINKED_LIST_H

