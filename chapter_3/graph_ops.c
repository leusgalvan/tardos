#include <stdio.h>
#include <stdlib.h>
#include "graph_ops.h"
#include "graph.h"
#include "doubly_linked_list.h"
#include "utils.h"

graph *g_bfs_tree(graph *g, int root) {
    if(g->n == 0) return NULL;
    graph *t = g_create(g->n);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) visited[i] = 0;
    visited[root] = 1;
    doubly_linked_list *queue = dll_create();
    dll_append(queue, root);
    int current_node, current_neighbor;
    doubly_linked_list *neighbors;
    while(!dll_is_empty(queue)) {
        current_node = dll_pop(queue);
        neighbors = get_neighbors(g, current_node);
        while(!dll_is_empty(neighbors)) {
            current_neighbor = dll_pop(neighbors);
            if(visited[current_neighbor]) continue;
            visited[current_neighbor] = 1;
            dll_append(queue, current_neighbor);
            g_add_edge(t, current_node, current_neighbor); 
        }
    }
    return t;
}

doubly_linked_list **g_bfs_paths(graph *g, int root) {
    if(g->n == 0) return NULL;
    doubly_linked_list **paths = malloc(sizeof(doubly_linked_list*) * g->n);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) {
        visited[i] = 0;
        paths[i] = dll_create();
    }
    doubly_linked_list *queue = dll_create();
    dll_append(queue, root);
    visited[root] = 1;
    int current_node, current_neighbor;
    doubly_linked_list *neighbors;
    while(!dll_is_empty(queue)) {
        current_node = dll_pop(queue);
        dll_append(paths[current_node], current_node);
        neighbors = get_neighbors(g, current_node);
        while(!dll_is_empty(neighbors)) {
            current_neighbor = dll_pop(neighbors);
            if(visited[current_neighbor]) continue;
            visited[current_neighbor] = 1;
            paths[current_neighbor] = dll_copy(paths[current_node]);
            dll_append(queue, current_neighbor);
        }
    }
    return paths;
}

doubly_linked_list *g_find_path(graph *g, int v, int w) {
    if(g->n == 0) return NULL;
    doubly_linked_list *path = dll_create();
    int visited[g->n];
    int parent[g->n];
    for(int i = 0; i < g->n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    doubly_linked_list *queue = dll_create();
    dll_append(queue, v);
    visited[v] = 1;
    doubly_linked_list *neighbors;
    int current_neighbor;
    while(!dll_is_empty(queue)) {
        v = dll_pop(queue);
        neighbors = get_neighbors(g, v);
        while(!dll_is_empty(neighbors)) {
            current_neighbor = dll_pop(neighbors);
            if(current_neighbor == w) {
                parent[current_neighbor] = v;
                do {
                    dll_push(path, w);
                    w = parent[w];
                } while(w != -1);
                return path;
            }
            if(!visited[current_neighbor]) {
                visited[current_neighbor] = 1;
                dll_append(queue, current_neighbor);
                parent[current_neighbor] = v;
            }
        }
    }
    return NULL;
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
    for(int i = 0; i < g->n; i++) {
        doubly_linked_list *neighbors_t = get_neighbors(t, i);
        doubly_linked_list *neighbors_g = get_neighbors(g, i);
        if(dll_size(neighbors_t) < dll_size(neighbors_g)) {
            while(!dll_is_empty(neighbors_t)) {
                visited[dll_pop(neighbors_t)] = 1;
            }
            while(!dll_is_empty(neighbors_g)) {
                w = dll_pop(neighbors_g);
                if(visited[w] == 0) {
                    g_remove_edge(g2, i, w);
                    l = g_find_path(g2, i, w);
                    dll_append(l, i);
                    return l;
                }
            }
        }
    }
    return NULL;
}

