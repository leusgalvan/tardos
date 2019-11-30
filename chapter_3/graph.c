#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "doubly_linked_list.h"
#include "utils.h"

void _ensure_order(int *v, int *w);

graph *g_create(int n) {
    graph *g = malloc(sizeof(graph));
    g->n = n;
    g->adj = malloc(sizeof(doubly_linked_list*) * n);
    for(int i = 0; i < n; i++) {
        g->adj[i] = dll_create(cmp_ints);
    }
    return g;
}

void g_add_edge(graph *g, int v, int w) {
    int *p = malloc(sizeof(int));
    *p = w;
    int *q = malloc(sizeof(int));
    *q = v;
    dll_push(g->adj[v], p);
    dll_push(g->adj[w], q);
}

void g_print(graph *g) {
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
    printf("]\n");
}

doubly_linked_list *get_neighbors(graph *g, int v) {
    return g->adj[v];
}

void _ensure_order(int *v, int *w) {
    if(*v > *w) {
        int temp = *v;
        *v = *w;
        *w = temp;
    }
}

