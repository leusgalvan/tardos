#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void _free_node(node *n);

doubly_linked_list* dll_create() {
    doubly_linked_list *l = malloc(sizeof(doubly_linked_list));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

void dll_push(doubly_linked_list *l, int elem) {
    node *n = malloc(sizeof(node));
    n->val = elem;
    n->prev = NULL;
    n->next = l->first;
    if(l->size > 0) l->first->prev = n;
    l->first = n;
    if(l->size == 0) l->last = n;
    l->size++;
}

int dll_pop(doubly_linked_list *l) {
    if(l->size == 0) return -1; // -1 is arbitray, treat as undefined
    node *head = l->first;
    int ret = head->val;
    l->first = l->first->next;
    if(l->size == 1) l->last = NULL;
    l->size--;
    free(head);
    return ret;
}

void dll_append(doubly_linked_list *l, int elem) {
    node *n = malloc(sizeof(node));
    n->val = elem;
    n->next = NULL;
    n->prev = l->last;
    if(l->size > 0) l->last->next = n;
    l->last = n;
    if(l->size == 0) l->first = n;
    l->size++;
}

int dll_size(doubly_linked_list *l) {
    return l->size;
}

int dll_is_empty(doubly_linked_list *l) {
    return l->size == 0;
}

int dll_remove(doubly_linked_list *l, int elem) {
    int isFirst = 1;
    for(node *n = l->first; n != NULL; n = n->next) {
        if(n->val == elem) {
            if(isFirst) {
                l->first = l->first->next;
                if(l->first != NULL) l->first->prev = NULL;
            } else {
                n->prev->next = n->next;
            }
            if(n->next == NULL) {
                l->last = l->last->prev;
                if(l->last != NULL) l->last->next = NULL;
            } else {
                n->next->prev = n->prev;
            }
            free(n);
            l->size--;
            return 1;
        }
        isFirst = 0;
    }
    return 0;
}

void dll_print(doubly_linked_list *l) {
    printf("[");
    if(dll_size(l) > 0) {
        node *n = l->first;
        printf("%d", n->val);
        for(n = n->next; n != NULL; n = n->next) {
            printf(", %d", n->val);
        }
    }
    printf("]");
}

void dll_println(doubly_linked_list *l) {
    dll_print(l);
    printf("\n");
}

void dll_free(doubly_linked_list *l) {
    node *n = l->first;
    while(n != NULL) {
        node *tmp = n->next;
        free(n);
        n = tmp;
    }
    free(l);
}

void dll_concat(doubly_linked_list *l, doubly_linked_list *l2) {
    if(l->size == 0) {
        *l = *l2;
        return;
    }

    l->size += (l2->size);

    l->last->next = l2->first;
    l2->first->prev = l->last;
    l->last = l2->last;
}

doubly_linked_list *dll_copy(doubly_linked_list *l) {
    doubly_linked_list *ret = dll_create();
    if(l->size > 0) {
        for(node *n = l->first; n != NULL; n = n->next) {
            dll_append(ret, n->val);
        }
    }
    return ret;
}

