#include <stdio.h>
#include <stdlib.h>
void calculateSeekTime(int requestSequence[], int numRequests, int initialHeadPosition, int
direction) {
 int seekTime = 0;
 int currentHeadPosition = initialHeadPosition;
 printf("Seek Sequence: %d", currentHeadPosition);
 if (direction == 1) { // Move towards higher cylinder numbers
 // Go to the end of the disk
 for (int i = currentHeadPosition; i <= 199; i++) {
 printf(" -> %d", i);
 seekTime += abs(i - currentHeadPosition);
 currentHeadPosition = i;
 }
 // Go to the beginning of the disk
 for (int i = 199; i >= 0; i--) {
 printf(" -> %d", i);
 seekTime += abs(i - currentHeadPosition);
 currentHeadPosition = i;
 }
 } else { // Move towards lower cylinder numbers
 // Go to the beginning of the disk
 for (int i = currentHeadPosition; i >= 0; i--) {
 printf(" -> %d", i);
 seekTime += abs(i - currentHeadPosition);
 currentHeadPosition = i;
 }
 // Go to the end of the disk
 for (int i = 0; i <= 199; i++) {
 printf(" -> %d", i);
 seekTime += abs(i - currentHeadPosition);
 currentHeadPosition = i;
 }
 }
 printf("\nTotal Seek Time: %d\n", seekTime);
}
int main() {
 int numRequests;
 int initialHeadPosition;
 int direction;
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
 printf("Enter the direction (1 for towards higher cylinders, 0 for towards lower cylinders):");
 scanf("%d", &direction);
 calculateSeekTime(requestSequence, numRequests, initialHeadPosition, direction);
 free(requestSequence);
 return 0;
}



