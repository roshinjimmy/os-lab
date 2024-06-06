#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared_resource = 0;
sem_t mutex;

void* access_resource(void* thread_name) {
    char* name = (char*) thread_name;
    printf("%s is trying to access the resource.\n", name);
    sem_wait(&mutex);
    printf("%s has acquired the resource and is performing some operation.\n", name);
    for (int i = 0; i < 3; i++) {
        printf("%s is working...\n", name);
        shared_resource+=1;
    }
    printf("%s has finished its operation.\n", name);
    sem_post(&mutex);
    printf("%s has released the resource.\n", name);
    pthread_exit(NULL);
}

int main() {
    sem_init(&mutex, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, access_resource, (void*)"Thread 1");
    pthread_create(&thread2, NULL, access_resource, (void*)"Thread 2");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sem_destroy(&mutex);
    printf("All threads have finished.\n");
    printf("Shared Resource Value=%d\n",shared_resource);
    return 0;
}
