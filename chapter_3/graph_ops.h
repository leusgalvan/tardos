#ifndef GRAPH_OPS_H
#define GRAPH_OPS_H

#include "graph.h"
#include "doubly_linked_list.h"

graph *g_bfs_tree(graph *g);
doubly_linked_list **g_bfs_paths(graph *g);

#endif // GRAPH_OPS_H

