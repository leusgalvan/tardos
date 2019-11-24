#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../chapter_2/linked_list.h"

int main() {
    graph g = g_create(3);
    g_add_edge(g, 0, 1);
    g_add_edge(g, 0, 2);
    g_add_edge(g, 1, 2);
    g_print(g);

    printf("\nNeighbors of node 0: ");
    ll_print(get_neighbors(g, 0));    
    return 0;
}
