#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    graph g = g_create(3);
    g_add_edge(g, 0, 1);
    g_add_edge(g, 0, 2);
    g_add_edge(g, 1, 2);
    g_print(g);

    return 0;
}
