#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct thread_args {
    int thread_id;
    int sum;
    char message[256];
};

void *print_message_func(void *arg) {
    char *message = (char *) arg;
    printf("%s\n", message);
    return NULL;
}

void *print_sum_func(void *arg) {
    struct thread_args *tmp = (struct thread_args *) arg;

    struct thread_args *args = (struct thread_args *) malloc(sizeof(struct thread_args));
    if (args == NULL) {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }

    args->thread_id = tmp->thread_id;
    args->sum = tmp->sum + 1;
    snprintf(args->message, sizeof(args->message), "%s (Modified in thread)", tmp->message);

    return (void *) args;
}

void *call_self(void *arg) {
    printf("thread id = %lu\n", pthread_self());
    pthread_exit(NULL);
    return NULL;
}

void * thread_func(void *arg) {
    pthread_detach(pthread_self());
    sleep(1);
    printf("thread is ended");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3;

    char *message1 = "Test message 1!";
    char *message2 = "Test message 2!";

    pthread_create(&thread1, NULL, print_message_func, (void *) message1);
    pthread_create(&thread2, NULL, print_message_func, (void *) message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    struct thread_args args;
    args.thread_id = 1;
    args.sum = 10;
    snprintf(args.message, sizeof(args.message), "%s - %s", message1, message2);

    struct thread_args *result;
    pthread_create(&thread3, NULL, print_sum_func, (void *) &args);

    pthread_join(thread3, (void **) &result);

    printf("%s\n", result->message);
    printf("%d\n", result->sum);
    printf("%d\n", result->thread_id);

    free(result);

    pthread_t thread4;
    pthread_create(&thread4, NULL, call_self, NULL);
    printf("In main thread id = %lu\n", thread4);
    pthread_join(thread4, NULL);

    pthread_t thread5;
    int ret = pthread_create(&thread5, NULL, thread_func, NULL);
    if (ret != 0) {
        perror("Failed to create thread");
        exit(1);
    }
    printf("In main thread after thread5 is created, id = %lu\n", thread5);
    pthread_exit(NULL);
    return 0;
}
