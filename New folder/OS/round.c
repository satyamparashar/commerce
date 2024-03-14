#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

void roundRobin(Process processes[], int n, int quantum) {
    int time = 0;
    int i;
    int completed = 0;

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int execution_time = (processes[i].remaining_time < quantum) ? processes[i].remaining_time : quantum;
                processes[i].remaining_time -= execution_time;
                time += execution_time;

                printf("Process %d executed for %d units of time.\n", processes[i].process_id, execution_time);

                if (processes[i].remaining_time == 0) {
                    completed++;
                    printf("Process %d completed at time %d.\n", processes[i].process_id, time);
                }
            }
        }
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes. Please enter a number between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }

    Process processes[MAX_PROCESSES];

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i].process_id = i + 1;
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    roundRobin(processes, n, quantum);

    return 0;
}
