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
int getLRUPage(int pageOrder[MAX_FRAMES]) {
 return pageOrder[MAX_FRAMES - 1];
}
void updatePageOrder(int pageOrder[MAX_FRAMES], int currentPage) {
 // Move the current page to the front of the page order
 for (int i = 0; i < MAX_FRAMES; i++) {
 if (pageOrder[i] == currentPage) {
 for (int j = i; j > 0; j--) {
 pageOrder[j] = pageOrder[j - 1];
 }
 pageOrder[0] = currentPage;
 break;
 }
 }
}
void lruPageReplacement(int frames[MAX_FRAMES], int pageOrder[MAX_FRAMES], int
page) {
 int leastRecentlyUsedPage = getLRUPage(pageOrder);
 for (int i = 0; i < MAX_FRAMES; i++) {
 if (frames[i] == leastRecentlyUsedPage) {
 frames[i] = page;
 break;
 }
 }
 updatePageOrder(pageOrder, page);
}
int main() {
 int frames[MAX_FRAMES];
 initializeFrames(frames);
 int pageSequence[] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4};
 int pageSequenceSize = sizeof(pageSequence) / sizeof(pageSequence[0]);
 int pageOrder[MAX_FRAMES];
 for (int i = 0; i < MAX_FRAMES; i++) {
 pageOrder[i] = -1; // Initialize page order
 }
 int pageFaults = 0;
 printf("Page Replacement using LRU:\n");
 for (int i = 0; i < pageSequenceSize; i++) {
 int currentPage = pageSequence[i];
 if (!isPageInFrames(frames, currentPage)) {
 printf("Page %d caused a page fault. ", currentPage);
 if (pageFaults < MAX_FRAMES) {
 frames[pageFaults] = currentPage;
 pageOrder[pageFaults] = currentPage;
 } else {
 lruPageReplacement(frames, pageOrder, currentPage);
 }
 pageFaults++;
 } else {
 printf("Page %d is already in memory. ", currentPage);
 updatePageOrder(pageOrder, currentPage);
 }
 printFrames(frames);
 }
 printf("\nTotal Page Faults: %d\n", pageFaults);
 return 0;
}

