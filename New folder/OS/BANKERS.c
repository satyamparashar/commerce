#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocated[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

// Function to check if the system is in a safe state
int isSafe(int processes, int resources) {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};

    // Initialize work array with available resources
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < processes) {
        int found = 0;

        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == resources) {
                    // Process can complete, release resources
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocated[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if (!found) {
            // No process found, the system is in an unsafe state
            return 0;
        }
    }

    // If all processes finish, the system is in a safe state
    return 1;
}

// Function to request resources by a process
void requestResources(int processes, int resources, int process, int request[]) {
    for (int i = 0; i < resources; i++) {
        if (request[i] > need[process][i] || request[i] > available[i]) {
            printf("Invalid request. The request exceeds the maximum need or available resources.\n");
            return;
        }
    }

    // Try allocating the resources temporarily
    for (int i = 0; i < resources; i++) {
        available[i] -= request[i];
        allocated[process][i] += request[i];
        need[process][i] -= request[i];
    }

    // Check if the system remains in a safe state after the request
    if (isSafe(processes, resources)) {
        printf("Request granted. The system is in a safe state.\n");
    } else {
        // Rollback the allocation if the system becomes unsafe
        for (int i = 0; i < resources; i++) {
            available[i] += request[i];
            allocated[process][i] -= request[i];
            need[process][i] += request[i];
        }
        printf("Request denied. The system would be in an unsafe state.\n");
    }
}

int main() {
    int processes, resources;

    // Input the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    // Input the maximum resources matrix
    printf("Enter the maximum resources matrix:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input the allocated resources matrix
    printf("Enter the allocated resources matrix:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocated[i][j]);
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    // Input the available resources vector
    printf("Enter the available resources vector:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    // Check if the initial state is safe
    if (isSafe(processes, resources)) {
        printf("The initial state is safe.\n");
    } else {
        printf("The initial state is unsafe.\n");
        return 1;
    }

    // Demonstrate resource request
    int process, request[MAX_RESOURCES];

    printf("Enter the process number requesting resources: ");
    scanf("%d", &process);

    printf("Enter the resource request (e.g., R1 R2 ...): ");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &request[i]);
    }

    requestResources(processes, resources, process, request);

    return 0;
}
