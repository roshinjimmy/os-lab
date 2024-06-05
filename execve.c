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
        char *args[] = {"/usr/bin/env",NULL};
        char *envp[] = {"MY_VARIABLE = Hello World", "PATH = usr/bin:/bin",NULL};

        if(execve("usr/bin/env",args,envp) == -1){
            perror("execve failed");
            exit(1);
        }
    }
    else{
        wait(NULL);
        printf("Child process finished\n");
    }
    return 0;
}