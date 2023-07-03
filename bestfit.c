#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int block[m];
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &block[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n];
    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    int allocation[n];

    for (i = 0; i < n; i++) {
        int bestFitIdx = -1;
        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (bestFitIdx == -1 || block[j] < block[bestFitIdx]) {
                    bestFitIdx = j;
                }
            }
        }

        if (bestFitIdx != -1) {
            allocation[i] = bestFitIdx;
            block[bestFitIdx] -= process[i];
        } else {
            allocation[i] = -1;
        }
    }

    printf("\nPNo.\tPSize\tBNo.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (allocation[i] != -1) {
            printf("%d\t\t", allocation[i] + 1);
            printf("Fragment: %d\tBSize: %d\n", block[allocation[i]], block[allocation[i]] - process[i]);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
