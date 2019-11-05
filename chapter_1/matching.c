#include <stdio.h>
#include <stdlib.h>

int* findMatching(int, int**, int**);
int prefers(int*, int, int, int);
int findFreeMan(int, int*, int**);
int findHighestRankedUnproposedWoman(int*, int*, int);

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

    for(int k = 0; k < n; k++) printf("%d ", match[k]);
    printf("\n");
    return 0;
}

int* findMatching(int n, int** menPreferences, int** womenPreferences) {
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
