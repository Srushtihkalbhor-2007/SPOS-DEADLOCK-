#include <stdio.h>
#include "../include/deadlock.h"

void checkSafeState(int n, int m, int alloc[][10], int max[][10], int avail[]) {

    int need[10][10];
    int finish[10] = {0};
    int safeSeq[10];

    // Calculate Need matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Print Need matrix
    printf("\nNeed Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int count = 0;

    printf("\n--- Process Execution ---\n");

    while(count < n) {
        int found = 0;

        for(int i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int canRun = 1;

                for(int j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if(canRun) {
                    printf("\nP%d is executing...\n", i);

                    printf("Resources allocated: ");
                    for(int j = 0; j < m; j++) {
                        printf("%d ", alloc[i][j]);
                    }
                    printf("\n");

                    // Release resources
                    for(int j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }

                    printf("P%d finished, releasing resources...\n", i);

                    printf("Available now: ");
                    for(int j = 0; j < m; j++) {
                        printf("%d ", avail[j]);
                    }
                    printf("\n");

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nDeadlock detected!\n");

            printf("Processes stuck:\n");
            for(int i = 0; i < n; i++) {
                if(finish[i] == 0) {
                    printf("P%d waiting (Need: ", i);
                    for(int j = 0; j < m; j++) {
                        printf("%d ", need[i][j]);
                    }
                    printf(")\n");
                }
            }
            return;
        }
    }

    printf("\nSystem is in SAFE state\nSafe sequence: ");
    for(int i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if(i != n-1) printf(" -> ");
    }
    printf("\n");
}