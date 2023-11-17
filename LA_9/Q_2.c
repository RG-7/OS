/*
    Two threads thread1 and thread2 are updating the common variable inside a critical
    section. Write a program using semaphore to ensure that only one thread can access the
    critical section at a time, to prevent the race condition.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define a global variable to be shared by two threads
int common_variable = 10;
// Define a semaphore
sem_t semaphore;
void *Incre(void *arg)
{
    int thread_id = *((int *)arg);
    // Wait on the semaphore (Increment it)
    sem_wait(&semaphore);
    int i = common_variable;
    // Critical section: update the common variable
    i += 1;
    sleep(2);
    common_variable = i;
    printf("Thread %d updated common_variable to %d\n", thread_id, common_variable);
    // Signal that we're done with the critical section (increment the semaphore)
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void *Decr(void *arg)
{

    int thread_id = *((int *)arg);
    // Wait on the semaphore (decrement it)
    sem_wait(&semaphore);
    // Critical section: update the common variable
    int i = common_variable;
    // Critical section: update the common variable
    i -= 1;
    common_variable = i;
    printf("Thread %d decremented common_variable to %d\n", thread_id, common_variable);
    // Signal that we're done with the critical section (increment the semaphore)
    sem_post(&semaphore);
    pthread_exit(NULL);
}

int main()
{
    // Initialize the semaphore with a value of 1
    sem_init(&semaphore, 0, 1);
    pthread_t thread1, thread2;
    int thread_id1 = 1;
    int thread_id2 = 2;

    // Create two threads
    pthread_create(&thread1, NULL, Incre, &thread_id1);
    pthread_create(&thread2, NULL, Decr, &thread_id2);
    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // Destroy the semaphore
    sem_destroy(&semaphore);
    printf("Final common_variable value: %d\n", common_variable);
    return 0;
}