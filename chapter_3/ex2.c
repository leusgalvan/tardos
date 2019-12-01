#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graph_ops.h"
#include "utils.h"
#include "doubly_linked_list.h"

doubly_linked_list *find_cycle(graph *g);

int main() {
    int n = 5;
    graph *g = g_create(n);
    g_add_edge(g, 0, 1);
    g_add_edge(g, 1, 2);
    g_add_edge(g, 2, 3);
    g_add_edge(g, 3, 1);
    g_add_edge(g, 3, 4);

    doubly_linked_list *cycle = find_cycle(g);

    dll_println(cycle, intToStr);

    return 0;
}

doubly_linked_list *find_cycle(graph *g) {
    if(g->n == 0) return NULL;
    graph *g1 = g_copy(g);
    graph *g2 = g_copy(g);
    graph *t = g_bfs_tree(g1, 0);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) visited[i] = 0;
    int w;
    doubly_linked_list *l;
    int *p = malloc(sizeof(int));
    for(int i = 0; i < g->n; i++) {
        doubly_linked_list *neighbors_t = get_neighbors(t, i);
        doubly_linked_list *neighbors_g = get_neighbors(g, i);

        if(dll_size(neighbors_t) < dll_size(neighbors_g)) {
            while(!dll_is_empty(neighbors_t)) {
                visited[*((int*)dll_pop(neighbors_t))] = 1;
            }
            while(!dll_is_empty(neighbors_g)) {
                w = *((int*)dll_pop(neighbors_g));
                if(visited[w] == 0) {
                    g_remove_edge(g2, i, w);
                    l = g_find_path(g2, i, w);
                    *p = i;
                    dll_append(l, p);
                    return l;
                                  
                }
            }
        }
    }
    return NULL;
}

