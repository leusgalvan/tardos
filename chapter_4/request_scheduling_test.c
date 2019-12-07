#include <stdio.h>
#include <stdlib.h>
#include "request_scheduling.h"
#include "../chapter_3/doubly_linked_list.h"

int main() {
    int n = 3;
    int *start_times = malloc(sizeof(int) * n);
    int *end_times = malloc(sizeof(int) * n);
    start_times[0] = 1; end_times[0] = 4;
    start_times[1] = 2; end_times[1] = 9;
    start_times[2] = 6; end_times[2] = 9;

    doubly_linked_list *sched = schedule(start_times, end_times, n);
    printf("Sched: ");
    dll_println(sched);
    return 0;
}

