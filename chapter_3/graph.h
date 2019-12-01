#ifndef GRAPH_H
#define GRAPH_H

#include "doubly_linked_list.h"

typedef struct {
    int n;
    doubly_linked_list **adj;
} graph;

graph *g_create(int n);
void g_add_edge(graph *g, int v, int w);
void g_print(graph *g);
doubly_linked_list *get_neighbors(graph *g, int v);
void g_remove_edge(graph *g, int v, int w);
graph *g_copy(graph *g);

#endif // GRAPH_H

