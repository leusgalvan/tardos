#include <stdio.h>
#include <stdlib.h>
#include "dag.h"
#include "utils.h"
#include "dag_ops.h"
#include "doubly_linked_list.h"

int main() {
    dag *g = dag_create(5);
    dag_add_edge(g, 4, 2);
    dag_add_edge(g, 4, 0);
    dag_add_edge(g, 4, 1);
    dag_add_edge(g, 1, 0);
    dag_add_edge(g, 3, 4);
    printf("Graph g:\n");
    dag_print(g);
    doubly_linked_list *ts = dag_top_sort(g);
    printf("Topsort for graph g: ");
    dll_println(ts);
    printf("\n********************************\n\n");

    dag *g2 = dag_create(5);
    dag_add_edge(g2, 0, 1);
    dag_add_edge(g2, 1, 2);
    dag_add_edge(g2, 2, 3);
    dag_add_edge(g2, 3, 4);
    dag_add_edge(g2, 4, 0);
    printf("Graph g2:\n");
    dag_print(g2);
    dag *t = dag_bfs_tree(g2, 0);
    printf("BFS tree for graph g2:\n");
    dag_print(t);
    printf("\n********************************\n\n");

    dag *g3 = dag_create(5);
    dag_add_edge(g3, 0, 1);
    dag_add_edge(g3, 1, 2);
    dag_add_edge(g3, 1, 3);
    dag_add_edge(g3, 1, 4);
    dag_add_edge(g3, 3, 4);
    printf("Graph g3:\n");
    dag_print(g3);
    doubly_linked_list *path = dag_find_path(g3, 0, 4);
    printf("Path from 0 to 4 in g3:\n");
    dll_println(path);
    printf("\n********************************\n\n");

    dag *g4 = dag_create(5);
    dag_add_edge(g4, 0, 1);
    dag_add_edge(g4, 1, 2);
    dag_add_edge(g4, 2, 3);
    dag_add_edge(g4, 3, 4);
    printf("Graph g4 before removing edge (2,3):\n");
    dag_print(g4);
    dag_remove_edge(g4, 2, 3);
    printf("Graph g4 after removing edge (2,3):\n");
    dag_print(g4);
    printf("\n********************************\n\n");

    dag *g5 = dag_create(5);
    dag_add_edge(g5, 0, 1);
    dag_add_edge(g5, 1, 2);
    dag_add_edge(g5, 2, 3);
    dag_add_edge(g5, 3, 1);
    dag_add_edge(g5, 3, 4);
    printf("Graph g5:\n");
    dag_print(g5);
    doubly_linked_list *cycle = dag_find_cycle(g5);
    printf("Cycle in g5:\n");
    dll_println(cycle);
    
    dag *g6 = dag_create(5);
    dag_add_edge(g6, 0, 1);
    dag_add_edge(g6, 1, 2);
    dag_add_edge(g6, 2, 3);
    dag_add_edge(g6, 3, 1);
    dag_add_edge(g6, 3, 4);
    printf("Graph g6:\n");
    dag_print(g6);
    doubly_linked_list *empty_ts = dag_top_sort(g6);
    printf("Topsort for graph g6: ");
    dll_println(empty_ts);

    return 0;
}
