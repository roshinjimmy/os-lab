#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;

    // Create a shared memory segment with key 2345, size 1024 bytes, and permissions 0666
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);

    // Attach the process to the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shared_memory); // Prints the address where the segment is attached

    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100); // Get some input from user

    strcpy(shared_memory, buff); // Write data to shared memory
    printf("You wrote: %s\n", (char *)shared_memory);

    return 0;
}
