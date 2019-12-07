#include <stdio.h>
#include <stdlib.h>
#include "dag.h"
#include "doubly_linked_list.h"
#include "utils.h"

int main() {
    dag *g = dag_create(3);
    dag_add_edge(g, 0, 1);
    dag_add_edge(g, 0, 2);
    dag_add_edge(g, 1, 2);
    dag_print(g);

    printf("\nNeighbors of node 0: ");
    dll_println(dag_get_neighbors(g, 0));    
    return 0;
}

