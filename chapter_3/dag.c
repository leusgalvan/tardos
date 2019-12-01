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
        g->adj[i] = dll_create(cmp_ints);
        g->rev[i] = dll_create(cmp_ints);
    }
    return g;
}

void dag_add_edge(dag *g, int v, int w) {
    int *p = malloc(sizeof(int));
    *p = w;
    int *q = malloc(sizeof(int));
    *q = v;
    dll_push(g->adj[v], p);
    dll_push(g->rev[w], q);
}

void dag_print(dag *g) {
    printf("n: %d\n", g->n);
    printf("adj: [\n");
    if(g->n > 0) {
        printf("  0: ");
        dll_println(g->adj[0], intToStr);
        for(int i = 1; i < g->n; i++) {
            printf("  %d: ", i);
            dll_println(g->adj[i], intToStr);
        }
    }
    printf("rev: [\n");
    if(g->n > 0) {
        printf("  0: ");
        dll_println(g->rev[0], intToStr);
        for(int i = 1; i < g->n; i++) {
            printf("  %d: ", i);
            dll_println(g->rev[i], intToStr);
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

