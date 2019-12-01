#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "doubly_linked_list.h"
#include "utils.h"

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

void g_remove_edge(graph *g, int v, int w) {
    int *p = malloc(sizeof(int));
    *p = w;
    dll_remove(g->adj[v], p);
    *p = v;
    dll_remove(g->adj[w], p);
    free(p);
}

graph *g_copy(graph *g) {
    graph *ret = malloc(sizeof(graph));
    ret->n = g->n;
    ret->adj = malloc(sizeof(doubly_linked_list*) * g->n);
    for(int i = 0; i < g->n; i++) {
        ret->adj[i] = dll_copy(g->adj[i]);
    }
    return ret;
}

