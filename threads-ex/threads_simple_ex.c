//
// Created by moezgen on 12/20/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function() {
  printf("Hello World\n");
  return NULL;
}

int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, thread_function, NULL);
  pthread_join(thread, NULL); // wait for the thread
  pthread_exit(NULL);
  return 0;
}