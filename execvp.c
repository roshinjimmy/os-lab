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

        char *args = {"ls","-l",NULL};
        execvp(args[0],args);

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