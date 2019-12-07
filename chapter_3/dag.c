#include <stdio.h>
#include <stdlib.h>
#include "dag.h"
#include "doubly_linked_list.h"
#include "utils.h"

dag *dag_create(int n) {
    dag *g = malloc(sizeof(dag));
    g->n = n;
    g->adj = malloc(sizeof(doubly_linked_list*) * n);
    g->rev = malloc(sizeof(doubly_linked_list*) * n);
    for(int i = 0; i < n; i++) {
        g->adj[i] = dll_create();
        g->rev[i] = dll_create();
    }
    return g;
}

void dag_add_edge(dag *g, int v, int w) {
    dll_push(g->adj[v], w);
    dll_push(g->rev[w], v);
}

void dag_print(dag *g) {
    printf("n: %d\n", g->n);
    printf("adj: [\n");
    if(g->n > 0) {
        printf("  0: ");
        dll_println(g->adj[0]);
        for(int i = 1; i < g->n; i++) {
            printf("  %d: ", i);
            dll_println(g->adj[i]);
        }
    }
    printf("]\nrev: [\n");
    if(g->n > 0) {
        printf("  0: ");
        dll_println(g->rev[0]);
        for(int i = 1; i < g->n; i++) {
            printf("  %d: ", i);
            dll_println(g->rev[i]);
        }
    }
    printf("]\n");
}

doubly_linked_list *dag_get_neighbors(dag *g, int v) {
    return g->adj[v];
}

doubly_linked_list *dag_get_rev_neighbors(dag *g, int v) {
    return g->rev[v];
}

dag *dag_copy(dag *g) {
    dag *ret = dag_create(g->n);
    if(g->n > 0) {
        for(int i = 0; i < g->n; i++) {
            ret->adj[i] = dll_copy(g->adj[i]);
            ret->rev[i] = dll_copy(g->rev[i]);
        }
    }
    return ret;
}

void dag_remove_edge(dag *g, int v, int w) {
    dll_remove(g->adj[v], w);
    dll_remove(g->rev[w], v);
}

