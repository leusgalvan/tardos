#include <stdio.h>
#include <stdlib.h>
#include "matching.h"

int prefers(int*, int, int, int);
int findFreeMan(int, int*, int**);
int findHighestRankedUnproposedWoman(int*, int*, int);
void _printArray(int*, int, int);
void printArray(int**, int, char*);

int* findMatching(int n, int** menPreferences, int** womenPreferences) {
    printf("Finding stable matching\n");
    printArray(menPreferences, n, "Men preferences");
    printArray(womenPreferences, n, "Women preferences");
    int** menProposals = (int**) malloc(sizeof(int*) * n);
    int* menMatching = (int*) malloc(sizeof(int) * n);
    int* womenMatching = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        menProposals[i] = (int*) malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++) {
            menProposals[i][j] = 0;
        }
        menMatching[i] = -1;
        womenMatching[i] = -1;
    }
    int m;
    while((m = findFreeMan(n, menMatching, menProposals)) > -1) {
        printf("Evaluating man %d\n", m);
        int w = findHighestRankedUnproposedWoman(menPreferences[m], menProposals[m], n);
        printf("  Highest ranked woman: %d\n", w);
        int m2 = womenMatching[w];
        if(m2 == -1) {
            printf("  Woman is free\n");
            printf("  Adding match: (%d, %d)\n", m, w);
            menMatching[m] = w;
            womenMatching[w] = m;
        } else if(m == prefers(womenPreferences[w], n, m, m2)) {
            printf("  Woman does not prefer her current match %d\n", m2);
            printf("  Adding match: (%d, %d)\n", m, w);
            menMatching[m] = w;
            womenMatching[w] = m;
            menMatching[m2] = -1;
        }
        menProposals[m][w] = 1;
    }
    return menMatching;
}

int findHighestRankedUnproposedWoman(int* menPreferences, int* menProposals, int n) {
    for(int i = 0; i < n; i++) {
        int w = menPreferences[i];
        if(!menProposals[w]) return w;
    }
    return -1;
}

int prefers(int* a, int n, int m, int m2) {
    for(int i = 0; i < n; i++) {
        if(a[i] == m) return m;
        if(a[i] == m2) return m2;
    }
    return -1;
}

int findFreeMan(int n, int* menMatching, int** menProposals) {
    for(int i = 0; i < n; i++) {
        if(menMatching[i] == -1) {
           return i;
        }
    }
    return -1;
}

void _printArray(int *a, int n, int pos) {
    printf("  %d: [", pos);
    if(n > 0) printf("%d", a[0]);
    for(int i = 1; i < n; i++) {
        printf(", %d", a[i]);
    }
    printf("]");
}
void printArray(int** a, int n, char* name) {
    printf("%s: [\n", name);
    if(n > 0) _printArray(a[0], n, 0);
    for(int i = 1; i < n; i++) {
        printf("\n");
        _printArray(a[i], n, i);
    }
    printf("\n]\n");
}