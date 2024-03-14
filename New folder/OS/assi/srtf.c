#include <stdio.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_arrival_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void shortest_remaining_time_first(Process processes[], int n) {
    sort_by_arrival_time(processes, n);

    int current_time = 0;
    int completed_processes = 0;

    printf("Execution Order: ");

    while (completed_processes < n) {
        int shortest_burst_index = -1;
        int shortest_burst = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_burst_time < shortest_burst && processes[i].remaining_burst_time > 0) {
                shortest_burst = processes[i].remaining_burst_time;
                shortest_burst_index = i;
            }
        }

        if (shortest_burst_index == -1) {
            current_time++;
            continue;
        }

        printf("%d ", processes[shortest_burst_index].process_id);

        processes[shortest_burst_index].remaining_burst_time--;
        current_time++;

        if (processes[shortest_burst_index].remaining_burst_time == 0) {
            completed_processes++;
        }
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].remaining_burst_time = processes[i].burst_time;
    }

    printf("SRTF Schedule:\n");
    shortest_remaining_time_first(processes, n);

    return 0;
}
