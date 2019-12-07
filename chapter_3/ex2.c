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

    dll_println(cycle);

    return 0;
}

