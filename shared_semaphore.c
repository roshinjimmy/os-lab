#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sharedValue = 0;
sem_t semaphore;

void* incrementThread(void* arg) {
    sem_wait(&semaphore);
    sharedValue++;
    printf("Incremented: %d\n", sharedValue);
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void* decrementThread(void* arg) {
    sem_wait(&semaphore);
    sharedValue--;
    printf("Decremented: %d\n", sharedValue);
    sem_post(&semaphore);
    pthread_exit(NULL);
}

int main() {
    sem_init(&semaphore, 0, 1);

    pthread_t incThread, decThread;
    pthread_create(&incThread, NULL, incrementThread, NULL);
    pthread_create(&decThread, NULL, decrementThread, NULL);

    pthread_join(incThread, NULL);
    pthread_join(decThread, NULL);

    sem_destroy(&semaphore);

    return 0;
}
