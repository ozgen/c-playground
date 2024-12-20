//
// Created by moezgen on 12/20/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int count = 0;

void *thread_func1(void *arg) {
    while (1) {
        pthread_mutex_lock(&count_mutex);

        // Wait until `count` reaches COUNT_HALT1 or COUNT_DONE
        while (count < COUNT_HALT1) {
            pthread_cond_wait(&cond, &count_mutex);
        }

        if (count >= COUNT_DONE) {
            pthread_mutex_unlock(&count_mutex);
            break;
        }

        count++;
        printf("Counter value in func1: %d\n", count);

        // Signal `thread_func2`
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&count_mutex);
    }

    return NULL;
}

void *thread_func2(void *arg) {
    while (1) {
        pthread_mutex_lock(&count_mutex);

        // Wait until `count` reaches COUNT_HALT2 or COUNT_DONE
        while (count >= COUNT_HALT1 && count < COUNT_HALT2) {
            pthread_cond_wait(&cond, &count_mutex);
        }

        if (count >= COUNT_DONE) {
            pthread_mutex_unlock(&count_mutex);
            break;
        }

        count++;
        printf("Counter value in func2: %d\n", count);

        // Signal `thread_func1`
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&count_mutex);
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads
    pthread_create(&thread1, NULL, thread_func1, NULL);
    pthread_create(&thread2, NULL, thread_func2, NULL);

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
