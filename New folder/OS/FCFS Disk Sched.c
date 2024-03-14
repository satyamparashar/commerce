#include <stdio.h>
#include <stdlib.h>
void calculateSeekTime(int requestSequence[], int numRequests, int initialHeadPosition) {
 int seekTime = 0;
 int currentHeadPosition = initialHeadPosition;
 printf("Seek Sequence: %d", currentHeadPosition);
 for (int i = 0; i < numRequests; i++) {
 int distance = abs(requestSequence[i] - currentHeadPosition);
 seekTime += distance;
 currentHeadPosition = requestSequence[i];
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
 return 0;
}
