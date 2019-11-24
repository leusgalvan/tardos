#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _node {
    void *val;
    struct _node *next;
} node;

typedef node *linked_list;

linked_list *ll_create();
void *ll_pop(linked_list *l);
void ll_push(linked_list *l, void *elem);
int ll_is_empty(linked_list *l);
void ll_print(linked_list *l);

#endif // LINKED_LIST_H
