#ifndef DAG_H
#define DAG_H

#include "doubly_linked_list.h"

typedef struct {
    int n;
    doubly_linked_list **adj;
    doubly_linked_list **rev;
} dag;

dag *dag_create(int n);
void dag_add_edge(dag *g, int v, int w);
void dag_print(dag *g);
doubly_linked_list *dag_get_neighbors(dag *g, int v);
doubly_linked_list *dag_get_rev_neighbors(dag *g, int v);
dag *dag_copy(dag *g);
void dag_remove_edge(dag *g, int v, int w);

#endif // DAG_H

