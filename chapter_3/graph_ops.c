#include <stdio.h>
#include <stdlib.h>
#include "graph_ops.h"
#include "graph.h"
#include "doubly_linked_list.h"
#include "utils.h"

graph *g_bfs_tree(graph *g) {
    if(g->n == 0) return NULL;

    graph *t = g_create(g->n);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) visited[i] = 0;
    visited[0] = 1;

    doubly_linked_list *queue = dll_create(cmp_ints);
    int *p = malloc(sizeof(int));
    *p = 0;
    dll_append(queue, p);
    
    int root, current_neighbor, *q;
    doubly_linked_list *neighbors;
    while(!dll_is_empty(queue)) {
        root = *((int*)dll_pop(queue));
        neighbors = get_neighbors(g, root);
        while(!dll_is_empty(neighbors)) {
            current_neighbor = *((int*)dll_pop(neighbors));
            if(visited[current_neighbor]) continue;
            visited[current_neighbor] = 1;
            q = malloc(sizeof(int));
            *q = current_neighbor;
            dll_append(queue, q);
            g_add_edge(t, root, current_neighbor); 
        }
    }

    return t;
}

doubly_linked_list **g_bfs_paths(graph *g) {
    if(g->n == 0) return NULL;

    doubly_linked_list **paths = malloc(sizeof(doubly_linked_list*) * g->n);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) {
        visited[i] = 0;
        paths[i] = dll_create(cmp_ints);
    }
    doubly_linked_list *queue = dll_create(cmp_ints);
    int *p = malloc(sizeof(int));
    *p = 0;
    dll_append(queue, p);
    visited[0] = 1;
    int root, current_neighbor, *q;
    doubly_linked_list *neighbors;
    while(!dll_is_empty(queue)) {
        root = *((int*)dll_pop(queue));
        p = malloc(sizeof(int));
        *p = root;
        dll_append(paths[root], p);
        neighbors = get_neighbors(g, root);
        while(!dll_is_empty(neighbors)) {
            current_neighbor = *((int*)dll_pop(neighbors));
            if(visited[current_neighbor]) continue;
            visited[current_neighbor] = 1;
            paths[current_neighbor] = dll_copy(paths[root]);
            q = malloc(sizeof(int));
            *q = current_neighbor;
            dll_append(queue, q);
        }
    }
    return paths;
}

