#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
 pid_t child_pid;
 child_pid = fork();
 if (child_pid == -1) {
 perror("Fork failed");
 exit(1);
 }
 if (child_pid == 0) {
 printf("Child process (PID=%d) is running.\n", getpid());
 sleep(10);
 printf("Child process (PID=%d) is exiting.\n", getpid());
 } else {
 printf("Parent process (PID=%d) is running.\n", getpid());
 sleep(5);
 printf("Parent process (PID=%d) is exiting.\n", getpid());
 }
 return 0;
}
