#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../chapter_2/linked_list.h"

void _ensure_order(int *v, int *w);

graph g_create(int n) {
    graph g;
    g.n = n;
    g.adj = malloc(sizeof(linked_list*) * n);
    for(int i = 0; i < n; i++) {
        g.adj[i] = ll_create();
    }
    return g;
}

void g_add_edge(graph g, int v, int w) {
    _ensure_order(&v, &w);
    int *p = malloc(sizeof(int));
    *p = w;
    ll_push(g.adj[v], p);
}

void g_print(graph g) {
    printf("n: %d\n", g.n);
    printf("adj: [\n");
    if(g.n > 0) {
        printf("  0: ");
        ll_print(g.adj[0]);
        for(int i = 1; i < g.n; i++) {
            printf("  %d: ", i);
            ll_print(g.adj[i]);
        }
    }
    printf("]\n");
}

linked_list *get_neighbors(graph g, int v) {
    return g.adj[v];
}

void _ensure_order(int *v, int *w) {
    if(*v > *w) {
        int temp = *v;
        *v = *w;
        *w = temp;
    }
}
