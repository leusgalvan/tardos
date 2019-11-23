#include <stdio.h>
#include <stdlib.h>
#include "matching.h"

int main() {
    int n = 5;
    int** menPrefs = (int**) malloc(sizeof(int*) * n);
    int** womenPrefs = (int**) malloc(sizeof(int*) * n);

    for(int i = 0; i < n; i++) {
        menPrefs[i] = (int*) malloc(sizeof(int) * n);
        womenPrefs[i] = (int*) malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++) {
            menPrefs[i][j] = j;
            womenPrefs[i][j] = n-j-1;
        }
    }

    int* match = findMatching(n, menPrefs, womenPrefs);

    printf("\nMatching found:\n");
    for(int k = 0; k < n; k++) printf("%d -> %d\n", k, match[k]);
    return 0;
}