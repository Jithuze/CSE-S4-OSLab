#include <stdio.h>

void main() {
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf("Enter No Of Process : ");
    scanf("%d", &NOP);
    y = NOP;

    for (i = 0; i < NOP; i++) {
        printf("Arrival Time : ");
        scanf("%d", &at[i]);
        printf("Burst Time : ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("Enter Time Quantum : ");
    scanf("%d", &quant);

    printf("\nPNo\t\tBT\t\tTAT\t\tWT");

    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0) {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1) {
            y--;
            printf("\nPno[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }

        if (i == NOP - 1)
            i = 0;
        else if (at[i + 1] <= sum)
            i++;
        else
            i = 0;
    }
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;

    printf("Average WT : %f ", avg_wt);
    printf("\nAverage TAT : %f ", avg_tat);
}

