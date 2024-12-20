//
// Created by moezgen on 12/20/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
int j = 0;

void * do_process(){
  pthread_mutex_lock(&lock);
  int i =0;
  j++;
  while(i<2){
    printf("%d\n",j);
    sleep(1);
    i++;
  }
  printf("... Done\n");
  pthread_mutex_unlock(&lock);
  return NULL;
}

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void * do_process2() {
  pthread_mutex_lock(&mutex);
  counter = counter+5;
  pthread_mutex_unlock(&mutex);
}

int main() {

  pthread_t thread1, thread2;
  if(pthread_mutex_init(&lock, NULL) != 0) {
    printf("Mutex init failed\n");
    return -1;
  }
  j = 0;

  pthread_create(&thread1, NULL, do_process, NULL);
  pthread_create(&thread2, NULL, do_process, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  pthread_mutex_destroy(&lock);

  int thread_count = 10;
  pthread_t threads[thread_count];

  for(int i = 0; i < thread_count; i++) {
    pthread_create(&threads[i], NULL, do_process2, NULL);
  }
  for(int i = 0; i < thread_count; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  printf( "counter : %d\n", counter);
  return 0;
}