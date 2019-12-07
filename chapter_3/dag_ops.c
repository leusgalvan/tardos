#include <stdio.h>
#include <stdlib.h>
#include "dag_ops.h"
#include "dag.h"
#include "utils.h"

doubly_linked_list *dag_top_sort(dag *g) {
    int incoming[g->n];
    doubly_linked_list *eligible = dll_create();
    for(int i = 0; i < g->n; i++) {
        incoming[i] = dll_size(dag_get_rev_neighbors(g, i));
        if(incoming[i] == 0) {
            dll_push(eligible, i);
        }
    }
    doubly_linked_list *ret = dll_create();
    int v, w;
    doubly_linked_list *neighbors;    
    while(!dll_is_empty(eligible)) {
        v = dll_pop(eligible);
        dll_append(ret, v);
        neighbors = dag_get_neighbors(g, v);
        while(!dll_is_empty(neighbors)) {
            w = dll_pop(neighbors);
            incoming[w]--;
            if(incoming[w] == 0) {
                dll_push(eligible, w);
            }
            dag_remove_edge(g, v, w);
        }
    }
    doubly_linked_list *cycle = dll_create(), *rev_neighbors;
    int visited[g->n];
    if(dll_size(ret) < g->n) {
        for(int i = 0; i < g->n; i++) {
            visited[i] = 0;
            if(incoming[i] > 0) {
                v = i;
            }
        }
        while(!visited[v]) {
            visited[v] = 1;
            dll_append(cycle, v);
            rev_neighbors = dag_get_rev_neighbors(g, v);
            v = dll_pop(rev_neighbors);
        }
        dll_append(cycle, v);
        while(dll_pop(cycle) != v);
        dll_push(cycle, v);
        return cycle;
    }
    return ret;
}

doubly_linked_list *dag_find_path(dag *g, int v, int w) {
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
        neighbors = dag_get_neighbors(g, v);
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
    return path;
}

dag *dag_bfs_tree(dag *g, int root) {
    if(g->n == 0) return NULL;
    dag *t = dag_create(g->n);
    int visited[g->n];
    for(int i = 0; i < g->n; i++) visited[i] = 0;
    visited[root] = 1;
    doubly_linked_list *queue = dll_create();
    dll_append(queue, root);
    int current_node, current_neighbor;
    doubly_linked_list *neighbors;
    while(!dll_is_empty(queue)) {
        current_node = dll_pop(queue);
        neighbors = dag_get_neighbors(g, current_node);
        while(!dll_is_empty(neighbors)) {
            current_neighbor = dll_pop(neighbors);
            if(visited[current_neighbor]) continue;
            visited[current_neighbor] = 1;
            dll_append(queue, current_neighbor);
            dag_add_edge(t, current_node, current_neighbor);
        }
    }

    return t;
}

