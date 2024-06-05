#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid == -1){
        perror("fork failed");
        exit(1);
    }
    else if(pid == 0){
        printf("The child process(PID: %d) is executing ls -l\n", getpid());

        execl("/bin/ls","ls","-l",NULL);

        perror("execvp failed");
        exit(1); 
    }
    else{
        printf("Parent process(PID: %d) waiting for child...\n",getpid());
        wait(NULL);
        printf("Child process completed\n");
    }
    return 0;
}