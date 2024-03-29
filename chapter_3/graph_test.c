#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "doubly_linked_list.h"
#include "utils.h"

int main() {
    graph *g = g_create(3);
    g_add_edge(g, 0, 1);
    g_add_edge(g, 0, 2);
    g_add_edge(g, 1, 2);
    g_print(g);

    printf("\nNeighbors of node 0: ");
    dll_println(get_neighbors(g, 0));    

    graph *copy = g_copy(g);
    g_print(copy);

    return 0;
}

