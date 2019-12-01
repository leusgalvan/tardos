#include <stdio.h>
#include <stdlib.h>
#include "graph_ops.h"
#include "graph.h"
#include "doubly_linked_list.h"
#include "utils.h"

graph *g_bfs_tree(graph *g, int v0) {
    if(g->n == 0) return NULL;

    graph *t = g_create(g->n);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) visited[i] = 0;
    visited[v0] = 1;

    doubly_linked_list *queue = dll_create(cmp_ints);
    int *p = malloc(sizeof(int));
    *p = v0;
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

doubly_linked_list **g_bfs_paths(graph *g, int v0) {
    if(g->n == 0) return NULL;

    doubly_linked_list **paths = malloc(sizeof(doubly_linked_list*) * g->n);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) {
        visited[i] = 0;
        paths[i] = dll_create(cmp_ints);
    }
    doubly_linked_list *queue = dll_create(cmp_ints);
    int *p = malloc(sizeof(int));
    *p = v0;
    dll_append(queue, p);
    visited[v0] = 1;
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

doubly_linked_list *g_find_path(graph *g, int v, int w) {
    if(g->n == 0) return NULL;
    doubly_linked_list *path = dll_create(cmp_ints);
    int visited[g->n];
    int parent[g->n];
    for(int i = 0; i < g->n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    doubly_linked_list *queue = dll_create(cmp_ints);
    int *p = malloc(sizeof(int));
    *p = v;
    dll_append(queue, p);
    visited[v] = 1;
    doubly_linked_list *neighbors;
    int current_neighbor;
    while(!dll_is_empty(queue)) {
        v = *((int*)dll_pop(queue));
        neighbors = get_neighbors(g, v);
        while(!dll_is_empty(neighbors)) {
            current_neighbor = *((int*)dll_pop(neighbors));
            if(current_neighbor == w) {
                parent[current_neighbor] = v;
                do {
                    p = malloc(sizeof(int));
                    *p = w;
                    dll_push(path, p);
                    w = parent[w];
                } while(w != -1);
                return path;
            }
            if(!visited[current_neighbor]) {
                visited[current_neighbor] = 1;
                p = malloc(sizeof(int));
                *p = current_neighbor;
                dll_append(queue, p);
                parent[current_neighbor] = v;
            }
        }
    }
    return NULL;
}

