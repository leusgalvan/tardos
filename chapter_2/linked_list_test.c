#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int head(linked_list l);

int main() {
    linked_list *l = ll_create();

    int values[] = {5,3,7,2,6};
    for(int i = 0; i < 5; i++) {
        ll_push(l, &values[i]);
    }
    printf("List: ");
    ll_print(l);
    printf("\nIs empty: %s\n\n", ll_is_empty(l)? "true": "false");
    for(int i = 0; i < 5; i++) {
        printf("Popped: %d\n", *((int*)ll_pop(l)));
    }
    printf("\nList: ");
    ll_print(l);
    printf("\nIs empty: %s\n", ll_is_empty(l)? "true": "false");
    return 0;
}

