#include <stdio.h>
#include <stdlib.h>

int **findSums(int *a, int n);
int **_findSums(int *a, int n, int **table);
void printTable(int **table, int n);

int main() {
    int n = 5;
    int a[] = {6, 3, 5, 2, 7};
    int **b = findSums(a, n);
    printTable(b, n);
    return 0;
}

int **findSums(int *a, int n) {
    int **table = (int**) malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++) {
        table[i] = (int*) malloc(sizeof(int) * n);
    }

    return _findSums(a, n, table);
}

int **_findSums(int *a, int n, int **table) {
    if(n > 0) {
        for(int i = 0; i < n; i++) {
           table[i][i] = a[i];
           for(int j = i + 1; j < n; j++) {
                table[i][j] = table[i][j-1] + a[j];
           }
        }
    }
    return table;
}

void printTable(int **table, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%2d ", j < i? -1: table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
