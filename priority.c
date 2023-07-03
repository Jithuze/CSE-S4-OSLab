#include<stdio.h>

void main() {
    int i, j, n;
    int b[20], p[20], pr[20], g[20], t[20], w[20];
    float avgw = 0, avgt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Process Id: ");
        scanf("%d", &p[i]);
        printf("Burst Time: ");
        scanf("%d", &b[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
    }

    // Sort the processes based on priority (in ascending order)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pr[j] > pr[j + 1]) {
                // Swap priorities
                int temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                // Swap burst times
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    g[0] = b[0]; // Completion time of the first process is 0

    for (i = 1; i < n; i++) {
        g[i] = g[i - 1] + b[i - 1]; // Calculate completion time for each process
    }

    for (i = 0; i < n; i++) {
        t[i] = g[i] + b[i]; // Calculate turnaround time
        w[i] = t[i] - b[i]; // Calculate waiting time
        avgw += w[i]; // Calculate average waiting time
        avgt += t[i]; // Calculate average turnaround time
    }

    avgw = avgw / n;
    avgt = avgt / n;

    printf("PID\tBT\tPRT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], b[i], pr[i], g[i], t[i], w[i]);
    }

    printf("Average Wait Time: %f\n", avgw);
    printf("Average Turnaround Time: %f\n", avgt);
}
