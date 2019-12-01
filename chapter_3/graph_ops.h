#ifndef GRAPH_OPS_H
#define GRAPH_OPS_H

#include "graph.h"
#include "doubly_linked_list.h"

graph *g_bfs_tree(graph *g, int v0);
doubly_linked_list **g_bfs_paths(graph *g, int v0);
doubly_linked_list *g_find_path(graph *g, int v, int w);

#endif // GRAPH_OPS_H

