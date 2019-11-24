#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

linked_list* ll_create() {
    linked_list *l = malloc(sizeof(linked_list));
    *l = NULL;
    return l;
}

int ll_is_empty(linked_list *l) {
    return *l == NULL;
}

void *ll_pop(linked_list *l) {
    void *headVal = (*l)->val;
    linked_list head = *l;
    *l = (*l)->next;
    free(head);
    return headVal;
}

void ll_push(linked_list *l, void *elem) {
    linked_list head = malloc(sizeof(node*));
    head->val = elem;
    head->next = *l;
    *l = head;
}

void ll_print(linked_list *l) {
    printf("[");
    if(!ll_is_empty(l)) {
        printf("%d", *((int*)(*l)->val));
        l = &((*l)->next);
        for(;!ll_is_empty(l); l = &((*l)->next)) {
            printf(", %d", *((int*)(*l)->val));
        }
    }
    printf("]\n");
}
