#include <stdio.h>
#include "../include/deadlock.h"
#define MAX 10
int main() {

    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[MAX][MAX], max[MAX][MAX], avail[MAX];

    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for(int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for(int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(int j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    checkSafeState(n, m, alloc, max, avail);

    return 0;
}