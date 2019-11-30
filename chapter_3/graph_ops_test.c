#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graph_ops.h"
#include "doubly_linked_list.h"
#include "utils.h"

int main() {
    int n = 8;
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

    printf("Grah:\n");
    g_print(g);

    graph *t = g_bfs_tree(g);
    printf("BFS Tree:\n");
    g_print(t);

    doubly_linked_list **paths = g_bfs_paths(g);
    printf("BFS Paths:\n");
    for(int i = 0; i < n; i++) {
        dll_println(paths[i], intToStr);
    }
    return 0;
}
