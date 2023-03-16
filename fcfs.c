#include <stdio.h>

int main() {
    int pid[30], at[30], bt[30], tat[30], ct[30], wt[30], tat_wt = 0, n, i, j, temp, temp1, temp2;
    float sum_wt, avg_wt;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("\nEnter the process id: ");
        scanf("%d", &pid[i]);
        printf("Enter the arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter the burst time: ");
        scanf("%d", &bt[i]);
    }
    
    printf("\n\t\t\tArrival Time\tBurst Time");
    for(i = 0; i < n; i++) {
        printf("\nProcess[%d]\t\t%d\t\t%d", pid[i], at[i], bt[i]);
    }
    printf("\n\n");
    
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;

                temp2 = pid[i];
                pid[i] = pid[j];
                pid[j] = temp2;
            }
        }
    }
    
    ct[0] = bt[0] + at[0];
    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }
    
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        tat_wt += wt[i];
    }
    avg_wt = (float) tat_wt / n;
    
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time");
    for(i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", pid[i], at[i], bt[i], wt[i], ct[i], tat[i]);
    }
    printf("\n\nAverage waiting time: %.2f", avg_wt);
    
    return 0;
}

