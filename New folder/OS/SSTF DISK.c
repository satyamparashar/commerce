#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include the header file for INT_MAX
// Function to calculate seek time using SSTF algorithm
void calculateSeekTime(int requestSequence[], int numRequests, int initialHeadPosition) {
 int seekTime = 0;
 int currentHeadPosition = initialHeadPosition;
 int visited[numRequests];
 for (int i = 0; i < numRequests; i++) {
 visited[i] = 0; // Initialize all requests as not visited
 }
 printf("Seek Sequence: %d", currentHeadPosition);
 for (int i = 0; i < numRequests; i++) {
 int minDistance = INT_MAX; // Use INT_MAX from <limits.h>
 int nextRequest = -1;
 // Find the request with the shortest seek time
 for (int j = 0; j < numRequests; j++) {
 if (!visited[j]) {
 int distance = abs(requestSequence[j] - currentHeadPosition);
 if (distance < minDistance) {
 minDistance = distance;
 nextRequest = j;
 }
 }
 }
 visited[nextRequest] = 1; // Mark the request as visited
 seekTime += minDistance;
 currentHeadPosition = requestSequence[nextRequest];
 printf(" -> %d", currentHeadPosition);
 }
 printf("\nTotal Seek Time: %d\n", seekTime);
}
int main() {
 int numRequests;
 int initialHeadPosition;
 printf("Enter the number of requests: ");
 scanf("%d", &numRequests);
 int *requestSequence = (int *)malloc(numRequests * sizeof(int));
 if (requestSequence == NULL) {
 fprintf(stderr, "Memory allocation failed.\n");
 return 1; // Exit with an error code
 }
 printf("Enter the request sequence:\n");
 for (int i = 0; i < numRequests; i++) {
 scanf("%d", &requestSequence[i]);
 }
 printf("Enter the initial head position: ");
 scanf("%d", &initialHeadPosition);
 calculateSeekTime(requestSequence, numRequests, initialHeadPosition);
 free(requestSequence);
 return 0;}



