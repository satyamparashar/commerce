
#include <stdio.h>
#define MAX_FRAMES 3
void initializeFrames(int frames[MAX_FRAMES]) {
 for (int i = 0; i < MAX_FRAMES; i++) {
 frames[i] = -1; // -1 indicates an empty frame
 }
}
void printFrames(int frames[MAX_FRAMES]) {
 printf("Frames: ");
 for (int i = 0; i < MAX_FRAMES; i++) {
 if (frames[i] == -1) {
 printf("[ ] ");
 } else {
 printf("[%d] ", frames[i]);
 }
 }
 printf("\n");
}
int isPageInFrames(int frames[MAX_FRAMES], int page) {
 for (int i = 0; i < MAX_FRAMES; i++) {
 if (frames[i] == page) {
 return 1; // Page is already in frames
 }
 }
 return 0; // Page is not in frames
}
void fifoPageReplacement(int frames[MAX_FRAMES], int page, int *nextFrameIndex) {
 frames[*nextFrameIndex] = page;
 *nextFrameIndex = (*nextFrameIndex + 1) % MAX_FRAMES;}
int main() {
 int frames[MAX_FRAMES];
 initializeFrames(frames);
 int pageSequence[] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4};
 int pageSequenceSize = sizeof(pageSequence) / sizeof(pageSequence[0]);
 int pageFaults = 0;
 int nextFrameIndex = 0;
 printf("Page Replacement using FIFO:\n");
 for (int i = 0; i < pageSequenceSize; i++) {
 int currentPage = pageSequence[i];
 if (!isPageInFrames(frames, currentPage)) {
 printf("Page %d caused a page fault. ", currentPage);
 fifoPageReplacement(frames, currentPage, &nextFrameIndex);
 pageFaults++;
 } else {
 printf("Page %d is already in memory. ", currentPage);}
 printFrames(frames);}
 printf("\nTotal Page Faults: %d\n", pageFaults);
 return 0;
}


