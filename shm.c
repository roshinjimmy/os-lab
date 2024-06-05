#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *ptr;

    key = ftok("shmfile", 'R');

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    shm = shmat(shmid, NULL, 0);

    ptr = shm;
    sprintf(ptr, "Hello, shared memory!");
    printf("data written to shared memory \n");

    shmdt(shm);

    return 0;
}
