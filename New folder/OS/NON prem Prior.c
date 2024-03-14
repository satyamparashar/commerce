#include <stdio.h>
#define MAX_PROCESSES 10
typedef struct {
    int process_id;
    int priority;
    int burst_time;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void priority_nonpreemptive(Process processes[], int n) {
    int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    float average_waiting_time = 0, average_turnaround_time = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    waiting_time[0] = 0;
    turnaround_time[0] = processes[0].burst_time;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;

        average_waiting_time += waiting_time[i];
        average_turnaround_time += turnaround_time[i];
    }

    average_waiting_time /= n;
    average_turnaround_time /= n;

    // Display the schedule and timing information
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].priority,
               processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    int n;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter priority and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
    priority_nonpreemptive(processes, n);

    return 0;
}


