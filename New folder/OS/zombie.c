#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
 pid_t child_pid;
 child_pid = fork(); // Create a child process
 if (child_pid < 0) { // Fork failed
 perror("Fork failed");
 return 1;
 } else if (child_pid == 0) { // Child process
 printf("Child process is executing...\n");
 sleep(2); // Sleep for 2 seconds to simulate some work
 printf("Child process is done!\n");
 } else { // Parent process
 printf("Parent process is waiting for the child to finish...\n");
 sleep(5); // Sleep for 5 seconds to give child process time to finish
 printf("Parent process is done waiting.\n");
 }
 return 0;
}


