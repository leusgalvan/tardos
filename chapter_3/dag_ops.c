#include <stdio.h>
#include <stdlib.h>
#include "dag_ops.h"
#include "dag.h"
#include "utils.h"

int *top_sort(dag *g) {
    int incoming[g->n];
    doubly_linked_list *eligible = dll_create(cmp_ints);
    int *p;
    for(int i = 0; i < g->n; i++) {
        incoming[i] = dll_size(dag_get_rev_neighbors(g, i));
        if(incoming[i] == 0) {
            p = malloc(sizeof(int));
            *p = i;
            dll_push(eligible, p);
        }
    }
    int *ret = malloc(sizeof(int) * g->n);
    int v, w;
    doubly_linked_list *neighbors;
    int j = 0;
    while(!dll_is_empty(eligible)) {
        v = *((int*)dll_pop(eligible));
        ret[j++] = v;
        neighbors = dag_get_neighbors(g, v);
        while(!dll_is_empty(neighbors)) {
            w = *((int*)dll_pop(neighbors));
            incoming[w]--;
            if(incoming[w] == 0) {
                p = malloc(sizeof(int));
                *p = w;
                dll_push(eligible, p);
            }
        }
    }
    return ret;
}
