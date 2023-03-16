#include <stdio.h>

int main() {
    int pid[30], bt[30], c[30], tat[30], wt[30], n, i, j, temp1, temp;
    float sum_wt, avg_wt;

    printf("Enter the number of processes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter the process id : ");
        scanf("%d", &pid[i]);
        printf("\nEnter the burst time : ");
        scanf("%d", &bt[i]);
    }

    printf("\n\n");

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp1 = pid[i];
                pid[i] = pid[j];
                pid[j] = temp1;
            }
        }
    }

    c[0] = bt[0];

    for(i = 0; i < n; i++) {
        c[i] = c[i - 1] + bt[i];
    }

    sum_wt = 0;

    for(i = 0; i < n; i++) {
        tat[i] = c[i];
        wt[i] = tat[i] - bt[i];
        sum_wt = sum_wt + wt[i];
    }

    avg_wt = sum_wt / n;

    printf("\nThe Average waiting time : %f ", avg_wt);
    printf("\n\n\t\t BT \tCT\tTAT\tWT ");

    for(i = 0; i < n; i++) {
        printf("\nProcess[%d]\t%d\t%d\t%d\t%d\n", pid[i], bt[i], c[i], tat[i], wt[i]);
    }

    return 0;
}

