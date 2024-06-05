#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int num_processes = 3;
    pid_t child_pid;

    printf("The parent process (PID:%d) is creating child processes...\n",getpid());

    for(int i =0;i < num_processes;++i){
        child_pid = fork();
        if(child_pid == -1){
            perror("Child process not created");
            exit(1);
        }else if(child_pid == 0){
            printf("The child process (PID:%d) is created from parent process (PID:%d)\n",getpid(),getppid());
            exit(0);
        }
    }

    for(int i = 0;i< num_processes; ++i){
        wait(NULL);
    }

    printf("The parent process (PID:%d) has finished creating child processes\n",getpid());
    return 0;
}