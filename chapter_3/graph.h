#ifndef GRAPH_H
#define GRAPH_H

#include "../chapter_2/linked_list.h"

typedef struct {
    int n;
    linked_list **adj;
} graph;

graph g_create(int n);
void g_add_edge(graph g, int v, int w);
void g_print(graph g);

#endif // GRAPH_H
