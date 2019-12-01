#include <stdio.h>
#include <stdlib.h>
#include "dag.h"
#include "utils.h"
#include "dag_ops.h"

int main() {
    dag *g = dag_create(5);
    dag_add_edge(g, 4, 2);
    dag_add_edge(g, 4, 0);
    dag_add_edge(g, 4, 1);
    dag_add_edge(g, 1, 0);
    dag_add_edge(g, 3, 4);

    int *ts = top_sort(g);
    
    for(int i = 0; i < g->n; i++) printf("%d ", ts[i]);
    printf("\n");

    return 0;
}
