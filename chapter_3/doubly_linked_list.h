#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct _node {
    void *val;
    struct _node *prev;
    struct _node *next;
} node; 

typedef struct {
    node *first;
    node *last;
    int size;
    int (*cmp)(void*, void*);
} doubly_linked_list;

doubly_linked_list* dll_create(int (*cmp)(void*, void*));
void dll_push(doubly_linked_list *l, void *elem);
void *dll_pop(doubly_linked_list *l);
void dll_append(doubly_linked_list *l, void *elem);
int dll_size(doubly_linked_list *l);
int dll_is_empty(doubly_linked_list *l);
int dll_remove(doubly_linked_list *l, void *elem);
void dll_print(doubly_linked_list *l, char *(*toStr)(void*));
void dll_println(doubly_linked_list *l, char *(*toStr)(void*));
void dll_free(doubly_linked_list *l);

#endif // DOUBLY_LINKED_LIST_H

