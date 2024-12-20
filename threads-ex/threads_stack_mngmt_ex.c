//
// Created by moezgen on 12/20/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_attr_t attr;

void *do_work(void *thread_id) {
    long tid;
    size_t stack_size;
    tid = (long)thread_id;
    pthread_attr_getstacksize(&attr, &stack_size);
    printf("thread %ld stack size = %li bytes \n", tid, stack_size);
    pthread_exit(NULL);
}

void *do_work2(void *thread_id) {
    printf("hello world\n");
    pthread_cancel(pthread_self());
    return NULL;
}

int main() {
    pthread_t thread;
    size_t stack_size;
    pthread_t myID;
    long tid = 5;

    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stack_size);
    printf("initial thread %ld stack size = %li bytes \n", tid, stack_size);
    stack_size = 90000000;
    pthread_attr_setstacksize(&attr, stack_size);
    printf("Setting thread %ld stack size = %li bytes \n", tid, stack_size);
    myID = pthread_create(&thread, &attr, do_work, (void *)tid);
    if (myID) {
        printf("ERROR; return code from pthread_create() is %lud\n", myID);
        exit(-1);
    }

    pthread_t thread2;
    pthread_create(&thread2, NULL, do_work2, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
