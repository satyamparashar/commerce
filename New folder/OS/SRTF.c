#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_PROCESSES 10
typedef struct {
    int pid;  // Process ID
    int burst_time;  // Burst time
    int remaining_time;  // Remaining burst time
} Process;
void srtf_schedule(Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    int shortest = INT_MAX;
    int shortest_index = -1;

    printf("SRTF Schedule:\n");
    printf("Time\tProcess\n");

    while (completed < n) {
        shortest = INT_MAX;
        shortest_index = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].remaining_time < shortest && processes[i].burst_time > 0 && processes[i].pid != -1) {
                shortest = processes[i].remaining_time;
                shortest_index = i;  }}
        if (shortest_index == -1) {
            current_time++;
            continue;
        }
        processes[shortest_index].remaining_time--;
        current_time++;
        if (processes[shortest_index].remaining_time == 0) {
            printf("%d-%d\tP%d\n", current_time - 1, current_time, processes[shortest_index].pid);
            completed++;
            processes[shortest_index].pid = -1;   } }}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Maximum allowed: %d\n", MAX_PROCESSES);
        return 1;
    }
    Process processes[MAX_PROCESSES];
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;}
    srtf_schedule(processes, n);
    return 0;
}



