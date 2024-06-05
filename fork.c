#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    pid_t p = fork();

    if(p<0){
        perror("fork failed");
        exit(1);
    }else if(p == 0){
        printf("Hello from child(PID:%d)\n",getpid());
    }else if(p >0){
        printf("Hello from parent(PID:%d)\n",getpid());
    }
    return 0;
}