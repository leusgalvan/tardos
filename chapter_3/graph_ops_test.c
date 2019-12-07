#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graph_ops.h"
#include "doubly_linked_list.h"
#include "utils.h"

graph *make_graph(int n);

int main() {
    int n = 8;
    graph *g = make_graph(n);

    printf("Graph:\n");
    g_print(g);

    graph *t = g_bfs_tree(g, 1);
    printf("BFS Tree:\n");
    g_print(t);

    g = make_graph(n);
    doubly_linked_list **paths = g_bfs_paths(g, 1);
    printf("BFS Paths:\n");
    for(int i = 0; i < n; i++) {
        dll_println(paths[i]);
    }

    g = make_graph(n);
    doubly_linked_list *path = g_find_path(g, 1, 0);
    printf("Path between 1 and 0: ");
    dll_println(path);
    return 0;
}

graph *make_graph(int n) {
    graph *g = g_create(n);
    g_add_edge(g, 0, 1);
    g_add_edge(g, 0, 2);
    g_add_edge(g, 1, 2);
    g_add_edge(g, 1, 3);
    g_add_edge(g, 1, 4);
    g_add_edge(g, 3, 4);
    g_add_edge(g, 2, 4);
    g_add_edge(g, 2, 6);
    g_add_edge(g, 2, 7);
    g_add_edge(g, 4, 5);
    g_add_edge(g, 6, 7);
    return g;
}
