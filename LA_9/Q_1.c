/*
    Write a C programs to implement multithreading where first thread calculates the sum
    of the elements of shared data (int data [10]), another thread finds the maximum value,
    and the third thread finds the minimum value. The main thread waits for these threads
    to finish and prints their results.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
int data[] = {45, 56, 78, 32, 9, 5};

// Thread function to calculate the sum of data
void *calculate_sum(void *arg)
{
    int *thread_id = (int *)arg;
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum += data[i];
    }
    sleep(2);
    printf("Thread %d: Sum of data is %d\n", *thread_id, sum);
    pthread_exit(NULL);
}

// Thread function to find the maximum value in data
void *find_max(void *arg)
{
    int *thread_id = (int *)arg;
    int max = data[0];
    for (int i = 1; i < 6; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    printf("Thread %d: Maximum value in data is %d\n", *thread_id, max);
    pthread_exit(NULL);
}

// Thread function to find the minimum value in data
void *find_min(void *arg)
{
    int *thread_id = (int *)arg;
    int min = data[0];
    for (int i = 1; i < 6; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }
    printf("Thread %d: Minimum value in data is %d\n", *thread_id, min);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS], i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
    }

    // Create threads to perform different tasks
    pthread_create(&threads[0], NULL, calculate_sum, &thread_ids[0]);
    pthread_create(&threads[1], NULL, find_max, &thread_ids[1]);
    pthread_create(&threads[2], NULL, find_min, &thread_ids[2]);

    // Main thread waits for these threads to finish
    for (i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
