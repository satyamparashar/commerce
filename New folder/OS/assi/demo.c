
#include<stdio.h>
#include<unistd.h>
int main(){
    pid_t pid;
    printf("Before fork()\n");
    pid = fork();
    if(pid == 0){
        printf("Child process: PID = %d\n",getpid());
    }
    else if(pid > 0){
        printf("Parent process: PID=%d, Child PID=%d\n",getpid(),pid);
    }
    else{
        printf("Fork Failed\n");
        return 1;

    }
    printf("After fork()\n");
    return 0;
}
