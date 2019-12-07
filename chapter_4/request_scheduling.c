#include <stdio.h>
#include <stdlib.h>
#include "request_scheduling.h"
#include "../chapter_3/doubly_linked_list.h"

int cmp_requests(const void*, const void*);

typedef struct {int start; int end; int i;} request;

doubly_linked_list *schedule(int *start_times, int *end_times, int n) {
    request *requests = malloc(sizeof(request) * n);
    for(int i = 0; i < n; i++) {
        requests[i].start = start_times[i];
        requests[i].end = end_times[i];
        requests[i].i = i;
    }
    qsort(requests, n, sizeof(request), cmp_requests);
    doubly_linked_list *reqs_to_process = dll_create();
    for(int i = 0; i < n; i++) {
        dll_append(reqs_to_process, requests[i].i);
    }
    doubly_linked_list *ret = dll_create();
    int current_request_i;
    while(!dll_is_empty(reqs_to_process)) {
        current_request_i = dll_pop(reqs_to_process);
        dll_append(ret, current_request_i);
        while(!dll_is_empty(reqs_to_process) &&
               start_times[dll_peek_first(reqs_to_process)] < end_times[current_request_i]) {
            dll_pop(reqs_to_process);
        }
    }
    return ret;
}

int cmp_requests(const void *req_ptr_1, const void *req_ptr_2) {
    request req_1 = *((request*) req_ptr_1);
    request req_2 = *((request*) req_ptr_2);
    return req_1.end < req_2.end? -1: req_1.end > req_2.end? 1: 0;
}
