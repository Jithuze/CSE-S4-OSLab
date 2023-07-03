#include <stdio.h>

void main() {
    int i, n, tq, remain, flag = 0, time = 0;
    int wt = 0, tat = 0;
    int at[20], bt[20], rt[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    while (remain != 0) {
        for (i = 0; i < n; i++) {
            if (rt[i] > tq) {
                time += tq;
                rt[i] -= tq;
            } else if (rt[i] <= tq && rt[i] > 0) {
                time += rt[i];
                rt[i] = 0;
                flag = 1;
            }

            if (rt[i] == 0 && flag == 1) {
                remain--;
                printf("P%d\t%d\t\t%d\n", i + 1, time - at[i], time - at[i] - bt[i]);
                wt += time - at[i] - bt[i];
                tat += time - at[i];
                flag = 0;
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f", (float) wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float) tat / n);
}
