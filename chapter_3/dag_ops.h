#ifndef DAG_OPS_H
#define DAG_OPS_H

#include "dag.h"
#include "doubly_linked_list.h"

doubly_linked_list *dag_top_sort(dag *g);
doubly_linked_list *dag_find_cycle(dag *g);
dag *dag_bfs_tree(dag *g, int root);
doubly_linked_list *dag_find_path(dag *g, int v, int w);

#endif // DAG_OPS_H
