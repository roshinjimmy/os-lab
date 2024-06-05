#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int sum =0;

int calculateSum(int start, int end){
    for(int i =start;i<= end;i++){
        sum +=i;
    }
    return sum;
}

int main(){
    int N;

    printf("Enter a number N(N<= 25): ");
    scanf("%d",&N);

    pid_t pid = fork();

    if(pid == -1){
        perror("fork failed");
        exit(1);
    }else if(pid == 0){
        int sum = calculateSum(1,N/2);
        printf("Child1: The sum of numbers from %d to %d is: %d\n",1,N/2,sum);
        exit(sum);
    }
    else{
        pid_t pid2 = fork();
        if(pid2 == -1){
            perror("fork failed");
            exit(1);
        }else if(pid2 ==0){
            int sum = calculateSum((N/2)+1,N);
            printf("Child2: The sum of numbers form %d to %d is: %d\n",(N/2)+1,N,sum);
            exit(sum);
        }
        else{
            int status1,status2;
            waitpid(pid,&status1,0);
            waitpid(pid2,&status2,0);

            int total_sum = WEXITSTATUS(status1) + WEXITSTATUS(status2);
            printf("Parent: The sum of numbers from 1 to %d is: %d\n",N,total_sum);
        }
    }
    return 0;
}