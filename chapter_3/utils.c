#include <stdlib.h>
#include "utils.h"

 char *intToStr(void *elem) {
     char *s = malloc(sizeof(char) * 16);
     int i = *((int*)elem);
     return itoa(i, s, 10);
 }

int cmp_ints(void *v1, void *v2) {
    int x = *((int*) v1);
    int y = *((int*) v2);
    return x < y? -1: x > y? 1: 0;
}

int cmp_arrays(int *a1, int *a2, int n) {
    for(int i = 0; i < n; i++) {
        if(a1[i] < a2[i]) return -1;
        if(a1[i] > a2[i]) return 1;
    }
    return 0;
}

