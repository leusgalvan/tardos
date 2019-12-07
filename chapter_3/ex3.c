#include <stdio.h>
#include <stdlib.h>
#include "dag_ops.h"
#include "dag.h"
#include "utils.h"
#include "doubly_linked_list.h"

doubly_linked_list *tsort(dag *g, int *has_cycle);

int main() {
    int n = 5;
    dag *dag_with_cycle = dag_create(n);
    dag_add_edge(dag_with_cycle, 0, 1);
    dag_add_edge(dag_with_cycle, 1, 2);
    dag_add_edge(dag_with_cycle, 2, 3);
    dag_add_edge(dag_with_cycle, 3, 1);
    dag_add_edge(dag_with_cycle, 3, 4);
    doubly_linked_list *cycle = dag_top_sort(dag_with_cycle);
    printf("cycle: ");
    dll_println(cycle);

    dag *dag_without_cycle = dag_create(n);
    dag_add_edge(dag_without_cycle, 4, 2);
    dag_add_edge(dag_without_cycle, 4, 0);
    dag_add_edge(dag_without_cycle, 4, 1);
    dag_add_edge(dag_without_cycle, 1, 3);
    doubly_linked_list *ord = dag_top_sort(dag_without_cycle);
    printf("ord: ");
    dll_println(ord);
}

